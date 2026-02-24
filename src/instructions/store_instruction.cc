// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo store_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase StoreInstruction.

#include "store_instruction.h"
#include "../operands/operand.h"
#include "../data_memory/data_memory.h"
#include "../input_tape/input_tape.h"
#include "../output_tape/output_tape.h"
#include "../program_memory/program_memory.h"
#include "../operands/direct_addressing_operand.h"
#include <stdexcept>
#include <string>

void StoreInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  auto* operand = GetOperand();
  int register_index = operand->GetOperandIndex(data);
  if (register_index <= 0) {
    throw std::logic_error("STORE cannot access into R0 or constant, line " + std::to_string(GetLine()));
  }

  float input_value = data.GetRegisterScalar(0);
  // Case Ri o Ri[x]
  if (operand->OperandIsDirect()) {
    auto* direct = dynamic_cast<DirectAddressingOperand*>(operand);
    if (!(direct->HasIndexOperand())) {
      // STORE Ri
      data.SetRegisterScalar(register_index, input_value);
    } else {
      // STORE Ri[x]  -> x can be =i, i o *i
      int offset = static_cast<int>(direct->GetIndexOperand()->GetOperandValue(data, instructions));
      data.SetRegisterValue(register_index, offset, input_value);
    }
  } else {
    // STORE *i
    data.SetRegisterScalar(register_index, input_value);
  }
}
