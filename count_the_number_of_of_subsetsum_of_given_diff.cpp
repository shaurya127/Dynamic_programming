#include <iostream>
using namespace std;
// count the number of of subsetsum of given diff

int countbsetsum(int arr[],int sum,int n){
    int dp[n+1][sum+1];
    //initialization of dp array of column
    for(int i=0;i<sum+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}


int main() {

   int arr[]={1,1,2,3};
   int diff=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    // we use simple math for find this equation
    int subsetsum=diff+sum/2;
   cout<<countbsetsum(arr,subsetsum,n);
  return 0;
}