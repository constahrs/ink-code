# C++ 控制结构 (Control Structures)

## 条件语句 (Conditional Statements)

### if 语句

```cpp
int age = 18;

if (age >= 18) {
    cout << "成年人" << endl;
}
```

### if-else 语句

```cpp
int score = 75;

if (score >= 60) {
    cout << "及格" << endl;
} else {
    cout << "不及格" << endl;
}
```

### if-else if-else 语句

```cpp
int score = 85;

if (score >= 90) {
    cout << "优秀" << endl;
} else if (score >= 80) {
    cout << "良好" << endl;
} else if (score >= 70) {
    cout << "中等" << endl;
} else if (score >= 60) {
    cout << "及格" << endl;
} else {
    cout << "不及格" << endl;
}
```

### 嵌套 if 语句

```cpp
int age = 20;
bool hasLicense = true;

if (age >= 18) {
    if (hasLicense) {
        cout << "可以开车" << endl;
    } else {
        cout << "需要先获得驾照" << endl;
    }
} else {
    cout << "年龄不够" << endl;
}
```

## switch 语句

```cpp
int day = 3;

switch (day) {
    case 1:
        cout << "星期一" << endl;
        break;
    case 2:
        cout << "星期二" << endl;
        break;
    case 3:
        cout << "星期三" << endl;
        break;
    case 4:
        cout << "星期四" << endl;
        break;
    case 5:
        cout << "星期五" << endl;
        break;
    case 6:
        cout << "星期六" << endl;
        break;
    case 7:
        cout << "星期日" << endl;
        break;
    default:
        cout << "无效的天数" << endl;
}
```

### switch 没有 break 的情况

```cpp
char grade = 'B';

switch (grade) {
    case 'A':
    case 'B':
    case 'C':
        cout << "通过" << endl;
        break;
    case 'D':
    case 'F':
        cout << "失败" << endl;
        break;
    default:
        cout << "无效等级" << endl;
}
```

## 循环语句 (Loops)

### for 循环

```cpp
// 基本 for 循环
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
// 输出: 0 1 2 3 4

// 倒序循环
for (int i = 10; i > 0; i--) {
    cout << i << " ";
}
// 输出: 10 9 8 7 6 5 4 3 2 1

// 步长为 2
for (int i = 0; i <= 10; i += 2) {
    cout << i << " ";
}
// 输出: 0 2 4 6 8 10
```

### 嵌套 for 循环

```cpp
// 打印九九乘法表
for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= i; j++) {
        cout << j << "x" << i << "=" << (i*j) << "\t";
    }
    cout << endl;
}
```

### while 循环

```cpp
int count = 0;

while (count < 5) {
    cout << count << " ";
    count++;
}
// 输出: 0 1 2 3 4
```

### do-while 循环

```cpp
int number;

do {
    cout << "请输入一个正数 (0 退出): ";
    cin >> number;
} while (number != 0);
```

### 范围 for 循环 (C++11)

```cpp
int numbers[] = {1, 2, 3, 4, 5};

for (int num : numbers) {
    cout << num << " ";
}
// 输出: 1 2 3 4 5
```

## 跳转语句 (Jump Statements)

### break 语句

```cpp
// 跳出循环
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // 当 i 等于 5 时跳出循环
    }
    cout << i << " ";
}
// 输出: 0 1 2 3 4
```

### continue 语句

```cpp
// 跳过当前迭代
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // 跳过偶数
    }
    cout << i << " ";
}
// 输出: 1 3 5 7 9
```

### goto 语句 (不推荐使用)

```cpp
int x = 0;

start:
    x++;
    cout << x << " ";
    if (x < 5) {
        goto start;
    }
```

## 示例程序

```cpp
#include <iostream>
using namespace std;

int main() {
    // 示例 1: 判断奇偶
    int num = 7;
    if (num % 2 == 0) {
        cout << num << " 是偶数" << endl;
    } else {
        cout << num << " 是奇数" << endl;
    }
    
    // 示例 2: 计算阶乘
    int n = 5;
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    cout << n << "! = " << factorial << endl;
    
    // 示例 3: 找最大值
    int arr[] = {23, 45, 12, 67, 34};
    int max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "最大值: " << max << endl;
    
    // 示例 4: 打印星号三角形
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
```

## 练习题

1. 编写程序判断一个年份是否为闰年
2. 使用循环计算 1 到 100 的和
3. 编写程序找出 1 到 100 之间的所有素数
4. 使用嵌套循环打印菱形图案
5. 编写猜数字游戏(给出提示"太大"或"太小")
