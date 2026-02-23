// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo store_output_tape_file.cc: fichero de definicion.
// Contiene la definicion de la clase StoreOutputTapeFile.

#include "store_output_tape_file.h"
#include <fstream>

bool StoreOutputTapeFile::StoreTape() const {
  std::ofstream file_output_stream{file_path_};
  if (!file_output_stream.is_open()) {
    return false;
  }
  OutputTape aux_tape = GetOutputTape();
  while (!aux_tape.EmptyTape()) {
    float output = aux_tape.GetNextOutput();
    file_output_stream << output << std::endl;
  }
  file_output_stream.close();
  return true;
}