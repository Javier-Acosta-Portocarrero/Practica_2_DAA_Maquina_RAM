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

#include "div_instruction.h"
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"

void DivInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  float divisor_value = GetOperand() -> GetOperandValue(data, instructions); 
  if (divisor_value == 0) {
    throw std::logic_error("Can't divide by 0, line " + std::to_string(GetLine()));
  }
  // Register 0 --> accumulator
  data.SetRegisterScalar(0, data.GetRegisterScalar(0) / divisor_value);
}
