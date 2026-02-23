// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo add_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase AddInstruction.

#include "add_instruction.h"
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"

void AddInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  float value_to_add = GetOperand() -> GetOperandValue(data, instructions); 
  // Register 0 --> accumulator
  data.SetRegisterValue(0, data.GetRegisterValue(0) + value_to_add);
}
