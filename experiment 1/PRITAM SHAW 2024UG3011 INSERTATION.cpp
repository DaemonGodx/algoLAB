#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
    cin>>n;
    int  arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
     int swaps=0,compaisons=0;
     for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
         compaisons++;
        while(j>0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
             swaps++;
        }
        arr[j+1]=temp;
    }
     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
     cout<<endl;
     cout<<"TotalSwaps:"<<swaps<<endl;;
    cout<<"Totalcomprisons:"<<compaisons;
}
    