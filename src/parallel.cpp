#include <iostream>
#include <pthread.h>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int* a;
int n;
int numThreads;
volatile bool globalSorted = false;  // volatile for visibility
pthread_barrier_t barrier;
bool* localSortedArr;                 // array to collect thread-local sorted flags

struct ThreadArgs {
    int id;
};

void* threadFunc(void* arg) {
    ThreadArgs* args = (ThreadArgs*) arg;
    int id = args->id;

    while (true) {
        localSortedArr[id] = true;

        // Odd phase
        for (int i = 1 + 2 * id; i < n - 1; i += 2 * numThreads) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                localSortedArr[id] = false;
            }
        }
        pthread_barrier_wait(&barrier);

        // Even phase
        for (int i = 0 + 2 * id; i < n - 1; i += 2 * numThreads) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                localSortedArr[id] = false;
            }
        }
        pthread_barrier_wait(&barrier);

        if (id == 0) {
            bool allSorted = true;
            for (int i = 0; i < numThreads; i++) {
                allSorted = allSorted && localSortedArr[i];
            }
            globalSorted = allSorted;
        }
        pthread_barrier_wait(&barrier);

        if (globalSorted)
            break;
    }

    return nullptr;
}

int main() {
    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter number of threads: ";
    cin >> numThreads;

    a = new int[n];
    localSortedArr = new bool[numThreads];

    for (int i = 0; i < n; i++) a[i] = rand() % 10000;


    pthread_t threads[numThreads];
    ThreadArgs args[numThreads];
    pthread_barrier_init(&barrier, NULL, numThreads);

    auto start = high_resolution_clock::now();

    for (int i = 0; i < numThreads; i++) {
        args[i].id = i;
        pthread_create(&threads[i], NULL, threadFunc, &args[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms\n";

    delete[] a;
    delete[] localSortedArr;
    pthread_barrier_destroy(&barrier);

    return 0;
}
