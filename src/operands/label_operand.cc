// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 23/02/2024
// Archivo label_operand.cc: fichero de definición.
// Contiene la definición de la clase LabelOperand.

#include "label_operand.h"

float LabelOperand::GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const {
  // If the label is not valid, the method GetLineByLabel will throw an exception.
  unsigned line = instructions.GetLineByLabel(label_);
  return line;  
}