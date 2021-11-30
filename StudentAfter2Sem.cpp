#include "StudentAfter2Sem.h"

double StudentAfter2Sem::averageMark() {
    double sum = 0;

    for (int mark : marks2){
        sum += mark;
    }
    return (double) (StudentAfter1Sem::averageMark()*4 + sum) / 9;
}

StudentAfter2Sem::StudentAfter2Sem(const int *marks2, char *name, int course, int group, int studentNum)
        : StudentAfter1Sem(marks2, name, course, group, studentNum) {
    for (int i = 0; i < 5; ++i) {
        this->marks2[i] = marks2[i];
    }
}

StudentAfter2Sem::StudentAfter2Sem(StudentAfter2Sem *student) : StudentAfter1Sem(*student) {
    for (int i = 0; i < 5; ++i) {
        this->marks2[i] = marks2[i];
    }
}

void StudentAfter2Sem::setMarks2(int *marks2) {
    for (int i = 0; i < 5; ++i) {
        this->marks2[i] = marks2[i];
    }
}

double StudentAfter2Sem::getMarks2() { return *marks2; }

std::ostream &operator<<(std::ostream &out, const StudentAfter2Sem &student) {
    out << (Student)student;
    out << student.marks2;
    return out;
}
