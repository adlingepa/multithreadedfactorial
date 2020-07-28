/////////////////////////////////////////////////////////////////////////////
// NAME     : test_factorial_4_threads.cpp
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


TEST(sample_test_case, factorial_of_20) { EXPECT_EQ(2432902008176640000, GetFactorial(20, 4)); }
