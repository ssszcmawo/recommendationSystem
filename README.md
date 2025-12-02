# Recommendation System

This repository contains a simple recommendation system implemented in C++. The project was created as a small practice task to reinforce algorithmic thinking after studying the book "Grokking Algorithms."

## Description

The project demonstrates a minimal recommendation engine using plain C++. It calculates similarity between movies based on average ratings and genre, and provides a simple way to recommend the most similar movies.
## Structure

- `src/` Source files
- `include/` Header files
- `main.cpp` Example program demonstrating system usage
- `outDebug/` Output directory for builds or debug artifacts

## Requirements

- C++ compiler supporting C++17 or newer
- Standard C++ library

## Build

Compile with your preferred toolchain. Example using g++:

```bash
g++ -std=c++17 src/*.cpp -o recommendation
