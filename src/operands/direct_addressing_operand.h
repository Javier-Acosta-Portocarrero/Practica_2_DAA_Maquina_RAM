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
#include "optional"

class DirectAddressingOperand : public Operand {
 public:
  DirectAddressingOperand(unsigned register_index) : register_index_{register_index} {}
  DirectAddressingOperand(unsigned register_index, Operand* index_vector_register) : register_index_{register_index}, index_vector_register_{index_vector_register} {}
  ~DirectAddressingOperand() = default;

  float GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const override;
  inline int GetOperandIndex(const DataMemory& data) const override { return register_index_;}
  inline Operand* GetIndexOperand() const {return index_vector_register_;}

  inline bool HasIndexOperand() const { return index_vector_register_ != nullptr; }
  inline bool OperandIsDirect() const override { return true;}
 private:
  unsigned register_index_{0};
  Operand* index_vector_register_{nullptr};
};

#endif