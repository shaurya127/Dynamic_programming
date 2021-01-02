#include <bits/stdc++.h>
using namespace std;
int LIS(int arr[],int n){
    // first create a lis array 
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    // take maximum in lis[] array
    int res=lis[0];
    for(int i=1;i<n;i++){
        res=max(res,lis[i]);
    }
    return res;
}


int main() {
    int arr[]={50, 3, 10, 7, 40, 80};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<LIS(arr,n);
   
}
