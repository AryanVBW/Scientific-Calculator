# Scientific Calculator

A command-line scientific calculator implemented in C with support for both Windows and macOS.

## Features

- Basic arithmetic operations (Addition, Subtraction, Multiplication, Division)
- Scientific functions:
  - Square root
  - Power function
  - Trigonometric functions (sin, cos, tan)
  - Natural logarithm
  - Factorial
- Error handling for invalid inputs
- Clear and intuitive menu interface

## Requirements

### For Windows
- MinGW GCC Compiler or Visual Studio
- Command Prompt or PowerShell

### For macOS
- Xcode Command Line Tools (includes GCC)
- Terminal

## Installation

### Windows

1. Install MinGW:
   - Download MinGW installer from [MinGW website](https://mingw-w64.org/doku.php)
   - Run the installer and select gcc compiler
   - Add MinGW to system PATH

2. Verify installation:
   ```cmd
   gcc --version
   ```

### macOS

1. Install Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```

2. Verify installation:
   ```bash
   gcc --version
   ```

## Compilation Instructions

### Windows

1. Open Command Prompt
2. Navigate to the calculator directory:
   ```cmd
   cd path\to\calculator
   ```
3. Compile the program:
   ```cmd
   gcc scientific_calc.c -o calculator.exe -lm
   ```

### macOS

1. Open Terminal
2. Navigate to the calculator directory:
   ```bash
   cd path/to/calculator
   ```
3. Compile the program:
   ```bash
   gcc scientific_calc.c -o calculator -lm
   ```

## Running the Calculator

### Windows
```cmd
calculator.exe
```

### macOS
```bash
./calculator
```

## Usage Instructions

1. When you run the calculator, you'll see a menu with numbered options (1-12)
2. Enter the number corresponding to your desired operation
3. Follow the prompts to enter numbers
4. View the result
5. Press any key to continue to the next calculation
6. Select option 12 to exit the program

## Available Operations

1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Square root
6. Power
7. Sine
8. Cosine
9. Tangent
10. Natural logarithm
11. Factorial
12. Exit

## Input Guidelines

- For basic arithmetic: Enter two numbers when prompted
- For trigonometric functions: Enter angle in degrees
- For square root: Enter a non-negative number
- For logarithm: Enter a positive number
- For factorial: Enter a non-negative integer
- For power: Enter base and exponent when prompted

## Error Handling

The calculator handles various error cases:
- Division by zero
- Negative numbers for square root
- Invalid inputs for logarithm
- Invalid inputs for factorial
- General invalid inputs

## Troubleshooting

### Windows
If you get 'gcc not recognized':
1. Verify MinGW is installed
2. Check if gcc is in system PATH
3. Try reopening Command Prompt

### macOS
If you get 'command not found':
1. Verify Xcode Command Line Tools installation
2. Try running:
   ```bash
   xcode-select --install
   ```


