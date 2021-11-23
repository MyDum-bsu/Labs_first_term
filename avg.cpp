#include "avg.h"

double groupAfter1Sem(const std::vector<StudentAfter1Sem> &students, int group) {
    double avg = 0;
    int i = 0;
    for (StudentAfter1Sem student: students) {
        if (student.getGroup() == group) {
            avg += student.averageMark();
            i++;
        }
    }
    return avg / i;
}

double groupAfter2Sem(const std::vector<StudentAfter2Sem> &students, int group) {
    double avg = 0;
    int i = 0;
    for (StudentAfter2Sem student: students) {
        if (student.getGroup() == group) {
            avg += student.averageMark();
            i++;
        }
    }
    return avg / i;
}

double  arrayAfterSem(const std::vector<Student> &students, int group) {
    double avg = 0;
    int i = 0;
    for (auto student: students) {
        if (student.getGroup() == group) {
            avg += student.averageMark();
            i++;
        }
    }
    return avg / i;
}