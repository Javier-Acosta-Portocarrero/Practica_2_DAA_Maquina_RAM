// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo load_instruction.h: fichero de declaracion.
// Contiene la declaracion de la clase LoadInstruction.

#ifndef LOAD_INSTRUCTION_H_
#define LOAD_INSTRUCTION_H_

#include "instruction.h"

class LoadInstruction : Instruction {
 public:
  LoadInstruction(Operand* operand, unsigned line) : Instruction(operand, line) {}
  ~LoadInstruction() = default;
  
  void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) override;
};

#endif