//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)



#include<bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int>&arr,int&sl,int&sr){
    int max_sum=INT_MIN,curr_sum=0,temp_start=0;
    for(int i=0;i<arr.size();i++){
        curr_sum+=arr[i];
        if(curr_sum>max_sum){
            max_sum=curr_sum;
            sl=temp_start;
            sr=i;}
        if(curr_sum<0){
            curr_sum=0;
            temp_start=i+1;
        }
    }
    return max_sum;
}

int main(){
    vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
    int sl=0,sr=0;
    int sum=maxSubarray(arr,sl,sr);
    cout<<"Maximum Subarray: ";
    for(int i=sl;i<=sr;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Maximum Sum="<<sum;
}