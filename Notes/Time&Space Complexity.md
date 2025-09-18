# #Time Complexity
    The rate at which the time taken increases wrt. the size of the input. 

    1. Look for Worst Case Scenario
    2. Avoid constants
    3. Avoid Lower Values$

    O(no. of operations)   Big O Notation

    O(4n^3 + 3n^2 + 8)  --> O(N^3)

    Big O, Big Omega, and Big Theta Notations (Complexity Analysis)

1.  ## Big O (O) → Upper Bound

   Meaning: Growth is at most this fast (worst case).

   Formal Definition: f(n) = O(g(n)) means there exist constants c > 0
    and n₀ such that f(n) ≤ c · g(n) ∀ n ≥ n₀

    Think of it as: “It won’t grow faster than this.”

    Example: 4n³ + 3n² + 8 = O(n³) (for large n, n³ dominates — we only
    need a constant c so that f(n) stays below c·n³).

2.  ## Big Omega (Ω) → Lower Bound 

    Meaning: Growth is at least this fast (**best case guarantee**).

    Formal Definition: f(n) = Ω(g(n)) means there exist constants c > 0
    and n₀ such that f(n) ≥ c · g(n) ∀ n ≥ n₀

    Think of it as: “It grows no slower than this.”
    Example: 4n³ + 3n² + 8 = Ω(n³) (for large n, f(n) will always be at
    least proportional to n³).

3.  ## Big Theta (Θ) → Tight Bound

    Meaning: Growth is exactly this fast (both upper and lower bound).
    Formal Definition: f(n) = Θ(g(n)) means f(n) = O(g(n)) AND f(n) =
    Ω(g(n))
    Think of it as: “It grows like this — no faster, no slower.”
    Example: 4n³ + 3n² + 8 = Θ(n³) (because it’s bounded above and below
    by multiples of n³).




    