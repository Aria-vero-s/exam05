# BigInt Class – Arbitrary Precision Unsigned Integers

## Goal of the Exercise
The goal of this exercise is to implement a `bigint` class in C++ that can store and manipulate **arbitrary precision unsigned integers**. Unlike built-in integer types, which have a maximum value, this class can represent numbers of virtually unlimited size by storing digits as strings. The exercise focuses on understanding how to:

- Handle numbers larger than standard integer types.
- Implement addition, comparison, and digit-shifting operations.
- Overload operators in C++.
- Work with strings to perform numeric computations.

---

## Big Ideas

1. **Arbitrary Precision**
   - Regular integer types (`int`, `long long`) are limited by the number of bits they use.
   - `bigint` uses a `std::string` to store each digit, allowing for numbers of any size.

2. **Addition**
   - Addition is performed digit by digit from **right to left**, carrying over when needed.
   - Strings are manipulated to simulate how humans perform addition by hand.

3. **Digit Shifts (Base 10)**
   - `<<` multiplies the number by `10^n` (append zeros to the right).
   - `>>` divides the number by `10^n` (remove digits from the right).
   - This is similar to bit shifts, but in decimal.

4. **Comparison**
   - Numbers are compared by **length first**: longer numbers are larger.
   - If lengths are equal, comparison proceeds **digit by digit from left to right**.

5. **Operator Overloading**
   - Arithmetic (`+`, `+=`, `++`)
   - Digit shifts (`<<`, `>>`, `<<=`, `>>=`)
   - Comparison (`<`, `>`, `<=`, `>=`, `==`, `!=`)
   - Output (`<<` for `std::ostream`)

6. **Increment Operators**
   - Prefix (`++x`) and postfix (`x++`) are implemented using the addition operator.

---

## Key Points

- All operations are performed on the string representation of the number.
- Leading zeros are automatically removed to ensure correct representation.
- The class is designed to be **exam-friendly**, focusing on clarity and correctness rather than extreme optimization.
- Works with arbitrarily large numbers without overflow issues.

---

## Example Usage

```cpp
#include "bigint.hpp"
#include <iostream>

int main() {
    bigint a(12345);
    bigint b("987654321");

    bigint c = a + b;
    std::cout << "Sum: " << c << std::endl;

    c <<= 3; // multiply by 1000
    std::cout << "Left shift: " << c << std::endl;

    c >>= 5; // divide by 100000
    std::cout << "Right shift: " << c << std::endl;

    if (a < b) std::cout << "a is smaller than b" << std::endl;

    ++a; // increment
    std::cout << "a incremented: " << a << std::endl;

    return 0;
}
