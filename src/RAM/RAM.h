// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo RAM.h: fichero de declaracion.
// Contiene la declaracion de la RAM.

#ifndef RAM_H_
#define RAM_H_

#include "../program_memory/load_program_RAM_file.cc"
#include "../output_tape/store_output_tape_file.cc"
#include "../input_tape/load_input_tape_file.cc"
#include "../data_memory/data_memory.cc"
#include "../Arithmetic_Control_Logic_Unit/arithmetic_control_logic_unit.cc"

class RAM {
  public:
  RAM(const std::string&  input_path, const std::string& program_path, const std::string& output_path = "") : input_path_(input_path), program_path_(program_path), output_path_(output_path) {}
  ~RAM() = default;
  void Execute();

  private:
  std::string input_path_, program_path_, output_path_;
};

#endif