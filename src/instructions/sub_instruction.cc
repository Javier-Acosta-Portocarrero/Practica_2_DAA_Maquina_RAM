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
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"

void SubInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  float value_to_substract = GetOperand() -> GetOperandValue(data, instructions); 
  // Register 0 --> accumulator
  data.SetRegisterScalar(0, data.GetRegisterScalar(0) - value_to_substract);
}
