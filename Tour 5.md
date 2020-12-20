## Tour 5

### 基本程序结构

- 顺序
- 分支
- 循环

#### if分支语句

```c++
if (p != NULL) 
{
  cout << *p << endl;
} 
else 
{
  //
}
```

#### switch语句

```c++
typedef enum _COLOR {
  RED,
  GREEN,
  BLUE,
  UNKNOWN
} color;

color color1;
color1 = GREEN;
switch (color1) 
{
  case RED:
  {
    cout << "red" << endl;
    break;
  }
  case GREEN:
  {
    cout << "green" << endl;
    break;
  }
  case BLUE:
  {
    cout << "blue" << endl;
    break;
  }
  default:
  {
    cout << "unknown color" << endl;
    break;
  }
}
```

两者比较：

- switch只支持常量值固定相等的分支判断
- if还可以判断区间范围
- switch所有case的速度几乎一样，类似于查表的过程
- if开始处几个分支效果高，之后效率递减

### 自定义结构-枚举

- 使用#define和const创建符号常量，使用enum不仅能够创建符号常量，还能定义新的数据类型；

- 枚举类型enum(enumeration)的声明和定义

  - ```c++
    enum wT {
      Monday, ... , Sunday
    };
    ```

  - ```c++
    wT weekday;
    ```

声明不产生实际的内存空间，但是定义会

#### 细节：

- 枚举值不可以做左值
- 非枚举变量不可以赋值给枚举变量
- 枚举变量可以赋值给非枚举变量

### 自定义结构-结构体与联合体

- 使用struct定义的是结构体

```c++
struct Student 
{
  char name[6];
  int age;
  Score s;
}
```

- 使用union定义的是联合体：

```c++
union Score 
{
  double sc;
  char level;
};
```

```c++
cout << sizeof(Score) << endl; // 8 而不是 9
cout << sizeof(Student) << endl; // 24 而不是 18
```

 #### 结构体数据对齐问题

- 结构体的内存布局

![image-20201220204119183](/Users/yao/Library/Application%20Support/typora-user-images/image-20201220204119183.png)

 如果是`char double short`那么第一个的size是24；如果是`char short double`那么size是16.因为内存区域的大小需要满足最大子单元内存大小的整数倍。比如16/8=2。内存的布局不是紧密的。

- 缺省对齐原则
  - 32位CPU
  - char 任何地址
  - short 偶数地址
  - int 4的整数倍地址
  - double 4的整数倍地址 

### 循环结构

- while 和 do while 和 for

```c++
//while
int sum = 0;
int index = 1;
while(index<=100) {
  sum += index;
  index++;
}
// do while
int sum = 0;
int index = 1;
do {
  sum+= index;
  index++;
} while(index<=100);
//for
for(int index=1; index<=100; index++) {
  sum += index;
}
```

### 函数

- 一个C++程序是由若干个源程序文件构成，而一个源程序是由若干个函数构成，函数将一段逻辑封装起来，便于复用；

- 函数分成：
  - 库函数：标准函数，由C++系统提供；比如`strcpy_s`等；
  - 用户自定义函数：需要用户定义后使用；比如：自定义的判断闰年函数isLeapYear；

- 函数的所有组成部分：
  - 返回类型：一个函数可以返回一个值
  - 函数名称：这是函数的实际名称，函数名和参数列表一起构成了函数签名
  - 参数：参数列表可以函数参数的类型、顺序、数量。参数是可选的，也就是说，函数可能不包含参数。
  - 函数主体：函数主体包含一组定义函数执行任务的语句

- 函数重载overload与C++ Name Mangling
  - int test(int a);
  - int test(double a);
  - int test(int a, double d);

- 内联函数 inline

如果一个函数是内联的，那么在编译的时候，编译器会把该函数的代码副本放置在每个调用该函数的地方。

```c++
inline int MaxValue(int x, int y)
{
  return (x > y) ? x : y;
}
```

引入内联函数的目的是为了解决程序中函数调用的效率问题。注：内联函数内部不能有太复杂的逻辑，编译器有时会有自己的优化策略，所以内联不一定起作用。

**就是把函数体中核心的代码copy到调用区从而较少了调用的时间，但是花费了更多的空间**

#### 指 向函数的指针与返回指针的函数

- 每一个函数都占用一段内存单元，他们有一个起始位置，指向函数入口地址的指针成为函数指针
- 一般形式：数据类型（*指针变量名）（参数表）
  - Int(*p)(int);

- 注意与返回指针的函数之间的区别：
  - int(*p)(int);  是指针，指向一个函数入口地址
  - Int* p(int);   是函数，返回的值是一个指针
  - bool ProcessNum(int i, int j, int(*p)(int a, int b));
    - int(*p)(int a, int b)) - 回调函数
  - char *strcpy(char *dest, const char *src)

```c++
int MaxValue(int x, int y);
int MinValue(int x, int y);
int AddValue(int x, int y);
bool op(int x, int y, int(*p)(int a, int b));
op(x, y, MaxValue);
op(x, y, MinValue);
op(x, y, AddValue);
```

### 命名空间

- 同一个班级，同一个公司，很容易出现同名的人；
- 命名空间这个概念，可作为附加信息来区分不同库中相同名称的函数、类、变量等，命名空间即定义了上下文。**本质上，命名空间就是定义了一个范围**。
- 关键词：using和namespace的使用。

### 递归

- 四个基本法则
  - 基准情形：无需递归就能解出
  - 不断推进：每一次递归调用都必须使求解状况朝着接近基准情形的方向推进
  - 设计法则：假设所有的递归调用都能运行
  - 合成效益法则：求解一个问题的同一个实例时，切勿在不同的递归调用中做重复性的工作

- 递归的缺陷
  - 空间上需要开辟大量的栈空间
  - 时间上可能需要大量的重复运算
- 递归的优化
  - 尾递归：所有递归形式的调用都出现在函数的末尾
  - 使用循环替代
  - 使用动态规划，空间换时间

#### 常规递归

```c++
int fib(int x) {
  if(x==0) return 0;
  else if(x==1) return 1;
  else return fib(x-1) + fib(x-2);
}

fib(5)
```

#### 循环

```c++
int fib(int x) {
  if(x<2) return x;
  int tmp;
  int a=0, b=1;
  for(int i = 2; i<=x; i++) {
    tmp = a;
    a = b;
    b = tmp+a;
  }
  return b;
}
```

#### 尾递归

**看编译器，有的编译不会做尾递归的优化**

```c++
int fib(int n, int ret0, int ret1) {
  if(n==0) return ret0;
  else if(n==1) return ret1;
  return fib(n-1, ret1, ret0+ret1); //编译器优化成了循环
}

fib(10, 0, 1)
```

#### 动态规划思路

```c++
int g_a[1000];
int fib(int n) {
	g_a[0] = 0;
  g_a[1] = 1;
  for(int i = 2; i<=n; i++) {
    if(g_a[i]==0) {
      g_a[i] = g_a[i-1] + g_a[i-2];
    }
  }
  return g_a[n];
}
```

