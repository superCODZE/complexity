# Experimental Analysis of Algorithm Complexity

## 1. Objectives

- Implement four primality test algorithms.
- Measure their execution time on samples of prime numbers.
- Compare theoretical complexity with experimental measurements.
- Assess how the choice of datasets affects the interpretation of performance.

## 2. Team

- [superCODZE](https://github.com/superCODZE)
- [SamyBakiri](https://github.com/SamyBakiri)
- [iimosv](https://github.com/iimosv)
- [flowereve](https://github.com/flowereve)

## 3. Algorithms
Algorithms A1, A2, A3 and A4 are the four primality tests implemented in TP1.

| ID | Principle | Worst-case complexity |
|----|-----------|-----------------------|
| A1 | Test divisibility by 2, 3, ..., N-1 | O(N) |
| A2 | Test divisors from 2 to N/2 | O(N) |
| A3 | Test divisors from 2 to √N | O(√N) |
| A4 | Handle even N separately, then test only odd divisors up to √N | O(√N) (about 2x faster than A3) |

## 4. Data and Methodology

Tests are run in two steps, using the same four algorithms.

### Step 1: Reference sample

A series of 12 prime numbers of increasing size, provided in the assignment:

`1000003, 2000003, 4000037, 8000009, 16000057, 32000011, 64000031, 128000003, 256000001, 512000009, 1024000009, 2048000011`

Output: timing tables and T(N) charts for A1 to A4.

### Step 2: Test datasets (TP0)

The TP0 datasets were generated with TP0's own data-generation algorithm

| Dataset | Content |
|---------|---------|
| Random100 | 100 randomly drawn prime numbers |
| Random1000 | 1000 randomly drawn prime numbers |
| Test-1 | 100 prime numbers in [1000, 1000000] |
| Test-2 | 10 prime numbers per number of digits (3, 4, 5, ...) |
| Test-3 | Structured sample of numbers with 3, 6, 9 and 12 digits |

Goal: observe the effect of data size and distribution on measured times.


## 5. Deliverables

- C source code of the nine algorithms.
- Execution time tables (reference sample, then test datasets).
- Comparison charts: measured T(N) vs. theoretical complexity, A1 to A4.
- Conclusion: best-performing algorithm and agreement between theory and experiment.
