// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo main.cc: fichero de implementación.
// Contiene la implementación de la main.

#include "./RAM/RAM.h"
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc < 3 || argc > 4) {
    std::cerr << "Uso:\n  " << argv[0] << " <program.ram> <input.txt> [output.txt]\n";
    return 1;
  }
  // Load program and input tape from files
  std::string program_path = argv[1];
  std::string input_path   = argv[2];
  std::string output_path;
  // If an output path is provided, we will save the output tape to that file after execution.
  if (argc == 4) {
    output_path = argv[3];
  }
  RAM* machine = nullptr; 
  try {  
    LoadInputTapeFile input_tape_loader(input_path);
    input_tape_loader.LoadTape();
    LoadProgramRAMFile program_loader(program_path);
    auto program_loaded_ = program_loader.Load();
    InputTape input = input_tape_loader.GetInputTape();

    machine = new RAM(program_loaded_, input);

    machine->Execute();
    std::cout << "Ejecución completada correctamente.\n";
    unsigned num_instructions = machine->GetNumberInstructionsExecuted();
    std::cout << "Número de instrucciones ejecutadas: " << num_instructions << "\n";
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
  }
  // If an output path is provided, save the output tape to the file even if there was an error.
  if (!output_path.empty() && machine != nullptr) {
    StoreOutputTapeFile output_saver(machine->GetOutputTape(), output_path);
    if (output_saver.StoreTape()) {
      std::cout << "Salida guardada en " << output_path << "\n";
    } else {
      std::cerr << "Error al guardar la salida en " << output_path << "\n";
    }
  }

  delete machine;
  return 0;
}