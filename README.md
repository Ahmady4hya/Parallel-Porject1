
# 🧵 Parallel Odd-Even Transposition Sort using Pthreads & OpenMP

This repository contains two projects that implement and compare parallel versions of the **Odd-Even Transposition Sort** (a.k.a. Brick Sort) algorithm using two different multithreading technologies:

- **Project 1**: POSIX Threads (Pthreads)
- **Project 2**: OpenMP

The goal is to improve sorting performance on multi-core systems, analyze execution time, and measure speedup versus the sequential baseline.

---

## 📌 Project Objectives

- Implement both sequential and parallel versions of the Odd-Even Transposition Sort algorithm.
- Use **Pthreads** (Project 1) and **OpenMP** (Project 2) to explore different parallelization techniques.
- Measure execution time and analyze performance for various array sizes and thread counts.
- Visualize speedup and efficiency using tables and graphs.
- Practice proper repository and documentation management for distributed computing assignments.

---

## 🧠 Algorithm Overview

Odd-Even Transposition Sort works by alternating two phases:

1. **Odd Phase**: compare & swap (1,2), (3,4), (5,6), ...
2. **Even Phase**: compare & swap (0,1), (2,3), (4,5), ...

These comparisons are independent within each phase, making the algorithm **naturally parallelizable**.

---

## 🗂️ Folder Structure

Parallel-Porject1/
├── src/
│   ├── sequential.cpp         # Sequential implementation
│   ├── parallel.cpp           # Pthreads implementation (Project 1)
│   └── parallel_omp.cpp       # OpenMP implementation (Project 2)
├── results/
│   ├── timing_data.csv        # Timing results (Pthreads + OpenMP)
│   └── validation.txt         # Output verification
├── docs/
│   ├── report.pdf             # Full project report
│   └── graphs/
│       ├── time_vs_threads.png
│       └── speedup_vs_threads.png
└── README.md

---

## 🚀 How to Compile and Run

### 🔧 Pthreads

g++ -O2 -pthread -o parallel src/parallel.cpp
./parallel

### 🔧 OpenMP

g++ -O2 -fopenmp -o parallel_omp src/parallel_omp.cpp
./parallel_omp

You'll be prompted to enter:
- Array size
- Number of threads

---

## 🧠 OpenMP Parallelization Strategy

OpenMP simplifies thread management by using `#pragma omp parallel for` to automatically divide work across threads. Each odd or even phase is parallelized like this:

#pragma omp parallel for schedule(static)
for (int i = phaseStart; i < n - 1; i += 2) {
    if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
    }
}

This avoids the need to manually create, manage, and join threads — making OpenMP more concise and efficient for loop-based parallelism.

---

## 💻 Hardware Specifications

| Component         | Value                                 |
|------------------|----------------------------------------|
| **CPU Model**     | Intel Core i5-9300H @ 2.40GHz          |
| **Cores**         | 4 physical cores                       |
| **Threads**       | 8 logical threads                      |
| **OS**            | [Your OS here, e.g. Windows/Linux/WSL] |

---

## 📊 OpenMP Performance Results

| Input Size | Threads | Execution Time (ms) | Speedup vs 1 Thread |
|------------|---------|----------------------|----------------------|
| 1,000      | 1       | 10                   | 1.00×               |
| 1,000      | 2       | 34                   | 0.29× ❌            |
| 1,000      | 3       | 39                   | 0.25× ❌            |
| 1,000      | 4       | 44                   | 0.23× ❌            |
| 5,000      | 1       | 140                  | 1.00×               |
| 5,000      | 2       | 344                  | 0.41× ❌            |
| 5,000      | 3       | 472                  | 0.29× ❌            |
| 5,000      | 4       | 623                  | 0.22× ❌            |
| 10,000     | 1       | 576                  | 1.00×               |
| 10,000     | 2       | 1245                 | 0.46× ❌            |
| 10,000     | 3       | 2257                 | 0.25× ❌            |
| 10,000     | 4       | 2560                 | 0.22× ❌            |
| 20,000     | 1       | 2895                 | 1.00×               |
| 20,000     | 2       | 5038                 | 0.57× ❌            |
| 20,000     | 3       | 7829                 | 0.36× ❌            |
| 20,000     | 4       | 10047                | 0.29× ❌            |

📌 **Note:** For small input sizes, OpenMP parallelization may degrade performance due to thread creation overhead and synchronization.

---

## 🧩 Observations & Challenges

### ⚠️ Challenges Faced
- **False speedup expectations**: Increasing thread count didn’t always improve performance — especially on small datasets.
- **Synchronization overhead**: Thread contention during swap operations limited scalability.
- **Race conditions**: Resolved using OpenMP `critical` and implicit barriers after each phase.

### ✅ Lessons Learned
- Multithreading benefits only appear when the **input size is large enough**.
- OpenMP is easier to implement and manage compared to manual thread handling with Pthreads.
- It's important to **benchmark properly** and not assume "more threads = faster."

---

## 🔧 Tools & Technologies

- **Language**: C++17
- **Parallelism**: Pthreads (Project 1), OpenMP (Project 2)
- **Time Measurement**: `std::chrono`
- **Graphing Tools**: Python (matplotlib) / Excel / Google Sheets

---

## 👨‍🏫 Course Information

- **Course**: Parallel and Distributed Computing  
- **Department**: Computer Systems Engineering  
- **University**: Arab American University  
- **Instructor**: Mr. Hussein Younis

