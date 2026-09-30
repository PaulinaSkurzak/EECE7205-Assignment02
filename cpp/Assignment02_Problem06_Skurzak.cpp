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

void siftDown(int A[], int root, int size, int &swaps){
    int child;
    while (2 * root + 1 < size) {
        child = 2 * root + 1; // left child
        if (child + 1 < size && A[child + 1] > A[child]) {
            child = child + 1; // right child exists and is greater
        }
        if (A[root] >= A[child]) {
            break;
        }
        swap(A[root], A[child]);
        swaps++;
        root = child;
    }
 }
 // Function 2: sorts arr in increasing order (the name changes per problem)
void heapSort(int A[], int n, int &swaps){
    for (int i = floor(n/2) - 1; i >= 0; i--) {
        siftDown(A, i, n, swaps);
    }
    cout << "Heap:  ";
    printArray(A, n);
    for (int end = n - 1; end > 0; end--) {
        swap(A[0], A[end]);
        swaps++;
        siftDown(A, 0, end, swaps);
        cout << "end = " << end << " heap: ";
        printArray(A, end); // print the current state of the heap
        cout << "sorted: ";
        printArray(A + end, n - end);
    }
}

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    int swaps = 0;
    heapSort(A, n, swaps); // calls printArray inside to show each step
    cout << "Sorted: ";
    printArray(A, n);
    cout << "siftDown swaps: " << swaps << endl;
    return 0;
}

// 
