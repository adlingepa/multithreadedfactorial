/////////////////////////////////////////////////////////////////////////////
// NAME     : test_factorial.cpp
// PURPOSE  :
// AUTHOR   : prashant
// DATE     : Jul 29, 2020
//
// Copyright Template: v1.1
//
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "gtest/gtest.h"

extern u_int64_t GetFactorial(int length, int chunks) ;

TEST(sample_test_case, sample_test) { EXPECT_EQ(1, 1); }

TEST(sample_test_case, factorial_of_0_should_be_1) { EXPECT_EQ(1, GetFactorial(0, 1)); }

TEST(sample_test_case, factorial_of_1) { EXPECT_EQ(1, GetFactorial(1, 1)); }

TEST(sample_test_case, factorial_of_4) { EXPECT_EQ(24, GetFactorial(4, 1)); }

TEST(sample_test_case, factorial_of_9) { EXPECT_EQ(362880, GetFactorial(9, 1)); }

TEST(sample_test_case, factorial_of_15) { EXPECT_EQ(1307674368000, GetFactorial(15, 1)); }

TEST(sample_test_case, factorial_of_20) { EXPECT_EQ(2432902008176640000, GetFactorial(20, 1)); }

