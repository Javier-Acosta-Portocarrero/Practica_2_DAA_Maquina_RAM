// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo sub_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase SubInstruction.

#include "sub_instruction.h"

void SubInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) {
  float value_to_substract = GetOperand() -> GetOperandValue(data); 
  // Register 0 --> accumulator
  data.SetRegisterValue(0, data.GetRegisterValue(0) - value_to_substract);
}
