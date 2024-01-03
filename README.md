# ft_printf 
## Overview

The ft_printf project at 42 challenges participants to implement a simplified version of the printf function in C. Explore variadic functions, string parsing, and formatting while supporting various conversion specifiers, flags, and modifiers.

## Key Features

- **Conversion Specifiers:** Implement handling for conversion specifiers like `%c`, `%s`, `%d`, `%u`, `%x`, `%p`, and more.

- **Flags and Modifiers:** Support flags such as `0`, `-`, and `+`, along with precision and width modifiers for precise formatting.

- **Variadic Function:** Master the use of variadic functions to handle a variable number of arguments.

- **Error Management:** Implement robust error handling to manage unexpected inputs and situations.

## Usage

1. **Clone the Repository:**
   ```bash
   git clone git@github.com:manugonz42/ft_printf.git
   ```
2. **Compile**
   ```bash
   cd ft_printf
   make
   ```
4. **Use it**
   ###### Create a main file like this:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
    ft_printf("Hello, %s! Your number is %d.\n", "John", 42);
    return 0;
   }
