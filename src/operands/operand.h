// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo operand.h: fichero de declaracion.
// Contiene la declaracion de la clase Operand.

#ifndef OPERAND_H_
#define OPERAND_H_

#include "../data_memory/data_memory.h"

class Operand {
 public:
  virtual ~Operand() = default;

  virtual float GetOperandValue(const DataMemory& data) const = 0;
  // int because -1 means constant operand, etc.
  virtual int GetOperandIndex(const DataMemory& data) const = 0;
};

#endif