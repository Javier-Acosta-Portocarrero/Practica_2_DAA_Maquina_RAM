// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo RAM.cc: fichero de implementación.
// Contiene la implementación de la RAM.

#include "RAM.h"

void RAM::Execute() {
  ACLU.ExecuteInstructions(program_memory_, data_memory_, input_tape_, output_tape_);
}

