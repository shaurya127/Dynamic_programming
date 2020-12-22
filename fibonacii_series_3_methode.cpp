#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//function to calculate to fibonachi series
// Recursive Approach -> O(2^n) Time complexity which is not good
// so for improve time complexity of this problem DP is come in piture

int fib(int n){
    // base case
    if(n==0 || n==1)
        return n;
    // recursive case
    return fib(n-1)+fib(n-2);
}

// In DP we have two methode
// 1. Top down Approach (Recursion + memoisation)
// 2. Bottom Up Approch (DP Array)

// Top down solutinon

int fibTD(int n,int dp[]){
    // base case
    if(n==0 || n==1)
        return n;
    // if dp array is already calculate then simply return it 
    if(dp[n]!=0){
        return dp[n];
    }
    // if not calculated then calculate it and return
    int ans;
    ans=fibTD(n-1,dp)+fibTD(n-2,dp);
    return dp[n]=ans;   
}

// Bottom-up approach  -> O(n) solution 

int fibBU(int n){
    int dp[1000]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;cin>>n;
    // make dp array
    int dp[1000]={0};
    // int res=fibTD(n,dp);
    int res=fibBU(n);

    //int res=fib(n);
    cout<<res<<endl; 
    return 0;  
}
