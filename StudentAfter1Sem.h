#ifndef LABS_FIRST_TERM_STUDENTAFTER1SEM_H
#define LABS_FIRST_TERM_STUDENTAFTER1SEM_H

#include "Student.h"

class StudentAfter1Sem : public Student {
private:
    int marks1[4];
public:
    StudentAfter1Sem(const int *marks1, char *name, int course, int group, int studentNum);

    StudentAfter1Sem(StudentAfter1Sem *student);

    double getMarks1();

    void setMarks1(int *marks1);

    double averageMark() override;

    friend std::ostream &operator<<(std::ostream &out,const StudentAfter1Sem &student);
};


#endif //LABS_FIRST_TERM_STUDENTAFTER1SEM_H
