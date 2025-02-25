#include <bits/stdc++.h>
using namespace std;

// Function to print the current state of the array
void printVector(int ar[], int n) {
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}

// Function to merge two sorted halves of the array
void merge(int ar[], int l, int m, int r, int n) {
    int ls = m - l + 1;  // Size of left subarray
    int rs = r - m;      // Size of right subarray

    // Create temporary arrays to hold the left and right subarrays
    vector<int> L(ls), R(rs);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < ls; i++)
        L[i] = ar[l + i];
    for (int i = 0; i < rs; i++)
        R[i] = ar[m + 1 + i];

    int cur = l, i = 0, j = 0;

    // Merge the two subarrays back into the main array
    while (i < ls && j < rs) {
        if (L[i] <= R[j])
            ar[cur++] = L[i++];
        else
            ar[cur++] = R[j++];
    }

    // Copy any remaining elements of L[]
    while (i < ls)
        ar[cur++] = L[i++];

    // Copy any remaining elements of R[]
    while (j < rs)
        ar[cur++] = R[j++];

    // Print the array after merging two subarrays
    printVector(ar, n);
}

// Function to perform Merge Sort recursively
void mergeSort(int ar[], int l, int r, int n) {
    if (l >= r) // Base case: if left index is greater or equal to right, stop recursion
        return;

    int m = l + (r - l) / 2; // Calculate the middle index

    // Recursively sort the first half
    mergeSort(ar, l, m, n);
    // Recursively sort the second half
    mergeSort(ar, m + 1, r, n);

    // Merge the two sorted halves
    merge(ar, l, m, r, n);
}

int main() {
    int n;
    cin >> n; // Input size of array
    vector<int> ar(n);

    // Input array elements
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    // Print the initial array before sorting
    cout << "Initial Array: ";
    printVector(ar.data(), n);

    // Call mergeSort function
    mergeSort(ar.data(), 0, n - 1, n);

    // Print the sorted array
    cout << "Sorted Array: ";
    printVector(ar.data(), n);

    return 0;
}
