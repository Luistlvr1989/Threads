#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

#define NUM_THREADS 10

int counter = 0;

void threadAction(int id);

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tThreads" << endl;
    cout << "===========================================================" << endl << endl;

    thread threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i] = thread(threadAction, i);
    }

    // We have to wait for the threads, otherwise the main thread may finish first
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    return EXIT_SUCCESS;
}

void threadAction(int id) {
    printf("(%d) counter = %d\n", id, ++counter);
}