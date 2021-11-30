#include "Student.h"

Student::Student(char *name, int course, int group, int studentNum) {

    this->group = group;
    this->course = course;
    this->name = name;
    this->studentNum = studentNum;
    ID = ++sID;
}

Student::Student(Student *student) {
    this->group = student->group;
    this->course = student->course;
    this->name = student->name;
    this->studentNum = student->studentNum;
    this->ID = student->ID;
}

void Student::setName(char *name) { this->name = name; }

void Student::setCourse(int course) { this->course = course; }

void Student::setGroup(int group) { this->group = group; }

char *Student::getName() { return name; }

int Student::getCourse() { return course; }

int Student::getGroup() { return group; }

int Student::getStudentNum() { return studentNum; }

std::ostream &operator<<(std::ostream &out,const Student &student) {
    out << student.name << std::endl;
    out << student.course << std::endl;
    out << student.group << std:: endl;
    out << student.studentNum << std::endl;
    out << student.ID << std::endl;
    return out;
}

double Student::averageMark() {
    return 0;
}