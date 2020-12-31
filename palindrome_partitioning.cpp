#include<bits/stdc++.h>
using namespace std;

bool ispalindrom(string s){
    string temp=s;
    reverse(s.begin(),s.end());
    return temp==s;
}

// recursion
int minPalPartion(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalindrom(s)){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=minPalPartion(s,i,k)+minPalPartion(s,k+1,j)+1;
        if(temp<ans){
            ans=min(temp,ans);
        }
    }
    return ans;
}


// memoization

int dp[1001][1001];
int minPalPartion_momo(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalindrom(s)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=minPalPartion(s,i,k)+minPalPartion(s,k+1,j)+1;
        if(temp<ans){
            ans=min(temp,ans);
        }
    }
    return dp[i][j]=ans;
}

int main() 
{ 
    memset(dp,-1,sizeof(dp));
    string str = "shs"; 
    // cout << "Min cuts needed for Palindrome"
    //         " Partitioning is "
    //      << minPalPartion(str,1,str.length()-1); 
    cout << "Min cuts needed for Palindrome"
            " Partitioning is "
         << minPalPartion_momo(str,1,str.length()-1); 
    return 0; 
} 