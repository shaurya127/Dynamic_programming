
#include <bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 
int solverec(int p[], int i, int j) 
{ 
	if (i == j) 
		return 0; 
	int k; 
	int min = INT_MAX; 
	int count; 

	// place parenthesis at different places 
	// between first and last matrix, recursively 
	// calculate count of multiplications for 
	// each parenthesis placement and return the 
	// minimum count 
	for (k = i; k < j; k++) 
	{ 
		count = MatrixChainOrder(p, i, k) 
				+ MatrixChainOrder(p, k + 1, j) 
				+ p[i - 1] * p[k] * p[j]; 

		if (count < min) 
			min = count; 
	} 

	// Return minimum count 
	return min; 
} 


// memoization

int dp[1001][1001];

int solvememo(int arr[],int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<min){
            min=temp;
        }
    }
    // before returning the answer lets store in dp array
    return dp[i][j]=min;
}

// Driver Code 
int main() 
{ 
    memset(dp,-1,sizeof(dp));
	int arr[] = { 1, 2, 3, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Minimum number of multiplications is "
		<< solvememo(arr, 1, n - 1); 
} 

