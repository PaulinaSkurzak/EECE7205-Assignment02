#include <iostream>
using namespace std;
// Function 1: prints the n elements of arr on one line, separated byspaces
void printArray(const int A[], int n){
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Helper function for quicksort: partitions the array around a pivot
int partition(int A[], int low, int high, int &comparisons, int &swaps, int depth) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++; // Count the comparison
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
            swaps++; // Count the swap
             if (depth == 0) {
                cout << "i = " << i << ", j = " << j << ", pivot = " << pivot << endl;
                printArray(A + low, high - low + 1);
            }
        }   
    }
    swap(A[i + 1], A[high]);
    if (depth == 0) {
        cout << "Final position of pivot: " << i + 1 << endl;
    }
    swaps++; // Count the swap
    return i + 1;
}

// Function 2: sorts arr in increasing order (the name changes per problem)
void quickSort(int A[], int low, int high, int &comparisons, int &swaps, int depth){
    if (low < high) {
        for (int i = 0; i < depth; i++) {
            cout << "  ";
}       //print pivot and subarray here next 
        cout << "pivot: " << A[high] << ", subarray: ";
        printArray(A + low, high - low + 1);
        int p = partition(A, low, high, comparisons, swaps, depth);
        quickSort(A, low, p - 1, comparisons, swaps, depth + 1);
        quickSort(A, p + 1, high, comparisons, swaps, depth + 1);
    }
}

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    int comparisons = 0, swaps = 0;
    quickSort(A, 0, n - 1, comparisons, swaps, 0); // calls printArray inside to show each step
    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;
    cout << "\n Already Sorted Array Test" << endl;
    int sortedArr[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int n2 = sizeof(sortedArr) / sizeof(sortedArr[0]);
    cout << "Original: ";
    printArray(sortedArr, n2);
    int comparisons2 = 0, swaps2 = 0;
    quickSort(sortedArr, 0, n2 - 1, comparisons2, swaps2, 0);
    cout << "Sorted: ";
    printArray(sortedArr, n2);
    cout << "Comparisons: " << comparisons2 << " Swaps: " << swaps2 << endl;
    return 0;
}
