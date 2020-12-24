#include<bits/stdc++.h>
using namespace std;
// coin change problem
int coins_change(int coins[],int n,int sum){
        int dp[n+1][sum+1];
        for(int i=0;i<sum+1;i++){
            dp[0][i]=0;
        }
        for(int j=0;j<n+1;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coins[i-1]<=j){
                    // here is only difference if select a any time then also we call on n

                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
}

int main(){
    int coins[] = {1, 2, 3}; 
    int m = sizeof(coins)/sizeof(coins[0]); 
    int sum = 4; 
    cout << coins_change(coins, m, sum); 

}