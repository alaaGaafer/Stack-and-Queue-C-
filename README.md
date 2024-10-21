# Stack and Queue Operations in C++

## Overview

This program implements various operations using **Stacks** and **Queues** in C++. The operations include:
- Checking for balanced parentheses in an expression.
- Converting a decimal number to binary.
- Converting an infix expression to postfix and evaluating the result.
- Moving the nth element of a queue to the front.
- Reversing the elements of a queue.

The program utilizes **Stacks** and **Queues** implemented using **Singly Linked Lists (SLL)**. Each feature is menu-driven, allowing users to interactively choose operations to perform.

## Features

1. **Check Balanced Parentheses**
   - Verifies if the parentheses in a given expression are balanced. Supports `()`, `{}`, `[]`, and `<>`.

2. **Convert Decimal to Binary**
   - Converts a given decimal number to its binary representation using a stack.

3. **Infix to Postfix Conversion & Evaluation**
   - Converts an infix mathematical expression (e.g., `3 + 5 * 2`) to postfix notation (Reverse Polish Notation).
   - Evaluates the postfix expression and returns the result.

4. **Move nth Element to Front in a Queue**
   - Moves the nth element of a queue to the front of the queue.

5. **Reverse a Queue**
   - Reverses the elements of a queue.

5. **Menu Options**
   - The program will display a menu with the following options:
     1. Check for balanced brackets.
     2. Convert decimal to binary.
     3. Convert infix to postfix expression and evaluate.
     4. Move Nth element to front in a queue of strings.
     5. Reverse elements of a queue of doubles.
     6. Exit.

   Choose an option by entering the corresponding number.

## Example Usage

1. **Balanced Parentheses**:
   - Input: `{[()]}`
   - Output: `Balanced`

2. **Decimal to Binary**:
   - Input: `10`
   - Output: `10 in binary is: 1010`

3. **Infix to Postfix and Evaluation**:
   - Input: `3 + 5 * 2`
   - Output: 
     - Postfix: `3 5 2 * +`
     - Evaluation: `13`

4. **Move nth Element to Front**:
   - Queue: `["apple", "banana", "cherry", "date"]`
   - Move 3rd element ("cherry") to the front.

5. **Reverse Queue**:
   - Queue: `[1.1, 2.2, 3.3]`
   - Reversed queue: `[3.3, 2.2, 1.1]`

## File Structure

- `main.cpp` : Main program with all functionalities.
- `SLL.h` : Header file for singly linked list implementation.
- `StackSLL.h` : Header file for stack implementation using singly linked list.
- `QueueSLL.h` : Header file for queue implementation using singly linked list.

