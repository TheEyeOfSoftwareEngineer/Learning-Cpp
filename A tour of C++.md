## A tour of C++ 

### Tour 0

This manual is edited to improve my ability to finish leetcode question with C++.

#### Programming Techniques

C++中的每一个变量都有其数据类型，数据类型决定这变量所占内存空间的大小和布局方式、该空间能存储的值的范围，以及变量能参与的运算。

Each variable in C++ has its own data type. The data type determines the size and layout of the memory space occupied by the variable, the range of values that can be stored in that space, and the operations that the variable can participate in.

- Common definitions of data types

```c++
char a[10] = "a";       // 1 byte
short int s = 97;       // 2 byte
int m = 97;             // 4 byte
long int n = 97;        // 4 byte  
float f = 97.0f;        // 4 byte
double d = 97.0;        // 8 byte
long double k = 97.0;   // 8 byte
bool b = true;          // 1 byte
wchar_t w[10] = L"a";   // 2 byte
```

- Operator

  - Arithematic Operator
    - +
    - -
    - *
    - /
    - %
    - ++
    - --

  ```c++
  #include<iostream>
  
  using namespace std;
  
  int main() {
    int A = 10;
    int B = 20;
    cout << A+B << endl; // 30
    cout << A-B << endl; // -10
    cout << A*B << endl; // 200
    cout << B/A << endl; // 2
    cout << 15/A << endl; // 1
    cout << 15.0/A << endl; // 1.5
    cout << B%A << endl; // 0
    cout << ++A << endl; // 11
    cout << A-- << endl; // 10
    cout << A++ << endl; // 10
  }
  ```

  - Relationship Operators
    - ==
    - !=
    - `>`
    - <
    - `>=`
    - <=

  ```c++
  #include<iostream>
  
  using namespace std;
  
  int main() {
    int A = 10;
    int B = 20;
    cout << A==B << endl; // 0
    cout << A!=B << endl; // 1
    cout << A>B << endl;  // 0
    cout << A<B << endl;  // 1
    cout << A>=B << endl; // 0
    cout << A<=B << endl; // 1
  }
  ```

  - Logic Operators
    - &&
    - ||
    - !

  ```c++
  #include<iostream>
  #include<assert.h>
  using namespace std;
  
  int main() {
    int A = false;
    int B = true;
    cout << (A==true||A!=true) << endl; // 1
    cout << (B==true||B!=true) << endl; // 1
    cout << (A==true&&B==true) << endl; // 0
    
    assert(A==true||A!=true); 
  	assert(B==true||B!=true); 
  	assert(A==true&&B==true); 
  }
  ```

  - Assignment Operator
    - =
    - +=
    - -=
    - *=
    - /=
    - %=
    - <<=
    - `>>=`
    - &=
    - ^=
    - |=
  - Miscellaneous Operators
    - sizeof: return the size of the variable. For example, sizeof(a) returns 4 (byte) which a is an int
    - Condition ? X : Y if condition is true return X else Y
    - `,` : commit the series of operations sequencely, and returm the last one
    - `.` and `->` : member operation used in reference class, struct and others.
    - Cast: int(2.20) return 2
    - &: pointer operator. For example `&a` returns the real address of a
    - *: pointer operator: For example *var returns var 

  ```c++
  #include<iostream>
  
  using namespace std;
  
  int main() {
    int A = 10;
    int B = 20;
    cout << sizeof(A) << endl; // 4
    int C = A > B ? 1 : 0;
    cout << C << endl; // 0
    int E = (A, B, C);
    cout << E << endl; // 0
    float F = float(E);
    cout << F << endl;  // 0
    cout << &F << endl;  // 0xFFXXX
    float* P = &F; // float* means the pointer which points to a float number and the value is the memory address of that float number
    cout << P << endl; // 0xFFXXX
    cout << *P << endl; // 0
  }
  ```

  ```c++
  #include <iostream>
  
  typedef struct {
    short Sunday = 0;
    short Monday = 1;
    short Tuesday = 2;
    short Wednesday = 3;
    short Thursday = 4;
    short Friday = 5;
    short Saturday = 6;
  } Week;
  
  int main() {
    Week w;
    std::cout << w.Friday << std::endl;  // 5
    std::cout << sizeof(w) << std::endl; // 14
  }
  ```

  - Bitwise operator
    - & bitwiese and
    - ^ XOR
    - | bitwise or
    - ~
    - `>>`
    - <<

  ```c++
  #include<iostream>
  
  using namespace std;
  
  int main() {
    int A = 10;
    int B = 20;
    cout << (A&B) << endl; // 01010&10100 = 00000 -> 0
    cout << (A|B) << endl; // 01010|10100 = 11110 -> 30
    cout << A^B << endl;  // 01010^10100 = 11110 -> 30
    cout << ~A << endl;  // ~0000000000001010 = 1111111111110101 -> 0000000000001011 -> -11
    cout << A<<2 << endl; // 00001010<<2 -> 00101000-> 40
    cout << A>>2 << endl; // 00001010>>2 -> 00000010 -> 2
  }
  ```

### Reference

Competitive Programming, 2018

