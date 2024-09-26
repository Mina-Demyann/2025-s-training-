Let's go step by step through the solution and proof to help you understand it in detail.

### Problem Summary:
You are given an integer \( n \), and you need to split it into two integers \( k \) and \( n - k \) such that the **LCM** (Least Common Multiple) of \( k \) and \( n - k \) is minimized.

### The Key Idea:
- The best way to minimize the **LCM** is to choose \( k \) as the largest **proper factor** of \( n \). A proper factor of \( n \) is any factor of \( n \) other than \( n \) itself.

### Step-by-Step Breakdown:

#### 1. **Choosing Two Integers:**
You want to split \( n \) into two integers, \( k \) and \( n - k \), where:
- \( k \leq n - k \)
- This means \( n - k \geq n / 2 \).

#### 2. **Why \( k \) Should Be a Factor of \( n \):**
To minimize the **LCM(k, n - k)**, it's crucial that \( k \) divides \( n \), i.e., \( k \mid n \). Let's prove this next.

#### 3. **When \( k \mid n \) (k is a divisor of n):**
- If \( k \) divides \( n \), then there exists some integer \( m \) such that \( m \cdot k = n \).
- Therefore, \( n - k = (m - 1) \cdot k \), which is also a multiple of \( k \).
- Since both \( k \) and \( n - k \) are multiples of \( k \), the **LCM(k, n - k)** equals \( n - k \) (the larger of the two).

#### 4. **When \( k \nmid n \) (k is not a divisor of n):**
- If \( k \) does **not** divide \( n \), then \( k \) does **not** divide \( n - k \) either. 
- In this case, the **LCM(k, n - k)** must be larger than \( n - k \), because the least common multiple must be a number divisible by both \( k \) and \( n - k \), and neither divides the other.
- Hence, **LCM(k, n - k)** will be **greater than or equal to \( n \)** when \( k \nmid n \).

#### 5. **Conclusion:**
To minimize the **LCM(k, n - k)**, \( k \) must be a divisor of \( n \). The smallest possible **LCM** is when \( k \mid n \) and the **LCM(k, n - k)** equals \( n - k \).

#### 6. **Maximizing \( k \):**
Since **LCM(k, n - k)** equals \( n - k \) when \( k \mid n \), you want to minimize \( n - k \), which means you need to **maximize \( k \)**. The largest possible divisor of \( n \), other than \( n \) itself, is the **largest proper factor** of \( n \).

### Step-by-Step Example:

For \( n = 100 \):
- The divisors of \( 100 \) are \( 1, 2, 4, 5, 10, 20, 25, 50, 100 \).
- The largest proper factor of \( 100 \) is \( 50 \).
- Hence, split \( 100 \) into \( k = 50 \) and \( n - k = 50 \).
- **LCM(50, 50) = 50**, which is smaller than any other combination.

### Finding the Largest Proper Factor Efficiently:
- To efficiently find the largest proper factor of \( n \), you can find the smallest prime factor \( p \) of \( n \). Once you find this smallest prime factor \( p \), the largest proper factor of \( n \) will be \( \frac{n}{p} \).
- If \( n \) is prime (i.e., it has no divisors other than 1 and \( n \)), then the largest proper factor is \( 1 \).

### How the Solution Fits in the Time Limit:
- The maximum value of \( n \) is \( 10^9 \), so the largest possible factor you need to check is \( \sqrt{10^9} \approx 10^5 \). You only need to check numbers up to \( 10^5 \) to find the smallest prime factor of \( n \).
- The number of test cases is small enough, and checking for factors up to \( \sqrt{n} \) ensures that the solution runs within the time limits.

### Final Thought:
By choosing the largest proper factor of \( n \), you ensure that the **LCM(k, n - k)** is minimized, and you can compute this efficiently within the constraints of the problem.
