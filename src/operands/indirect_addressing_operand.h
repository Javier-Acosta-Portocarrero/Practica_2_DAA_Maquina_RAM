// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo indirect_addressing_operand.h: fichero de declaracion.
// Contiene la declaracion de la clase IndirectAddressingOperand.

#ifndef INDIRECT_ADDRESSING_OPERAND_H_
#define INDIRECT_ADDRESSING_OPERAND_H_

#include "operand.h"

class IndirectAddressingOperand : public Operand {
 public:
  IndirectAddressingOperand(unsigned indirect_register_index) : indirect_register_index_{indirect_register_index} {}
  ~IndirectAddressingOperand() = default;

  float GetOperandValue(const DataMemory& data) const override;
  int GetOperandIndex(const DataMemory& data) const override { return data.GetRegisterValue(indirect_register_index_);}
 private:
  unsigned indirect_register_index_{0};
};

#endif