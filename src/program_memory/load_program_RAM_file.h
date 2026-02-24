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
  /**
   * @brief Construye el archivo  que contiene el programa RAM
   * 
   * @param program_path 
   */
  LoadProgramRAMFile(const std::string& program_path) : program_path_(program_path) {}
  LoadProgramRAMFile() = default;
  ~LoadProgramRAMFile() = default;
  /**
   * @brief Establece el archivo del programa RAM
   * 
   * @param program_path 
   */
  inline void SetProgram(const std::string& program_path) {program_path_ = program_path;}
  /**
   * @brief Carga el programa RAM linea a linea
   * 
   * @return ProgramMemory 
   */
  ProgramMemory Load() override;
  private:
  std::string program_path_;
  /**
   * @brief Separa y clasifica cada elemento de la linea para obtener las instrucciones a ejecutar
   * 
   * @param line 
   * @param line_number 
   * @param program 
   * @return Instruction* 
   */
  Instruction* ParseInstruction(const std::string& line, unsigned line_number, ProgramMemory& program);
  /**
   * @brief Separa y clasifica cada elemento de la instrucción para obtener el tipo de operando a crear
   * 
   * @param text 
   * @return Operand* 
   */
  Operand* ParseOperand(const std::string& text); 
};

#endif