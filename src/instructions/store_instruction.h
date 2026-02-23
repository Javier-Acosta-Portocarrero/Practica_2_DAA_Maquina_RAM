// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo store_instruction.h: fichero de declaracion.
// Contiene la declaracion de la clase StoreInstruction.

#ifndef STORE_INSTRUCTION_H_
#define STORE_INSTRUCTION_H_

#include "instruction.h"

class StoreInstruction : public Instruction {
 public:
  StoreInstruction(Operand* operand, unsigned line) : Instruction(operand, line) {}
  ~StoreInstruction() = default;
  
  void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) override;
};

#endif