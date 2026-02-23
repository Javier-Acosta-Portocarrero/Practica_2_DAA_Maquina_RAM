// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo direct_addressing_operand.cc: fichero de definicion.
// Contiene la definicion de la clase DirectAddressingOperand.

#include "direct_addressing_operand.h"

float DirectAddressingOperand::GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const {
  // If the register is not valid, the method GetRegisterValue will throw an exception.
  if (!index_vector_register_) {
    return data.GetRegisterScalar(register_index_);
  }
  return data.GetRegisterValue(register_index_, index_vector_register_);
  
}