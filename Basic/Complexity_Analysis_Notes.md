# Complexity Analysis Notes

1s ~ 10^8 operations

## 1. Time Complexity

### Big-O (O) → Upper Bound

-   **Meaning:** Growth is at most this fast (worst-case).
-   **Formal Definition:** f(n) = O(g(n)) means there exist constants c
    \> 0 and n₀ such that\
    **f(n) ≤ c · g(n)** for all n ≥ n₀.
-   **Think of it as:** "It won't grow faster than this."
-   **Example:** 4n³ + 3n² + 8 = **O(n³)**

### Big-Omega (Ω) → Lower Bound

-   **Meaning:** Growth is at least this fast (best-case guarantee).
-   **Formal Definition:** f(n) = Ω(g(n)) means there exist constants c
    \> 0 and n₀ such that\
    **f(n) ≥ c · g(n)** for all n ≥ n₀.
-   **Think of it as:** "It grows no slower than this."
-   **Example:** 4n³ + 3n² + 8 = **Ω(n³)**

### Big-Theta (Θ) → Tight Bound

-   **Meaning:** Growth is exactly this fast (both upper and lower
    bound).
-   **Formal Definition:** f(n) = Θ(g(n)) means\
    f(n) = O(g(n)) AND f(n) = Ω(g(n))
-   **Think of it as:** "It grows like this --- no faster, no slower."
-   **Example:** 4n³ + 3n² + 8 = **Θ(n³)**

### Intuition Table

  -----------------------------------------------------------------------
  Notation           Meaning                           Analogy
  ------------------ --------------------------------- ------------------
  **O**              ≤ (upper bound)                   "I will reach the
                                                       party no later
                                                       than 7 PM."

  **Ω**              ≥ (lower bound)                   "I will reach the
                                                       party no earlier
                                                       than 7 PM."

  **Θ**              Tight bound                       "I will reach the
                                                       party around 7 PM
                                                       (consistently)."
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## 2. Space Complexity

### Definition

Space complexity measures the **total amount of memory** an algorithm
needs to run to completion.

It's basically **Auxiliary Space + Input Space**

**c = a + b means c is the auxiliary space, a and b are input space**. So, O(3) or O(n) is the space complexity


### Components of Space Complexity

-   **Fixed Part:** (Independent of input size)
    -   Instruction space (code)
    -   Fixed-size variables
    -   Constants
    -   Program environment data
-   **Variable Part:** (Depends on input size)
    -   Dynamic memory allocation
    -   Function call stack (recursive calls, local variables)
    -   Auxiliary data structures created by algorithm

### Measuring Space Complexity

-   Expressed as a function of input size n.
-   Big-O, Ω, Θ notations are also used here.

### Example

If algorithm uses: - Constant memory: c - Memory proportional to n: k·n

**Space complexity = c + k·n → O(n)**

### Typical Space Complexities

  Complexity     Meaning             Example
  -------------- ------------------- ---------------------------
  **O(1)**       Constant space      Swapping two numbers
  **O(log n)**   Logarithmic space   Binary search recursion
  **O(n)**       Linear space        Copying array
  **O(n²)**      Quadratic space     Dynamic programming table

### Time-Space Trade-off

-   **Use more memory for speed:** Hash tables, memoization.
-   **Use less memory for slower speed:** Recompute instead of storing
    results.

