// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 23/02/2024
// Archivo label_operand.h: fichero de declaracion.
// Contiene la declaracion de la clase LabelOperand.

#ifndef LABEL_OPERAND_H_
#define LABEL_OPERAND_H_

#include "operand.h"
#include <string>

class LabelOperand : public Operand {
 public:
  LabelOperand(const std::string& label) : label_{label} {}
  ~LabelOperand() = default;
  
  float GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const override;
  // -1 means that this operand is not an index, but a label.
  inline int GetOperandIndex(const DataMemory& data) const override { return -1;}

  inline bool OperandIsDirect() const override { return false;}
 private:
  std::string label_;  
};

#endif