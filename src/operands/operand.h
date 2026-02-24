// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Diseño y Analisis de Algoritmos
// Curso: 3º
// Practica 2: Máquina RAM
// Autor: Javier Acosta Portocarrero
// Autor: Gabriel Gallardo Noda
// Fecha: 17/02/2024
// Archivo operand.h: fichero de declaracion.
// Contiene la declaracion de la clase Operand.

#ifndef OPERAND_H_
#define OPERAND_H_

#include "../data_memory/data_memory.h"
#include "../program_memory/program_memory.h"

class ProgramMemory;

class Operand {
 public:
  virtual ~Operand() = default;

  /**
   * @brief Obtiene el valor que almacena el tipo de operando
   * 
   * @param data 
   * @param instructions 
   * @return float 
   */
  virtual float GetOperandValue(const DataMemory& data, const ProgramMemory& instructions) const = 0;
  // int because -1 means constant operand, etc.
  /**
   * @brief Obtiene el índice del tipo de operando (si es que tiene)
   * 
   * @param data 
   * @return int 
   */
  virtual int GetOperandIndex(const DataMemory& data) const = 0;
  // Needed for vector registers, to know if we need to write into a specific position.
  virtual bool OperandIsDirect() const = 0;
};

#endif