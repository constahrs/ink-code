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
            
            // 输入验证
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "无效的输入!请输入数字。" << endl;
                continue;
            }
            
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
