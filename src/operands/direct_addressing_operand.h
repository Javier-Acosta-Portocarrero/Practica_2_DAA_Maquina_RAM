// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo direct_addressing_operand.h: fichero de declaracion.
// Contiene la declaracion de la clase DirectAddressingOperand.

#ifndef DIRECT_ADDRESSING_OPERAND_H_
#define DIRECT_ADDRESSING_OPERAND_H_

#include "operand.h"

class DirectAddressingOperand : public Operand {
 public:
  DirectAddressingOperand(unsigned register_index) : register_index_{register_index} {}
  ~DirectAddressingOperand() = default;

  float GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const override;
  inline int GetOperandIndex(const DataMemory& data) const override { return register_index_;}
 private:
  unsigned register_index_{0};
};

#endif