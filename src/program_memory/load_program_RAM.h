// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 20/02/2026
// Archivo load_program_RAM.h: fichero de declaracion.
// Contiene la declaracion de la load_program_RAM.

#ifndef LOAD_PROGRAM_RAM_H_
#define LOAD_PROGRAM_RAM_H_

#include "program_memory.h"

class LoadProgramRAM {
  public:
  ~LoadProgramRAM() = default;
  virtual ProgramMemory Load() = 0;
};

#endif