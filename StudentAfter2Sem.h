#ifndef LABS_FIRST_TERM_STUDENTAFTER2SEM_H
#define LABS_FIRST_TERM_STUDENTAFTER2SEM_H

#include "StudentAfter1Sem.h"

class StudentAfter2Sem : public StudentAfter1Sem {
private:
    int marks2[5];
public:
    StudentAfter2Sem(const int *marks2, char *name, int course, int group, int studentNum);

    StudentAfter2Sem(StudentAfter2Sem *student);

    double averageMark() override;

    double getMarks2();

    void setMarks2(int *marks2);

    friend std::ostream &operator<<(std::ostream &out, const StudentAfter2Sem &student);
};


#endif //LABS_FIRST_TERM_STUDENTAFTER2SEM_H
