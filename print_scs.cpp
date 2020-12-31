/* Dynamic Programming implementation of SCS problem */
#include<bits/stdc++.h> 
using namespace std; 

/* Returns length of SCS for X[0..m-1], Y[0..n-1] */
void lcs( string X, string Y, int m, int n ) 
{ 
int dp[m+1][n+1]; 

/* Following steps build L[m+1][n+1] in bottom up fashion. Note 
	that dp[i][j] contains length of SCS of X[0..i-1] and Y[0..j-1] */
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

// result string to store the scs

string result;
// Start from the right-most-bottom-most corner and 
// one by one store characters in scs[] 
int i = m, j = n; 
while (i > 0 && j > 0) 
{ 
	// If current character in X[] and Y are same, then 
	// current character is part of SCS 
	if (X[i-1] == Y[j-1]) 
	{ 
        result.push_back(X[i-1]);
		i--; j--;  // reduce values of i, j and index 
	} 
    else{
        if(dp[i-1][j]>dp[i][j-1]){
            result.push_back(X[i-1]);
            i--;
        }
        else{
            result.push_back(Y[j-1]);
            j--;
        }
    }
} 

while(i>0){
    result.push_back(X[i-1]);
    i--;
}
while(j>0){
    result.push_back(Y[j-1]);
    j--;
}


reverse(result.begin(),result.end());
// Print the scs 
cout << "SCS of " << X << " and " << Y << " is " << result; 
} 

/* Driver program to test above function */
int main() 
{ 
   
string  X = "AGGTAB" ;
string  Y = "GXTXAYB" ;
int m=X.length();
int n=Y.length();
lcs(X, Y, m, n); 
return 0; 
} 
