// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo input_tape.cc: fichero de definicion.
// Contiene la definicion de la clase InputTape.

#include "input_tape.h"
#include <stdexcept>

float InputTape::GetNextInput() {
  if (tape_.empty()) {
    return 0.0;
  }
  const float input = tape_.front();
  tape_.pop();
  return input;
}