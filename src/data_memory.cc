// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo data_memory.cc: fichero de definicion.
// Contiene la definicion de la clase DataMemory.

#include "data_memory.h"
#include <stdexcept>

DataMemory::DataMemory() {
  memory_.resize(33, 0.0);
}

float DataMemory::GetRegisterValue(unsigned register_index) const {
  if (register_index > 32) {
    throw std::out_of_range("Invalid register");
  }
  return memory_[register_index];
}
  
void DataMemory::SetRegisterValue(unsigned register_index, float value) {
  if (register_index > 32) {
    throw std::out_of_range("Invalid register");
  }
  memory_[register_index] = value;
}