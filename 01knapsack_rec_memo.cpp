
//0-1 Knapsack problem 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 

	// Base Case 
	if (n == 0 || W == 0) 
		return 0; 

	// rec case
    // here are two case 1. if weight of item is graeter than weight of bag
    // in this condition we simply not add to bag and remove from weight array
    // 2. if wt of item is less or equal to wt of bag in this case we add this
    // wt to our bag and decrese bag size by item weight
	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included 
	else
		return max( 
			val[n - 1] 
				+ knapSack(W - wt[n - 1], 
						wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 


// memoisation code

int dp[10][20];


int knapSack(int W, int wt[], int val[], int n) 
{ 

	// Base Case 
	if (n == 0 || W == 0) 
		return 0; 
    if(dp[n][W]!=-1){
        return dp[n][W];
    }

	if (wt[n - 1] > W) 
		return dp[n][W]=knapSack(W, wt, val, n - 1); 
	else
		return dp[n][W]= max( 
			val[n - 1] 
				+ knapSack(W - wt[n - 1], 
						wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 

// Driver code 
int main() 
{ 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
	// int val[] = { 1, 3, 4,5 }; 
	// int wt[] = { 1, 4, 5,7 }; 
	// int W = 7; 
    memset(dp,-1,sizeof(dp));
	int n = sizeof(val) / sizeof(val[0]); 
	cout << knapSack(W, wt, val, n); 
	return 0; 
} 

