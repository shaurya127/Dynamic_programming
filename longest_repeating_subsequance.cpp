#include<bits/stdc++.h> 
using namespace std; 

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int  lcs( string X, string Y, int m, int n ) 
{ 
    int dp[m+1][n+1]; 
        for (int i=0; i<=m; i++) 
        { 
	        for (int j=0; j<=n; j++) 
	        { 
	        if (i == 0 || j == 0) 
		        dp[i][j] = 0; 
            // main differance is  ** i!=j **
	        else if (X[i-1] == Y[j-1] && i!=j) 
		        dp[i][j] = dp[i-1][j-1] + 1; 
	        else
		        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
	        } 
        } 
    return dp[m][n];
}

/* Driver program to test above function */
int main() 
{ 
string X = "axxxy"; 
string Y = X; 
int m=X.length();
int n=Y.length();
cout<<lcs(X, Y, m, n); 
return 0; 
} 
