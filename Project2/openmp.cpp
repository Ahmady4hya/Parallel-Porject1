#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void oddEvenSortOMP(int arr[], int n, int numThreads) {
    bool sorted = false;

    omp_set_num_threads(numThreads);

    while (!sorted) {
        sorted = true;

        // Odd phase
        #pragma omp parallel for schedule(static)
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                #pragma omp critical
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        // Even phase
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                #pragma omp critical
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}

int main() {
    int n, numThreads;

    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter number of threads: ";
    cin >> numThreads;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    cout << "Original array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    auto start = high_resolution_clock::now();

    oddEvenSortOMP(arr, n, numThreads);

    auto end = high_resolution_clock::now();

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms\n";

    delete[] arr;
    return 0;
}
