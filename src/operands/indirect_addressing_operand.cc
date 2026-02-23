// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo indirect_addressing_operand.cc: fichero de definicion.
// Contiene la definicion de la clase IndirectAddressingOperand.

#include "indirect_addressing_operand.h"

float IndirectAddressingOperand::GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const {
  // If one of the registers is not valid, the method GetRegisterValue will throw an exception.
  float value = data.GetRegisterScalar(data.GetRegisterScalar(indirect_register_index_));
  return value;
}