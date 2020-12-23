## Dynamic Programming

Dynamic programming is an algorithm design technique that can be used to find optimal solutions to problems and to count the number of solutions. This chapter is an introduction to dynamic programming, and the technique will be used many times later in the book when designing algorithms.

### Basic Concepts

#### **When Greedy Fails**

In this section, we go through the basic concepts of dynamic programming in the context of a coin change problem. First we present a greedy algorithm for the problem, which does not always produce an optimal solution. After this, we show how the problem can be efficiently solved using dynamic programming.

Suppose that we are given a set of coin values coins=$\{c_1, c_2. ..., c_n\}$ and a target sum of money *n*, and we are asked to construct the sum *n* using as few coins as possible. There are no restrictions on how many times we can use each coin value. For example, if coins= {1,2,5} and *n* = 12, the optimal solution is 5 + 5 + 2 = 12, which requires three coins.

There is a natural greedy algorithm for solving the problem: Always select the largest possible coin so that the sum of coin values does not exceed the target sum. For example, if *n* = 12, we first select two coins of value 5 and then one coin of value 2, which completes the solution. This looks like a reasonable strategy, but is it always optimal?

It turns out that this strategy does *not* always work. For example, if coins = {1,3,4} and *n* = 6, the optimal solution has only two coins (3 + 3 = 6) but the greedy strategy produces a solution with three coins (4 + 1 + 1 = 6). This simple counter example shows that the greedy algorithm is not correct.

局部的最优解不代表全局的最优解

How could we solve the problem, then? Of course, we could try to find another greedy algorithm, but there are no other obvious strategies that we could consider. Another possibility would be to create a brute force algorithm that goes through all possible ways to select coins. Such an algorithm would surely give correct results, but it would be very slow on large inputs.

However, using dynamic programming, we can create an algorithm that is almost like a brute force algorithm but it is also *efficient*. Thus, we can both be sure that the algorithm is correct and use it for processing large inputs. Furthermore, we can use the same technique for solving a large number of other problems.

动态规划实质上是高效率的暴力破解

#### **Finding an Optimal Solution**

To use dynamic programming, we should formulate the problem recursively so that the solution to the problem can be calculated from solutions to smaller subproblems. In the coin problem, a natural recursive problem is to calculate values of a function $solve(x)$: What is the minimum number of coins required to form a sum *x*? Clearly, the values of the function depend on the values of the coins. For example, if coins = {1, 3, 4}, the first values of the function are as follows:

$$solve(0)=0$$

$$solve(1)=1$$

$$solve(2)=2$$

$$solve(3)=1$$

$$solve(4)=1$$

$$solve(5)=2$$

$$solve(6)=2$$

$$solve(7)=2$$

$$solve(8)=2$$

$$solve(9)=3$$

$$solve(10)=3$$

代表着我们最少可以用几枚硬币就可以组成对应的数字。

For example, solve(10) = 3, because at least 3 coins are needed to form the sum 10. The optimal solution is 3 + 3 + 4 = 10.

The essential property of solve is that its values can be recursively calculated from its smaller values. The idea is to focus on the *first* coin that we choose for the sum. For example, in the above scenario, the first coin can be either 1, 3, or 4. If we first choose coin 1, the remaining task is to form the sum 9 using the minimum number of coins, which is a subproblem of the original problem. Of course, the same applies to coins 3 and 4. Thus, we can use the following recursive formula to calculate the minimum number of coins:

$$slove(x) = min(solve(x-1)+1, solve(x-3)+1, solve(x-4)+1)$$

The base case of the recursion is solve(0) = 0, because no coins are needed to

form an empty sum. For example,

$$solve(10)=solve(7)+1=solve(4)+2=solve(0)+3=3$$

Now we are ready to give a general recursive function that calculates the minimum number of coins needed to form a sum *x*:

$$solve(x) = \begin{cases} inf & x<0 \\ 0 & x=0 \\ min_{c \in coins} solve(x-c)+1 & x > 0 \end{cases}$$

First, if *x* < 0, the value is infinite, because it is impossible to form a negative sum of money. Then, if *x* = 0, the value is zero, because no coins are needed to form an empty sum. Finally, if *x* > 0, the variable *c* goes through all possibilities how to choose the first coin of the sum.

Once a recursive function that solves the problem has been found, we can directly implement a solution in C++ (the constant INF denotes infinity):

```c++
int solve(int x) {
  if(x < 0) return INF;
  if(x == 0) return 0;
  int best = INF;
  for (auto c: coins) {
    best = min(best, solve(x-c)+1);
  }
  return best;
}
```

Still, this function is not efficient, because there may be a large number of ways to construct the sum and the function checks all of them. Fortunately, it turns out that there is a simple way to make the function efficient.

这个过程是先使劲用一个选中硬币c然后一直算到最底处，然后从最底处一层一层向上算出best的值。然后换硬币再重复类似的过程。

##### **Memoization**

The key idea in dynamic programming is *memoization*, which means that we store each function value in an array directly after calculating it. Then, when the value is needed again, it can be retrieved from the array without recursive calls. To do this, we create arrays

```c++
bool ready[N];
int value[N];
```

where ready[x] indicates whether the value of solve(*x* ) has been calculated, and if it is,value[*x*] contains this value. The constant *N* has been chosen so that all required values fit in the arrays.

After this, the function can be efficiently implemented as follows:

```c++
int solve(int x) {
  if(x < 0) return INF;
  if(x == 0) return 0;
  if(ready[x]) return value[x];
  int best = INF;
  for (auto c: coins) {
    best = min(best, solve(x-c)+1);
  }
  ready[x] = true;
  value[x] = best;
  return best;
}
```

The function handles the base cases *x* < 0 and *x* = 0 as previously. Then it checks from ready[*x* ] if solve(*x* ) has already been stored in value[*x* ], and if it is, the function directly returns it. Otherwise the function calculates the value of solve(*x* ) recursively and stores it in value[*x* ].

This function works efficiently, because the answer for each parameter *x* is calcu- lated recursively only once. After a value of solve(*x* ) has been stored in value[*x* ], it can be efficiently retrieved whenever the function will be called again with the pa- rameter *x*. The time complexity of the algorithm is *O*(*nk*), where *n* is the target sum and *k* is the number of coins.

这里我们选用纯递归的方式来写一下：

```c++
int solve(int x) {
  if(x < 0) return INF;
  if(x == 0) return 0;
  int best = INF;
  if(x >= 1) {
    best = min(best, solve(x-1)+1);
  }
  if(x >= 3) {
    best = min(best, solve(x-3)+1);
  }
  if(x >= 4) {
    best = min(best, solve(x-4)+1);
  }
  return best;
}
```

##### **Iterative Implementation** 

Note that we can also *iteratively* construct the array value using a loop as follows:

```c++
value[0] = 0;
for (int x = 1; x <=n; x++) {
  value[x] = INF;
  for (auto c : coins) {
    if(x-c >= 0) {
      value[x] = min(value[x], value[x-c]+1);
    }
  }
}
```

In fact, most competitive programmers prefer this implementation, because it is shorter and has smaller constant factors. From now on, we also use iterative implementations in our examples. Still, it is often easier to think about dynamic programming solutions in terms of recursive functions.

##### **Constructing a Solution**

Sometimes we are asked both to find the value of an optimal solution and to give an example how such a solution can be constructed. To construct an optimal solution in our coin problem, we can declare a new array that indicates for each sum of money the first coin in an optimal solution:

```c++
int first[N];
```

Then, we can modify the algorithm as follows:

```c++
value[0] = 0;
for (int x = 1; x <= n; x++) {
  value[x] = INF;
  for (auto c : coins) {
    if (x-c >= 0 && value[x-c]+1 < value[x]) { 
      value[x] = value[x-c]+1;
			first[x] = c;
		} 
  }
}
```

After this, the following code prints the coins that appear in an optimal solution for the sum *n*:

```c++
while (n > 0) {
	cout << first[n] << "\n"; 
  n -= first[n];
}
```

#### Counting Solutions

Let us now consider another variant of the coin problem where our task is to calculate the total number of ways to produce a sum *x* using the coins. For example, if coins = {1,3,4} and *x* = 5, there are a total of 6 ways:

- 1+1+1+1+1
- 1+1+3
- 1+3+1
- 1+4
- 3+1+1
- 4+1

Again, we can solve the problem recursively. Let solve(*x* ) denote the number of ways we can form the sum *x* . For example, if coins = {1, 3, 4}, then solve(5) = 6 and the recursive formula is

$$slove(x) = solve(x-1)+solve(x-3)+solve(x-4)$$

Then, the general recursive function is as follows:

$$solve(x) = \begin{cases} 0 & x<0 \\ 1 & x=0 \\ \sum_{c \in coins} solve(x-c) & x > 0 \end{cases}$$

If *x* < 0, the value is zero, because there are no solutions. If *x* = 0, the value is one, because there is only one way to form an empty sum. Otherwise we calculate the sum of all values of the form solve(*x* − *c*) where *c* is in coins.

The following code constructs an array count such that count[*x*] equals the value ofsolve(*x*) for 0 ≤ *x* ≤ *n*:

```c++
count[0] = 1;
for (int x = 1; x <= n; x++) {
  for (auto c : coins) { 
    if (x-c >= 0) {
      count[x] += count[x-c];
    }
	} 
}
```

Often the number of solutions is so large that it is not required to calculate the exact number but it is enough to give the answer modulo *m* where, for example, $m = 10^9 + 7$. This can be done by changing the code so that all calculations are done modulo *m*. In the above code, it suffices to add the line

```c++
count[x] %= m;
```

after the line

```c++
count[x] += count[x-c];
```



## Reference

Guide to Competitive Programming Learning and Improving Algorithms Through Contests, Antti Laaksonen



