# CS509 – Assignment 4 (Individual)

## Student Information

- **Course:** CS509 – PG Software Lab
- **Mode of Assignment:** Individual
- **Name:** Abhijeet Damodar
- **Entry Number:** 2026AIM1001
- **Branch:** Artificial Intelligence (AI)

---

# Objective

This assignment contains two graph based algorithms:

1. Graph Coloring
2. PageRank

Both algorithms are implemented in C++ using separate source and header files. A common driver program is used to run either algorithm on a selected test case.

The program reads the input graph from the `tests` folder and prints the result along with the execution time.

---

# Directory Structure

```text
assignment_04_individual/
|
├── driver/
|   └── driver.cpp
|
├── src/
|   ├── coloring.cpp
|   ├── coloring.h
|   ├── pagerank.cpp
|   └── pagerank.h
|
├── tests/
|   ├── color_10.txt
|   ├── color_100.txt
|   ├── color_10000.txt
|   ├── color_50000.txt
|   ├── color_100000.txt
|   |
|   ├── pagerank_10.txt
|   ├── pagerank_100.txt
|   ├── pagerank_1000.txt
|   ├── pagerank_10000.txt
|   └── pagerank_50000.txt
|
└── assignment4.exe
```

---

# Compilation

Open the terminal inside the `assignment_04_individual` folder.

Compile using:

```bash
g++ -std=c++17 driver/driver.cpp src/coloring.cpp src/pagerank.cpp -o assignment4.exe
```

Run the program using:

```bash
./assignment4.exe
```

If the driver accepts the algorithm and test file as command line arguments, it can be run as:

```bash
./assignment4.exe color tests/color_10.txt
```

or

```bash
./assignment4.exe pagerank tests/pagerank_10.txt
```

---

# Task 1 – Graph Coloring

## Description

Graph coloring assigns a color to each vertex such that two connected vertices do not receive the same color.

The implementation uses the graph given in the input test file and assigns colors to the vertices.

The output shows the color assigned to each vertex and the time taken by the coloring algorithm.

## Time Complexity

For the simple greedy coloring approach, the time complexity is generally:

```text
O(V + E)
```

where:

- `V` = number of vertices
- `E` = number of edges

The exact running time can depend on the graph representation and implementation.

---

# Task 2 – PageRank

## Description

PageRank is used to calculate the importance of vertices in a directed graph.

The algorithm starts with an initial rank for every vertex and repeatedly updates the ranks using the incoming links of each vertex.

A damping factor is used while calculating the new rank.

The general PageRank update is:

```text
PR(v) = (1-d)/N + d * sum(PR(u)/outDegree(u))
```

where:

- `d` = damping factor
- `N` = number of vertices
- `u` = vertex having an edge towards `v`
- `outDegree(u)` = number of outgoing edges from `u`

The algorithm is repeated until the required number of iterations or convergence condition is reached.

## Time Complexity

The time complexity depends on the number of iterations and the graph representation.

For `I` iterations using an adjacency-list representation, it is approximately:

```text
O(I * (V + E))
```

where:

- `V` = number of vertices
- `E` = number of edges
- `I` = number of PageRank iterations

---

# Input Test Cases

The test files are stored inside the `tests` directory.

## Graph Coloring Test Cases

```text
color_10.txt
color_100.txt
color_10000.txt
color_50000.txt
color_100000.txt
```

## PageRank Test Cases

```text
pagerank_10.txt
pagerank_100.txt
pagerank_1000.txt
pagerank_10000.txt
pagerank_50000.txt
```

The number in the filename represents the approximate number of vertices used in that test case.

---

# Running Through Driver

The driver provides a simple menu:

```text
1. Coloring
2. PageRank
Enter choice:
```

For example, selecting:

```text
1
```

runs Graph Coloring.

Selecting:

```text
2
```

runs PageRank.

After selecting the algorithm, the available test cases are displayed and one test case can be selected.

---

# Output

## Graph Coloring

The program displays:

- Vertices
- Assigned colors
- Execution time

## PageRank

The program displays:

- PageRank values of the vertices
- Execution time

The execution time is measured using C++ timing functions.

---

# Performance Measurement

The execution time is measured using the C++ `chrono` library.

The basic timing method is:

```cpp
auto start = chrono::high_resolution_clock::now();

/* algorithm */

auto end = chrono::high_resolution_clock::now();
```

The difference between the start and end time is used to calculate the execution time.

The actual timing can vary depending on the system, compiler settings and system load, so the values obtained by running the program should be used for the final performance table.

---

# Performance Table

## Graph Coloring

| Test File | Vertices | Execution Time |
|-----------|---------:|---------------:|
| color_10.txt | 10 | 0ms |
| color_100.txt | 100 | 0ms |
| color_10000.txt | 10,000 | 3.067ms |
| color_50000.txt | 50,000 | 20.54ms |
| color_100000.txt | 100,000 | 38.614ms |

## PageRank

| Test File | Vertices | Execution Time |
|-----------|---------:|---------------:|
| pagerank_10.txt | 10 | 0ms |
| pagerank_100.txt | 100 | 0ms |
| pagerank_1000.txt | 1,000 | 0ms |
| pagerank_10000.txt | 10,000 | 0ms |
| pagerank_50000.txt | 50,000 | 2.772ms |

---

# Use of CSR

The graph data can be represented using the CSR graph module used in the earlier assignment.

CSR stores the graph using arrays such as:

```text
rowPtr
colIdx
values
```

This representation avoids storing unnecessary empty entries and is useful for sparse graphs.

---

# Software Requirements

- C++17
- GNU g++
- Windows / Linux / WSL
- Standard C++ Library

---

# Conclusion

This assignment implements Graph Coloring and PageRank using C++.

Different graph sizes are used to check the correctness and performance of both algorithms. The driver provides a simple way to select the algorithm and test case, while the actual algorithm implementations are kept separately in the `src` folder.

The execution time can be compared across the different test sizes to observe how the algorithms behave as the graph size increases.

---

# References

1. CS509 – PG Software Lab Assignment Specification
2. C++17 Standard Library Documentation
3. GNU C++ Compiler Documentation
