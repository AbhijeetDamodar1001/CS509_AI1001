# Assignment 3 - Minimum Spanning Tree

## Assignment Type

Individual

### Student Information
- NAME: Abhijeet Damodar
- ENTRY NO.: 2026AIM1001
- BRANCH: ARTIFICIAL INTELLIGENCE (AI)
- COURSE: CS509

---

## 1. Overview

This assignment implements two algorithms for finding a Minimum Spanning
Tree (MST):

1. **Kruskal's Algorithm**
2. **Prim's Algorithm**

Both algorithms work on the same weighted and undirected graph. The graph
is first prepared in CSR format and then passed to the required algorithm.

The program displays the MST edges, total MST weight and the time taken by
the algorithm.

The main aim is to compare the two MST approaches on graphs of different
sizes.

---

## 2. Folder Structure

```text
assignment_03/
|
├── driver/
|   └── driver.cpp
|
├── src/
|   ├── kruskal.cpp
|   ├── kruskal.h
|   ├── prim.cpp
|   └── prim.h
|
├── tests/
|   ├── mst_10.txt
|   ├── mst_100.txt
|   ├── mst_10000.txt
|   ├── mst_50000.txt
|   └── mst_100000.txt
|
└── assignment.exe
```

The CSR implementation from the previous assignment is reused instead of
copying it again into this assignment.

---

## 3. Workflow

### Kruskal

```text
tests/mst_*.txt
      ↓
driver.cpp
      ↓
read graph
      ↓
convert graph to CSR
      ↓
kruskal.cpp
      ↓
sort edges + Union-Find
      ↓
MST edges and total weight
      ↓
execution time
```

### Prim

```text
tests/mst_*.txt
      ↓
driver.cpp
      ↓
read graph
      ↓
convert graph to CSR
      ↓
prim.cpp
      ↓
select minimum connecting edge
      ↓
MST edges and total weight
      ↓
execution time
```

Both algorithms use the same input graph so that their MST weights and
execution times can be compared fairly.

---

## 4. Kruskal's Algorithm

Kruskal's algorithm considers the edges in increasing order of their
weights.

The basic process is:

1. Collect the graph edges.
2. Sort them according to weight.
3. Check whether adding an edge will form a cycle.
4. Add the edge if it connects two different components.
5. Continue until `V-1` edges are selected.

A Union-Find / Disjoint Set structure is used to keep track of the
connected components.

---

## 5. Prim's Algorithm

Prim's algorithm builds the MST starting from one vertex. Vertex `0` is
used as the starting vertex.

The main steps are:

1. Start with vertex `0`.
2. Find the minimum weight edge going from the current tree to an
   unvisited vertex.
3. Add that vertex and edge to the MST.
4. Repeat until all vertices are included.

A priority queue is used to efficiently find the next minimum edge.

---

## 6. Test Cases

The assignment requires the following graph sizes for MST:

| Test File | Vertices |
|---|---:|
| `mst_10.txt` | 10 |
| `mst_100.txt` | 100 |
| `mst_10000.txt` | 10,000 |
| `mst_50000.txt` | 50,000 |
| `mst_100000.txt` | 100,000 |

The same graph files are used for both Kruskal and Prim.

The larger graphs are kept sparse so that they can be tested on a normal
student system.

---

## 7. Timing Results

The following are the timings recorded during testing:

| Test File | Vertices | Time (ms) |
|---|---:|---:|
| `mst_10.txt` | 10 | 0 |
| `mst_100.txt` | 100 | 0 |
| `mst_10000.txt` | 10,000 | 18.629 |
| `mst_50000.txt` | 50,000 | 140.393 |
| `mst_100000.txt` | 100,000 | 291.517 |

These values are the timings supplied from the current MST runs. They are
kept as recorded rather than assigning them separately to Kruskal or Prim,
because the supplied values were not labelled by algorithm.

For a final Kruskal-vs-Prim comparison, the two algorithm timings should be
recorded separately.

---

## 8. Timing Method

The timer is started just before the MST algorithm is called and stopped
immediately after it finishes.

The following work is kept outside the measured algorithm time:

- Reading the input file
- Input parsing
- CSR conversion
- Printing the result

For Kruskal, creating the edge list from the already prepared CSR and
sorting the edges are part of the Kruskal algorithm and should be included
in its measured time.

---

## 9. Expected Result

For a connected graph with `V` vertices:

- The MST should contain exactly `V-1` edges.
- The total MST weight should be minimum.
- Kruskal and Prim should produce the same total MST weight.
- The selected edges can be different if the graph has more than one
  valid MST.

For the assignment's sample graph, the expected total MST weight is:

```text
16
```

---

## 10. Output

The program reports:

```text
Algorithm: Kruskal's MST
MST edges:
...
Total MST weight: ...
Execution time: ... ms
```

and similarly for Prim:

```text
Algorithm: Prim's MST
MST edges:
...
Total MST weight: ...
Execution time: ... ms
```

The important correctness check is that both algorithms give the same
minimum total weight.

---

## 11. Compilation

Open the terminal inside the `assignment_03` folder and compile the
program using the required source files.

Example:

```powershell
g++ driver/driver.cpp src/kruskal.cpp src/prim.cpp ../assignment_01/src/csr.cpp -o assignment
```

Then run:

```powershell
./assignment.exe
```

---

## 12. Conclusion

Kruskal's and Prim's algorithms were implemented to solve the Minimum
Spanning Tree problem using the same weighted undirected graph inputs.

The different test sizes help in checking both correctness and performance.
The results from both algorithms can be compared using their MST weight and
execution time.
