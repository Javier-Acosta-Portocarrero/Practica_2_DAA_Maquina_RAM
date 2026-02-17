// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo mul_instruction.h: fichero de declaracion.
// Contiene la declaracion de la clase MulInstruction.

#ifndef MUL_INSTRUCTION_H_
#define MUL_INSTRUCTION_H_

#include "instruction.h"

class MulInstruction : Instruction {
 public:
  MulInstruction(Operand* operand, unsigned line) : Instruction(operand, line) {}
  ~MulInstruction() = default;
  
  void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) override;
};

#endif