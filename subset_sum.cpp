#include <iostream>
using namespace std;
// subset sum problem

bool issubsetsum(int arr[],int sum,int n){
    int dp[n+1][sum+1];
    //initialization of dp array of column
    for(int i=0;i<sum+1;i++){
        dp[0][i]=false;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
   int arr[]={3, 34, 4, 12, 5, 2};
   int sum=9;
    int n=sizeof(arr)/sizeof(arr[0]);
  
    cout<<issubsetsum(arr,sum,n)<<endl;
}
