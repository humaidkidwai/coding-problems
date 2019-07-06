#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){

    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int dp[row+1][col+1],count = 1;

    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= row; i++)
        dp[i][1] = arr[i-1][0] ^ 1;

    for(int i = 1; i <= col; i++)
        dp[1][i] = arr[0][i-1] ^ 1;

    for(int i = 2; i <= row; i++)
        for(int j = 2; j <= col; j++)
            if(arr[i-1][j-1] == 0){
                dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
                count = max(count,dp[i][j]);
            }

    return count;
}