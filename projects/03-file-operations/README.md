# 文件操作项目

这是一个展示C++文件操作的项目,包括文本文件的读写和简单的笔记管理系统。

## 功能特性

- 创建和写入文件
- 读取文件内容
- 追加内容到文件
- 复制文件
- 统计文件信息(行数、字符数)
- 简单的笔记管理系统

## 代码实现

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileManager {
public:
    // 写入文件
    void writeToFile(const string& filename, const string& content) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "错误: 无法打开文件 " << filename << endl;
            return;
        }
        
        file << content;
        file.close();
        cout << "内容已写入文件: " << filename << endl;
    }
    
    // 读取文件
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "错误: 无法打开文件 " << filename << endl;
            return;
        }
        
        cout << "\n--- 文件内容: " << filename << " ---" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << "--- 文件结束 ---\n" << endl;
        
        file.close();
    }
    
    // 追加到文件
    void appendToFile(const string& filename, const string& content) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cout << "错误: 无法打开文件 " << filename << endl;
            return;
        }
        
        file << content;
        file.close();
        cout << "内容已追加到文件: " << filename << endl;
    }
    
    // 复制文件
    void copyFile(const string& source, const string& destination) {
        ifstream srcFile(source);
        if (!srcFile.is_open()) {
            cout << "错误: 无法打开源文件 " << source << endl;
            return;
        }
        
        ofstream destFile(destination);
        if (!destFile.is_open()) {
            cout << "错误: 无法创建目标文件 " << destination << endl;
            srcFile.close();
            return;
        }
        
        string line;
        while (getline(srcFile, line)) {
            destFile << line << endl;
        }
        
        srcFile.close();
        destFile.close();
        cout << "文件已复制: " << source << " -> " << destination << endl;
    }
    
    // 统计文件信息
    void fileStatistics(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "错误: 无法打开文件 " << filename << endl;
            return;
        }
        
        int lineCount = 0;
        int charCount = 0;
        int wordCount = 0;
        string line;
        
        while (getline(file, line)) {
            lineCount++;
            charCount += line.length();
            
            // 简单的单词计数
            bool inWord = false;
            for (char c : line) {
                if (isspace(c)) {
                    inWord = false;
                } else if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }
        
        file.close();
        
        cout << "\n--- 文件统计: " << filename << " ---" << endl;
        cout << "行数: " << lineCount << endl;
        cout << "字符数: " << charCount << endl;
        cout << "单词数: " << wordCount << endl;
        cout << "------------------------\n" << endl;
    }
};

class NoteManager {
private:
    string notesFile;
    
public:
    NoteManager(const string& filename) : notesFile(filename) {}
    
    // 添加笔记
    void addNote() {
        string note;
        cout << "\n请输入笔记内容 (输入 'END' 结束):" << endl;
        cin.ignore();
        
        ofstream file(notesFile, ios::app);
        if (!file.is_open()) {
            cout << "错误: 无法打开笔记文件" << endl;
            return;
        }
        
        // 添加时间戳
        time_t now = time(0);
        char* dt = ctime(&now);
        file << "\n=== 笔记 [" << dt << "] ===" << endl;
        
        while (getline(cin, note)) {
            if (note == "END") break;
            file << note << endl;
        }
        
        file.close();
        cout << "笔记已保存!" << endl;
    }
    
    // 显示所有笔记
    void displayNotes() {
        ifstream file(notesFile);
        if (!file.is_open()) {
            cout << "没有找到笔记文件!" << endl;
            return;
        }
        
        cout << "\n--- 所有笔记 ---" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << "--- 笔记结束 ---\n" << endl;
        
        file.close();
    }
    
    // 搜索笔记
    void searchNotes() {
        string keyword;
        cout << "请输入搜索关键词: ";
        cin.ignore();
        getline(cin, keyword);
        
        ifstream file(notesFile);
        if (!file.is_open()) {
            cout << "没有找到笔记文件!" << endl;
            return;
        }
        
        cout << "\n--- 搜索结果 ---" << endl;
        string line;
        int lineNumber = 0;
        bool found = false;
        
        while (getline(file, line)) {
            lineNumber++;
            if (line.find(keyword) != string::npos) {
                cout << "行 " << lineNumber << ": " << line << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "未找到包含 '" << keyword << "' 的笔记" << endl;
        }
        cout << "--- 搜索结束 ---\n" << endl;
        
        file.close();
    }
    
    // 清空笔记
    void clearNotes() {
        char confirm;
        cout << "确定要删除所有笔记吗? (y/n): ";
        cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y') {
            ofstream file(notesFile, ios::trunc);
            file.close();
            cout << "所有笔记已清空!" << endl;
        } else {
            cout << "操作已取消" << endl;
        }
    }
};

int main() {
    NoteManager noteManager("notes.txt");
    int choice;
    
    while (true) {
        cout << "\n======= 笔记管理系统 =======" << endl;
        cout << "1. 添加笔记" << endl;
        cout << "2. 显示所有笔记" << endl;
        cout << "3. 搜索笔记" << endl;
        cout << "4. 清空笔记" << endl;
        cout << "5. 退出" << endl;
        cout << "============================" << endl;
        cout << "请选择操作 (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                noteManager.addNote();
                break;
            case 2:
                noteManager.displayNotes();
                break;
            case 3:
                noteManager.searchNotes();
                break;
            case 4:
                noteManager.clearNotes();
                break;
            case 5:
                cout << "感谢使用!再见!" << endl;
                return 0;
            default:
                cout << "无效选择!请重试。" << endl;
        }
    }
    
    return 0;
}
```

## 如何运行

### 编译
```bash
g++ -o file_manager file_manager.cpp
```

### 运行
```bash
./file_manager
```

## 文件操作示例

### 基本文件读写示例

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 写入文件
    ofstream outFile("example.txt");
    outFile << "Hello, World!" << endl;
    outFile << "C++ File Operations" << endl;
    outFile.close();
    
    // 读取文件
    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    
    return 0;
}
```

## 扩展功能建议

1. 加密和解密笔记
2. 标签/分类系统
3. 导出为不同格式(PDF, HTML)
4. 备份和恢复功能
5. 云同步功能
6. 笔记版本控制
7. 富文本编辑器集成

## 学习要点

- 文件流 (ifstream, ofstream, fstream)
- 文件打开模式 (ios::in, ios::out, ios::app, ios::trunc)
- 文件读写操作
- 错误处理
- 字符串搜索和处理
- 时间处理
