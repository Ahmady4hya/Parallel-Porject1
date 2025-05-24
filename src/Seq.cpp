#include <iostream>
#include <type_traits>
#include <chrono>
using namespace std::chrono;
using namespace std;

void oddEvenSort(int arr[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;

        // Odd phase
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        // Even phase
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}

int main() {
    cout << "Enter size: ";
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    oddEvenSort(arr, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms\n";
    return 0;
}
