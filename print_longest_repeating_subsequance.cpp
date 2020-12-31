
#include<bits/stdc++.h> 
using namespace std; 

/* Returns length of LRS for X[0..m-1], Y[0..n-1] */
void lrs( string X, string Y, int m, int n ) 
{ 
int dp[m+1][n+1]; 

/* Following steps build L[m+1][n+1] in bottom up fashion. Note 
	that L[i][j] contains length of LRS of X[0..i-1] and Y[0..j-1] */
for (int i=0; i<=m; i++) 
{ 
	for (int j=0; j<=n; j++) 
	{ 
	if (i == 0 || j == 0) 
		dp[i][j] = 0; 
	else if (X[i-1] == Y[j-1] && i!=j ) 
		dp[i][j] = dp[i-1][j-1] + 1; 
	else
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
	} 
} 

// result string to store the lcs

string result;
// Start from the right-most-bottom-most corner and 
// one by one store characters in lcs[] 
int i = m, j = n; 
while (i > 0 && j > 0) 
    { 
        // If this cell is same as diagonally 
        // adjacent cell just above it, then  
        // same characters are present at  
        // str[i-1] and str[j-1]. Append any  
        // of them to result. 
        if (dp[i][j] == dp[i-1][j-1] + 1) 
        { 
           result.push_back(X[i-1]); 
           i--; 
           j--; 
        } 
  
        // Otherwise we move to the side 
        // that that gave us maximum result 
        else if (dp[i][j] == dp[i-1][j]) 
            i--; 
        else
            j--; 
    } 

reverse(result.begin(),result.end());
// Print the lcs 
cout << "LRS of " << X << " and " << Y << " is " << result; 
} 

/* Driver program to test above function */
int main() 
{ 
string X = "AABEBCDD"; 
string Y = X; 
int m=X.length();
int n=Y.length();
lcs(X, Y, m, n); 
return 0; 
} 