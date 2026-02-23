// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo read_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase ReadInstruction.

#include "read_instruction.h"
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"
#include "../operands/direct_addressing_operand.h"
#include <stdexcept>
#include <sstream>

void ReadInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  auto* operand = GetOperand();
  int register_index = operand->GetOperandIndex(data);
  if (register_index <= 0) {
    throw std::logic_error("READ cannot write into R0 or constant, line " + std::to_string(GetLine()));
  }

  float input_value = input_tape.GetNextInput();
  if (operand->OperandIsDirect()) {
    auto* direct = dynamic_cast<DirectAddressingOperand*>(operand);
    if (!direct->GetIndexVectorRegister()) {
      data.SetRegisterScalar(register_index, input_value);
    } 
    else {
      data.SetRegisterValue(register_index, direct->GetIndexVectorRegister(), input_value);
    }
  }
  else {
    data.SetRegisterScalar(register_index, input_value);
  }
}