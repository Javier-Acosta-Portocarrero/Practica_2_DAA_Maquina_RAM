// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 24/02/2024
// Archivo exp_instruction.h: fichero de declaracion.
// Contiene la declaracion de la clase ExpInstruction.

#ifndef EXP_INSTRUCTION_H_
#define EXP_INSTRUCTION_H_

#include "instruction.h"

class ExpInstruction : public Instruction {
 public:
  ExpInstruction(Operand* operand, unsigned line) : Instruction(operand, line) {}
  ~ExpInstruction() = default;
  
  /**
   * @brief R0 se eleva al operando y el resultado se almacena en R0
   * 
   * @param data 
   * @param input_tape 
   * @param output_tape 
   * @param instructions 
   */
  void Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) override;
};

#endif