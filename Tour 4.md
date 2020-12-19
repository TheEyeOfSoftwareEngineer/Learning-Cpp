## Tour 4

### CPP存储区域的划分

```c++
int a = 0;                  //(GVAR)全局初始化区
int* p1;                    //(bss)全局未初始化区

int main() {                //text代码区
  int b = 1;                //(stack)栈区变量
  char s[] = "abc";         //(stack)栈区变量
  int* p2 = NULL;           //(stack)栈区变量
  char* p3 = "123456";      //123456\0在常量区，p3在stack栈区
  static int c = 0;         //(GVAR)全局（静态）初始化区
  p1 = new int(10);         //heap堆区变量
  p2 = new int(20);         //heap堆区变量
  chae* p4 = new char[7];   //heap堆区变量
  strcpy_s(p4, 7, "123456");  //text代码区
  
  return 0; 
}
```

```c++
char* p3 = "123456";
//该指针指向的区域是常量区，是无法改变的；如果其指向一个数组，其存储在栈区，那么是可以改变的
```

![image-20201219184306775](/Users/yao/Library/Application%20Support/typora-user-images/image-20201219184306775.png)

### 堆heap

#### 动态分配资源-heap

### RAII

- 依托栈和析构函数，来对所有的资源-包括堆内存在内进行管理。
- 代表：智能指针`std::auto_ptr`和`boost:shared_ptr`

 ### Summary

- 堆和栈中的变量对比

|                | stack区            | heap区                                              |
| -------------- | ------------------ | --------------------------------------------------- |
| scope          | 函数体内，语句块{} | 整个程序范围内，有new，malloc开始，delete，free结束 |
| 编译间大小确定 | 变量大小范围确定   | 变量大小范围不确定，需要运行期确定                  |
| 大小范围       | 各系统不同         | 堆控件上限是接近内存的总大小的                      |
| 内存分配方式   | 地址由高到底减少   | 地址由低到高增加                                    |
| 内容是否可变   | 可变               | 可变                                                |

- 全局静态存储区和常量存储区的变量对比

|                      | 全局静态存储区     | 常量存储区 |
| -------------------- | ------------------ | ---------- |
| 存储内容             | 全局变量，静态变量 | 常量       |
| 编译期间大小是否确定 | 确定               | 确定       |
| 内容可变性           | 可变               | 不可变     |

### C++的引用

- 是一种特殊的指针，不允许修改的指针
  - 不存在空引用
  - 必须初始化
  - 一个引用永远指向它初始化的那个对象

#### 基本使用

可以认为是指定变量的别名

```c++
int x1 = 1, x2 = 3;
int& rx = x;
rx = 2;
cout << x1 << endl;  // 2
cout << rx << endl;  // 2
rx = x2;
cout << x1 << endl;  // 3
cout << rx << endl;  // 3
```

```c++
//值交换
//method1
void swap(int& a, int&b) {
  
}
swap(a, b);
//method2
swap(&a, &b);
void swap(int* a, int* b) {
  
}
```

 