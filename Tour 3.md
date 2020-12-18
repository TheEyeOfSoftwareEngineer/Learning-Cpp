## Tour 3

### 指针的概念

![image-20201218172633528](/Users/yao/Library/Application%20Support/typora-user-images/image-20201218172633528.png)

- 内存由多个内存单元组成。这些内存单元用于存放各种类型的数据。
- 计算机对内存的每个内存单元都进行了编号，这个编号就成为内存地址，地址决定了内存单元在内存中的位置。

```c++
int a = 112, b = -1;
float c = 3.14f;
int* d = &a;
float* e - &c;
```

![image-20201218173420884](/Users/yao/Library/Application%20Support/typora-user-images/image-20201218173420884.png)

***变量名存储的是所指向值的内存地址***

#### 指针的定义与间接访问操作

- 指针定义的基本形式：指针本身就是一个变量，其符合变量定义的基本形式，它存储的是值的地址。对类型T，T*是“到T的指针”类型，一个类型为`T*`的变量能保存一个类型T的对象的地址

- 通过一个指针访问它所指向地址的过程称为间接访问（indirection）或者引用指针（dereferencing the point）；这个用于执行间接访问的操作符是单目操作符`*`；

```c++
cout << (*d) << endl; // 112
cout << (*e) << endl; // 3.14
```

```c++
#include <iostream>

using namespace std;

int main() {
  int a = 112, b = -1;
  float c = 3.14f;
  int* d = &a;
  float* e = &c;
  cout << d << endl;     // 0x7ffee723e28c
  cout << e << endl;     // 0x7ffee723e284
  cout << (&d) << endl;  // 0x7ffee723e278
  cout << (&e) << endl;  // 0x7ffee723e270
  cout << (*d) << endl;  // 112
  cout << (*e) << endl;  // 3.14
}
```

关于变量，地址和指针变量小结：

- 一个变量有三个重要的信息
  - 变量的地址位置
  - 变量所存的信息 （值）
  - 变量的类型 （*记录在编译器当中*）
- 指针变量是一个专门用来记录变量的地址的变量；通过指针变量可以间接的access另一个变量的值。

### C++原生指针

```c++
int main() {
  char strHelloWorld[] = {"helloworld"};
  char* pStrHelloWorld = "helloworld";
  pStrHelloWorld = strHelloWorld;     // 指针变量的值允许改变
  strHelloWOrld = pStrHelloWorld;     // 报错：数组变量的值不允许改变
}
```



> `char strHelloWorld[11] = {"HelloWorld"};`
>
> strHelloWorld不可变，strHelloWorld[index]的值可变；
>
> `char* pStrHelloWorld = "HelloWorld"；`
>
> pStrHelloWorld可变，但是pStrHelloWorld[index]的值可变不可变取决于所指区间的存储区域是否可变。

### 左值和右值

编译器为其单独分配了一块存储空间，可以取其地址的，左值可以放在赋值运算符左边；

右值指的是数据本身，不能取到其自身地址，右值*只能*赋值运算符右侧。

- 左值最常见的情况如函数和数据成员的名字
- 右值是没有标识符、不可以取地址的表达式，*一般也称之为“临时对象”*

比如：a = b + c; &a是允许的操作，而&(b+c)不能通过编译。因此a是一个左值，而(b+c)是一个右值。

### 几种C++中的原始指针

- 一般类型指针T*

如int*

- 指针的数组(array of pointers)与数组的指针(a pointer to an array)：
  - 指针的数组 T* t[]
  - 数组的指针 T(*t) []

如`int* a[4]`表示包含4个int型指针的元素的数组；`int(*b)[4]`表示一个指向包含4个int元素的指针。

```c++
int main() {
  int c[4] = {0x80000000, 0xFFFFFFFF, 0x00000000, 0x7FFFFFFF};
  int* a[4];
  int(*b)[4];
  b = &c;
  for(unsigned int i = 0; i < 4; ++i) {
    a[i] = &(c[i]);
  }
  
  cout << *(a[0]) << endl; // 0x8000000
  cout << (*b)[3] << endl; // 0x7FFFFFF
}
```

- const pointer与pointer to const

```c++
char strHelloWorld[] = {"helloworld"};
char const *pStr1 = "helloworld";         // pStr1本身可变但是指向的值不可变
char* const pStr2 = "helloworld";         // pStr2本身不可变但是他所指向的值可变
char const * const pStr3 = "helloworld";  // pStr3本身和指向的值均不可变
pStr1 = strHelloWorld;
// pStr2 = strHelloWorld;   // pStr2不可改
// pStr3 = strHelloWorld;   // pStr3不可改
```

### 指向指针的指针

```c++
int a - 123;
int* b = &a;
int** c = &b;
```

- *操作符具有从右向左的结合行
  - `**`相当于`*(*c)`
  - *c相当于b
  - **c相当于·`*b`，得到a的值

### 未初始化和非法指针

```c++
int *a; // 并不知道a在这里指向了哪里
*a = 12;
```

### NULL指针

一个特殊的指针变量，表示不指向任何东西。`int *a = NULL`避免非法指针。

表示特定的指针目前未指向任何东西。

对于一个指针，不知道初始化地址，那么就用NULL指针。在使用前先判断这个指针的值是否为NULL。

### 野指针

指向“垃圾”内存的指针。if等判断对它们不起作用，因为没有置为NULL。

- 指针变量没有初始化
- 已经释放不用的指针没有置NULL，如delete和free之后的指针
- 指针操作超越了变量的工作范围（一般是有生命周期的变量）

### 原始指针的基本运算

#### &和*操作符

```c++
char ch - 'a';
char* cP = &ch;
```

![image-20201218191948145](/Users/yao/Library/Application%20Support/typora-user-images/image-20201218191948145.png)

*个人理解：结合之前左右值的含义，我们在创建一个变量'a'的时候因为其为常量所以在栈列中，系统会保存该值的地址，**但是我们得不到这个地址**。所以这也让这个变量不能成为左值。左值是我们可以 直接取内存地址/访问其内存空间 进行操作的值。*

 ![image-20201218192934603](/Users/yao/Library/Application%20Support/typora-user-images/image-20201218192934603.png)

*`*cp`在左值的时候表示取指向的空间，右值表示取指向空间的值*

#### ++与--操作符

```c++
char* cp1 = ++cp;
char* cp2 = cp++;
```

#### ++进一步说明

![image-20201218220306751](/Users/yao/Library/Application%20Support/typora-user-images/image-20201218220306751.png)

![image-20201218220531834](/Users/yao/Library/Application%20Support/typora-user-images/image-20201218220531834.png)

*左值取空间，右值取值*

#### ++++, ----等运算符

编译器程序分解成符号的方法是：一个字符一个字符的读入，如果该字符可能组成一个符号，那么读入下一个字符，一直到读入的字符不能再组成一个有意义的符号。--贪心法

```c++
int a = 1, b = 2;c;
c = a+++b; // == a++ +b
d = a++++b; // == a++ ++b, error
```

