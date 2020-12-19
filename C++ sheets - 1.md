## C++ features

### input and output

```c++
// cin
int a, b;
string x;
cin >> a >> b >> x;
```

```c++
// cout
int a = 123, b = 456;
string x = "monkey";
cout << a << " " << b << " " << x << "\n";
```

Input and output are sometimes a bottleneck in the program. The following lines at the beginning of the code make input and output more efficient:

```c++
ios::sync_with_stdio(0);
cin.tie(0);
```

**Note that the newline "\n" works faster than endl, because endl always causes a flush operation.**

The C functions scanf and printf are an alternative to the C++ standard streams. They are usually slightly faster, but also more difficult to use. The following code reads two integers from the input:

```c++
// scanf
int a, b;
scanf("%d %d", &a, &b);
// printf
int a = 123, b = 456; 
printf("%d %d\n", a, b);
```

Sometimes the program should read a whole input line, possibly containing spaces. This can be accomplished by using the getline function:

```c++
string s;
getline(cin, s);
```

If the amount of data is unknown, the following loop is useful:

```c++
while (cin >> x) { 
  // code
} // just like the way we can use in the native nodejs
```

In some contest systems, files are used for input and output. An easy solution for this is to write the code as usual using standard streams, but add the following lines to the beginning of the code

```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

### Working with numbers

- Integer

The following code defines a long long variable:

```c++
long long x = 123456789123456789LL;
```

The suffix LL means that the type of the number is long long.

**A common mistake** when using the type long long is that the type int is still used somewhere in the code. For example, the following code contains a subtle error:

```c++
int a = 123456789;
long long b = a*a;
cout << b << "\n"; // -1757895751
```

Even though the variable b is of type long long, both numbers in the expression `a*a` are of type int and the result is also of type int. Because of this, the variable b will have a wrong result. The problem can be solved by changing the type of a to long long or by changing the expression to (long long)`a*a`.

Usually contest problems are set so that the type long long is enough. 

- Modular Arithmetic

```c++

long long x = 1;
for (int i = 1; i <= n; i++) {
	x = (x*i)%m; 
}
cout << x << "\n";
```

Usually we want the remainder to always be between 0 . . . *m* − 1. However, in C++ and other languages, **the remainder of a negative number is either zero or negative.** An easy way to make sure there are no negative remainders is **to first calculate the remainder as usual and then add *m* if the result is negative**:

```c++
x = x%m;
if (x < 0) x += m; // for example -9 / 2 = -5 ... 1
```

However, this is only needed when there are subtractions in the code and the remainder may become negative.

- Floating Point Number

he most useful floating point types in C++ are the 64-bit double and, as an extension in the g++ compiler, the 80-bit long double. In most cases, double is enough, but long double is more accurate.

The required precision of the answer is usually given in the problem statement. An easy way to output the answer is to use the printf function and give the number of decimal places in the formatting string. For example, the following code **prints the value of *x* with 9 decimal places**:

```c++
printf("%.9f\n", x);
```

A difficulty when using floating point numbers is that some numbers cannot be represented accurately as floating point numbers, and there will be rounding errors. For example, in the following code, the value of *x* is slightly smaller than 1, while the correct value would be 1.

```c++
double x = 0.3*3+0.1;
printf("%.20f\n", x); // 0.99999999999999988898
```

It is risky to compare floating point numbers with the == operator, because it is possible that the values should be equal but they are not because of precision errors. A better way to compare floating point numbers is to assume that two numbers are equal if the difference between them is less than ε, where ε is a small number. For example, in the following code ε = 10^−9:

```c++
if (abs(a-b) < 1e-9) { 
  // a and b are equal
}
```

Note that while floating point numbers are inaccurate, integers up to a certain limit can still be represented accurately. For example, using double, it is possible to accurately represent all integers whose absolute value is at most 2^53.

### Shortning Code

**Type Names** The command typedef can be used to give a short name to a data type. For example, the name long long is long, so we can define a short name ll as follows:

```c++
typedef long long ll;
```

```c++
long long a = 123456789; 
long long b = 987654321; 
cout << a*b << "\n";
```

can be shortened as follows:

```c++
ll a = 123456789;
ll b = 987654321;
cout << a*b << "\n";
```

The command typedef can also be used with more complex types. For example, the following code gives the name vi for a vector of integers and the name pi for a pair that contains two integers.

```c++
typedef vector<int> vi; 
typedef pair<int,int> pi;
```

**Macros** Another way to shorten code is to define *macros*. A macro specifies that certain strings in the code will be changed before the compilation. In C++, macros are defined using the #define keyword.

```c++
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
```

After this, the code

```c++
v.push_back(make_pair(y1,x1)); 
v.push_back(make_pair(y2,x2)); 
int d = v[i].first+v[i].second;
```

can be shortened as follows:

```c++

v.PB(MP(y1,x1)); v.PB(MP(y2,x2));
int d = v[i].F+v[i].S;
```

A macro can also have parameters, which makes it possible to shorten loops and other structures. For example, we can define the following macro:

```c++
#define REP(i,a,b) for (int i = a; i <= b; i++)
```

After this, the code

```c++
for (int i = 1; i <= n; i++) { 
  search(i);
}
```

can be shortened as follows:

```c++
REP(i,1,n) {
  search(i);
}
```

## Recursive Algorithms

*Recursion* often provides an elegant way to implement an algorithm. In this section, we discuss recursive algorithms that systematically go through candidate solutions to a problem. First, we focus on generating subsets and permutations and then discuss the more general backtracking technique

### **Generating Subsets**

Our first application of recursion is generating all subsets of a set of *n* elements. For example, the subsets of {1, 2, 3} are ∅, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, and {1, 2, 3}. The following recursive function search can be used to generate the subsets. The function maintains a vector

```c++
vector<int> subset;
```

that will contain the elements of each subset. The search begins when the function

is called with parameter 1.

```c++
void search(int k) { 
  if (k == n+1) {
		// process subset 
  } else {
		// include k in the subset
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
		// don’t include k in the subset
		search(k+1);
  }
} 
```

When the function search is called with parameter *k*, it decides whether to include the element *k* in the subset or not, and in both cases, then calls itself with parameter *k* + 1 Then, if *k* = *n* + 1, the function notices that all elements have been processed and a subset has been generated.

![image-20201219220520684](/Users/yao/Library/Application%20Support/typora-user-images/image-20201219220520684.png)

### **Generating Permutations**

Next we consider the problem of generating all permutations of a set of *n* elements. For example, the permutations of {1, 2, 3} are (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), and (3, 2, 1). Again, we can use recursion to perform the search. The fol- lowing function search maintains a vector

```c++
vector<int> permutation;
```

that will contain each permutation, and an array

```c++
bool chosen[n+1];
```

which indicates for each element if it has been included in the permutation. The

search begins when the function is called without parameters.

```c++
void search() {
	if (permutation.size() == n) {
		// process permutation 
  } else {
		for (int i = 1; i <= n; i++) { 
      if (chosen[i]) continue; 
      chosen[i] = true;
      permutation.push_back(i); 
      search();
			chosen[i] = false;
    	permutation.pop_back();
    }
  }
}
```

Each function call appends a new element to permutation and records that it has been included in chosen. If the size of permutation equals the size of the set, a permutation has been generated.

Note that the C++ standard library also has the function next_permutation that can be used to generate permutations. The function is given a permutation, and it produces the next permutation in lexicographic order. The following code goes through the permutations of {1, 2, . . . , *n*}:

```c++
for (int i = 1; i <= n; i++) { 
  permutation.push_back(i);
}
do {
	// process permutation
} while (next_permutation(permutation.begin(), permutation.end()));
```

### **Backtracking**

A *backtracking* algorithm begins with an empty solution and extends the solution step by step. The search recursively goes through all different ways how a solution can be constructed.

As an example, consider the problem of calculating the number of ways *n* queens can be placed on an *n* × *n* chessboard so that no two queens attack each other. 

The problem can be solved using backtracking by placing queens on the board row by row. More precisely, exactly one queen will be placed on each row so that no queen attacks any of the queens placed before. A solution has been found when all *n* queens have been placed on the board.

The algorithm can be implemented as follows:

![image-20201219222511197](/Users/yao/Library/Application%20Support/typora-user-images/image-20201219222511197.png)

```c++
void search(int y) {
  if (y == n) {
		count++;
		return; 
  }
  for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue; 
    col[x] = diag1[x+y] = diag2[x-y+n-1] = 1; 
    search(y+1);
		col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	} 
}
```

The search begins by calling search(0). The size of the board is *n*, and the code calculates the number of solutions to count. The code assumes that the rows and columns of the board are numbered from 0 to *n* − 1. When search is called with parameter *y*, it places a queen on row *y* and then calls itself with parameter *y* + 1. Then, if *y* = *n*, a solution has been found, and the value of count is increased by one.

The array col keeps track of the columns that contain a queen, and the arrays diag1 and diag2 keep track of the diagonals. It is not allowed to add another queen to a column or diagonal that already contains a queen.

The above backtracking algorithm tells us that there are 92 ways to place 8 queens on the 8 × 8 board. When *n* increases, the search quickly becomes slow, because the number of solutions grows exponentially.

## Bit Manipulation

**Bit Shifts** The *left bit shift x* << *k* appends *k* zero bits to the number, and the *right bit shift x* >> *k* removes the *k* last bits from the number. Note that *x* << *k* corresponds to multiplying *x* by 2*k* , and *x* >> *k* corresponds to dividing *x* by 2*k* rounded down to an integer.

**Bit Masks** A *bit mask* of the form 1 << *k* has a one bit in position *k* and all other bits are zero, so we can use such masks to access single bits of numbers. In particular, the *k*th bit of a number is one exactly when *x* & (1 << *k*) is not zero. The following code prints the bit representation of an int number *x* :

```c++
for (int k = 31; k >= 0; k--) { 
  if (x&(1<<k)) cout << "1"; 
  else cout << "0";
}
```

It is also possible to modify single bits of numbers using similar ideas. The formula *x* |(1<<*k*) sets the *k*th bit of *x*  to one,the formul a *x* &~(1<<*k*) sets the*k*thbit of *x* to zero, and the formula *x* ˆ (1 << *k*) inverts the *k*th bit of *x*. Then, the formula *x* &(*x*−1) sets the last one bit of *x*  to zero,and the formul a *x* &−*x* sets all the one bits to zero, except for the last one bit. The formula *x* | (*x* − 1) inverts all the bits after the last one bit. Finally, a positive number *x* is a power of two exactly when *x* & (*x* − 1) = 0.

One pitfall when using bit masks is that 1 << k is always an int bit mask. An easy way to create a long long bit mask is 1LL << k.

## Reference

Guide to Competitive Programming Learning and Improving Algorithms Through Contests (Undergraduate Topics in Computer Science), Antti Laaksonen