# Competitive Programming Solutions

[![GitHub stars](https://img.shields.io/github/stars/Vaibhav-kesarwani/Competitive-Programming?style=social)](https://github.com/Vaibhav-kesarwani/Competitive-Programming/stargazers)
[![GitHub last commit](https://img.shields.io/github/last-commit/Vaibhav-kesarwani/Competitive-Programming)](https://github.com/Vaibhav-kesarwani/Competitive-Programming/commits/main)
[![GitHub language count](https://img.shields.io/github/languages/count/Vaibhav-kesarwani/Competitive-Programming)](https://github.com/Vaibhav-kesarwani/Competitive-Programming)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A comprehensive collection of algorithmic problem solutions and contest implementations solved across various competitive programming platforms. Written primarily in C++.

---

## About

This repository contains solutions to competitive programming problems from multiple online judges and contest platforms. Solutions are organized by platform and problem ID for easy reference and learning.

**Key Features:**
- Solutions to problems from Codeforces, LeetCode, AtCoder, and CodeChef
- Clean, well-structured C++ code
- Organized by platform and problem identifier
- Includes test cases and local testing setup via CPH (Competitive Programming Helper)

---

## Table of Contents

- [About](#about)
- [Repository Structure](#repository-structure)
- [Platforms](#platforms)
- [Tech Stack](#tech-stack)
- [Getting Started](#getting-started)
- [Building and Running](#building-and-running)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

---

## Repository Structure

```
Competitive-Programming/
|
|-- Leetcode/                 LeetCode problem solutions organized by problem ID & slug
|   |-- 1-two-sum/
|   |-- DCP-08-26/            Daily coding problem sets & specialized collections
|   |-- ...
|
|-- *.cpp                     Codeforces, AtCoder, and custom contest/practice source files
|-- *.bin                     Compiled binaries for local testing & execution
|-- .cph/                     Competitive Programming Helper (CPH) configurations & test cases
|-- .gitignore                Git ignore rules
|-- LICENSE                   MIT License
|-- README.md                 This file
```

---

## Platforms

| Platform | Description | Link |
|----------|-------------|------|
| **Codeforces** | Division rounds, educational rounds, and practice problems (Div. 2, Div. 3, Div. 4) | [codeforces.com](https://codeforces.com/) |
| **LeetCode** | Daily challenges, weekly/bi-weekly contests, and topic-wise problem solutions | [leetcode.com](https://leetcode.com/) |
| **AtCoder** | Beginner Contests (ABC) and regular contests | [atcoder.jp](https://atcoder.jp/) |
| **CodeChef** | Starters and monthly challenges | [codechef.com](https://www.codechef.com/) |

---

## Tech Stack

| Category | Details |
|----------|---------|
| **Language** | C++ (C++17 / C++20) |
| **Editor/IDE** | Visual Studio Code |
| **Tooling** | CPH (Competitive Programming Helper) extension for rapid local test case verification |
| **Compiler** | g++ with C++20 support |

---

## Getting Started

### Prerequisites

- **g++** with C++17 or C++20 support
- **Visual Studio Code** (recommended)
- **CPH Extension** for VS Code (optional, for test case management)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Vaibhav-kesarwani/Competitive-Programming.git
   cd Competitive-Programming
   ```

2. Verify your g++ installation:
   ```bash
   g++ --version
   ```

---

## Building and Running

### Compile and Run a Single Problem

```bash
# Compile with optimizations (C++20)
g++ -std=c++20 -O3 ProblemName.cpp -o ProblemName.bin

# Run the compiled binary
./ProblemName.bin
```

### Debug Build

```bash
# Compile with debug symbols and no optimizations
g++ -std=c++20 -g -O0 ProblemName.cpp -o ProblemName_debug.bin

# Run with gdb (if needed)
./ProblemName_debug.bin
```

### Quick One-Liner

```bash
# Compile and run in one command
g++ -std=c++20 -O3 ProblemName.cpp -o ProblemName.bin && ./ProblemName.bin
```

---

## Contributing

Contributions are welcome! Here's how you can contribute:

1. **Fork** the repository
2. **Create** a feature branch:
   ```bash
   git checkout -b feature/amazing-solution
   ```
3. **Commit** your changes:
   ```bash
   git commit -m "Add solution for ProblemName"
   ```
4. **Push** to the branch:
   ```bash
   git push origin feature/amazing-solution
   ```
5. **Open** a Pull Request

### Contribution Guidelines

- Follow the existing file naming conventions
- Include problem links in file comments where applicable
- Ensure your code compiles without warnings
- Test your solutions before submitting

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Author

**Vaibhav Kesarwani**

- GitHub: [@Vaibhav-kesarwani](https://github.com/Vaibhav-kesarwani)

---

If you find these solutions helpful for your competitive programming journey, consider giving this repository a star!
