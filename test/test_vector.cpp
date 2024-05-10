#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, norm) {
    auto* testVect1 = new MatVect(3);
    testVect1->set_elem(0, 3);
    testVect1->set_elem(1, 4);
    testVect1->set_elem(2, 0);
    EXPECT_EQ(testVect1->norm(), 5);
}
TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);

    ASSERT_EQ(v.size(), 2U);  // przyrostek "U" oznacza wartość bez znaku (ang. unsigned)
    EXPECT_EQ(v.get_elem(0), 0);
    EXPECT_EQ(v.get_elem(1), 0);
}
TEST(MatlabVectorTest, add) {
    MatVect v1(4U);
    MatVect v2(2U);
    v1.set_elem(0,1);
    v1.set_elem(1,4);
    v1.set_elem(2,7);
    v2.set_elem(0,6);
    v2.set_elem(1,3);
    MatVect v3 = add_vectors(v1, v2);
    EXPECT_EQ(v3.get_elem(0), 7);
    EXPECT_EQ(v3.get_elem(1), 7);
    EXPECT_EQ(v3.get_elem(2), 7);
    EXPECT_EQ(v3.get_elem(3), 0);
}