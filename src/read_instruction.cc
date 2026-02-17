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
#include <stdexcept>
#include <sstream>

void ReadInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) {
  unsigned resgister_index = GetOperand() -> GetOperandIndex(data);
  if (resgister_index == 0) {
    std::string error_message{std::string("READ instruction can not read into accumulator (R0), line ") +
                                          std::to_string(GetLine())};
    throw std::logic_error(error_message);
  } else if (resgister_index == -1) {
    std::string error_message{std::string("READ instruction can not read into a constant operand, line ") +
                                          std::to_string(GetLine())};
    throw std::logic_error(error_message);
  }
  float input_value = input_tape.GetNextInput();
  data.SetRegisterValue(resgister_index, input_value);
}