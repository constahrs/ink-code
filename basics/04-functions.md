# C++ 函数 (Functions)

## 函数基础

函数是执行特定任务的代码块。

### 函数语法

```cpp
返回类型 函数名(参数列表) {
    // 函数体
    return 返回值;
}
```

### 简单函数示例

```cpp
// 无参数，无返回值
void sayHello() {
    cout << "Hello, World!" << endl;
}

// 有参数，有返回值
int add(int a, int b) {
    return a + b;
}

// 使用函数
int main() {
    sayHello();
    int sum = add(5, 3);
    cout << "和: " << sum << endl;
    return 0;
}
```

## 函数参数

### 值传递 (Pass by Value)

```cpp
void increment(int x) {
    x++;  // 只修改副本
}

int main() {
    int num = 5;
    increment(num);
    cout << num << endl;  // 输出: 5 (未改变)
    return 0;
}
```

### 引用传递 (Pass by Reference)

```cpp
void increment(int &x) {
    x++;  // 修改原始值
}

int main() {
    int num = 5;
    increment(num);
    cout << num << endl;  // 输出: 6 (已改变)
    return 0;
}
```

### 指针传递 (Pass by Pointer)

```cpp
void increment(int *x) {
    (*x)++;  // 通过指针修改值
}

int main() {
    int num = 5;
    increment(&num);
    cout << num << endl;  // 输出: 6
    return 0;
}
```

### 常量参数

```cpp
void printValue(const int &x) {
    cout << x << endl;
    // x = 10;  // 错误: 不能修改 const 参数
}
```

## 默认参数

```cpp
int power(int base, int exponent = 2) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    cout << power(3) << endl;      // 9 (3^2)
    cout << power(3, 3) << endl;   // 27 (3^3)
    return 0;
}
```

## 函数重载 (Function Overloading)

```cpp
// 不同参数个数
int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

// 不同参数类型
double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(1, 2) << endl;        // 3
    cout << add(1, 2, 3) << endl;     // 6
    cout << add(1.5, 2.5) << endl;    // 4.0
    return 0;
}
```

## 递归函数 (Recursive Functions)

```cpp
// 计算阶乘
int factorial(int n) {
    if (n <= 1) {
        return 1;  // 基本情况
    }
    return n * factorial(n - 1);  // 递归情况
}

// 斐波那契数列
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "5! = " << factorial(5) << endl;        // 120
    cout << "fib(7) = " << fibonacci(7) << endl;    // 13
    return 0;
}
```

## 内联函数 (Inline Functions)

```cpp
inline int square(int x) {
    return x * x;
}

// 内联函数建议编译器将函数代码内联到调用处
// 适用于小型、频繁调用的函数
```

## Lambda 表达式 (C++11)

```cpp
// 基本语法: [捕获列表](参数列表) -> 返回类型 { 函数体 }

auto add = [](int a, int b) -> int {
    return a + b;
};

cout << add(3, 4) << endl;  // 7

// 简化形式 (自动推断返回类型)
auto multiply = [](int a, int b) {
    return a * b;
};

// 捕获外部变量
int x = 10;
auto addX = [x](int a) {
    return a + x;
};
cout << addX(5) << endl;  // 15
```

## 函数指针

```cpp
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    // 声明函数指针
    int (*operation)(int, int);
    
    operation = add;
    cout << operation(5, 3) << endl;  // 8
    
    operation = subtract;
    cout << operation(5, 3) << endl;  // 2
    
    return 0;
}
```

## 示例程序

```cpp
#include <iostream>
using namespace std;

// 判断素数
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 交换两个数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 计算数组和
int arraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 查找最大值
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // 测试素数判断
    cout << "7 是素数? " << (isPrime(7) ? "是" : "否") << endl;
    
    // 测试交换
    int x = 5, y = 10;
    cout << "交换前: x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "交换后: x=" << x << ", y=" << y << endl;
    
    // 测试数组操作
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    cout << "数组和: " << arraySum(numbers, size) << endl;
    cout << "最大值: " << findMax(numbers, size) << endl;
    
    return 0;
}
```

## 练习题

1. 编写函数计算两个数的最大公约数(GCD)
2. 编写函数反转字符串
3. 编写递归函数计算 x 的 n 次方
4. 编写函数对数组进行冒泡排序
5. 编写函数判断一个字符串是否为回文
