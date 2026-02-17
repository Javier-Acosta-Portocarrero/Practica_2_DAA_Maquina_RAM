// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo output_tape.cc: fichero de definicion.
// Contiene la definicion de la clase OutputTape.

#include "output_tape.h"

float OutputTape::GetNextOutput() {
  const float output = tape_.top();
  tape_.pop();
  return output;
}


void OutputTape::AddOutput(const float& output) {
  tape_.push(output);
}