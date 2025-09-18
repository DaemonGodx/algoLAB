//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)


#include<bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>&arr,int l,int m,int h,int&cl,int&cr){
    int sum=0,left_sum=INT_MIN,max_left=m;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;max_left=i;
        }
    }
    sum=0;int right_sum=INT_MIN,max_right=m+1;
    for(int i=m+1;i<=h;i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum=sum;max_right=i;
        }
    }
    cl=max_left;
    cr=max_right;
    return left_sum+right_sum;
}

int maxSubarraySum(vector<int>&arr,int l,int h,int&sl,int&sr){
    if(l==h){
        sl=sr=l;
        return arr[l];
    }
    int m=(l+h)/2;
    int ll,lr,rl,rr,cl,cr;
    int left=maxSubarraySum(arr,l,m,ll,lr);
    int right=maxSubarraySum(arr,m+1,h,rl,rr);
    int cross=maxCrossingSum(arr,l,m,h,cl,cr);
    if(left>=right&&left>=cross){
        sl=ll;
        sr=lr;
        return left;
    }
    else if(right>=left&&right>=cross){
        sl=rl;
        sr=rr;
        return right;
    }
    else{
        sl=cl;
        sr=cr;
        return cross;
    }
}

int main(){
    vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
    int n=arr.size(),sl=0,sr=0;
    int sum=maxSubarraySum(arr,0,n-1,sl,sr);
    cout<<"Maximum Subarray: ";
    for(int i=sl;i<=sr;i++)cout<<arr[i]<<" ";
    cout<<"\nMaximum Sum="<<sum;
}