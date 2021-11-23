#include "StudentAfter1Sem.h"

StudentAfter1Sem::StudentAfter1Sem(const int *marks1, char *name,
                                   int course, int group, int studentNum) : Student(name, course, group, studentNum) {
    for (int i = 0; i < 4; ++i) {
        this->marks1[i] = marks1[i];
    }
}

StudentAfter1Sem::StudentAfter1Sem(StudentAfter1Sem *student) : Student(*student) {
    for (int i = 0; i < 4; ++i) {
        this->marks1[i] = student->marks1[i];
    }
}

double StudentAfter1Sem::averageMark() {
    double sum = 0;

    for (int mark: marks1) {
        sum += mark;
    }
    return sum / 4;
}

void StudentAfter1Sem::setMarks1(int *marks1) {
    for (int i = 0; i < 4; ++i) {
        this->marks1[i] = marks1[i];
    }
}

double StudentAfter1Sem::getMarks1() { return *marks1; }

std::ostream &operator<<(std::ostream &out, const StudentAfter1Sem &student) {
    out << (Student) student;
    out << student.marks1;
    return out ;
}
