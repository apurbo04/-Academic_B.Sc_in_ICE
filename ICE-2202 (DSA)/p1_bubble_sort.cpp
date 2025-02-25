#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int> &v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                printVector(v); // Print after each swap
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << "Initial Array: ";
    printVector(v); // Print initial array
    
    bubbleSort(v, n);
    
    cout << "Sorted Array: ";
    printVector(v); // Print final sorted array
    
    return 0;
}
