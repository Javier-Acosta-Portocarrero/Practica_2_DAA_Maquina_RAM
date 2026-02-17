// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo output_tape.h: fichero de declaracion.
// Contiene la declaracion de la clase OutputTape.

#ifndef OUTPUT_TAPE_H_
#define OUTPUT_TAPE_H_

#include <stack>

class OutputTape {
 public:
  OutputTape(std::stack<float> tape) : tape_(tape) {}
  OutputTape() = default;
  ~OutputTape() = default;
  
  float GetNextOutput();
  void AddOutput(const float& output);
 private:
  std::stack<float> tape_;
};

#endif