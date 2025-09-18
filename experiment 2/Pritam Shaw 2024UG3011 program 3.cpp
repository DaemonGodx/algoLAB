//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)


#include <bits/stdc++.h>
using namespace std;

void getMinMax(vector<int>&arr,int low,int high,int &mn,int &mx){
    if(low==high){
        if(arr[low]<mn) mn=arr[low];
        if(arr[low]>mx) mx=arr[low];
        return;
    }
    if(high==low+1){
        if(arr[low]<arr[high]){
            if(arr[low]<mn) mn=arr[low];
            if(arr[high]>mx) mx=arr[high];
        }else{
            if(arr[high]<mn) mn=arr[high];
            if(arr[low]>mx) mx=arr[low];
        }
        return;
    }
    int mid=(low+high)/2;
    getMinMax(arr,low,mid,mn,mx);
    getMinMax(arr,mid+1,high,mn,mx);
}

int main(){
    vector<int>arr={100,11,445,1,330,3000};
    cout<<"Array: ";
    for(int x:arr) cout<<x<<" ";
    cout<<"\n";
    int mn=INT_MAX,mx=INT_MIN;
    getMinMax(arr,0,arr.size()-1,mn,mx);
    cout<<"Minimum = "<<mn<<"\n";
    cout<<"Maximum = "<<mx<<"\n";
}
