#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
private:
    string id;
    string name;
    int age;
    double score;
    
public:
    Student(string id, string name, int age, double score)
        : id(id), name(name), age(age), score(score) {}
    
    string getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    double getScore() const { return score; }
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setScore(double s) { score = s; }
    
    void display() const {
        cout << left << setw(10) << id 
             << setw(15) << name 
             << setw(6) << age 
             << setw(10) << fixed << setprecision(2) << score << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;
    
public:
    void addStudent() {
        string id, name;
        int age;
        double score;
        
        cout << "\n--- 添加学生 ---" << endl;
        cout << "学号: ";
        cin >> id;
        
        if (findStudentById(id) != -1) {
            cout << "错误: 学号已存在!" << endl;
            return;
        }
        
        cout << "姓名: ";
        cin.ignore();
        getline(cin, name);
        cout << "年龄: ";
        cin >> age;
        cout << "成绩: ";
        cin >> score;
        
        students.push_back(Student(id, name, age, score));
        cout << "学生添加成功!" << endl;
    }
    
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "没有学生记录!" << endl;
            return;
        }
        
        cout << "\n--- 所有学生 ---" << endl;
        cout << left << setw(10) << "学号" 
             << setw(15) << "姓名" 
             << setw(6) << "年龄" 
             << setw(10) << "成绩" << endl;
        cout << string(45, '-') << endl;
        
        for (const auto& student : students) {
            student.display();
        }
    }
    
    int findStudentById(const string& id) const {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }
    
    void searchStudent() const {
        string id;
        cout << "\n--- 搜索学生 ---" << endl;
        cout << "请输入学号: ";
        cin >> id;
        
        int index = findStudentById(id);
        if (index == -1) {
            cout << "未找到该学生!" << endl;
            return;
        }
        
        cout << "\n找到学生:" << endl;
        cout << left << setw(10) << "学号" 
             << setw(15) << "姓名" 
             << setw(6) << "年龄" 
             << setw(10) << "成绩" << endl;
        cout << string(45, '-') << endl;
        students[index].display();
    }
    
    void deleteStudent() {
        string id;
        cout << "\n--- 删除学生 ---" << endl;
        cout << "请输入学号: ";
        cin >> id;
        
        int index = findStudentById(id);
        if (index == -1) {
            cout << "未找到该学生!" << endl;
            return;
        }
        
        students.erase(students.begin() + index);
        cout << "学生删除成功!" << endl;
    }
    
    void updateStudent() {
        string id;
        cout << "\n--- 修改学生信息 ---" << endl;
        cout << "请输入学号: ";
        cin >> id;
        
        int index = findStudentById(id);
        if (index == -1) {
            cout << "未找到该学生!" << endl;
            return;
        }
        
        string name;
        int age;
        double score;
        
        cout << "新姓名: ";
        cin.ignore();
        getline(cin, name);
        cout << "新年龄: ";
        cin >> age;
        cout << "新成绩: ";
        cin >> score;
        
        students[index].setName(name);
        students[index].setAge(age);
        students[index].setScore(score);
        
        cout << "学生信息更新成功!" << endl;
    }
    
    void calculateAverage() const {
        if (students.empty()) {
            cout << "没有学生记录!" << endl;
            return;
        }
        
        double sum = 0;
        for (const auto& student : students) {
            sum += student.getScore();
        }
        
        double average = sum / students.size();
        cout << fixed << setprecision(2);
        cout << "平均成绩: " << average << endl;
    }
    
    void showTopAndBottom() const {
        if (students.empty()) {
            cout << "没有学生记录!" << endl;
            return;
        }
        
        size_t maxIndex = 0, minIndex = 0;
        for (size_t i = 1; i < students.size(); i++) {
            if (students[i].getScore() > students[maxIndex].getScore()) {
                maxIndex = i;
            }
            if (students[i].getScore() < students[minIndex].getScore()) {
                minIndex = i;
            }
        }
        
        cout << "\n最高分学生:" << endl;
        cout << left << setw(10) << "学号" 
             << setw(15) << "姓名" 
             << setw(6) << "年龄" 
             << setw(10) << "成绩" << endl;
        cout << string(45, '-') << endl;
        students[maxIndex].display();
        
        cout << "\n最低分学生:" << endl;
        cout << left << setw(10) << "学号" 
             << setw(15) << "姓名" 
             << setw(6) << "年龄" 
             << setw(10) << "成绩" << endl;
        cout << string(45, '-') << endl;
        students[minIndex].display();
    }
    
    void displayMenu() {
        cout << "\n======= 学生管理系统 =======" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 搜索学生" << endl;
        cout << "4. 删除学生" << endl;
        cout << "5. 修改学生信息" << endl;
        cout << "6. 计算平均成绩" << endl;
        cout << "7. 显示最高/最低分" << endl;
        cout << "8. 退出" << endl;
        cout << "============================" << endl;
        cout << "请选择操作 (1-8): ";
    }
    
    void run() {
        int choice;
        
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
            
            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayAllStudents();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    deleteStudent();
                    break;
                case 5:
                    updateStudent();
                    break;
                case 6:
                    calculateAverage();
                    break;
                case 7:
                    showTopAndBottom();
                    break;
                case 8:
                    cout << "感谢使用!再见!" << endl;
                    return;
                default:
                    cout << "无效选择!请重试。" << endl;
            }
        }
    }
};

int main() {
    StudentManager manager;
    manager.run();
    return 0;
}
