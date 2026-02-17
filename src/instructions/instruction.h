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

#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"

class Instruction {
 public:
  Instruction(Operand* operand, unsigned line) : operand_{operand}, line_{line} {}
  virtual ~Instruction() { delete operand_;}
  
  // Must throw an exception if the instruction is illegal
  virtual void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) = 0;

  Operand* GetOperand() { return operand_;}
  unsigned GetLine() const { return line_;}
 private:
  Operand* operand_;
  unsigned line_{0};
};

#endif