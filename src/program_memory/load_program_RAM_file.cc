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

ProgramMemory LoadProgramRAMFile::Load() {
  std::ifstream program_input_stream{program_path_};
  if (!program_input_stream.is_open()) {
    throw std::runtime_error("No se pudo abrir el fichero");
  }

  ProgramMemory program;
  std::string line;
  unsigned linea{1};

  while (std::getline(program_input_stream, line)) {
    if (line.empty()) continue;
    if (line[0] == '#') continue;

    size_t first = line.find_first_not_of(" \t");
    if (first != std::string::npos) line.erase(0, first);

    try {
      auto inst = ParseInstruction(line, linea, program);
      if (inst) {
        program.AddInstruction(linea, std::move(inst));
        ++linea;
      }
    } catch (const std::exception& e) {
      throw std::runtime_error(
        "Error en linea " + std::to_string(linea) + ": " + e.what());
    }
  }

  return program;
}


std::unique_ptr<Instruction> LoadProgramRAMFile::ParseInstruction(const std::string& line, unsigned line_number, ProgramMemory& program) {
  std::string currentLine = line;
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

    size_t first = currentLine.find_first_not_of(" \t");
    if (first == std::string::npos) return nullptr;  
    currentLine.erase(0, first);
  }

  std::istringstream iss(currentLine);
  std::string opcode;
  iss >> opcode;
  std::string operand_text;
  iss >> operand_text;

  std::unique_ptr<Operand> operand = ParseOperand(operand_text);

  if (opcode == "LOAD") {
    return std::make_unique<LoadInstruction>(std::move(operand), line_number);
  }
  if (opcode == "STORE") {
    return std::make_unique<StoreInstruction>(std::move(operand), line_number);
  }
  if (opcode == "ADD") {
    return std::make_unique<AddInstruction>(std::move(operand), line_number);
  }
  if (opcode == "SUB") {
    return std::make_unique<SubInstruction>(std::move(operand), line_number);
  }
  if (opcode == "MUL") {
    return std::make_unique<MulInstruction>(std::move(operand), line_number);
  }
  if (opcode == "DIV") {
    return std::make_unique<DivInstruction>(std::move(operand), line_number);
  }
  if (opcode == "READ") {
    return std::make_unique<ReadInstruction>(std::move(operand), line_number);
  }
  if (opcode == "WRITE") {
    return std::make_unique<WriteInstruction>(std::move(operand), line_number);
  }
  if (opcode == "HALT") {
    if (!operand_text.empty()) {
      throw std::runtime_error("HALT no admite operando");
    }
    return std::make_unique<HaltInstruction>(nullptr, line_number);
  }
  std::unique_ptr<Operand> jump_operand = std::make_unique<LabelOperand>(operand_text);
  if (opcode == "JUMP") {
    return std::make_unique<JumpInstruction>(std::move(jump_operand), line_number);
  }
  if (opcode == "JZERO") {
    return std::make_unique<JzeroInstruction>(std::move(jump_operand), line_number);
  }
  if (opcode == "JGTZ") {
    return std::make_unique<JgtzInstruction>(std::move(jump_operand), line_number);
  }
  
  throw std::runtime_error("Opcode desconocido: " + opcode);
}

std::unique_ptr<Operand> LoadProgramRAMFile::ParseOperand(const std::string& text) {
  if (text.empty()) return nullptr;
  
  if (text[0] == '=') {
    float value = std::stof(text.substr(1));
    return std::make_unique<ConstantOperand>(value);
  }
  if (text[0] == '*') {
    int index = std::stoi(text.substr(1));
    return std::make_unique<IndirectAddressingOperand>(index);
  }
  int index = std::stoi(text);
  return std::make_unique<DirectAddressingOperand>(index);
}