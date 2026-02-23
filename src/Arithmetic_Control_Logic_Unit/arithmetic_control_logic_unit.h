// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo arithmetic_control_logic_unit.h: fichero de declaracion.
// Contiene la declaracion de arithmetic_control_logic_unit.

#ifndef ARITHMETIC_CONTROL_LOGIC_UNIT_H_
#define ARITHMETIC_CONTROL_LOGIC_UNIT_H_

#include "../program_memory/program_memory.h"
#include "../instructions/instruction.h"

class ArithmeticControlLogicUnit {
  public:
  ArithmeticControlLogicUnit() = default;
  ~ArithmeticControlLogicUnit() = default;

  unsigned GetNumberInstructions() const {return numero_instrucciones_ejecutadas_;}
  void ExecuteInstructions(ProgramMemory& program, DataMemory& data_memory, InputTape& input_tape, OutputTape& output_tape);
  private:
  unsigned numero_instrucciones_ejecutadas_ {0};
};

#endif