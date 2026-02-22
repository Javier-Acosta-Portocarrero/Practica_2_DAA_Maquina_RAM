// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo program_memory.h: fichero de declaracion.
// Contiene la declaracion de la ProgramMemory.

#ifndef PROGRAM_MEMORY_H_
#define PROGRAM_MEMORY_H_

#include <map>
#include <memory>
#include "../instructions/instruction.h"
#include "../instructions/add_instruction.cc"
#include "../instructions/div_instruction.cc"
#include "../instructions/halt_instruction.cc"
#include "../instructions/jgtz_instruction.cc"
#include "../instructions/jump_instruction.cc"
#include "../instructions/jzero_instruction.cc"
#include "../instructions/load_instruction.cc"
#include "../instructions/mul_instruction.cc"
#include "../instructions/read_instruction.cc"
#include "../instructions/store_instruction.cc"
#include "../instructions/sub_instruction.cc"
#include "../instructions/write_instruction.cc"
#include "../operands/constant_operand.h"
#include "../operands/direct_addressing_operand.cc"
#include "../operands/indirect_addressing_operand.cc"

class ProgramMemory {
  public:
  ProgramMemory(const std::string&  file_path) : program_path_{file_path} {}

  ~ProgramMemory() = default;

  bool LoadProgram();
  const std::map<unsigned, std::unique_ptr<Instruction>>& GetProgram() const { return instrucciones_;}
  size_t GetProgramSize() {return instrucciones_.size();}
  Instruction& GetInstruction(unsigned pc) {return *instrucciones_.at(pc);}
  private:
  //Ordena por su linea de entrada contiendo su respectiva instrucción
  //std::map<int, std::string> instrucciones_;
  std::map<unsigned, std::unique_ptr<Instruction>> instrucciones_;
  std::string program_path_;
  std::unique_ptr<Instruction> ParseInstruction(const std::string& line, unsigned line_number);
  std::unique_ptr<Operand> ParseOperand(const std::string& text);
  std::map<std::string, int> label_table_;
};

#endif