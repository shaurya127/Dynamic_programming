#include<bits/stdc++.h>
using namespace std;
// Road cutting problem
int Road_cutting(int wt[],int val[],int n,int W){
        int dp[n+1][W+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<W+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(wt[i-1]<=j){
                    // here is only difference if select a any time then also we call on n

                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][W];
}

int main(){
    int length[]={1,2,3,4,5,6,7,8};
    // price of rod of length N
    int price[]={1,5,8,9,10,17,17,20};
    int n=sizeof(price)/sizeof(price[0]);
    // length of rod
    int N=8;
    cout<<"maximum profit is "<<Road_cutting(length,price,n,N);

}