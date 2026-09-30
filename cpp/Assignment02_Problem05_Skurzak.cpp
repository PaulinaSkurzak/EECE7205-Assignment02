#include <iostream>
#include <cmath>
using namespace std;
// Function 1: prints the n elements of arr on one line, separated byspaces
void printArray(const int A[], int n){
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
// Function 2: sorts arr in increasing order (the name changes per problem)

void merge(int A[], int low, int mid, int high, int &comparisons, int n, int &finalmergecomparisons) {
    int L[mid - low + 1];
    for (int i = 0; i < mid - low + 1; i++) {
        L[i] = A[low + i];
    }

    int R[high - mid];
    for (int i = 0; i < high - mid; i++) {
        R[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < mid - low + 1 && j < high - mid) {
        comparisons++;
        if (low == 0 && high == n - 1)
            finalmergecomparisons++;

        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < mid - low + 1) {
        A[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < high - mid) {
        A[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(int A[], int low, int high, int &comparisons, int n, int &finalmergecomparisons){
    if (low < high) {
        cout << "Split: ";
        printArray(A + low, high - low + 1);
        int mid = floor((low + high) / 2);
        mergeSort(A, low, mid, comparisons, n, finalmergecomparisons);
        mergeSort(A, mid + 1, high, comparisons, n, finalmergecomparisons);
        merge(A, low, mid, high, comparisons, n, finalmergecomparisons);
        cout << "Merge: ";
        printArray(A + low, high - low + 1);
    }
}

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    int comparisons = 0;
    int finalmergecomparisons = 0;
    mergeSort(A, 0, n - 1, comparisons, n, finalmergecomparisons); // calls printArray inside to show each step
    cout << "Final merge comparisons: " << finalmergecomparisons << endl;
    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << endl;
    cout << "\n Sorted Array Test" << endl;
    int sortedArr[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int n2 = sizeof(sortedArr) / sizeof(sortedArr[0]);
    cout << "Original: ";
    printArray(sortedArr, n2);
    int comp2 = 0, fmc2 = 0;
    mergeSort(sortedArr, 0, n2 - 1, comp2, n2, fmc2);
    cout << "Sorted: ";
    printArray(sortedArr, n2);
    cout << "Comparisons: " << comp2 << endl;
    cout << "\n Reversed Array Test" << endl;
    int reversedArr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    int n3 = sizeof(reversedArr) / sizeof(reversedArr[0]);
    cout << "Original: ";
    printArray(reversedArr, n3);
    int comp3 = 0, fmc3 = 0;
    mergeSort(reversedArr, 0, n3 - 1, comp3, n3, fmc3);
    cout << "Sorted: ";
    printArray(reversedArr, n3);
    cout << "Comparisons: " << comp3 << endl;
    return 0;
}

// 
