/////////////////////////////////////////////////////////////////////////////
// NAME     : factorial_main.cpp
// PURPOSE  :
// AUTHOR   : prashant
// DATE     : Jul 26, 2020
//
// Copyright Template: v1.1
//
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

extern u_int64_t GetFactorial(int length, int chunks) ;

int main(int argc, char **argv) {
    // length od string is 28
    int length = argv[1] ? atoi(argv[1]) : 10;
    int chunks = argv[2] ? atoi(argv[2]) : 3;
	GetFactorial(length, chunks);
   return 0;
}
