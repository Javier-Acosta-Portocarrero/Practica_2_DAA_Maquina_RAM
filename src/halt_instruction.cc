// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo halt_instruction.cc: fichero de definicion.
// Contiene la definicion de la clase HaltInstruction.

#include "halt_instruction.h"

void HaltInstruction::Execute(DataMemory& data, InputTape& input_tape, OutputTape& output_tape) {
  // PC = -1 --> STOP
  data.SetProgramCounter(-1);
}
