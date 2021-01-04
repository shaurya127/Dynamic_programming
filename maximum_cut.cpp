
#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b)? a : b;} 
// function that eturns the maximum 
// number of rods that can be 
// made from the rod of length N 
int cuttingRod(int n,int a,int b,int c ) 
{ 
	if(n<0) return -1;
    if(n==0) return 0;
    int res=max(cuttingRod(n-a,a,b,c),max(cuttingRod(n-b,a,b,c),cuttingRod(n-c,a,b,c)));
    if(res==-1){
        return res;
    }
    else{
        return res+1;
    }

} 

// dp solution 

int maxcuts_dp(int n,int a,int b,int c){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        if(i-a>=0) dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0) dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0) dp[i]=max(dp[i],dp[i-c]);
        if(dp[i]!=-1){
            dp[i]++;
        }
    }
    return dp[n];
}

// Driver code 
int main() 
{ 
	int N = 17; 
	int a=10,b=11,c=3;
	cout << cuttingRod(N,a,b,c)<<endl;
    cout<<maxcuts_dp(N,a,b,c)<<endl; 
	return 0; 
} 
