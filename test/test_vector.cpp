#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, norm) {
    auto testVect1 = Matlab::Vector(3);
    testVect1[0] = 3;
    testVect1[1] = 4;
    testVect1[2] = 0;
    EXPECT_EQ(testVect1.norm(), 5);
}
TEST(MatlabVectorTest, createWithSize) {
    Matlab::Vector v(2U);

    ASSERT_EQ(v.size(), 2U);  // przyrostek "U" oznacza wartość bez znaku (ang. unsigned)
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}
TEST(MatlabVectorTest, add) {
    Matlab::Vector v1(4U);
    Matlab::Vector v2(4U);
    v1[0] = 5;
    v1[1] = 2;
    v1[2] = 7;
    v2[0] = 2;
    v2[1] = 5;
    Matlab::Vector v3 = add_vectors(v1, v2);
    EXPECT_EQ(v3[0], 7);
    EXPECT_EQ(v3[1], 7);
    EXPECT_EQ(v3[2], 7);
    EXPECT_EQ(v3[3], 0);
}
TEST(MatlabVectorTest, toSting) {
    Matlab::Vector v({1, 2, 3});
    EXPECT_EQ(to_string(v), "[ 1, 2, 3 ]");
}

TEST(MatlabVectorTest, dodatkowe){
    Matlab::Matrix mat(5, 5);
    mat[1][1] = 1;
    std::cout<<to_string(mat);
    Matlab::Matrix mat2({{1, 2}, {3, 4}});
    std::cout<<to_string(mat2);
    Matlab::Matrix mat3({{9, 8}, {7, 6}});
    std::cout<<to_string(add_matrices(mat2, mat3));
    std::cout<<mat3.sum()<<" "<<mat3[1][1];
}