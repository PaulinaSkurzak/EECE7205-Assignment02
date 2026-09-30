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
void bubbleSort(int A[], int n, int &comparisons, int &swaps){
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; //reset once per pass
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                swaps++;
                swapped = true; //mark that this pass did something
            }
        }
        printArray(A, n); // show the array after each pass
        if (swapped ==false) {
            break; //no swaps in this pass, array is sorted 
        }
    }
}

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    int comparisons = 0, swaps = 0;
    bubbleSort(A, n, comparisons, swaps); // calls printArray inside to show each step
    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;

    cout << "\nAlready Sorted Test" << endl;
    int sortedArray[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int n2 = sizeof(sortedArray) / sizeof(sortedArray[0]);
    cout << "Original: ";
    printArray(sortedArray, n2);
    int comparisons2 = 0, swaps2 = 0;
    bubbleSort(sortedArray, n2, comparisons2, swaps2);
    cout << "Sorted: ";
    printArray(sortedArray, n2);
    cout << "Comparisons: " << comparisons2 << " Swaps: " << swaps2 << endl;
    return 0;
}

// 
