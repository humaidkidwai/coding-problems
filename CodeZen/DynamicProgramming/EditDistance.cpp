#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){

    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int m = s1.size(), n = s2.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++)
        dp[0][i] = i;
    for(int j = 0; j <= m; j++)
        dp[j][0] = j;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[m - i] == s2[n - j])
                dp[i][j] = dp[i - 1][j - 1];
            else{
                dp[i][j] = min(min(1 + dp[i-1][j-1],1 + dp[i][j-1]),1 + dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
