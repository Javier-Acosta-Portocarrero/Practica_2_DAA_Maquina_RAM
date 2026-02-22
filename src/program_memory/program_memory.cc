// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo program_memory.cc: fichero de implementación.
// Contiene la implementación de la ProgramMemory.

#include "program_memory.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

bool ProgramMemory::LoadProgram() {
  std::ifstream program_input_stream{program_path_};
  if (!program_input_stream.is_open()) {
    return false;
  }

  std::string line;
  unsigned linea{1};

  while (std::getline(program_input_stream, line)) {
    if (line.empty()) continue;
    if (line[0] == '#') continue;
    //Quitamos los espacios iniciales que pueda tener
    size_t first = line.find_first_not_of(" \t");
    if (first != std::string::npos) line.erase(0, first);
    try {
      auto inst = ParseInstruction(line, linea);
      if (inst) {
        instrucciones_.emplace(linea, std::move(inst));
        ++linea;
      }

    } catch (const std::exception& e) {
      throw std::runtime_error(
        "Error en linea " + std::to_string(linea) + ": " + e.what());
    }
  }

  return true;
}

std::unique_ptr<Instruction> ProgramMemory::ParseInstruction(const std::string& line, unsigned line_number) {
  std::string working = line;
  size_t colon_pos = working.find(':');
  if (colon_pos != std::string::npos) {
    std::string label = working.substr(0, colon_pos);
    if (label_table_.count(label)) 
    throw std::runtime_error("Etiqueta duplicada: " + label);
    label_table_[label] = line_number;
    working.erase(0, colon_pos + 1);

    size_t first = working.find_first_not_of(" \t");
    if (first == std::string::npos) return nullptr;  
    working.erase(0, first);
  }

  std::istringstream iss(working);

  std::string opcode;
  iss >> opcode;

  std::string operand_text;
  iss >> operand_text;

  std::unique_ptr<Operand> operand = ParseOperand(operand_text);

  if (opcode == "LOAD")
  return std::make_unique<LoadInstruction>(std::move(operand), line_number);
  if (opcode == "STORE")
  return std::make_unique<StoreInstruction>(std::move(operand), line_number);
  if (opcode == "ADD")
  return std::make_unique<AddInstruction>(std::move(operand), line_number);
  if (opcode == "SUB")
  return std::make_unique<SubInstruction>(std::move(operand), line_number);
  if (opcode == "MUL")
  return std::make_unique<MulInstruction>(std::move(operand), line_number);
  if (opcode == "DIV")
  return std::make_unique<DivInstruction>(std::move(operand), line_number);
  if (opcode == "READ")
  return std::make_unique<ReadInstruction>(std::move(operand), line_number);
  if (opcode == "WRITE")
  return std::make_unique<WriteInstruction>(std::move(operand), line_number);
  if (opcode == "HALT")
  return std::make_unique<HaltInstruction>(nullptr, line_number);
  if (opcode == "JUMP")
  return std::make_unique<JumpInstruction>(operand_text, line_number);
  if (opcode == "JZERO")
  return std::make_unique<JzeroInstruction>(operand_text, line_number);
  if (opcode == "JGTZ")
  return std::make_unique<JgtzInstruction>(operand_text, line_number);
  throw std::runtime_error("Opcode desconocido: " + opcode);
}

std::unique_ptr<Operand> ProgramMemory::ParseOperand(const std::string& text) {
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