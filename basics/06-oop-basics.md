# C++ 面向对象编程基础 (Object-Oriented Programming Basics)

## 类和对象 (Classes and Objects)

### 类的定义

```cpp
class Student {
public:
    // 成员变量 (属性)
    string name;
    int age;
    double gpa;
    
    // 成员函数 (方法)
    void display() {
        cout << "姓名: " << name << endl;
        cout << "年龄: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};
```

### 创建对象

```cpp
int main() {
    // 创建对象
    Student s1;
    s1.name = "张三";
    s1.age = 20;
    s1.gpa = 3.8;
    
    // 调用方法
    s1.display();
    
    return 0;
}
```

## 构造函数和析构函数

### 构造函数

```cpp
class Student {
private:
    string name;
    int age;
    
public:
    // 默认构造函数
    Student() {
        name = "未知";
        age = 0;
    }
    
    // 参数化构造函数
    Student(string n, int a) {
        name = n;
        age = a;
    }
    
    // 使用初始化列表 (推荐)
    Student(string n, int a) : name(n), age(a) {
    }
    
    void display() {
        cout << "姓名: " << name << ", 年龄: " << age << endl;
    }
};

int main() {
    Student s1;                    // 调用默认构造函数
    Student s2("李四", 22);        // 调用参数化构造函数
    
    s1.display();
    s2.display();
    
    return 0;
}
```

### 析构函数

```cpp
class MyClass {
private:
    int *data;
    
public:
    MyClass() {
        data = new int[10];
        cout << "构造函数调用" << endl;
    }
    
    ~MyClass() {
        delete[] data;
        cout << "析构函数调用" << endl;
    }
};
```

## 访问修饰符

```cpp
class Person {
private:
    // 只能在类内部访问
    string socialSecurityNumber;
    
protected:
    // 可以在类内部和派生类中访问
    int employeeId;
    
public:
    // 可以从任何地方访问
    string name;
    
    void setSSN(string ssn) {
        socialSecurityNumber = ssn;
    }
    
    string getSSN() {
        return socialSecurityNumber;
    }
};
```

## 封装 (Encapsulation)

```cpp
class BankAccount {
private:
    double balance;
    string accountNumber;
    
public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }
    
    // Getter
    double getBalance() const {
        return balance;
    }
    
    string getAccountNumber() const {
        return accountNumber;
    }
    
    // Setter
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};
```

## 静态成员

```cpp
class Counter {
private:
    static int count;  // 静态成员变量
    
public:
    Counter() {
        count++;
    }
    
    static int getCount() {  // 静态成员函数
        return count;
    }
};

// 静态成员变量必须在类外初始化
int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    cout << "对象数量: " << Counter::getCount() << endl;  // 3
    return 0;
}
```

## 友元函数

```cpp
class Rectangle {
private:
    int width;
    int height;
    
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    
    // 声明友元函数
    friend int area(Rectangle r);
};

// 友元函数可以访问私有成员
int area(Rectangle r) {
    return r.width * r.height;
}

int main() {
    Rectangle rect(5, 4);
    cout << "面积: " << area(rect) << endl;  // 20
    return 0;
}
```

## this 指针

```cpp
class Point {
private:
    int x, y;
    
public:
    Point(int x, int y) {
        this->x = x;  // this 指向当前对象
        this->y = y;
    }
    
    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;  // 返回当前对象的引用
    }
    
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(0, 0);
    p.move(5, 3).move(2, 1);  // 链式调用
    p.display();  // (7, 4)
    return 0;
}
```

## 运算符重载

```cpp
class Complex {
private:
    double real;
    double imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // 重载 + 运算符
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // 重载 << 运算符 (友元函数)
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;
    cout << c3 << endl;  // 4 + 6i
    return 0;
}
```

## 继承 (Inheritance)

```cpp
// 基类
class Animal {
protected:
    string name;
    
public:
    Animal(string n) : name(n) {}
    
    void eat() {
        cout << name << " 正在吃东西" << endl;
    }
};

// 派生类
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, string b) : Animal(n), breed(b) {}
    
    void bark() {
        cout << name << " 正在叫: 汪汪!" << endl;
    }
    
    void showInfo() {
        cout << "名字: " << name << ", 品种: " << breed << endl;
    }
};

int main() {
    Dog dog("旺财", "金毛");
    dog.eat();      // 继承的方法
    dog.bark();     // 自己的方法
    dog.showInfo();
    return 0;
}
```

## 多态 (Polymorphism)

```cpp
class Shape {
public:
    virtual double area() = 0;  // 纯虚函数
    virtual void display() {
        cout << "这是一个形状" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    void display() override {
        cout << "圆形, 面积: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() override {
        return width * height;
    }
    
    void display() override {
        cout << "矩形, 面积: " << area() << endl;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
    }
    
    delete shapes[0];
    delete shapes[1];
    
    return 0;
}
```

## 示例程序: 学生管理系统

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string id;
    string name;
    double score;
    
public:
    Student(string id, string name, double score)
        : id(id), name(name), score(score) {}
    
    void display() const {
        cout << "学号: " << id 
             << ", 姓名: " << name 
             << ", 成绩: " << score << endl;
    }
    
    double getScore() const {
        return score;
    }
    
    string getName() const {
        return name;
    }
};

int main() {
    Student students[] = {
        Student("001", "张三", 85.5),
        Student("002", "李四", 92.0),
        Student("003", "王五", 78.5)
    };
    
    cout << "学生信息:" << endl;
    for (const auto& s : students) {
        s.display();
    }
    
    // 找最高分
    double maxScore = students[0].getScore();
    string topStudent = students[0].getName();
    
    for (const auto& s : students) {
        if (s.getScore() > maxScore) {
            maxScore = s.getScore();
            topStudent = s.getName();
        }
    }
    
    cout << "\n最高分学生: " << topStudent 
         << ", 分数: " << maxScore << endl;
    
    return 0;
}
```

## 练习题

1. 创建一个 Book 类,包含书名、作者、价格等属性
2. 实现一个 Rectangle 类,包含长、宽和计算面积、周长的方法
3. 创建一个继承体系: Vehicle -> Car, Motorcycle
4. 实现一个 Stack 类 (栈数据结构)
5. 创建一个简单的银行账户管理系统
