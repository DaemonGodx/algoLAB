//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)
//Experiment-3 Task-1-Implementation of Radix Sort
#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);
    for (int i = 0; i < arr.size(); i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < arr.size(); i++) arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10) countSort(arr, exp);
}

int main() {
    int n;cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    radixSort(arr);
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}