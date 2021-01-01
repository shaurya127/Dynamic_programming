#include <bits/stdc++.h>
using namespace std;

int dp[151][151][2];

int waystocount(string s, int i,int j,bool istrue){
    // base case
    if(i>j) return 0;
    if(i==j){
        if(istrue){
            return 'T'==s[i];
        }
        else{
            return 'F'==s[i];
        }
    }
    int ans=0;
    if(dp[i][j][istrue]!=-1){
        return dp[i][j][istrue];
    }
    for(int k=i+1;k<j;k=k+2){
        int lefttrue=waystocount(s,i,k-1,true);
        int leftfalse=waystocount(s,i,k-1,false);
        int righttrue=waystocount(s,k+1,j,true);
        int rightfalse=waystocount(s,k+1,j,false);
        // based on operator
        if(s[k]=='^'){
            if(istrue){
                ans=ans+lefttrue*rightfalse+leftfalse*righttrue;
            }
            else{
                ans=ans+leftfalse*rightfalse+lefttrue*righttrue;
            }
        }
        else if(s[k]=='|'){
            if(istrue){
                ans+=lefttrue*rightfalse+leftfalse*righttrue+lefttrue*righttrue;
            }
            else{
                ans+=leftfalse*rightfalse;
            }
        }
        else{
            if(istrue){
                ans+=lefttrue*righttrue;
            }
            else{
                ans+=leftfalse*rightfalse+leftfalse*righttrue+lefttrue*rightfalse;
            }
        }
    }
    return dp[i][j][istrue]=ans;
}


int main() {
    string s="T^T^F";
    int n=s.length();
    memset(dp,-1,sizeof(dp));
    int res=waystocount(s,0,n-1,true);
    cout<<res;
}
