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
void insertionSort(int A[], int n, int &comparisons, int &shifts){
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            comparisons++;
            A[j + 1] = A[j];
            shifts++;
            j--;
        }
        if (j >= 0) comparisons++; // for the last comparison when while condition fails
        A[j + 1] = key;
        cout << "i = " << i << ", key = " << key << ": ";
        printArray(A, n); // show the array after each pass
    }
}

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    int comparisons = 0, shifts = 0;
    insertionSort(A, n, comparisons, shifts); // calls printArray inside to show each step
    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << " Shifts: " << shifts << endl;

    cout << "\n Fewest Shifts Test" << endl;
    int arr1[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original: ";
    printArray(arr1, n1);
    int comp1 = 0, shift1 = 0;
    insertionSort(arr1, n1, comp1, shift1);
    cout << "Sorted: ";
    printArray(arr1, n1);
    cout << "Comparisons: " << comp1 << "Shifts: " << shift1 << endl;

    cout << "\n Most Shifts Test" << endl;
    int arr2[] = {62, 34, 32, 23, 19, 14, 7, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original: ";
    printArray(arr2, n2);
    int comp2 = 0, shift2 = 0;
    insertionSort(arr2, n2, comp2, shift2);
    cout << "Sorted: ";
    printArray(arr2, n2);
    cout << "Comparisons: " << comp2 << " Shifts: " << shift2 << endl;
        return 0;
}

// 
