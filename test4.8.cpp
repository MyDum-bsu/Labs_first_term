#include "gtest/gtest.h"
#include "lab4.8A.h"
#include "lab4.8B.h"


TEST(strrchr, 1) {

    char* line = "recdvtfbunbjnmonuvvcerfybuhnijmkhiytrcvynioqbvyvbkmkifvu";

    ASSERT_EQ(&line[43], strrchr1(line, 'q'));
}

TEST(strrchr, 2) {

    char* line = "aaaaaaaaaaaaaaaaaaaaaaaaaa";

    ASSERT_EQ(nullptr, strrchr1(line, 'q'));
}

TEST(SearchWord, 1){
    char* line = "recd vtfbunbj nmonuvvcer fybuhnij mkhiyt rcv ynioqbvyvb kmkifvu";
    ASSERT_TRUE(SearchWord(line, 70));
}

TEST(SearchWord, 2){
    char* line = "ddd fff hhh ttt uuu";
    ASSERT_FALSE(SearchWord(line, 70));
}


