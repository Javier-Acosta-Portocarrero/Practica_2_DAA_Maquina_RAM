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
    bool save_output = false;

    if (argc == 4) {
      output_path = argv[3];
    }

    RAM machine(input_path, program_path, output_path);

    std::cout << "Ejecución completada correctamente.\n";
    machine.Execute();

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}