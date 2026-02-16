#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class NoteManager {
private:
    string notesFile;
    
public:
    NoteManager(const string& filename) : notesFile(filename) {}
    
    void addNote() {
        string note;
        cout << "\n请输入笔记内容 (输入 'END' 结束):" << endl;
        cin.ignore();
        
        ofstream file(notesFile, ios::app);
        if (!file.is_open()) {
            cout << "错误: 无法打开笔记文件" << endl;
            return;
        }
        
        time_t now = time(0);
        string timestamp = ctime(&now);
        // 移除 ctime 返回的尾随换行符
        if (!timestamp.empty() && timestamp.back() == '\n') {
            timestamp.pop_back();
        }
        file << "\n=== 笔记 [" << timestamp << "] ===" << endl;
        
        while (getline(cin, note)) {
            if (note == "END") break;
            file << note << endl;
        }
        
        file.close();
        cout << "笔记已保存!" << endl;
    }
    
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
        
        // 输入验证
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "无效的输入!请输入数字。" << endl;
            continue;
        }
        
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
