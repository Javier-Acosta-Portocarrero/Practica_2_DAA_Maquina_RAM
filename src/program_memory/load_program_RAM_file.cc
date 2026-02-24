// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo load_program_RAM_file.cc: fichero de implementación.
// Contiene la implementación de la load_program_RAM.

#include "load_program_RAM_file.h"
#include "../instructions/add_instruction.h"
#include "../instructions/div_instruction.h"
#include "../instructions/halt_instruction.h"
#include "../instructions/jgtz_instruction.h"
#include "../instructions/jump_instruction.h"
#include "../instructions/jzero_instruction.h"
#include "../instructions/load_instruction.h"
#include "../instructions/mul_instruction.h"
#include "../instructions/read_instruction.h"
#include "../instructions/store_instruction.h"
#include "../instructions/sub_instruction.h"
#include "../instructions/write_instruction.h"
#include "../operands/constant_operand.h"
#include "../operands/direct_addressing_operand.h"
#include "../operands/indirect_addressing_operand.h"
#include "../operands/label_operand.h"

//#include <iostream>
ProgramMemory LoadProgramRAMFile::Load() {
  std::ifstream program_input_stream{program_path_};
  if (!program_input_stream.is_open()) {
    throw std::runtime_error("No se pudo abrir el fichero");
  }

  ProgramMemory program;
  std::string line;
  unsigned linea{1};

  while (std::getline(program_input_stream, line)) {
    // Remove leading whitespace
    size_t first = line.find_first_not_of(" \t");
    if (first != std::string::npos) line.erase(0, first);
    if (line.empty()) continue;
    if (line[0] == '#') continue;
    // Make it uppercase
    for (char& character : line) {
      character = std::toupper(character);
    }
    try {
      Instruction* inst = ParseInstruction(line, linea, program);
      if (inst) {
        program.AddInstruction(linea, inst);
        ++linea;
      }
    } catch (const std::exception& e) {
      throw std::runtime_error(
        "Error en linea " + std::to_string(linea) + ": " + e.what());
    }
  }

  return program;
}


Instruction* LoadProgramRAMFile::ParseInstruction(const std::string& line, unsigned line_number, ProgramMemory& program) {
  std::string currentLine = line;
  // Check for label and remove it from the line if it exists. We also check for duplicate labels.
  size_t colon_pos = currentLine.find(':');
  if (colon_pos != std::string::npos) {
    std::string label = currentLine.substr(0, colon_pos);
    int contador = 0;
    for (const auto& labelPair : program.GetTableLabel()) {
      if (labelPair.first == label) {
        contador++;
        if (contador > 1) {
          throw std::runtime_error("Etiqueta duplicada: " + label);
        }
      }
    } 
    program.AddLabel(line_number, label);
    currentLine.erase(0, colon_pos + 1);

    // Remove leading whitespace after label.
    size_t first = currentLine.find_first_not_of(" \t");
    if (first == std::string::npos) return nullptr;  
    currentLine.erase(0, first);
  }
  //std::cout << "Parsing instruction at line " << line_number << ": " << currentLine << std::endl;

  std::istringstream iss(currentLine);
  std::string opcode;
  iss >> opcode;
  std::string operand_text;
  iss >> operand_text;
  // First we check for instructions without operand (HALT)
  if (opcode == "HALT") {
    if (!operand_text.empty()) {
      throw std::runtime_error("HALT no admite operando");
    }
    return new HaltInstruction(nullptr, line_number);
  }
  // Then we check for jump instructions, which have a label as operand.
  Operand* jump_operand = new LabelOperand(operand_text);
  if (opcode == "JUMP") {
    return new JumpInstruction(jump_operand, line_number);
  }
  if (opcode == "JZERO") {
    return new JzeroInstruction(jump_operand, line_number);
  }
  if (opcode == "JGTZ") {
    return new JgtzInstruction(jump_operand, line_number);
  }
  // Finally, we check for instructions with a non label operand (all the rest)
  Operand* operand = ParseOperand(operand_text);
  if (opcode == "LOAD") {
    return new LoadInstruction(operand, line_number);
  }
  if (opcode == "STORE") {
    return new StoreInstruction(operand, line_number);
  }
  if (opcode == "ADD") {
    return new AddInstruction(operand, line_number);
  }
  if (opcode == "SUB") {
    return new SubInstruction(operand, line_number);
  }
  if (opcode == "MUL") {
    return new MulInstruction(operand, line_number);
  }
  if (opcode == "DIV") {
    return new DivInstruction(operand, line_number);
  }
  if (opcode == "READ") {
    return new ReadInstruction(operand, line_number);
  }
  if (opcode == "WRITE") {
    return new WriteInstruction(operand, line_number);
  }
  throw std::runtime_error("Opcode desconocido: " + opcode);
}

Operand* LoadProgramRAMFile::ParseOperand(const std::string& text) {
  if (text.empty()) return nullptr;
  // Constants 
  if (text[0] == '=') {
    float value = std::stof(text.substr(1));
    return new ConstantOperand(value);
  }
  // Indirect addressing
  if (text[0] == '*') {
    int index = std::stoi(text.substr(1));
    return new IndirectAddressingOperand(index);
  }
  // Direct addressing. We need to check if there's a bracket to determine if it's a vector access or not.
  auto bracket_pos = text.find('[');
  std::string base_str = (bracket_pos != std::string::npos) ? text.substr(0, bracket_pos) : text;
  // if (base_str[0] == 'R') base_str.erase(0,1);  
  int base_index = std::stoi(base_str);
  if (bracket_pos != std::string::npos) {
    // If there's a bracket, we need to parse the index operand
    auto closing = text.find(']');
    std::string index_text = text.substr(bracket_pos + 1, closing - bracket_pos - 1);
    Operand* index_operand = ParseOperand(index_text);
    return new DirectAddressingOperand(base_index, index_operand);
  } else {
    // If it's just a number, it's a direct register access (Ri)
    return new DirectAddressingOperand(base_index);
  }
}