# C++ 变量和数据类型 (Variables and Data Types)

## 变量 (Variables)

变量是程序中用来存储数据的命名内存位置。

### 变量声明和初始化
```cpp
// 声明变量
int age;
double price;
char grade;

// 初始化变量
int count = 0;
double pi = 3.14159;
char letter = 'A';

// C++11 统一初始化
int x{10};
double y{3.14};
```

## 基本数据类型 (Basic Data Types)

### 整数类型 (Integer Types)
- `int`: 整数 (通常 4 字节)
- `short`: 短整数 (通常 2 字节)
- `long`: 长整数 (通常 4 或 8 字节)
- `long long`: 超长整数 (至少 8 字节)

```cpp
int score = 100;
short year = 2024;
long population = 1000000L;
long long bigNumber = 9223372036854775807LL;
```

### 浮点类型 (Floating-Point Types)
- `float`: 单精度浮点数 (4 字节)
- `double`: 双精度浮点数 (8 字节)
- `long double`: 扩展精度浮点数

```cpp
float temperature = 36.5f;
double distance = 384400.0;
long double precision = 3.14159265358979323846L;
```

### 字符类型 (Character Types)
- `char`: 单个字符 (1 字节)
- `wchar_t`: 宽字符
- `char16_t`: UTF-16 字符
- `char32_t`: UTF-32 字符

```cpp
char initial = 'J';
char newline = '\n';
char tab = '\t';
```

### 布尔类型 (Boolean Type)
- `bool`: 布尔值 (true 或 false)

```cpp
bool isValid = true;
bool hasError = false;
```

## 常量 (Constants)

### const 关键字
```cpp
const double PI = 3.14159;
const int MAX_SIZE = 100;
```

### constexpr (编译时常量)
```cpp
constexpr int BUFFER_SIZE = 1024;
constexpr double E = 2.71828;
```

## 类型转换 (Type Conversion)

### 隐式转换
```cpp
int i = 10;
double d = i;  // int 自动转换为 double
```

### 显式转换 (类型转换)
```cpp
double pi = 3.14159;
int truncated = (int)pi;  // C 风格转换
int truncated2 = int(pi);  // 函数风格转换
int truncated3 = static_cast<int>(pi);  // C++ 风格转换 (推荐)
```

## 示例程序

```cpp
#include <iostream>
using namespace std;

int main() {
    // 变量声明和初始化
    int age = 25;
    double height = 1.75;
    char grade = 'A';
    bool isStudent = true;
    
    // 常量
    const double PI = 3.14159;
    
    // 输出
    cout << "年龄: " << age << endl;
    cout << "身高: " << height << " 米" << endl;
    cout << "等级: " << grade << endl;
    cout << "是学生: " << (isStudent ? "是" : "否") << endl;
    cout << "PI 值: " << PI << endl;
    
    return 0;
}
```

## 练习题

1. 声明一个整数变量存储你的出生年份
2. 声明一个浮点数变量存储你的体重(公斤)
3. 创建一个常量表示一周的天数
4. 练习不同数据类型之间的转换
