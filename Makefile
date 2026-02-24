CXX = g++
CXXFLAGS =  -std=c++23 
TARGET = practica2_DAA

SOURCES = src/main.cc src/RAM/RAM.cc src/program_memory/load_program_RAM_file.cc src/output_tape/output_tape.cc  src/output_tape/store_output_tape_file.cc src/input_tape/input_tape.cc src/input_tape/load_input_tape_file.cc src/operands/direct_addressing_operand.cc src/operands/indirect_addressing_operand.cc src/operands/label_operand.cc src/data_memory/data_memory.cc src/instructions/add_instruction.cc src/instructions/sub_instruction.cc src/instructions/mul_instruction.cc src/instructions/div_instruction.cc src/instructions/jump_instruction.cc src/instructions/jzero_instruction.cc src/instructions/jgtz_instruction.cc src/instructions/read_instruction.cc src/instructions/write_instruction.cc src/instructions/halt_instruction.cc src/instructions/load_instruction.cc src/instructions/store_instruction.cc src/Arithmetic_Control_Logic_Unit/arithmetic_control_logic_unit.cc src/instructions/instruction.cc src/instructions/exp_instruction.cc
OBJECTS = $(SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

cleano:
	rm -f $(OBJECTS)

.PHONY: all clean cleano