## Tour 6

### STL

#### STL标准库六大组件

- 空间适配器
  - allocator
- 容器
  - string
  - vector
  - list
  - deque
  - map
  - set
  - multimap
  - multiset
- 适配器
  - stack
  - queue
  - priority_queue
- 仿函数
  - greater
  - less
  - ...
- 算法
  - find
  - swap
  - reverse
  - sort
  - merge
  - ...
- 迭代器
  - iterator
  - const_iterator
  - reverse_iterator
  - const_reverse_iterator

![image-20201221155457320](/Users/yao/Library/Application%20Support/typora-user-images/image-20201221155457320.png)

#### 容器container

- 容器用于存放数据
- 序列式容器（sequence containers）
  - 其中的元素都是可排序的；STL提供了vector，list，deque等序列式容器，而stack，queue，priority_queue则是容器适配器
- 关联式容器（Associative Containers）
  - 每个数据元素都是一个键key和值value组成。当元素被插入到容器时，按其键以某种特定规则放入适当位置；常见的STL关联容器如：set, multiset, map, multimap

##### 序列式容器的使用

```c++
#include<vector>
#include<list>
#include<queue>
#include<iostream>
#include<stack>

using namespace std;

struct Display {     //函数类
  void operator()(int i) {
    cout << i << " ";
  }
};

int main() {
  
  //init
  int iArr[] = {1,2,3,4,5};
  vector<int> iVector(iArr, iArr+4);
  list<int> iList(iArr, iArr+4); //底层是双向链表
  deque<int> iDeque(iArr, iArr+4);
  queue<int> iQueue(iDeque);   //queue和stack底层实现是deque 双向队列
  stack<int> iStack(iDeque);
  priority_queue<int> iPQueue(iArr, iArr+4);

  //iteration
  for_each(iVector.begin(), iVector.end(), Display());
  for_each(iList.begin(), iList.end(), Display());
  for_each(iDeque.begin(), iDeque.end(), Display());
  
  while(!iQueue.empty()) {
    cout << iQueue.front() << " ";
    iQueue.pop();
  }
  
  while(!iStack.empty()) {
    cout << iStack.top() << " ";
    iStack.pop();
  }
  
  while(!iPQueue.empty()) {
    cout << iPQueue.top() << " ";
    iPQueue.pop();
  }
  
  return 0;
}
```

##### 关联式容器的使用

```c++
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct Display {
  void operator()(pair<string, double> info) {
    cout << info.first << " " << info.second << endl;
  }
};


struct StuScore {
  string name;
  double score;
};

int main() {

  //init
  map<string, double> studentScore;
  studentScore["liming"] = 95.0;
  studentScore["lihong"] = 98.0;
  studentScore.insert(pair<string, double>("zhangsan", 100.0));
  studentScore.insert(pair<string, double>("lisi", 98.6));
  studentScore.insert(pair<string, double>("wangwu", 80.4));
  studentScore.insert(pair<string, double>("wangwu", 97.2)); // 同key插入是无效的
  studentScore["wangwu"] = 98.0;  // 修改是有效的
  studentScore.insert(map<string, double>::value_type("xiaoming", 87.6));

  //iteration
  for_each(studentScore.begin(), studentScore.end(), Display());

  //find
  //studentScore.find("wangwu") //返回的是一个指针
  map<string, double>::iterator iter;
  iter = studentScore.find("wangwu"); //返回的是一个指针
  if(iter != studentScore.end()) {
    cout << iter->second <<  " " << iter->first << endl; //pair指针 用->取值
  } else {
    //
  }
  cout << endl;
  
  // 使用迭代器完成遍历查找的过程 version 0.1 有问题
  // iter = studentScore.begin();
  // while(iter != studentScore.end()) {
  //   if(iter->second < 95.0) {
  //     studentScore.erase(iter); // 删除操作 迭代器失效
  //   } else {
  //     iter ++;
  //   }
  // }
  // for_each(studentScore.begin(), studentScore.end(), Display());

  // 使用迭代器完成遍历查找的过程 version 0.2 
  iter = studentScore.begin();
  while(iter != studentScore.end()) {
    if(iter->second < 95.0) {
      studentScore.erase(iter++); // 删除操作
    } else {
      iter ++;
    }
  }
  for_each(studentScore.begin(), studentScore.end(), Display());
  cout << endl;

  // for循环
  for(iter = studentScore.begin(); iter != studentScore.end(); iter++) {
    if(iter->second < 98.0) {
      iter = studentScore.erase(iter); // 迭代器失效以后会返回下一个迭代器的值，相当于传递了下一个指针的位置
    }
  }
  for_each(studentScore.begin(), studentScore.end(), Display());
  cout << endl;
  //vector<StuScore> studentScore2;
  //studentScore2.push_back(StuScore())

  // find并删除该元素
  iter = studentScore.find("lihong");
  studentScore.erase(iter);
  for_each(studentScore.begin(), studentScore.end(), Display());
  cout << endl;

  int rtn = studentScore.erase("lisi"); //取出的计数值 返回删除的元素个数 1-删除了 0-没有删除
  cout << rtn << endl;

  //删除范围
  studentScore.erase(studentScore.begin(), studentScore.end());
  for_each(studentScore.begin(), studentScore.end(), Display());
  cout << endl;
  
  return 0;
}
```

#### 仿函数functor

- 一般不会单独使用，主要是为了搭配STL算法使用
- 函数指针不能满足STL对抽象性的要求，不嫩刚去忙那住软件积木的要求，无法与STL其他组件搭配
- 本质就是类重载了一个operator()，创建一个行为类似函数的对象

```c++
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool MySort(int a, int b) {
  return a < b;
}

struct Display {
  void operator()(int x) {
    cout << x <<  " ";
  }
};

template<class T>
inline bool MySortT(T const& a, T const& b) {
  return a < b;
}

template<class T>
struct DisplayT {
  void operator()(T const& x) {
    cout << x <<  " ";
  }
};

struct SortF {
  bool operator()(int a, int b) {
    return a < b;
  }
};

struct DisplayF {
  void operator()(int x) {
    cout << x <<  " ";
  }
};

// C++仿函数模板
template<class T>
struct SortFT {
  inline bool operator()(T const& a, T const& b) {
    return a < b;
  }
};

template<class T>
struct DisplayFT {
  inline void operator()(T const& x) {
    cout << x <<  " ";
  }
};

int main() {

  //C++
  // int arr[] = {4,3,2,1,7};
  // for_each(arr, arr+5, Display());
  // cout << endl;
  // sort(arr, arr+5, MySort);
  // for_each(arr, arr+5, Display());

  //C++泛型
  int arr[] = {4,3,2,1,7};
  for_each(arr, arr+5, Display());
  cout << endl;
  sort(arr, arr+5, MySortT<int>);
  for_each(arr, arr+5, DisplayT<int>());
  cout << endl;

  //C++仿函数

  int arr2[] = {4,3,2,1,7};
  for_each(arr2, arr2+5, DisplayF());
  cout << endl;
  sort(arr2, arr2+5, SortF());
  for_each(arr2, arr2+5, DisplayF());
  cout << endl;

  //C++仿函数模板
  int arr3[] = {4,3,2,1,7};
  for_each(arr3, arr3+5, DisplayFT<int>());
  cout << endl;
  sort(arr3, arr3+5, SortFT<int>());
  for_each(arr3, arr3+5, DisplayFT<int>());
  cout << endl;

  return 0;
}
```

#### 算法algorithm

STL算法大致分为4类包含于<algorithm>, <numeric>, <functional>

- 非可变序列算法；指不直接修改其操作的容器内容的算法
- 可变序列算法：值可以修改它们所操作的容器内容的算法
- 排序算法：包括对序列进行排序和合并的算法、搜索算法以及有序序列上的集合操作
- 数值算法：对容器内容进行数值计算
- 最常见的算法：查找，排序和通用算法，排列组合算法，数值算法，集合算法等算法

##### 查找 排序等

```c++
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

  int ones[] = {1,2,3,4,5};
  int twos[] = {10,20,30,40,50};
  int results[5];

  transform(ones, ones+5, twos, results, std::plus<int>()); 
  for_each(results, results+5, [](int a) -> void {  
    cout << a << endl;
  });  // 第三部分是C++中lambda函数的写法
  // []中是外部传入的参数 （）内是函数主体部门的参数
  // 11 22 33 44 55
  cout << endl;

  //find
  int arr[] = {0,1,2,3,4,4,5,6,6,7,7,7,8};

  cout << count(arr, arr+sizeof(arr)/sizeof(arr[0]), 7); //统计7的个数
  cout << endl;
  cout << count(arr, arr+sizeof(arr)/sizeof(arr[0]), 6); //统计6的个数
  cout << endl;

  cout << count_if(arr, arr+sizeof(arr)/sizeof(arr[0]), bind2nd(less<int>(), 7)); //统计小于7的个数 2nd参数在函数右侧 
  cout << endl;
  cout << count_if(arr, arr+sizeof(arr)/sizeof(arr[0]), bind1st(less<int>(), 7));
  //统计大于7的个数 1st参数在函数左侧 
  cout << endl;

  //二分查找 有序序列
  cout << binary_search(arr, arr+sizeof(arr)/sizeof(arr[0]), 9) << endl;//能找到1不能0

  vector<int> iA(arr+2, arr+6);
  cout << *search(arr, arr+sizeof(arr)/sizeof(arr[0]), iA.begin(), iA.end()) << endl; //取子序列第一个元素出现的位置

  vector<int> iB;
  iB.push_back(10);
  iB.push_back(9);

  cout << *search(arr, arr+sizeof(arr)/sizeof(arr[0]), iB.begin(), iB.end());

  return 0;
}
```

##### 排列组合

```c++
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

void swap(char* a, char* b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void Permutation(char* pStr, char* pPosition) {

  //基准点
  if(*pPosition == '\0') {
    cout << pStr << endl;
  }
  else {
    for(char* pChar = pPosition; *pChar != '\0'; pChar++) {
      //依次和后面的字符交换
      cout << *pChar << " " << *pPosition << " exchange" << endl;
      swap(*pChar, *pPosition);
      Permutation(pStr, pPosition+1);
      //换回来
      swap(*pChar, *pPosition);
    }
  }

}

int main() {

  char test[] = "123";
  Permutation(test, test);
  cout << endl;
  
  return 0;
}
```

```c++
//使用next_permutation
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

  char test[] = "123";
  
  do {
    cout << test[0] << test[1] << test[2] << endl;
  } while(next_permutation(test, test+3)); //需要保证从小到大的排列顺序

  char test[] = "321";
  
  do {
    cout << test[0] << test[1] << test[2] << endl;
  } while(prev_permutation(test, test+3)); //需要保证从大到小的排列顺序
  
  return 0;
}
```

#### 迭代器iterator

- 是一种smart pointer，用于访问顺序容器和关联容器中的元素，相当于容器和操纵容器的算法之间的中介
- 按照定义迭代器分成以下四种
  - 正向迭代器：iterator
  - 常量正向迭代器：const_iterator //不会修改里面的值
  - 反向迭代器：reverse_iterator
  - 常量反向迭代器：const_reverse_iterator

##### 容器与迭代器

| 容器           | 迭代器功能   |
| -------------- | ------------ |
| vector         | 随机访问     |
| deque          | 随机访问     |
| list           | 双向访问     |
| set/multiset   | 双向访问     |
| map/multimap   | 双向访问     |
| stack          | 不支持迭代器 |
| queue          | 不支持迭代器 |
| priority_queue | 不支持迭代器 |

```c++
#include <iostream>
#include <list>

using namespace std;

int main() {

  list<int> v;

  v.push_back(3);
  v.push_back(4);
  v.push_front(2);
  v.push_front(1); // 1 2 3 4

  list<int>::const_iterator it;
  for(it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  } 
  cout << endl;

  list<int>::iterator it2;
  for(it2 = v.begin(); it2 != v.end(); it2++) {
    *it2 += 1;
    cout << *it2 << endl;
  }
  cout << endl;

  cout << v.front() << endl;
  v.pop_front();

  cout << v.back() << endl;
  v.pop_back();

  list<int>::reverse_iterator it3;
  for(it3 = v.rbegin(); it3 != v.rend(); it3++) {
    *it3 += 1;
    cout << *it3 << " ";
  }
  cout << endl;
  return 0;
}
```





