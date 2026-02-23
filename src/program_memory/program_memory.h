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

class LoadProgramRAMFile;

class ProgramMemory {
 public:
  ProgramMemory() = default;
  ~ProgramMemory() = default;

  size_t GetProgramSize() const {return instrucciones_.size();}
  Instruction& GetInstruction(unsigned pc) { return *instrucciones_.at(pc);}
  unsigned GetLineByLabel(const std::string& label) const { return label_table_.at(label); }

 private:
  friend class LoadProgramRAMFile;
  void AddInstruction(unsigned line, std::unique_ptr<Instruction> instruction) {instrucciones_.emplace(line, std::move(instruction));}
  void AddLabel(unsigned line, const std::string& label) {label_table_.emplace(line, label);}
  const std::map<std::string, unsigned>& GetTableLabel() const { return label_table_; }

  std::map<unsigned, std::unique_ptr<Instruction>> instrucciones_;
  std::map<std::string, unsigned> label_table_;
};

#endif