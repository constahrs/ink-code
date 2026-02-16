# 简单计算器项目

这是一个基于控制台的简单计算器程序,支持基本的算术运算。

## 功能特性

- 加法、减法、乘法、除法
- 支持小数运算
- 错误处理(除零错误)
- 用户友好的界面
- 持续运算模式

## 代码实现

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Calculator {
public:
    // 加法
    double add(double a, double b) {
        return a + b;
    }
    
    // 减法
    double subtract(double a, double b) {
        return a - b;
    }
    
    // 乘法
    double multiply(double a, double b) {
        return a * b;
    }
    
    // 除法
    double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("错误: 除数不能为零!");
        }
        return a / b;
    }
    
    // 显示菜单
    void displayMenu() {
        cout << "\n========== 简单计算器 ==========" << endl;
        cout << "1. 加法 (+)" << endl;
        cout << "2. 减法 (-)" << endl;
        cout << "3. 乘法 (*)" << endl;
        cout << "4. 除法 (/)" << endl;
        cout << "5. 退出" << endl;
        cout << "===============================" << endl;
        cout << "请选择操作 (1-5): ";
    }
    
    // 执行计算
    void calculate() {
        int choice;
        double num1, num2, result;
        
        while (true) {
            displayMenu();
            cin >> choice;
            
            if (choice == 5) {
                cout << "感谢使用计算器!再见!" << endl;
                break;
            }
            
            if (choice < 1 || choice > 5) {
                cout << "无效的选择!请重试。" << endl;
                continue;
            }
            
            cout << "请输入第一个数: ";
            cin >> num1;
            cout << "请输入第二个数: ";
            cin >> num2;
            
            try {
                switch (choice) {
                    case 1:
                        result = add(num1, num2);
                        cout << fixed << setprecision(2);
                        cout << num1 << " + " << num2 << " = " << result << endl;
                        break;
                    case 2:
                        result = subtract(num1, num2);
                        cout << fixed << setprecision(2);
                        cout << num1 << " - " << num2 << " = " << result << endl;
                        break;
                    case 3:
                        result = multiply(num1, num2);
                        cout << fixed << setprecision(2);
                        cout << num1 << " * " << num2 << " = " << result << endl;
                        break;
                    case 4:
                        result = divide(num1, num2);
                        cout << fixed << setprecision(2);
                        cout << num1 << " / " << num2 << " = " << result << endl;
                        break;
                }
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
    }
};

int main() {
    Calculator calc;
    calc.calculate();
    return 0;
}
```

## 如何运行

### 编译
```bash
g++ -o calculator calculator.cpp
```

### 运行
```bash
./calculator
```

## 示例输出

```
========== 简单计算器 ==========
1. 加法 (+)
2. 减法 (-)
3. 乘法 (*)
4. 除法 (/)
5. 退出
===============================
请选择操作 (1-5): 1
请输入第一个数: 10.5
请输入第二个数: 5.3
10.50 + 5.30 = 15.80

========== 简单计算器 ==========
1. 加法 (+)
2. 减法 (-)
3. 乘法 (*)
4. 除法 (/)
5. 退出
===============================
请选择操作 (1-5): 4
请输入第一个数: 20
请输入第二个数: 0
错误: 除数不能为零!
```

## 扩展功能建议

1. 添加更多运算:
   - 幂运算
   - 平方根
   - 百分比计算
   - 三角函数

2. 添加历史记录功能

3. 支持科学计数法

4. 添加内存功能 (M+, M-, MR, MC)

5. 实现表达式求值(例如: "2 + 3 * 4")

## 学习要点

- 类的设计和使用
- 函数的定义和调用
- 异常处理 (try-catch)
- 用户输入验证
- 循环和条件语句
- 格式化输出 (setprecision)
