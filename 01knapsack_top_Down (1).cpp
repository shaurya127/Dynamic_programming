#include <iostream>
using namespace std;
// top down approach of 0/1 knapsack problem
int kanpsack(int wt[],int val[],int W,int n){
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            // initialization(base case of recursion)
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            // check with item weight
            else if(wt[i-1]<=j){
                dp[i][j]=max( (val[i-1]+dp[i-1][j-wt[i-1]]), dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W=50;
    int n=sizeof(val)/sizeof(val[0]);
    int res=kanpsack(wt,val,W,n);
    cout<<res<<endl;
}
