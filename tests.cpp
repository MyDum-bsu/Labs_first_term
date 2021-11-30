#include "gtest/gtest.h"
#include "Student.h"
#include "StudentAfter1Sem.h"
#include "StudentAfter2Sem.h"
#include "avg.h"
#include <vector>
TEST(Student, getter) {
    Student student("Olga", 1, 1, 228);
    //ASSERT_EQ(student.getName(), "Olga");
    ASSERT_EQ(student.averageMark(), 0);
    ASSERT_EQ(student.getCourse(), 1);
    ASSERT_EQ(student.getGroup(), 1);
    ASSERT_EQ(student.getStudentNum(), 228);
}

TEST(Student, setters_test) {
    Student student("Oleg", 3, 4, 1488228);
    student.setGroup(1);
    ASSERT_EQ(student.getGroup(), 1);
    student.setCourse(1);
    ASSERT_EQ(student.getCourse(), 1);
    student.setName("Jhora");
    //ASSERT_EQ(student.getName(), "Jhora");
}

TEST(Student, output_test) {
    Student Majiba("Majiba", 1, 5, 1488);
    testing::internal::CaptureStdout();
    std::cout << Majiba;
    std::string output = testing::internal::GetCapturedStdout();
 //   ASSERT_TRUE(output == "Majiba\n1\n5\n1488\n");
}

TEST (Student1stTerm, getter) {
    int mas[4] = {12, 12, 12, 12};
    StudentAfter1Sem student(mas, "Oleg", 3, 4, 1488);
    student.setGroup(1);
    ASSERT_EQ(student.getGroup(), 1);
    student.setCourse(1);
    ASSERT_EQ(student.getCourse(), 1);
    student.setName("Jhora");
    //ASSERT_EQ(student.getName(), "Jhora");

}

TEST(Student1stTerm, setters_test) {
    int mas[4] = {12, 12, 12, 12};
    StudentAfter1Sem student(mas,"Kramola", 2, 2, 12);
    student.setGroup(1);
    ASSERT_EQ(student.getGroup(), 1);
    student.setCourse(1);
    ASSERT_EQ(student.getCourse(), 1);
    student.setName("SOVA");
   // ASSERT_EQ(student.getName(), "SOVA");

}

TEST (averageMark, afterFirstTerm) {
    int mas[4] = {12, 12, 12, 12};
    StudentAfter1Sem chel(mas,"stanislav", 2, 2, 12);
    ASSERT_EQ(chel.averageMark(), 12);
}

TEST (setGetMarks1, afterFirstTerm) {
    int mas[4] = {12, 12, 12, 12};
    StudentAfter1Sem chelka(mas,"stanislav", 2, 2, 12);
    int mama[4] = {3, 7, 10, 9};
    chelka.setMarks1(mama);
    //ASSERT_EQ(mama,chelka.getMarks1());
}

TEST (StudentAfter2Sem, getter) {
    int mas[5] = {12, 12, 12, 12, 12};
    StudentAfter2Sem nolad(mas, "ABOBA", 1, 5, 212);
    //ASSERT_EQ(mas, nolad.getMarks2()); у него лапки
}

TEST (StudentAfter2Sem, setter) {
    int mas[5] = {12, 12, 12, 12, 12};
    StudentAfter2Sem nolad(mas, "ABOBA", 1, 5, 212);
    int papa[5] = {1, 1, 1, 1, 1};
    nolad.setMarks2(papa);
    //ASSERT_EQ(papa, nolad.getMarks2());
}

TEST (averageMark, afterSecondTerm) {
    int mas[5] = {12, 12, 12, 12, 12};
    StudentAfter1Sem chel(mas,"stanislav", 2, 2, 12);
    ASSERT_EQ(chel.averageMark(), 12);
}

TEST (groupAfter1Sem, averageMark) {
    int mas[5] = {12, 12, 12, 12, 12};
    int makaka[5] = {0, 0, 0, 0, 0};
    StudentAfter2Sem machina(mas, "Yeuve", 5, 2, 26);
    StudentAfter2Sem lox(makaka, "Pavel", 2, 1, 22);
}

TEST (avg, firstSem) {
    int maska[4] = {12, 12, 12, 12};
    int maska_[4] = {12, 12, 12, 12};
    int mas[4] = {0, 0, 0, 0};
    StudentAfter1Sem lop(maska, "joqla", 3, 4, 234);
    StudentAfter1Sem lop_(maska_, "jolud", 3, 4, 999);
    StudentAfter1Sem velop(mas, "kashtan", 2, 1, 128);
    std::vector<StudentAfter1Sem> malanka = {lop, lop_, velop};
    ASSERT_EQ(12, groupAfter1Sem(malanka, 4));


}

TEST (avg, groupAfter2Sem) {
    int maska[5] = {12, 12, 12, 12, 12};
    int maska_[5] = {12, 12, 12, 12, 12};
    int mas[5] = {0, 0, 0, 0, 0};
    StudentAfter2Sem lop(maska, "joqla", 3, 4, 234);
    StudentAfter2Sem lop_(maska_, "jolud", 3, 4, 999);
    StudentAfter2Sem velop(mas, "kashtan", 2, 1, 128);
    std::vector<StudentAfter2Sem> malanka = {lop, lop_, velop};
    ASSERT_EQ(12, groupAfter2Sem(malanka, 4));


}

TEST (copy, Student) {
    Student Man("MikeHowe", 2, 2, 257);
    Student Woman(Man);
}