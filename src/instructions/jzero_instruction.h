// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo jzero_instruction.h: fichero de declaracion.
// Contiene la declaracion de la clase JzeroInstruction.

#ifndef JZERO_INSTRUCTION_H_
#define JZERO_INSTRUCTION_H_

#include "instruction.h"

class JzeroInstruction : public Instruction {
 public:
  JzeroInstruction(Operand* operand, unsigned line) : Instruction(operand, line) {}
  ~JzeroInstruction() = default;
  
  void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) override;
};

#endif