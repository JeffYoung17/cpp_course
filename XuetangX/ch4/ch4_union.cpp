#include <iostream>
#include <string>

using namespace std;

class ExamInfo {
private:
    string exam_name;
    enum ExamMode {
        GRADE,
        PASS,
        PERCENT
    };
    ExamMode mode;
    union {
        char grade;
        bool pass;
        int percent;
    }; // 无名联合体
public:
    // 构造函数重载
    ExamInfo(string name, char grade) : exam_name(name), mode(GRADE), grade(grade) {}
    ExamInfo(string name, bool pass) : exam_name(name), mode(PASS), pass(pass) {}
    ExamInfo(string name, int percent) : exam_name(name), mode(PERCENT), percent(percent) {}
    void showExamInfo();
};

int main()
{
    ExamInfo course1("English", 90);
    course1.showExamInfo();
    ExamInfo course2("Math", true);
    course2.showExamInfo();
    ExamInfo course3("Cpp", 'A');
    course3.showExamInfo();
    return 0;
}

void ExamInfo::showExamInfo()
{
    cout << "Exam: " << exam_name << endl;
    switch (mode){
        case GRADE: cout << grade; break;
        case PASS: cout << (pass ? "PASSED" : "Not passed"); break;
        case PERCENT: cout << percent;
    }
    cout << endl;
}