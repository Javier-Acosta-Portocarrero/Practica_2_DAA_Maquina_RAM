// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo mul_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase MulInstruction.

#include "mul_instruction.h"

void MulInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) {
  float multiplier_value = GetOperand() -> GetOperandValue(data); 
  // Register 0 --> accumulator
  data.SetRegisterValue(0, data.GetRegisterValue(0) * multiplier_value);
}
