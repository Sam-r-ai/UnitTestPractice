/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

//Password with both uppercase and lowercase letters
TEST(PasswordTest, MixedCasePassword) {
    Password my_password;
    bool actual = my_password.has_mixed_case("Password123");
    ASSERT_TRUE(actual);  
}

//Password with only uppercase letters
TEST(PasswordTest, UpperCaseOnlyPassword) {
    Password my_password;
    bool actual = my_password.has_mixed_case("PASSWORD");
    ASSERT_FALSE(actual);
}

//Password with only lowercase letters
TEST(PasswordTest, LowerCaseOnlyPassword) {
    Password my_password;
    bool actual = my_password.has_mixed_case("password");
    ASSERT_FALSE(actual);  
}

//Password with only digits (no letters)
TEST(PasswordTest, NoLettersPassword) {
    Password my_password;
    bool actual = my_password.has_mixed_case("123456");
    ASSERT_FALSE(actual);
}

//Empty password
TEST(PasswordTest, EmptyPassword) {
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_FALSE(actual);  
}