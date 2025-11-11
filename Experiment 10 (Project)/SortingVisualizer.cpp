#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
using namespace std;
using namespace chrono;

int comparisons = 0;

void printArray(const vector<int> &arr) {
    for (int num : arr) cout << num << " ";
    cout << "\n";
}

void bubbleSort(vector<int> arr) {
    comparisons = 0;
    auto start = high_resolution_clock::now();

    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }

    auto end = high_resolution_clock::now();
    printArray(arr);
    cout << "Time Complexity: O(n^2)\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Taken: " << duration_cast<microseconds>(end - start).count() << " µs\n";
}

void selectionSort(vector<int> arr) {
    comparisons = 0;
    auto start = high_resolution_clock::now();

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }

    auto end = high_resolution_clock::now();
    printArray(arr);
    cout << "Time Complexity: O(n^2)\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Taken: " << duration_cast<microseconds>(end - start).count() << " µs\n";
}

void insertionSort(vector<int> arr) {
    comparisons = 0;
    auto start = high_resolution_clock::now();

    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        comparisons++;
        arr[j + 1] = key;
    }

    auto end = high_resolution_clock::now();
    printArray(arr);
    cout << "Time Complexity: O(n^2)\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Taken: " << duration_cast<microseconds>(end - start).count() << " µs\n";
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(vector<int> arr) {
    comparisons = 0;
    auto start = high_resolution_clock::now();
    mergeSortHelper(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    printArray(arr);
    cout << "Time Complexity: O(n log n)\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Taken: " << duration_cast<microseconds>(end - start).count() << " µs\n";
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int> arr) {
    comparisons = 0;
    auto start = high_resolution_clock::now();
    quickSortHelper(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    printArray(arr);
    cout << "Time Complexity: O(n log n) avg, O(n^2) worst\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Taken: " << duration_cast<microseconds>(end - start).count() << " µs\n";
}

void bucketSort(vector<int> arr) {
    comparisons = 0;
    auto start = high_resolution_clock::now();

    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<vector<int>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = (arr[i] * n) / (maxVal + 1);
        buckets[index].push_back(arr[i]);
    }

    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        comparisons += bucket.size() * log2(bucket.size() + 1); // Estimate
    }

    int idx = 0;
    for (auto& bucket : buckets)
        for (int val : bucket)
            arr[idx++] = val;

    auto end = high_resolution_clock::now();
    printArray(arr);
    cout << "Time Complexity: O(n + k), Best for uniform distribution\n";
    cout << "Comparisons (approx): " << comparisons << "\n";
    cout << "Time Taken: " << duration_cast<microseconds>(end - start).count() << " µs\n";
}

void menu(const vector<int>& original) {
    int choice;
    do {
        cout << "\nSorting Algorithm Visualizer (Console)\n";
        cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n";
        cout << "4. Merge Sort\n5. Quick Sort\n6. Bucket Sort\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: bubbleSort(original); break;
            case 2: selectionSort(original); break;
            case 3: insertionSort(original); break;
            case 4: mergeSort(original); break;
            case 5: quickSort(original); break;
            case 6: bucketSort(original); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " integers:\n";
    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    menu(arr);
    return 0;
}
