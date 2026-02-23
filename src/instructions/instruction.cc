// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 23/02/2024
// Archivo instruction.cc: fichero de definición.
// Contiene la definición de la clase Instruction.

#include "instruction.h"
#include "../operands/operand.h"

Instruction::~Instruction() {
  delete operand_;
}