#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
// Function 1: prints the n elements of arr on one line, separated byspaces
void printArray(const int A[], int n){
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
//======Problem 01=========
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
        if (swapped ==false) {
            break; //no swaps in this pass, array is sorted 
        }
    }
}
//======Problem 02=========
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
        A[j + 1] = key;    }
}
//======Problem 03=========
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
    }
}
//======Problem 04=========
int partition(int A[], int low, int high, int &comparisons, int &swaps, int depth) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++; // Count the comparison
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
            swaps++; // Count the swap
        }   
    }
    swap(A[i + 1], A[high]);
    swaps++; // Count the swap
    return i + 1;
}

void quickSort(int A[], int low, int high, int &comparisons, int &swaps, int depth){
    if (low < high) {
        int p = partition(A, low, high, comparisons, swaps, depth);
        quickSort(A, low, p - 1, comparisons, swaps, depth + 1);
        quickSort(A, p + 1, high, comparisons, swaps, depth + 1);
    }
}
//======Problem 05=========
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
        int mid = floor((low + high) / 2);
        mergeSort(A, low, mid, comparisons, n, finalmergecomparisons);
        mergeSort(A, mid + 1, high, comparisons, n, finalmergecomparisons);
        merge(A, low, mid, high, comparisons, n, finalmergecomparisons);
    }
}
//======Problem 06=========
void siftDown(int A[], int root, int size, int &swaps, int &comparisons){
    int child;
    while (2 * root + 1 < size) {
        child = 2 * root + 1;
        comparisons++;
        if (child + 1 < size && A[child + 1] > A[child]) {
            child = child + 1;
        }
        comparisons++;
        if (A[root] >= A[child]) {
            break;
        }
        swap(A[root], A[child]);
        swaps++;
        root = child;
    }
}
void heapSort(int A[], int n, int &swaps, int &comparisons){
    for (int i = floor(n/2) - 1; i >= 0; i--) {
        siftDown(A, i, n, swaps, comparisons);
    }
    for (int end = n - 1; end > 0; end--) {
        swap(A[0], A[end]);
        swaps++;
        siftDown(A, 0, end, swaps, comparisons);
    }
}

//======Main=========
int main() {
    int original[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int sortedCopy[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int reversedCopy[] = {62, 34, 32, 23, 19, 14, 7, 5};
    int n = 8;

    // Problem 1
    int b1[8]; for (int i = 0; i < n; i++) b1[i] = original[i];
    int bc1 = 0, bs1 = 0;
    bubbleSort(b1, n, bc1, bs1);
    cout << "Problem 1: Original comparisons: " << bc1 << endl;

    int b2[8]; for (int i = 0; i < n; i++) b2[i] = sortedCopy[i];
    int bc2 = 0, bs2 = 0;
    bubbleSort(b2, n, bc2, bs2);
    cout << "Problem 1: Sorted comparisons: " << bc2 << endl;

    int b3[8]; for (int i = 0; i < n; i++) b3[i] = reversedCopy[i];
    int bc3 = 0, bs3 = 0;
    bubbleSort(b3, n, bc3, bs3);
    cout << "Problem 1: Reversed comparisons: " << bc3 << endl;

    // Problem 2
    int i1[8]; for (int i = 0; i < n; i++) i1[i] = original[i];
    int ic1 = 0, ish1 = 0;
    insertionSort(i1, n, ic1, ish1);
    cout << "Problem 2: Original comparisons: " << ic1 << endl;

    int i2[8]; for (int i = 0; i < n; i++) i2[i] = sortedCopy[i];
    int ic2 = 0, ish2 = 0;
    insertionSort(i2, n, ic2, ish2);
    cout << "Problem 2: Sorted comparisons: " << ic2 << endl;

    int i3[8]; for (int i = 0; i < n; i++) i3[i] = reversedCopy[i];
    int ic3 = 0, ish3 = 0;
    insertionSort(i3, n, ic3, ish3);
    cout << "Problem 2: Reversed comparisons: " << ic3 << endl;

    // Problem 3
    int s1[8]; for (int i = 0; i < n; i++) s1[i] = original[i];
    int sc1 = 0, ss1 = 0;
    selectionSort(s1, n, sc1, ss1);
    cout << "Problem 3: Original comparisons: " << sc1 << endl;

    int s2[8]; for (int i = 0; i < n; i++) s2[i] = sortedCopy[i];
    int sc2 = 0, ss2 = 0;
    selectionSort(s2, n, sc2, ss2);
    cout << "Problem 3: Sorted comparisons: " << sc2 << endl;

    int s3[8]; for (int i = 0; i < n; i++) s3[i] = reversedCopy[i];
    int sc3 = 0, ss3 = 0;
    selectionSort(s3, n, sc3, ss3);
    cout << "Problem 3: Reversed comparisons: " << sc3 << endl;

    // Problem 4    
    int q1[8]; for (int i = 0; i < n; i++) q1[i] = original[i];
    int qc1 = 0, qs1 = 0;
    quickSort(q1, 0, n - 1, qc1, qs1, 0);
    cout << "Problem 4: Original comparisons: " << qc1 << endl;

    int q2[8]; for (int i = 0; i < n; i++) q2[i] = sortedCopy[i];
    int qc2 = 0, qs2 = 0;
    quickSort(q2, 0, n - 1, qc2, qs2, 0);
    cout << "Problem 4: Sorted comparisons: " << qc2 << endl;

    int q3[8]; for (int i = 0; i < n; i++) q3[i] = reversedCopy[i];
    int qc3 = 0, qs3 = 0;
    quickSort(q3, 0, n - 1, qc3, qs3, 0);
    cout << "Problem 4: Reversed comparisons: " << qc3 << endl;

    // Problem 5
    int m1[8]; for (int i = 0; i < n; i++) m1[i] = original[i];
    int mc1 = 0, mf1 = 0;
    mergeSort(m1, 0, n - 1, mc1, n, mf1);
    cout << "Problem 5: Original comparisons: " << mc1 << endl;

    int m2[8]; for (int i = 0; i < n; i++) m2[i] = sortedCopy[i];
    int mc2 = 0, mf2 = 0;
    mergeSort(m2, 0, n - 1, mc2, n, mf2);
    cout << "Problem 5: Sorted comparisons: " << mc2 << endl;

    int m3[8]; for (int i = 0; i < n; i++) m3[i] = reversedCopy[i];
    int mc3 = 0, mf3 = 0;
    mergeSort(m3, 0, n - 1, mc3, n, mf3);
    cout << "Problem 5: Reversed comparisons: " << mc3 << endl;

    // Problem 6    
    int h1[8]; for (int i = 0; i < n; i++) h1[i] = original[i];
    int hs1 = 0, hc1 = 0;
    heapSort(h1, n, hs1, hc1);
    cout << "Problem 6: Original swaps: " << hs1 << " comparisons: " << hc1 << endl;

    int h2[8]; for (int i = 0; i < n; i++) h2[i] = sortedCopy[i];
    int hs2 = 0, hc2 = 0;
    heapSort(h2, n, hs2, hc2);
    cout << "Problem 6: Sorted swaps: " << hs2 << " comparisons: " << hc2 << endl;

    int h3[8]; for (int i = 0; i < n; i++) h3[i] = reversedCopy[i];
    int hs3 = 0, hc3 = 0;
    heapSort(h3, n, hs3, hc3);
    cout << "Problem 6: Reversed swaps: " << hs3 << " comparisons: " << hc3 << endl;

//=== Measure Time to Sort Random Arrays ===

// Step A: generate the three random arrays (sizes 1000, 5000, 10000)
int size1 = 1000;
int randomArray1000[1000];
for (int i = 0; i < size1; i++) {
    randomArray1000[i] = rand() % 100000 + 1;
}

int size2 = 5000;
int randomArray5000[5000];
for (int i = 0; i < size2; i++) {
    randomArray5000[i] = rand() % 100000 + 1;
}

int size3 = 10000;
int randomArray10000[10000];
for (int i = 0; i < size3; i++) {
    randomArray10000[i] = rand() % 100000 + 1;
}

// Bubble Sort
cout << "\n Problem 1 Sort Timing " << endl;
{
    int test[1000];
    for (int i = 0; i < size1; i++) test[i] = randomArray1000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(test, size1, comp, sw);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 1000: " << duration.count() << " microseconds" << endl;
}
{
    int test[5000];
    for (int i = 0; i < size2; i++) test[i] = randomArray5000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(test, size2, comp, sw);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 5000: " << duration.count() << " microseconds" << endl;
}
{
    int test[10000];
    for (int i = 0; i < size3; i++) test[i] = randomArray10000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(test, size3, comp, sw);
    auto end = chrono::high_resolution_clock::now();
    cout << "First 10 sorted: ";
    printArray(test, 10);   
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 10000: " << duration.count() << " microseconds" << endl;
}

// Insertion Sort
cout << "\n Problem 2 Sort Timing " << endl;
{
    int test[1000];
    for (int i = 0; i < size1; i++) test[i] = randomArray1000[i];
    int comp = 0, sh = 0;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(test, size1, comp, sh);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 1000: " << duration.count() << " microseconds" << endl;
}
{
    int test[5000];
    for (int i = 0; i < size2; i++) test[i] = randomArray5000[i];
    int comp = 0, sh = 0;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(test, size2, comp, sh);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 5000: " << duration.count() << " microseconds" << endl;
}
{
    int test[10000];
    for (int i = 0; i < size3; i++) test[i] = randomArray10000[i];
    int comp = 0, sh = 0;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(test, size3, comp, sh);
    auto end = chrono::high_resolution_clock::now();
    cout << "First 10 sorted: ";
    printArray(test, 10);
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 10000: " << duration.count() << " microseconds" << endl;
}

// Selection Sort 
cout << "\n Problem 3 Sort Timing " << endl;
{
    int test[1000];
    for (int i = 0; i < size1; i++) test[i] = randomArray1000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    selectionSort(test, size1, comp, sw);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 1000: " << duration.count() << " microseconds" << endl;
}
{
    int test[5000];
    for (int i = 0; i < size2; i++) test[i] = randomArray5000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    selectionSort(test, size2, comp, sw);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 5000: " << duration.count() << " microseconds" << endl;
}
{
    int test[10000];
    for (int i = 0; i < size3; i++) test[i] = randomArray10000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    selectionSort(test, size3, comp, sw);
    auto end = chrono::high_resolution_clock::now();
    cout << "First 10 sorted (Selection): ";
    printArray(test, 10);
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 10000: " << duration.count() << " microseconds" << endl;
}

// Quick Sort
cout << "\n Problem 4 Sort Timing " << endl;
{
    int test[1000];
    for (int i = 0; i < size1; i++) test[i] = randomArray1000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    quickSort(test, 0, size1 - 1, comp, sw, 0);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 1000: " << duration.count() << " microseconds" << endl;
}
{
    int test[5000];
    for (int i = 0; i < size2; i++) test[i] = randomArray5000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    quickSort(test, 0, size2 - 1, comp, sw, 0);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 5000: " << duration.count() << " microseconds" << endl;
}
{
    int test[10000];
    for (int i = 0; i < size3; i++) test[i] = randomArray10000[i];
    int comp = 0, sw = 0;
    auto start = chrono::high_resolution_clock::now();
    quickSort(test, 0, size3 - 1, comp, sw, 0);
    auto end = chrono::high_resolution_clock::now();
    cout << "First 10 sorted: ";
    printArray(test, 10);
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 10000: " << duration.count() << " microseconds" << endl;
}

// Merge Sort
cout << "\n Problem 5 Sort Timing " << endl;
{
    int test[1000];
    for (int i = 0; i < size1; i++) test[i] = randomArray1000[i];
    int comp = 0, fmc = 0;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(test, 0, size1 - 1, comp, size1, fmc);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 1000: " << duration.count() << " microseconds" << endl;
}
{
    int test[5000];
    for (int i = 0; i < size2; i++) test[i] = randomArray5000[i];
    int comp = 0, fmc = 0;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(test, 0, size2 - 1, comp, size2, fmc);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 5000: " << duration.count() << " microseconds" << endl;
}
{
    int test[10000];
    for (int i = 0; i < size3; i++) test[i] = randomArray10000[i];
    int comp = 0, fmc = 0;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(test, 0, size3 - 1, comp, size3, fmc);
    auto end = chrono::high_resolution_clock::now();
    cout << "First 10 sorted: ";
    printArray(test, 10);
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 10000: " << duration.count() << " microseconds" << endl;
}

// Heap Sort    
cout << "\n Problem 6 Sort Timing " << endl;
{
    int test[1000];
    for (int i = 0; i < size1; i++) test[i] = randomArray1000[i];
    int sw = 0, comp = 0;
    auto start = chrono::high_resolution_clock::now();
    heapSort(test, size1, sw, comp);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 1000: " << duration.count() << " microseconds" << endl;
}
{
    int test[5000];
    for (int i = 0; i < size2; i++) test[i] = randomArray5000[i];
    int sw = 0, comp = 0;
    auto start = chrono::high_resolution_clock::now();
    heapSort(test, size2, sw, comp);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 5000: " << duration.count() << " microseconds" << endl;
}
{
    int test[10000];
    for (int i = 0; i < size3; i++) test[i] = randomArray10000[i];
    int sw = 0, comp = 0;
    auto start = chrono::high_resolution_clock::now();
    heapSort(test, size3, sw, comp);
    auto end = chrono::high_resolution_clock::now();
    cout << "First 10 sorted: ";
    printArray(test, 10);
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Size 10000: " << duration.count() << " microseconds" << endl;
}
    return 0;
}
