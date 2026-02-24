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
  memory_.resize(33);
  for (auto& registers : memory_) {
    registers.resize(1, 0.0f);
  }
}

float DataMemory::GetRegisterScalar(unsigned register_index) const {
  if (register_index > 32) {
    throw std::out_of_range("Invalid register");
  }
  return memory_[register_index][0];
}

void DataMemory::SetRegisterScalar(unsigned register_index, float value) {
  if (register_index > 32) {
    throw std::out_of_range("Invalid register");
  }
  memory_[register_index].resize(1);
  memory_[register_index][0] = value;
}

float DataMemory::GetRegisterValue(unsigned reg, unsigned register_index) const {
  if (reg > 32) {
    throw std::out_of_range("Invalid register");
  }
  if (register_index >= memory_[reg].size()) {
    throw std::out_of_range("Invalid register index");
  }
  return memory_[reg][register_index];
}
  
void DataMemory::SetRegisterValue(unsigned reg, unsigned register_index, float value) {
  if (reg > 32) {
    throw std::out_of_range("Invalid register");
  }
  if (register_index >= memory_[reg].size()) {
    memory_[reg].resize(register_index + 1, 0.0f);
  }
  memory_[reg][register_index] = value;
}

void DataMemory::SetVector(unsigned reg, const std::vector<float>& memory_register) {
  if (reg > 32) {
    throw std::out_of_range("Invalid register");
  }
  memory_[reg] = memory_register;
}