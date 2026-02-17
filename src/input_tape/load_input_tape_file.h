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

#ifndef LOAD_INPUT_TAPE_FILE_H_
#define LOAD_INPUT_TAPE_FILE_H_

#include "load_input_tape.h"
#include <string>

class LoadInputTapeFile : LoadInputTape {
 public:
  LoadInputTapeFile(const std::string& file_path) : file_path_{file_path} {}
  LoadInputTapeFile() = default;
  ~LoadInputTapeFile() = default;

  bool LoadTape() override;

  void SetFilePath(const std::string& file_path) { file_path_ = file_path;};
 private:
  InputTape tape_;
  std::string file_path_{""};
};

#endif