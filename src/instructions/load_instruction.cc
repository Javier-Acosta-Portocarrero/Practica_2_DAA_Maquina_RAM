// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo load_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase LoadInstruction.

#include "load_instruction.h"
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"
#include <stdexcept>
#include <string>

void LoadInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  unsigned resgister_index = GetOperand() -> GetOperandIndex(data);
  if (resgister_index == 0) {
    std::string error_message{std::string("LOAD instruction can not load from accumulator (R0), line ") + std::to_string(GetLine())};
    throw std::logic_error(error_message);
  }
  float value_to_charge = GetOperand() -> GetOperandValue(data, instructions); 
  // Register 0 --> accumulator
  data.SetRegisterScalar(0, value_to_charge);
}
