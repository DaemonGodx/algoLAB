#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
    cin>>n;
    int  arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
     int swaps=0,compaisons=0;
     for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            compaisons++;
            if(arr[j]<arr[min])
            min=j;
        }
        if(min!=i){
        swaps++;
        swap(arr[i],arr[min]);
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
     cout<<endl;
     cout<<"TotalSwaps:"<<swaps<<endl;;
    cout<<"Totalcomprisons:"<<compaisons;
    
    
 }