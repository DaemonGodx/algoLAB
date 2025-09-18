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
        compaisons++;
        int swaped=false;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                {swaped=true; swaps++;}
            }
        }
        if(!swaped) break;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"TotalSwaps:"<<swaps<<endl;;
     cout<<"Totalcomprisons:"<<compaisons;
}