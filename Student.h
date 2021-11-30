#ifndef LABS_FIRST_TERM_STUDENT_H
#define LABS_FIRST_TERM_STUDENT_H

#include <iostream>


class Student {
private:
    static int sID;
    int ID;
    char *name;
    int course;
    int group;
    int studentNum;
public:

    Student(char *name, int course, int group, int studentNum);

    Student(Student *student);

    char *getName();

    int getCourse();

    int getGroup();

    int getStudentNum();

    void setName(char *name);

    void setCourse(int course);

    void setGroup(int group);


    friend std::ostream &operator<<(std::ostream &out, const Student &student);

    virtual double averageMark();
};


#endif //LABS_FIRST_TERM_STUDENT_H
