# 🧵 Parallel Odd-Even Transposition Sort using Pthreads

This project presents a parallel implementation of the **Odd-Even Transposition Sort** (also known as Brick Sort) algorithm using **POSIX Threads (Pthreads)** in C++. The primary objective is to compare the performance of the parallel version against its sequential counterpart and analyze the benefits and challenges of multithreading in sorting algorithms.

---

## 📌 Project Objectives

- Implement both sequential and parallel versions of the Odd-Even Transposition Sort algorithm.
- Utilize **Pthreads** to achieve thread-level parallelism.
- Measure and compare execution times to evaluate performance gains.
- Analyze scalability and efficiency across varying array sizes and thread counts.
- Provide comprehensive documentation for educational and benchmarking purposes.

---

## 🧠 Algorithm Overview

**Odd-Even Transposition Sort** is a comparison-based sorting algorithm that operates in two phases:

1. **Odd Phase**: Compare and swap elements at indices (1,2), (3,4), (5,6), ...
2. **Even Phase**: Compare and swap elements at indices (0,1), (2,3), (4,5), ...

These phases are repeated until the array is sorted. The algorithm is inherently parallelizable since comparisons and swaps in each phase are independent and can be executed concurrently.

---

## 🗂️ Folder Structure

Parallel-Porject1/
├── src/
│ ├── sequential.cpp # Sequential implementation
│ └── parallel.cpp # Parallel implementation using Pthreads
├── results/
│ ├── timing_data.csv # Execution time results
│ └── validation.txt # Output validation checksums
├── docs/
│ ├── report.pdf # Detailed project report
│ └── graphs/
│ ├── time_vs_threads.png
│ └── speedup_vs_threads.png
└── README.md

---

## 🚀 How to Compile and Run

### 🧮 Compilation

Ensure you have a C++ compiler installed. Use the following commands to compile the programs:

g++ -O2 -o sequential src/sequential.cpp
g++ -O2 -pthread -o parallel src/parallel.cpp

---

🔧 Tools & Technologies
Programming Language: C++17

Parallelism: POSIX Threads (Pthreads)

Timing: chrono library

Data Visualization: Python (matplotlib)

---

👨‍🏫 Course Information
Course: Parallel and Distributed Computing

Department: Computer Systems Engineering

University: Arab American University

Instructor: Mr. Hussein Younis

