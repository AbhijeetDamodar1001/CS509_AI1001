# Assignment 01 - General Matrix Multiplication (GEMM)

## Assignment Type

Individual

---

## Objective

The objective of this assignment is to perform matrix multiplication using two different methods.

- Simple GEMM
- Blocking GEMM

Both methods are executed on the same input, and their execution time is compared.

---

## Algorithm

### Simple GEMM

Simple GEMM uses three nested loops to multiply two matrices. Every element of the result matrix is calculated by multiplying one row of the first matrix with one column of the second matrix.

### Blocking GEMM

Blocking GEMM divides the matrices into small blocks. Instead of processing the whole matrix at once, it processes one block at a time. This improves cache utilization and gives better performance for large matrices.

---

## Input Format

The first line contains three integers.

```
M K N
```

where

- M = Number of rows in Matrix A
- K = Number of columns in Matrix A and rows in Matrix B
- N = Number of columns in Matrix B

After that,

- Matrix A is given.
- Matrix B is given.

Example

```
2 3 2

1 2 3
4 5 6

7 8
9 10
11 12
```

---

## File Structure

```
assignment_01
│
├── driver
│   └── driver.cpp
│
├── src
│   ├── simple.cpp
│   ├── simple.h
│   ├── blocking.cpp
│   └── blocking.h
│
├── tests
│   ├── test_01.txt
│   └── test_02.txt
│
├── outputs
│   ├── output_01.txt
│   └── output_02.txt
│
└── README.md
```

---

## Compilation

Open terminal inside the assignment folder.

```
g++ driver/driver.cpp src/simple.cpp src/blocking.cpp -o gemm
```

---

## Execution

Windows

```
.\gemm.exe
```

---

## Test Cases

| Test File | Matrix Size |
|-----------|-------------|
| test_01.txt | 2 × 3 and 3 × 2 |
| test_02.txt | 3 × 3 and 3 × 3 |

---

## Result Table

| Mode | Test File | Input Type | Matrix Size | Expected Output | Actual Output | Algorithm Time |
|------|-----------|------------|-------------|-----------------|---------------|----------------|
| Individual | test_01.txt | Matrix | 2 × 3 , 3 × 2 | Same Matrix | Same Matrix | ____ ms |
| Individual | test_02.txt | Matrix | 3 × 3 , 3 × 3 | Same Matrix | Same Matrix | ____ ms |

---

## Time Complexity

Simple GEMM

```
O(M × K × N)
```

Blocking GEMM

```
O(M × K × N)
```

---

## Space Complexity

Simple GEMM

```
O(M × N)
```

Blocking GEMM

```
O(M × N)
```

---

## References

- Course Notes
- Class Discussion
- C++ Documentation

---

## Conclusion

Both algorithms produce the same result.

Blocking GEMM is more efficient for larger matrices because it improves cache utilization.
