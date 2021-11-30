#include "gtest/gtest.h"
#include "Student.h"
#include "StudentAfter1Sem.h"
#include "StudentAfter2Sem.h"
TEST(Student, getter) {
    Student student("Olga", 1, 1, 228);
    ASSERT_EQ(student.getName(), "Olga");
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
    ASSERT_EQ(student.getName(), "Jhora");
}

TEST(Student, output_test) {
    Student Majiba("Majiba", 1, 5, 1488);
    testing::internal::CaptureStdout();
    std::cout << Majiba;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "Majiba\n1\n5\n1488\n");
}

TEST (Student1stTerm, getter) {
    int mas[4] = {12, 12, 12, 12};
    StudentAfter1Sem student(mas, "Oleg", 3, 4, 1488);
    student.setGroup(1);
    ASSERT_EQ(student.getGroup(), 1);
    student.setCourse(1);
    ASSERT_EQ(student.getCourse(), 1);
    student.setName("Jhora");
    ASSERT_EQ(student.getName(), "Jhora");

}

TEST(Student1stTerm, setters_test) {
    int mas[4] = {12, 12, 12, 12};
    StudentAfter1Sem student(mas,"Kramola", 2, 2, 12);
    student.setGroup(1);
    ASSERT_EQ(student.getGroup(), 1);
    student.setCourse(1);
    ASSERT_EQ(student.getCourse(), 1);
    student.setName("SOVA");
    ASSERT_EQ(student.getName(), "SOVA");

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
    ASSERT_EQ(mama,chelka.getMarks1());
}

TEST (StudentAfter2Sem, getter) {
    int mas[5] = {12, 12, 12, 12, 12};
    StudentAfter2Sem nolad(mas, "ABOBA", 1, 5, 212);
    ASSERT_EQ(mas, nolad.getMarks2());
}

TEST (StudentAfter2Sem, setter) {
    int mas[5] = {12, 12, 12, 12, 12};
    StudentAfter2Sem nolad(mas, "ABOBA", 1, 5, 212);
    int papa[5] = {1, 1, 1, 1, 1};
    nolad.setMarks2(papa);
    ASSERT_EQ(papa, nolad.getMarks2());
}