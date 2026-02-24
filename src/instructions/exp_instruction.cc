// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo div_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase DivInstruction.

#include "exp_instruction.h"
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"
#include <iostream>

void ExpInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  float exponent_value = GetOperand() -> GetOperandValue(data, instructions); 
  if (exponent_value < 0) {
    throw std::logic_error("Can't elavete to a negative number, line " + std::to_string(GetLine()));
  }
  float accumulator_value = data.GetRegisterScalar(0);
  // Register 0 --> accumulator
  float result{1};
  for (int i{1}; i <= exponent_value; ++i) {
    result *= accumulator_value;
  }
  data.SetRegisterScalar(0, result);
}
