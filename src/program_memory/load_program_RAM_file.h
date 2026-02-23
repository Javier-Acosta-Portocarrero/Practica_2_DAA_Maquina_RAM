// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo load_program_RAM_file.h: fichero de declaracion.
// Contiene la declaracion de la load_program_RAM.

#ifndef LOAD_PROGRAM_RAM_FILE_H_
#define LOAD_PROGRAM_RAM_FILE_H_

#include "load_program_RAM.h"

class LoadProgramRAMFile : public LoadProgramRAM {
  public:
  LoadProgramRAMFile(const std::string& program_path) : program_path_(program_path) {}
  LoadProgramRAMFile() = default;
  ~LoadProgramRAMFile() = default;
  void SetProgram(const std::string& program_path) {program_path_ = program_path;}
  std::unique_ptr<const ProgramMemory> Load() override;
  private:
  std::string program_path_;
  std::unique_ptr<Instruction> ParseInstruction(const std::string& line, unsigned line_number, ProgramMemory& program);
  std::unique_ptr<Operand> ParseOperand(const std::string& text); 
};

#endif