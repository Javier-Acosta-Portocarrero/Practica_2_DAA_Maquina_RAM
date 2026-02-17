// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo load_input_tape_file.h: fichero de declaracion.
// Contiene la declaracion de la clase LoadInputTapeFile.

#include "load_input_tape_file.h"
#include <fstream>

bool LoadInputTapeFile::LoadTape() {
  std::queue<float> inputs;
  std::ifstream file_input_stream{file_path_};
  if (!file_input_stream.is_open()) {
    return false;
  }
  float input{0.0};
  while (file_input_stream >> input) {
    inputs.push(input);
  }
  tape_ = InputTape{inputs};
  file_input_stream.close();
  return true;
}