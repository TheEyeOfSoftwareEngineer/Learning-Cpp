## Tour 2

### C++ basic container

#### Array

**概念**

- 代表内存里一组连续的同类型存储区
- 可以用来把多个存储区合并成一个整体

```c++
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8};
```

**数据声明**

- `int arr[10]`

- 类型名称int表示数组里所有元素的类型
- 名称arr是数组的名称
- 整数10表示数组里包含的元素个数
- 数组里元素个数不可以改变

**使用**

- 每个元素都有下标，通过下标可以直接访问任意一个元素
- 下标从0开始到元素个数减一为止
- 超过范围的下标不可以使用
- 数组名称和下标一起可以表示数组里的元素 arr[4]

**优点**

- 可以编写循环依次处理数组里所有的元素
- 循环变量依次代表所有有效下标

C语言中设计数组下标的原则：*从0开始，使用非对称区间*

- 让这个区间是一份非对称的区间 [ )
- 让下界（左侧）可以取到值，让上界（右侧）取不到值

这样设计的好处：

- 取值范围的大小：上界-下界
- 如果取值范围为空，上界=下界
- 即使赋值范围为空，上界永远不可能小于下界

##### 数组的增加

- 在数组尾部增加
  - 直接赋值（在合理的区间范围内）
- 在数组中插入
  - 原数组插入元素位置的元素从后向前不断用前面元素覆盖后面的元素，然后在插入元素处用新元素代替之前的元素；需要维护数组的capacity。

##### 数组的删除

- 删除数组尾部的元素
  - 直接用“\n”代替该尾部元素
- 删除数组中的元素
  - 原数组插入元素位置后一位的元素从前向后不断用后面元素覆盖前面的元素；需要维护数组的大小capacity。

##### 数组的访问

- 数组下标index方式访问：`a[2] = 5`;

- 指针方式访问：`int* p = a; *(p+2) = 5;`

##### 数组元素的查找

```c++
#include <iostream>

using namespace std;

int main() {
  int a[] = {1, 2, 3, 4};
  int len = sizeof(a) / sizeof(a[0]);
  for (int index = 0; index < len; ++i) {
    if(a[index] == 3) {
      cout << index << endl;
      return 0;
    }
  }
}
```

##### 二维数组

```c++
int main() {
  int a[2][4] = {
    {1,2,3,4},
    {5,6,7,8}
  };
  
  for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 4; ++col) {
      cout << a[row][col] << " ";
    }
    cout << endl;
  }
}
```

> 循环时尽可能满足“控件局限性”
>
> 1. 在一个小的时间窗口内，访问的变量地址越近越好，这样执行速度更快；
> 2. 也就是说：一般来说，需要将最长的循环放在最内层，最短的循环放在最外层，以减少CPU跨切循环层的次数。

#### Vector

> Dynamic Array， 面向对象方式的动态数组

使用最简单的数组，无法实现动态扩容插入元素，因为容量有限。

##### vector尾部添加

```c++
#include <vector>

using namespace std;
int main() {
	vector<int> vec = {1, 2, 3, 4};
	vec.push_back(5);  
}
```

##### vector的遍历操作

```c++
for (int index = 0; index < vec.size(); ++index) {
  cout << vec[index] << endl;
}
```

##### vector的插入操作

```c++
vec.insert(--ver.end(), 4);
// 该操作是在列表的最后一位前插入数字4
// vetor.insert(index, ele): index插入列表的位置，ele插入列表的元素
```

##### vector的删除操作

- `vec.pop_back()`

删除列表中的最后一个元素

- `vec.erase(vec.end()-1)`

erase对应的是删除指定位置的元素。**注意：vec.end()返回的位置是最后一个元素后。通过vec.end()-1来到了最后一个元素前面，然后erase删除掉这个元素。而insert是在这个元素前加上某个元素。**

#### Char & char array

**字符串变量**

- 字符串是以*空字符（'\0'）结束*的*字符数组*
- 空字符自动添加到字符串的内部表示中
- 在声明字符串变量时，*应该为这个空结束符预留一个额外元素的空间*。如`char strHelloWord[11] = {"HelloWorld"} //或者不写11而是空着`

**字符串常量**

- 字符串常量是一对双引号括起来的字符序列
- 字符串中每个字符作为一个数组元素存储 
- `"helloworld"`

 **字符串的指针表示方法**

- 指针表示方法

`char* pStrHelloWorld = "HelloWorld";`

- Char[]和char*的区别
  - 地址与地址存储的信息
  - 可变与不可变：指针指向的值是否可以改变取决于该值是否可以改变。如指向常量，那么就不能改变。

> `char strHelloWorld[11] = {"HelloWorld"};`
>
>   strHelloWorld不可变，strHelloWorld[index]的值可变；
>
> `char* pStrHelloWorld = "HelloWorld"；`
>
>   pStrHelloWorld可变，但是pStrHelloWorld[index]的值可变不可变取决于所指区间的存储区域是否可变。

 ##### 字符串长度

`strlen(s)`

##### 字符串比较

`strcmp(s1, s2)`

- 如果s1和s2是相同的，则返回0
- 如果s1<s2，则返回值小于0
- 如果s1>s2，则返回值大于0

两个字符串从左向右逐个字符比较，知道出现不同的字符或者遇到"\0"为止。例如"A"<"B"; "A"<"AB"; "Apple"<"Bananna"; "A"<"a"; "compare"<"computer";

##### 字符串拷贝

`strcpy(s1, s2)`

复制字符串s2到字符串s1;

##### 复制指定长度字符串

`strncpy(s1, s2, n)`

将字符串s2中前n个字符拷贝到s1中

##### 字符串拼接

`strcat(s1, s2)`

将字符串s2接到s1后面

##### 查找字符串

`strchr(s1, ch)`

指向字符串s1中字符ch的第一次出现的位置

##### 查找字符串

`strstr(s1, s2)`

指向字符串s1中字符串s2的第一次出现的位置

#### String

`#include<string>`

使用String可以更为方便和安全的管理字符串

```c++
#include<string>
using namespace std;

string s;
string s = "helloworld";
string s("helloworld");
string s = string("helloworld");
```

##### 获取字符串的长度

```c++
cout << s1.length() << endl;
cout << s1.size() << endl; // 和上面基本一样
cout << s1.capacity() << endl;
```

##### 字符串比较

==, !=, >, >=, <, <=

```c++
string s1 = "hello", s2 = " world!";
cout << (s1 == s2) << endl;
cout << (s1 != s2) << endl;
```

 ##### 转换成C风格的字符串

```c++
const char *c_str1 = s1.c_str();
cout << "The C-style string c_str1 is: " << c_str1 << endl;
```

##### 随机访问（获取字符串中某个字符）: []

```c++
string s = "hello";
s[0] = "h"; 
```

##### 字符串拷贝

```c++
string s1 = "hello";
string s2 = s1;
```

##### 字符串连接

+, +=

```c++
string s1 = "hello", s2 = " world!";
string s3 = s1 + s2;
s1 += s2;
```

