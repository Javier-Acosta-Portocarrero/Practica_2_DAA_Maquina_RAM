// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo store_output_tape_file.h: fichero de declaracion.
// Contiene la declaracion de la clase StoreOutputTapeFile.

#ifndef STORE_OUTPUT_TAPE_FILE_H_
#define STORE_OUTPUT_TAPE_FILE_H_

#include "store_output_tape.h"
#include <string>

class StoreOutputTapeFile : StoreOutputTape {
 public:
  StoreOutputTapeFile(const OutputTape& tape, const std::string& file_path = "") : tape_{tape}, file_path_{file_path} {}
  StoreOutputTapeFile() = default;
  ~StoreOutputTapeFile() = default;

  bool StoreTape() const override;
  
  void SetFilePath(const std::string& file_path) { file_path_ = file_path;}
 private:
  OutputTape tape_;
  std::string file_path_{""};
};

#endif