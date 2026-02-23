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
  try {
    if (argc < 3 || argc > 4) {
      std::cerr << "Uso:\n  " << argv[0] << " <program.ram> <input.txt> [output.txt]\n";
      return 1;
    }

    std::string program_path = argv[1];
    std::string input_path   = argv[2];
    std::string output_path;

    if (argc == 4) {
      output_path = argv[3];
    }
    LoadInputTapeFile input_tape_loader(input_path);
    input_tape_loader.LoadTape();
    LoadProgramRAMFile program_loader(program_path);
    auto program_loaded_ = program_loader.Load();
    InputTape input = input_tape_loader.GetInputTape();

    RAM machine(program_loaded_, input);

    machine.Execute();
    std::cout << "Ejecución completada correctamente.\n";
    // If an output path is provided, save the output tape to the file.
    if (argc == 4) {
      StoreOutputTapeFile output_saver(machine.GetOutputTape(), output_path);
      if (output_saver.StoreTape()) {
        std::cout << "Salida guardada en " << output_path << "\n";
      } else {
        std::cerr << "Error al guardar la salida en " << output_path << "\n";
        return 1;
      }
    }

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}