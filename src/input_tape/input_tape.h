// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo input_tape.h: fichero de declaracion.
// Contiene la declaracion de la clase InputTape.

#ifndef INPUT_TAPE_H_
#define INPUT_TAPE_H_

#include <queue>

class InputTape {
 public:
 /**
  * @brief Construye una cinta de entrada a partir de una cola
  * 
  * @param tape 
  */
  InputTape(const std::queue<float>& tape) : tape_(tape) {}
  InputTape() = default;
  ~InputTape() = default;
  /**
   * @brief Avanza una posición el "cabezal" de lectura de la cinta de entrada (cola)
   * 
   * @return float 
   */
  float GetNextInput();
 private:
  std::queue<float> tape_;
};

#endif