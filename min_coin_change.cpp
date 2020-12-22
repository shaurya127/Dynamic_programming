#include <bits/stdc++.h>
using namespace std;

// Top down approach

int mincoins(int n,int coins[],int T,int dp[]){
    // base case
    if(n==0)
        return 0;
    // lOokup
    if(dp[n]!=0){
        return dp[n];
    }
    // recursive case
    int ans=INT_MAX;
    for(int i=0;i<T;i++){
        if(n-coins[i]>=0){
            int subprob=mincoins(n-coins[i],coins,T,dp);
            ans=min(ans,subprob+1);
        }
    }
    dp[n]=ans;
    return dp[n];
}

// bottom-up approach

int mincoinsBU(int size,int coins[],int T){
    int dp[100]={0};
    // Iterate over all the case 1...N
    for(int n=1;n<=size;n++){
        dp[n]=INT_MAX;
        for(int i=0;i<T;i++){
            if(n-coins[i]>=0){
                int subprob=dp[n-coins[i]];
                dp[n]=min(dp[n],subprob+1);
            }
        }
    }
    return dp[size];
}

int main() {
    int N=15;
    int coins[]={1,7,10};
    int dp[100]={0};
    int T=sizeof(coins)/sizeof(int);
    // cout<<mincoins(N,coins,T,dp);
    cout<<mincoinsBU(N,coins,T);
}
