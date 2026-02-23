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
#include <fstream>
#include <sstream>
#include <stdexcept>

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

class LoadProgramRAMFile;
class ProgramMemory {
public:
  ProgramMemory() = default;
  ~ProgramMemory() = default;

  size_t GetProgramSize() const {return instrucciones_.size();}

  Instruction& GetInstruction(unsigned pc) { return *instrucciones_.at(pc);}

  const std::string& GetLabelLine(unsigned pc) const { return label_table_.at(pc); }

  private:
  friend class LoadProgramRAMFile;
  void AddInstruction(unsigned line, std::unique_ptr<Instruction> instruction) {instrucciones_.emplace(line, std::move(instruction));}
  void AddLabel(unsigned line, const std::string& label) {label_table_.emplace(line, label);}
  std::map<unsigned, std::unique_ptr<Instruction>> instrucciones_;
  std::map<unsigned, std::string> label_table_;
  const std::map<unsigned, std::string>& GetTableLabel() const { return label_table_; }
};

#endif