#include "pch.h"
#include "../MyDB/myDB.h"

TEST(TestCompareChar, HandleSameLengthChar) {
    myDB* db = new myDB();
    EXPECT_EQ(db->compareChar("a", "a"), 0);
    EXPECT_EQ(db->compareChar("bc", "bc"), 0);
    EXPECT_EQ(db->compareChar("defg", "defg"), 0);
    EXPECT_TRUE(db->compareChar("a", "b") < 0);
    EXPECT_TRUE(db->compareChar("ab", "ac") < 0);
    EXPECT_TRUE(db->compareChar("ba", "ab") > 0);
    EXPECT_TRUE(db->compareChar("bcdg", "bcde") > 0);
}

TEST(testCompareChar, HandleDiffLengthChar) {
    myDB* db = new myDB();
    EXPECT_TRUE(db->compareChar("a", "ab") < 0);
    EXPECT_TRUE(db->compareChar("abc", "abcd") < 0);
    EXPECT_TRUE(db->compareChar("abce", "abd") < 0);
    EXPECT_TRUE(db->compareChar("xyzu", "xyz") > 0);
    EXPECT_TRUE(db->compareChar("bcde", "bcd") > 0);
    EXPECT_TRUE(db->compareChar("achj", "acd") > 0);
}