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
#include <stdexcept>
#include <string>

void StoreInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  unsigned resgister_index = GetOperand() -> GetOperandIndex(data);
  if (resgister_index == 0) {
    std::string error_message{std::string("STORE instruction can not write to accumulator (R0), line ") +
                                          std::to_string(GetLine())};
    throw std::logic_error(error_message);
  } else if (resgister_index == -1) {
    std::string error_message{std::string("STORE instruction can not write to a constant operand, line ") +
                                          std::to_string(GetLine())};
    throw std::logic_error(error_message);
  }
  // Register 0 --> accumulator
  float value_to_store = data.GetRegisterValue(0);
  data.SetRegisterValue(resgister_index, value_to_store);
}
