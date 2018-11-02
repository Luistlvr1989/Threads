#include <iostream>
#include <thread>

using namespace std;

#define NUM_THREADS 10

void threadAction(int id);

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tThreads" << endl;
    cout << "===========================================================" << endl << endl;

    thread threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i] = thread(threadAction, i);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    return EXIT_SUCCESS;
}

void threadAction(int id) {
    cout << "Launched by thread " << id << endl;
}