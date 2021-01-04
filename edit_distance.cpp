
#include <bits/stdc++.h>
using namespace std;
 
 int min(int x, int y, int z) { return min(min(x, y), z); }
int editDist(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
 
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,
                          n - 1) // Replace
             );
}
 
// // memoization
int dp[501][501]; // globallay declare

int editDist_memo(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return dp[m][n]=editDist_memo(str1, str2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 
          dp[m][n]=1 + min(editDist_memo(str1, str2, m, n - 1), // Insert
                 editDist_memo(str1, str2, m - 1, n), // Remove
                 editDist_memo(str1, str2, m - 1,
                          n - 1) // Replace
             );
}

// top-down

int editdistance_topdown(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=0;j<=n;j++)
        dp[0][j]=j;
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
    
}


int main()
{
    memset(dp,-1,sizeof(dp));
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
 
    // cout << editDist(str1, str2, str1.length(),
    //                  str2.length());

    // cout << editDist_memo(str1, str2, str1.length(),
    //                  str2.length());
    
    cout << editdistance_topdown(str1, str2, str1.length(),
                     str2.length());
    return 0;
}