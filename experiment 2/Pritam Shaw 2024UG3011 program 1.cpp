//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(vector<int>&arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    vector<int>arr={10,7,8,9,1,5};
    cout<<"Initial: ";
    for(int x:arr)cout<<x<<" ";
    cout<<"\n";
    quicksort(arr,0,arr.size()-1);
    cout<<"Sorted: ";
    for(int x:arr)cout<<x<<" ";
}
