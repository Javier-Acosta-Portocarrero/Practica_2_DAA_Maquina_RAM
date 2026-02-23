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

  inline size_t GetProgramSize() const { return instrucciones_.size();}
  inline Instruction& GetInstruction(unsigned pc) { return *instrucciones_.at(pc);}
  inline unsigned GetLineByLabel(const std::string& label) const { return label_table_.at(label); }

 private:
  friend class LoadProgramRAMFile;
  inline void AddInstruction(unsigned line, Instruction* instruction) { instrucciones_.emplace(line, instruction);}
  inline void AddLabel(unsigned line, const std::string& label) { label_table_.emplace(label, line);}
  inline const std::map<std::string, unsigned>& GetTableLabel() const { return label_table_; }

  std::map<unsigned, Instruction*> instrucciones_;
  std::map<std::string, unsigned> label_table_;
};

#endif