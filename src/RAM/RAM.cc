// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo RAM.cc: fichero de implementación.
// Contiene la implementación de la RAM.

#include "RAM.h"

void RAM::Execute() {
    LoadInputTapeFile input_tape (input_path_);
    if (input_tape.LoadTape()) {
        LoadProgramRAMFile program (program_path_);
        auto program_loaded_ = program.Load();
        DataMemory data_memory;
        OutputTape output_tape;
        InputTape input;
        ArithmeticControlLogicUnit ACLU;
        ACLU.ExecuteInstructions(const_cast<ProgramMemory&>(*program_loaded_), data_memory, input, output_tape);
        StoreOutputTapeFile output_saver(output_tape, output_path_);
        output_saver.StoreTape();
    }
    else { 
        throw std::runtime_error("Cinta de entrada no cargada");
    }
}

