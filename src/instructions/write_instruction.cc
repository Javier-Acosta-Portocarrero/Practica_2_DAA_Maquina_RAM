// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo write_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase WriteInstruction.

#include "write_instruction.h"
#include <stdexcept>
#include <sstream>

void WriteInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape, const ProgramMemory& instructions) {
  unsigned resgister_index = GetOperand() -> GetOperandIndex(data);
  if (resgister_index == 0) {
    std::string error_message{std::string("WRITE instruction can not write from accumulator (R0), line ") +
                                          std::to_string(GetLine())};
    throw std::logic_error(error_message);
  } 
  float output_value = GetOperand() -> GetOperandValue(data, instructions);
  output_tape.AddOutput(output_value);
}