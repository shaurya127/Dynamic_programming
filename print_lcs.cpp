/* Dynamic Programming implementation of LCS problem */
#include<bits/stdc++.h> 
using namespace std; 

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( string X, string Y, int m, int n ) 
{ 
int dp[m+1][n+1]; 

/* Following steps build L[m+1][n+1] in bottom up fashion. Note 
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (int i=0; i<=m; i++) 
{ 
	for (int j=0; j<=n; j++) 
	{ 
	if (i == 0 || j == 0) 
		dp[i][j] = 0; 
	else if (X[i-1] == Y[j-1]) 
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
	// If current character in X[] and Y are same, then 
	// current character is part of LCS 
	if (X[i-1] == Y[j-1]) 
	{ 
        result.push_back(X[i-1]);
		// lcs[index-1] = X[i-1]; // Put current character in result 
		i--; j--;  // reduce values of i, j and index 
	} 
    else{
        if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
} 

reverse(result.begin(),result.end());
// Print the lcs 
cout << "LCS of " << X << " and " << Y << " is " << result; 
} 

/* Driver program to test above function */
int main() 
{ 
string X = "abcdgh"; 
string Y = "abedfhr"; 
int m=X.length();
int n=Y.length();
lcs(X, Y, m, n); 
return 0; 
} 
