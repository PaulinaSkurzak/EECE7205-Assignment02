#include <iostream>
using namespace std;
// Function 1: prints the n elements of arr on one line, separated byspaces
void printArray(const int A[], int n){
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
// Function 2: sorts arr in increasing order (the name changes per problem)
void selectionSort(int A[], int n, int &comparisons, int &swaps){
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        int minValue = A[minIndex]; // capture before the swap happens
        if (minIndex != i) {
            swap(A[i], A[minIndex]);
            swaps++;
        }
        cout << "min = " << minValue << " at index " << minIndex << ": ";
        printArray(A, n); // show the array after each pass
    }
}

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    int comparisons = 0, swaps = 0;
    selectionSort(A, n, comparisons, swaps); // calls printArray inside to show each step
    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;
    return 0;
}

// 
