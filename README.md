
# C Language Interpreter

This project is a C language interpreter, meticulously crafted in C++, designed to take C code as input and transform it into three-address code (TAC). By leveraging the power of Flex and Bison, this interpreter provides a robust tool for parsing and understanding C code, making it an essential utility for developers looking to dive deeper into the mechanics of the C programming language.

## Features

- **C to TAC Conversion**: Transforms standard C code into three-address code, facilitating easier analysis and optimization of C programs.
- **Flex and Bison Integration**: Utilizes Flex for lexical analysis and Bison for parsing, ensuring a seamless translation process from C code to TAC.
- **Error Handling**: Includes comprehensive error handling to guide users in correcting syntax or semantic errors in their C code input.
- **Cross-Platform Compatibility**: Designed to be compatible with various operating systems, ensuring a wide range of usability.

## Getting Started

Below are the instructions to set up the environment and run the interpreter on your local machine for development and testing purposes.

### Prerequisites

Ensure you have the following tools installed on your system:
- A C++ compiler (e.g., GCC, Clang)
- Flex (The Fast Lexical Analyzer)
- Bison (GNU Parser Generator)

### Installing

1. **Clone the repository**

   ```sh
   git clone https://github.com/betebetoven/OLC2PROYECTO2.git
   ```

2. **Navigate to the project directory**

   ```sh
   cd C-Language-Interpreter
   ```

3. **Build the project**

   Using Makefile (if provided):

   ```sh
   make
   ```

   Or manually compile:

   ```sh
   flex -o lexer.cpp lexer.l
   bison -d -o parser.cpp parser.y
   g++ -o CInterpreter parser.cpp lexer.cpp main.cpp
   ```

### Usage

The interpreter has a friendly Interface where the user can enter the code written in C, then the code generates the C output code,
this was an Academic project but I think it can be an Excellent and Hard excercise to understand memory handling when coding on high level Languages.

This will output the three-address code (TAC) of the provided C program.

## Example

Given a simple C program:

```c
int main() {
    int a = 5;
    int b = a + 2;
    return b;
}
```

The interpreter might produce the following TAC:

```
1: a = 5
2: b = a + 2
3: return b
```

## Contributing

Contributions to improve the interpreter are welcome. Please follow these steps to contribute:

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request


## Acknowledgments

- Special thanks to the Flex and Bison documentation and community for providing invaluable resources.
- Gratitude to all contributors who have helped to enhance this project.
