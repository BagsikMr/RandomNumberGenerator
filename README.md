## Table of contents
* [General info](#general-info)
* [Structure](#structure)
* [Functions](#functions)
* [Usage](#usage)

# General Info

This program is an implementation of a pseudo-random number generator based on a linear algorithm and shift registers.

## Structure

The `Global` struct contains the following fields:

- `Xc` - current value of `X`
- `X` - initial value of `X`
- `a` - parameter `a` for the linear algorithm
- `c` - parameter `c` for the linear algorithm
- `M` - maximum value for `X`
- `number_of_drawn_items` - number of items to be generated
- `line_gen_table` - array for storing frequencies from the line generator
- `binary_number` - array for storing binary numbers
- `shift_reg_gen_table` - array for storing frequencies from the shift register generator
- `p` - parameter `p` for the shift register generator
- `q` - parameter `q` for the shift register generator

## Functions

The program includes the following functions:

- `lineGenerator(Global* myGlobal)` - implements the line generator algorithm
- `print_binary(Global* myGlobal)` - prints the binary number
- `roll(bool* binary_number, bool element)` - performs a shift operation on the binary number array
- `shiftRegisterGenerator(Global* myGlobal)` - implements the shift register generator algorithm

## Usage

The program generates pseudo-random numbers using both the line generator and the shift register generator. The frequencies of the generated numbers are stored in the respective arrays `line_gen_table` and `shift_reg_gen_table`.

To run the program, compile and execute the code using a C++ compiler.


