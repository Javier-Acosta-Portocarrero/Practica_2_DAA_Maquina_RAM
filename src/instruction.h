// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo instruction.h: fichero de declaracion.
// Contiene la declaracion de la clase Instruction.

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "operand.h"
#include "data_memory.h"
#include "input_tape.h"
#include "output_tape.h"

class Instruction {
 public:
  virtual ~Instruction() { delete operand_;}
  
  // Must throw an exception if the instruction is illegal
  virtual void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) const = 0;
 private:
  Operand* operand_;
};

#endif