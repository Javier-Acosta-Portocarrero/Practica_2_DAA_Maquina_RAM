// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo data_memory.h: fichero de declaracion.
// Contiene la declaracion de la clase DataMemory.

#ifndef DATA_MEMORY_H_
#define DATA_MEMORY_H_

#include <vector>

class DataMemory {
 public:
  DataMemory();
  
  float GetRegisterValue(unsigned register_index) const;
  void SetRegisterValue(unsigned register_index, float value);
 private:
 std::vector<float> memory_;
};

#endif