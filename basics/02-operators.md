# C++ 运算符 (Operators)

## 算术运算符 (Arithmetic Operators)

```cpp
int a = 10, b = 3;

// 加法
int sum = a + b;         // 13

// 减法
int diff = a - b;        // 7

// 乘法
int product = a * b;     // 30

// 除法
int quotient = a / b;    // 3 (整数除法)
double result = 10.0 / 3.0;  // 3.333...

// 取模 (余数)
int remainder = a % b;   // 1

// 自增和自减
int x = 5;
x++;  // 后缀自增: x = 6
++x;  // 前缀自增: x = 7
x--;  // 后缀自减: x = 6
--x;  // 前缀自减: x = 5
```

## 赋值运算符 (Assignment Operators)

```cpp
int x = 10;

x += 5;   // x = x + 5;   x = 15
x -= 3;   // x = x - 3;   x = 12
x *= 2;   // x = x * 2;   x = 24
x /= 4;   // x = x / 4;   x = 6
x %= 4;   // x = x % 4;   x = 2
```

## 比较运算符 (Comparison Operators)

```cpp
int a = 10, b = 20;

a == b;   // 等于: false
a != b;   // 不等于: true
a > b;    // 大于: false
a < b;    // 小于: true
a >= b;   // 大于等于: false
a <= b;   // 小于等于: true
```

## 逻辑运算符 (Logical Operators)

```cpp
bool x = true, y = false;

// 逻辑与 (AND)
x && y;   // false (两个都为 true 时才为 true)

// 逻辑或 (OR)
x || y;   // true (至少一个为 true 就为 true)

// 逻辑非 (NOT)
!x;       // false (取反)
!y;       // true
```

## 位运算符 (Bitwise Operators)

```cpp
int a = 5;  // 二进制: 0101
int b = 3;  // 二进制: 0011

a & b;   // 按位与: 1 (0001)
a | b;   // 按位或: 7 (0111)
a ^ b;   // 按位异或: 6 (0110)
~a;      // 按位取反: -6
a << 1;  // 左移: 10 (1010)
a >> 1;  // 右移: 2 (0010)
```

## 条件运算符 (三元运算符)

```cpp
int a = 10, b = 20;

// 语法: condition ? value_if_true : value_if_false
int max = (a > b) ? a : b;  // max = 20

string result = (a == b) ? "相等" : "不相等";
```

## 运算符优先级

从高到低:
1. 括号 `()`
2. 一元运算符 `++`, `--`, `!`, `~`
3. 乘法、除法、取模 `*`, `/`, `%`
4. 加法、减法 `+`, `-`
5. 位移 `<<`, `>>`
6. 比较 `<`, `<=`, `>`, `>=`
7. 相等 `==`, `!=`
8. 按位与 `&`
9. 按位异或 `^`
10. 按位或 `|`
11. 逻辑与 `&&`
12. 逻辑或 `||`
13. 条件 `?:`
14. 赋值 `=`, `+=`, `-=`, 等

## 示例程序

```cpp
#include <iostream>
using namespace std;

int main() {
    // 算术运算
    int a = 15, b = 4;
    cout << "加法: " << (a + b) << endl;
    cout << "减法: " << (a - b) << endl;
    cout << "乘法: " << (a * b) << endl;
    cout << "除法: " << (a / b) << endl;
    cout << "取模: " << (a % b) << endl;
    
    // 比较运算
    cout << "\n比较运算:" << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a == b: " << (a == b) << endl;
    
    // 逻辑运算
    bool x = true, y = false;
    cout << "\n逻辑运算:" << endl;
    cout << "x && y: " << (x && y) << endl;
    cout << "x || y: " << (x || y) << endl;
    cout << "!x: " << (!x) << endl;
    
    // 三元运算符
    int max = (a > b) ? a : b;
    cout << "\n最大值: " << max << endl;
    
    return 0;
}
```

## 练习题

1. 编写程序计算两个数的平均值
2. 使用三元运算符判断一个数是奇数还是偶数
3. 编写程序交换两个变量的值(使用临时变量和不使用临时变量两种方法)
4. 使用位运算符检查一个数是否为2的幂
