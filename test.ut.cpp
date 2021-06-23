#include "gtest/gtest.h"
#include "Student.hpp"

constexpr char STUDENT_NAME[] = "Anna";
constexpr char STUDENT_SURNAME[] = "Nowak";
constexpr char STUDENT_ADDRESS[] = "Wroclaw";
constexpr char STUDENT_INDEX_NUMBER[] = "123456";
constexpr char STUDENT_PERSONAL_IDENTITY_NUMBER[] = "95012600149";
constexpr char STUDENT_GENDER[] = "F";

Student student(STUDENT_NAME, STUDENT_SURNAME, STUDENT_ADDRESS, STUDENT_INDEX_NUMBER, STUDENT_PERSONAL_IDENTITY_NUMBER, STUDENT_GENDER);

TEST(StudentGettersTests, getStudentNameByGetterAndShouldBeEqualAnna) {
    EXPECT_EQ(student.getName(), STUDENT_NAME);
}
TEST(StudentGettersTests, getStudentSurnameByGetterAndShouldBeEqualNowak) {
    EXPECT_EQ(student.getSurname(), STUDENT_SURNAME);
}
TEST(StudentGettersTests, getStudentAddressByGetterAndShouldBeEqualWroclaw) {
    EXPECT_EQ(student.getAddress(), STUDENT_ADDRESS);
}
TEST(StudentGettersTests, getStudentIndexNumberByGetterAndShouldBeEqual123456) {
    EXPECT_EQ(student.getIndexNumber(), STUDENT_INDEX_NUMBER);
}
TEST(StudentGettersTests, getStudentPersonalIndentityNumberByGetterAndShouldBeEqual95012600149) {
    EXPECT_EQ(student.getPersonalIdentityNumber(), STUDENT_PERSONAL_IDENTITY_NUMBER);
}
TEST(StudentGettersTests, getStudentGenderAndShouldBeEqualToF) {
    EXPECT_EQ(student.getGender(), STUDENT_GENDER);
}

TEST(StudentOperatorsTests, compareTwoIndexNumberInStudentClass) {
    Student student2(STUDENT_NAME, STUDENT_SURNAME, STUDENT_ADDRESS, "123456", STUDENT_PERSONAL_IDENTITY_NUMBER, STUDENT_GENDER);
    EXPECT_EQ(student.getIndexNumber(), student2.getIndexNumber());
}
TEST(PersonalIdentityNumberValidation, PersonalIdentityNumberShouldBeElevenCharacters) {
    EXPECT_EQ(std::size(student.getPersonalIdentityNumber()), 11);
}
