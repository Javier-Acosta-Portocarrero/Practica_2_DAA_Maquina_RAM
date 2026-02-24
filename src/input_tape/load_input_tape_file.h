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

class LoadInputTapeFile : public LoadInputTape {
 public:
 /**
  * @brief Construye el objeto que representa el archivo de la cinta de entrada
  * 
  * @param file_path 
  */
  LoadInputTapeFile(const std::string& file_path) : file_path_{file_path} {}
  LoadInputTapeFile() = default;
  ~LoadInputTapeFile() = default;
  /**
   * @brief Construye nuestra cola de cinta de entrada con los datos extraidos del archivo
   * 
   * @return true 
   * @return false 
   */
  bool LoadTape() override;
  /**
   * @brief  Establece el objeto que representa el archivo de la cinta de entrada con otro camino
   * 
   * @param file_path 
   */
  inline void SetFilePath(const std::string& file_path) { file_path_ = file_path;};
 private:
  std::string file_path_{""};
};

#endif