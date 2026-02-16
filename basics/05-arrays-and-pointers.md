# C++ 数组和指针 (Arrays and Pointers)

## 数组 (Arrays)

数组是存储相同类型元素的连续内存块。

### 一维数组

```cpp
// 声明和初始化
int numbers[5];  // 声明 5 个整数的数组

// 初始化
int scores[5] = {90, 85, 88, 92, 95};

// 部分初始化 (其余元素为 0)
int data[10] = {1, 2, 3};

// 自动确定大小
int values[] = {10, 20, 30, 40, 50};

// 访问元素
cout << scores[0] << endl;  // 90 (第一个元素)
cout << scores[4] << endl;  // 95 (最后一个元素)

// 修改元素
scores[2] = 100;
```

### 遍历数组

```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = 5;

// 使用 for 循环
for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}

// 使用范围 for (C++11)
for (int num : arr) {
    cout << num << " ";
}
```

### 二维数组

```cpp
// 声明和初始化
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// 访问元素
cout << matrix[1][2] << endl;  // 7

// 遍历二维数组
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

### 数组作为函数参数

```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    printArray(numbers, 5);
    return 0;
}
```

## 指针 (Pointers)

指针是存储变量内存地址的变量。

### 指针基础

```cpp
int x = 10;
int *ptr;  // 声明整数指针

ptr = &x;  // ptr 指向 x 的地址

cout << "x 的值: " << x << endl;           // 10
cout << "x 的地址: " << &x << endl;        // 内存地址
cout << "ptr 的值: " << ptr << endl;       // x 的地址
cout << "ptr 指向的值: " << *ptr << endl;  // 10 (解引用)

// 修改指针指向的值
*ptr = 20;
cout << "x 的新值: " << x << endl;  // 20
```

### 空指针

```cpp
int *ptr = nullptr;  // C++11 空指针
// int *ptr = NULL;  // C 风格空指针

if (ptr == nullptr) {
    cout << "指针为空" << endl;
}
```

### 指针和数组

```cpp
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;  // 数组名是指向第一个元素的指针

// 使用指针访问数组
cout << *ptr << endl;      // 10 (第一个元素)
cout << *(ptr + 1) << endl;  // 20 (第二个元素)
cout << *(ptr + 2) << endl;  // 30 (第三个元素)

// 指针算术
ptr++;  // 指向下一个元素
cout << *ptr << endl;  // 20
```

### 指针和函数

```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "交换前: x=" << x << ", y=" << y << endl;
    swap(&x, &y);
    cout << "交换后: x=" << x << ", y=" << y << endl;
    return 0;
}
```

### 动态内存分配

```cpp
// 单个变量
int *ptr = new int;
*ptr = 42;
cout << *ptr << endl;
delete ptr;  // 释放内存

// 数组
int size = 5;
int *arr = new int[size];
for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
}
// 使用数组...
delete[] arr;  // 释放数组内存
```

### 指针的指针

```cpp
int x = 10;
int *ptr1 = &x;
int **ptr2 = &ptr1;  // 指向指针的指针

cout << x << endl;         // 10
cout << *ptr1 << endl;     // 10
cout << **ptr2 << endl;    // 10
```

## 字符数组和字符串

```cpp
// C 风格字符串
char str1[20] = "Hello";
char str2[] = "World";

// 字符串操作
#include <cstring>

strlen(str1);           // 字符串长度
strcpy(str1, str2);     // 复制字符串
strcat(str1, str2);     // 连接字符串
strcmp(str1, str2);     // 比较字符串

// C++ string 类 (推荐)
#include <string>
string s1 = "Hello";
string s2 = "World";
string s3 = s1 + " " + s2;  // "Hello World"
cout << s3.length() << endl;
```

## 常见数组算法

```cpp
#include <iostream>
using namespace std;

// 线性搜索
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // 返回索引
        }
    }
    return -1;  // 未找到
}

// 冒泡排序
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 数组反转
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
```

## 示例程序

```cpp
#include <iostream>
using namespace std;

int main() {
    // 数组示例
    int scores[] = {85, 92, 78, 95, 88};
    int size = 5;
    
    // 计算平均分
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    double average = static_cast<double>(sum) / size;
    cout << "平均分: " << average << endl;
    
    // 指针示例
    int x = 100;
    int *ptr = &x;
    cout << "x 的值: " << x << endl;
    cout << "x 的地址: " << ptr << endl;
    cout << "通过指针访问: " << *ptr << endl;
    
    // 动态数组
    int n = 3;
    int *dynArr = new int[n];
    for (int i = 0; i < n; i++) {
        dynArr[i] = (i + 1) * 10;
    }
    
    cout << "动态数组: ";
    for (int i = 0; i < n; i++) {
        cout << dynArr[i] << " ";
    }
    cout << endl;
    
    delete[] dynArr;  // 释放内存
    
    return 0;
}
```

## 练习题

1. 编写函数找出数组中的最大值和最小值
2. 实现选择排序算法
3. 编写函数删除数组中的重复元素
4. 使用指针实现字符串反转
5. 编写二维数组的矩阵转置函数
