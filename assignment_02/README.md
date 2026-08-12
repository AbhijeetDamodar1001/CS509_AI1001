# Assignment 2 - Shortest Path Algorithms

## Assignment Type

Individual

### Student Information
- NAME: Abhijeet Damodar
- ENTRY NO.: 2026AIM1001
- BRANCH: ARTIFICIAL INTELLIGENCE(AI)
- COURSE - CS509 

---
## 1. Overview

This assignment contains two shortest path algorithms:

1. **Bellman-Ford**
2. **Floyd-Warshall**

Both algorithms are implemented in C++ using separate header and source files. A common `driver.cpp` is used to select the algorithm to run.

The program reads the selected test case from the `tests` folder and displays the result along with the execution time.

---

## 2. Folder Structure

```text
assignment_02/
|
├── driver/
|   └── driver.cpp
|
├── src/
|   ├── bellmanford.cpp
|   ├── bellmanford.h
|   ├── floydwarshall.cpp
|   └── floydwarshall.h
|
├── tests/
|   ├── bf_10.txt
|   ├── bf_100.txt
|   ├── bf_10000.txt
|   ├── bf_50000.txt
|   ├── bf_100000.txt
|   |
|   ├── fw_10.txt
|   ├── fw_100.txt
|   ├── fw_500.txt
|   ├── fw_1000.txt
|   └── fw_2000.txt
|
└── assignment.exe
```

---

## 3. Workflow

### Bellman-Ford

```text
tests/bf_*.txt
      ↓
driver.cpp
      ↓
read graph data
      ↓
bellmanford.cpp
      ↓
shortest distances
      ↓
execution time
```

### Floyd-Warshall

```text
tests/fw_*.txt
      ↓
driver.cpp
      ↓
read distance matrix
      ↓
floydwarshall.cpp
      ↓
shortest path matrix
      ↓
execution time
```

The driver handles the input and calls the required algorithm. The algorithm code is kept separately inside the `src` folder.

---

## 4. Bellman-Ford

Bellman-Ford finds the shortest distance from one source vertex to all other vertices.

The basic steps are:

1. Set the source distance to `0`.
2. Set the other distances to infinity.
3. Relax the edges repeatedly.
4. Check for a negative weight cycle.
5. Print the shortest distances.

### Test Cases

| Test File | Vertices |
|---|---:|
| `bf_10.txt` | 10 |
| `bf_100.txt` | 100 |
| `bf_10000.txt` | 10,000 |
| `bf_50000.txt` | 50,000 |
| `bf_100000.txt` | 100,000 |

---

## 5. Floyd-Warshall

Floyd-Warshall finds the shortest paths between every pair of vertices.

The main update used in the algorithm is:

```text
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

Each vertex is considered as an intermediate vertex.

### Test Cases

| Test File | Vertices |
|---|---:|
| `fw_10.txt` | 10 |
| `fw_100.txt` | 100 |
| `fw_500.txt` | 500 |
| `fw_1000.txt` | 1,000 |
| `fw_2000.txt` | 2,000 |

---

## 6. Timing Results

Timing can change depending on the computer, compiler and system load. The table below gives **representative values only**. The final report should preferably use the values printed by the program on the machine used for testing.

| Algorithm | Test Case | Time (ms) |
|---|---|---:|
| Bellman-Ford | 10 | 0.00 |
| Bellman-Ford | 100 | 0.01 |
| Bellman-Ford | 10,000 | 0.50 |
| Bellman-Ford | 50,000 | 2.50 |
| Bellman-Ford | 100,000 | 5.00 |
| Floyd-Warshall | 10 | 0.00 |
| Floyd-Warshall | 100 | 0.20 |
| Floyd-Warshall | 500 | 2.50 |
| Floyd-Warshall | 1,000 | 20.00 |
| Floyd-Warshall | 2,000 | 160.00 |

> **Note:** The timings above are sample values, not measured values. Replace them with the actual timings obtained after running the program before submitting the assignment.

---

## 7. Compilation

Open the terminal inside the `assignment_02` folder and run:

```powershell
g++ driver/driver.cpp src/bellmanford.cpp src/floydwarshall.cpp ../assignment_01/src/csr.cpp -I../assignment_01/src -o assignment
```

Then run:

```powershell
./assignment.exe
```

---

## 8. Running the Program

The program shows:

```text
1. Bellman-Ford
2. Floyd-Warshall
Enter choice:
```

Enter:

```text
1
```

for Bellman-Ford, or:

```text
2
```

for Floyd-Warshall.

The test file is already specified in the driver, so there is no need to select a test file from another menu.

---

## 9. Output

For Bellman-Ford, the program prints the shortest distances from the selected source and the execution time.

For Floyd-Warshall, the program prints the shortest path matrix and the execution time.

The output is kept simple so that the result can be checked easily with the input test case.

---

## 10. Conclusion

Both shortest path algorithms were implemented separately and connected using one driver program.

Bellman-Ford is used for single-source shortest paths and negative-cycle detection. Floyd-Warshall is used for all-pairs shortest paths.

Different input sizes are provided to check both correctness and performance.
