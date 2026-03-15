# Parentheses-Matching-Syntax-Checker

## Description

This project checks whether an expression has balanced parentheses using a stack data structure.

## Supported Brackets

* ()
* {}
* []

## Algorithm

1. Traverse expression
2. Push opening brackets to stack
3. Pop when closing bracket appears
4. Check if pairs match
5. If stack empty → Balanced

## Example

Input:
{(a+b)*[c-d]}

Output:
Balanced

## Technologies Used

* C Programming
* Stack Data Structure

## Compile

gcc syntax_checker.c -o checker

## Run

./checker
