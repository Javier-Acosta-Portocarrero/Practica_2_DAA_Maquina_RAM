// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo arithmetic_control_logic_unit.cc: fichero de implementación.
// Contiene la implementación de arithmetic_control_logic_unit.

#include "arithmetic_control_logic_unit.h"

void ArithmeticControlLogicUnit::ExecuteInstructions(ProgramMemory& program, DataMemory& data_memory, InputTape& input_tape, OutputTape& output_tape) {
  numero_instrucciones_ejecutadas_ = 0;
  data_memory.SetProgramCounter(0);

  while (data_memory.GetProgramCounter() < program.GetProgramSize() && data_memory.GetProgramCounter() != -1) {
    unsigned pc = data_memory.GetProgramCounter();
    Instruction& instruction = program.GetInstruction(pc);
    // Guardamos el PC antes de ejecutar
    unsigned old_pc = pc;
    instruction.Execute(data_memory, input_tape, output_tape, program);
    ++numero_instrucciones_ejecutadas_;
    // Si la instrucción no cambió el PC → ejecución secuencial
    if (data_memory.GetProgramCounter() == old_pc) {
      data_memory.SetProgramCounter(old_pc + 1);
    }
  }
}