# Modular Integer Library

A powerful C++ library for modular arithmetic, providing a ModInteger class with support for basic operations such as addition, subtraction, multiplication, division, exponentiation, square roots, arbitrary roots, and discrete logarithms.<br>Additionally, the library includes a ModuloHelper that enables compile-time calculation of the Euler totient function, primitive roots, and prime decomposition of a number.

# Table of Contents

- [Installation](#installation)
- [Features](#features)
  - [ModInteger Class](#modular-integer-features)
  - [ModuloHelper Library](#modulo-helper-features)
- [Examples](#examples)
- [License](#license)

# Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/your-repo-name.git
```

# Features
## Modular integer features
- Addition ('+')
- Subtraction ('-')
- Multiplication ('*')
- Division ('/')
- Inverse function ('number.inverse()')
- Exponentiation ('^' or 'pow(number, power)')
- Discrete log ```log(a, b)``` - returns ```std::optional <int>```
- Square root function ```sqrt(a)``` - returns ```std::optional < ModInteger >```
- Arbitrary root function ```kroot(number, power)``` - returns ```std::optional < ModInteger >```
- Has an inner ```__mod_value``` value set to ```Mod```
- Basic comparasion operators ('<', '==', '>', '<=', '>=', '!=')
- The last number for which the ```inverse()``` was called in stored as cache
- Ability to precalculate inverses of numbers in range $[1, n]$ in $O(n)$ time ('```initialiseInverse\<MOD>(n)```')
## Modulo helper features
- All function have syntax ModuloHelper::FUNCTION<X>::value and work in compile-time
- IsPrime \<X> - checks if $X$ is a prime number
- Phi \<X> - calculates Euler totient function of $X$
- PrimeDivisorsCount \<X> - calculates the number of unique prime divisors of $X$
- PrimeDivisors \<X> - returns an std::array of prime divisors of $X$
- BinPow \<MOD, A, B> - calculates $A^{B}\ mod\ MOD$
- PrimitiveRoot \<MOD> - calculates primitive root ($-1$ if no was found) under modulo MOD

# Examples
- An example of usage can be found [here](/src/testing.cpp)

# License
- The project is available under the MIT License. [See the details](/LICENSE.MD)
