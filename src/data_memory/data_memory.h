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
 /**
  * @brief Construye la memoria de datos (tamaño 32), inicalizando cada vector registro a 1 una posición siendo 0.0
  * 
  */
  DataMemory();
  /**
   * @brief Obtiene el primer elemento de un vector registro determinado
   * 
   * @param register_index 
   * @return float 
   */
  float GetRegisterScalar(unsigned register_index) const;
  /**
   * @brief Obtiene un determinado elemento de un vector registro determinado
   * 
   * @param reg 
   * @param register_index 
   * @return float 
   */
  float GetRegisterValue(unsigned reg, unsigned register_index) const;
  /**
   * @brief Obtiene el pc
   * 
   * @return int 
   */
  inline int GetProgramCounter() const { return program_counter_register_;}
  /**
   * @brief Establece el pc
   * 
   * @param program_counter 
   */
  inline void SetProgramCounter(unsigned program_counter) { program_counter_register_ = program_counter;}
  /**
   * @brief Establece un determinado elemento de un vector registro determinado
   * 
   * @param reg 
   * @param register_index 
   * @param value 
   */
  void SetRegisterValue(unsigned reg, unsigned register_index, float value);
  /**
   * @brief Establece el primer elemento de un vector registro determinado
   * 
   * @param register_index 
   * @param value 
   */
  void SetRegisterScalar(unsigned register_index, float value);
  /**
   * @brief Establece todo un vector registro asignándole otro
   * 
   * @param reg 
   * @param memory_register 
   */
  void SetVector(unsigned reg, const std::vector<float>& memory_register);
  /**
   * @brief Aumenta el pc 
   * 
   */
  inline void IncrementProgramCounter() { ++program_counter_register_;}
 private:
  std::vector<std::vector<float>> memory_;
  // Int because we need to know if HALT instruction is executed (PC = -1 --> STOP)
  int program_counter_register_{0};
};

#endif