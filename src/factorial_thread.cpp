/////////////////////////////////////////////////////////////////////////////
// NAME     : factorial_thread.c
// PURPOSE  :
// AUTHOR   : prashant
// DATE     : Jul 26, 2020
//
// Copyright Template: v1.1
//
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <pthread.h>
#include <iostream>
using namespace std;

typedef struct mult {
    int start;
    int end;
    u_int64_t *product;
} chunk_t;

static void *thread_function(void *dummyPtr) {
    chunk_t *chunkdata = (chunk_t *)dummyPtr;
    *(chunkdata->product) = 1;
    for (int i = chunkdata->start; i <= chunkdata->end; i++) {
        //        cout << "multiplying " << i << " with " << *(chunkdata->product) << "\n";
        *(chunkdata->product) *= i;
    }
    return NULL;
}

u_int64_t GetFactorial(int length, int chunks) {
    // if length is not divisible by chunk, one extra chunk will created with lesser size
    // 10 % 3 not zero, create 4 chunks as 1-3, 4-6, 7-9 and 10
    // 4 trhead aslo created to handle each chunk
    if(!chunks) return 0;
    
    int nThreads = (length % chunks) ? chunks + 1 : chunks;
    pthread_t thread_id[nThreads] = {0};
    u_int64_t multiplication[nThreads] = {0};
    int chunk_size = length / chunks;

    // https://stackoverflow.com/questions/37266713/pass-a-value-into-a-thread-from-a-while-loop
    // https://stackoverflow.com/questions/23051284/c-pthread-value-doesnt-stay-same-in-thread-parameter
    // https://stackoverflow.com/questions/42013821/passing-for-loop-index-into-pthread-create-argument-object-in-c
    // https://stackoverflow.com/questions/28205116/correct-way-to-pass-a-struct-to-pthread-within-a-for-loop
    // thread data should not initialized in the thread creation loop as it will overwritten by
    // subsequent thread
    chunk_t chunk[nThreads] = {0};
    for (int i = 0; i < nThreads; i++) {
        int start = chunk_size * i + 1;
        int end = start + chunk_size - 1;

        // handling upper limit
        if (end > length) end = length;

        cout << start << "  " << end << "\n";
        chunk[i].start = start;
        chunk[i].end = end;
        chunk[i].product = &multiplication[i];
    }

    for (int i = 0; i < nThreads; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, (void *)&chunk[i]);
    }

    u_int64_t factorial = 1;
    for (int i = 0; i < nThreads; i++) {
        pthread_join(thread_id[i], NULL);
        factorial *= multiplication[i];
    }

    /* Now that all threads are complete I can print the final result.     */
    /* Without the join I could be printing a value before all the threads */
    /* have been completed.                                                */
    cout << "Final factorial value: " << factorial << endl;
 	return factorial;
}

