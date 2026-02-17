// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo constant_operand.h: fichero de declaracion.
// Contiene la declaracion de la clase ConstantOperand.

#ifndef CONSTANT_OPERAND_H_
#define CONSTANT_OPERAND_H_

#include "operand.h"

class ConstantOperand : Operand {
 public:
  ConstantOperand(float value) : value_{value} {}
  ~ConstantOperand() = default;

  float GetOperandValue(const DataMemory& data) const override { return value_;}
 private:
  float value_{0.0};
};

#endif