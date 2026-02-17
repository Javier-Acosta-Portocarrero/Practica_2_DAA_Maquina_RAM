// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo data_memory.h: fichero de declaracion.
// Contiene la declaracion de la clase DataMemory.

#ifndef DATA_MEMORY_H_
#define DATA_MEMORY_H_

#include <vector>

class DataMemory {
 public:
  DataMemory();
  
  float GetRegisterValue(unsigned register_index) const;
  unsigned GetProgramCounter() const { return program_counter_register_;}
  void SetProgramCounter(unsigned program_counter) { program_counter_register_ = program_counter;}
  void SetRegisterValue(unsigned register_index, float value);

  void IncrementProgramCounter() { ++program_counter_register_;}
 private:
  std::vector<float> memory_;
  unsigned program_counter_register_{0};
};

#endif