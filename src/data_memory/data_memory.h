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
  
  float GetRegisterScalar(unsigned register_index) const;
  float GetRegisterValue(unsigned reg, unsigned register_index) const;
  inline int GetProgramCounter() const { return program_counter_register_;}
  inline void SetProgramCounter(unsigned program_counter) { program_counter_register_ = program_counter;}
  void SetRegisterValue(unsigned reg, unsigned register_index, float value);
  void SetRegisterScalar(unsigned register_index, float value);
  void SetVector(unsigned reg, const std::vector<float>& memory_register);

  inline void IncrementProgramCounter() { ++program_counter_register_;}
 private:
  std::vector<std::vector<float>> memory_;
  // Int because we need to know if HALT instruction is executed (PC = -1 --> STOP)
  int program_counter_register_{0};
};

#endif