// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo jgtz_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase JgtzInstruction.

#include "jgtz_instruction.h"

void JgtzInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) {
  // Register 0 --> accumulator
  float accumulator_value = data.GetRegisterValue(0);
  if (accumulator_value > 0.0) {
    // We allow registers to store addresses to jump.
    int address = static_cast<int>(GetOperand() -> GetOperandValue(data)); 
    data.SetProgramCounter(address);
  }
}
