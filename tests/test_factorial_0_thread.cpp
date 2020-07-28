/////////////////////////////////////////////////////////////////////////////
// NAME     : test_factorial_0_thread.cpp
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

TEST(sample_test_case, factorial_of_20_with_0_thread) { EXPECT_EQ(0, GetFactorial(20, 0)); }

