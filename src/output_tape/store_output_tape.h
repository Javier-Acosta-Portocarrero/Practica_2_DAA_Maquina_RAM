// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo store_output_tape.h: fichero de declaracion.
// Contiene la declaracion de la clase StoreOutputTape.

#ifndef STORE_OUTPUT_TAPE_H_
#define STORE_OUTPUT_TAPE_H_

#include "output_tape.h"

class StoreOutputTape {
 public:
  StoreOutputTape(const OutputTape& tape) : tape_{tape} {}
  virtual ~StoreOutputTape() = default;

  virtual bool StoreTape() const = 0;

  inline void SetOutputTape(const OutputTape& tape) { tape_ = tape;}
  inline OutputTape GetOutputTape() const { return tape_;}
 private:
  OutputTape tape_;
};

#endif