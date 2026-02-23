// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo load_input_tape.h: fichero de declaracion.
// Contiene la declaracion de la clase LoadInputTape.

#ifndef LOAD_INPUT_FILE_H_
#define LOAD_INPUT_FILE_H_

#include "input_tape.h"

class LoadInputTape {
 public:
  virtual ~LoadInputTape() = default;

  virtual bool LoadTape() = 0;
  
  InputTape GetInputTape() { return tape_;};
  void SetInputTape(const InputTape& tape) { tape_ = tape;};
 private:
  InputTape tape_;
};

#endif