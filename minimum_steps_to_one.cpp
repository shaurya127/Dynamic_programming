#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/* n->1
we can perform these three operations to reduce n to 1
1. n=>n/3 if n%3==0
2. n=>n/2 if n%2==0
3. n-1

f(n)=min(x,y,z)+1
f(n)=min(f(n/3)+f(n/2)+f(n-1))+1

*/

// Top down approach 

int minsteps(int n,int dp[]){
    // base case if n=1 then it is already 1 so we simply return 0
    if(n==1)
        return 0;
    // recursive case
    if(dp[n]!=0){
        return dp[n];
    }
    // otherwise we have three options 
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0){
        op1=minsteps(n/3,dp)+1;
    }
    if(n%2==0){
        op2=minsteps(n/2,dp)+1;
    }
    op3=minsteps(n-1,dp)+1;
    int ans=min(min(op1,op2),op3);
    return dp[n]=ans;
}

// BottomUp approach

int minstepsBU(int n){
    int dp[100]={0};
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(n%3==0){
            op1=dp[i/3];
        }
        if(n%2==0){
            op2=dp[i/2];
        }
        op3=dp[i-1];
        dp[i]=min(min(op1,op2),op3)+1;
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int dp[100]={0};
    // int res=minsteps(n,dp);
    int res=minstepsBU(n);
    cout<<res;
    return 0;

}
