int Solution::solve(int A, int B)
{
    int dp[A + 1][B + 1], i, j, k, low, high, mid;
    for (i = 0; i <= A; i++)
        dp[i][0] = 0;
    for (i = 1; i <= B; i++)
        dp[0][i] = INT_MAX;
    for (i = 1; i <= B; i++)
        dp[1][i] = i;
    for (i = 1; i <= A; i++)
        dp[i][1] = 1;
    for (i = 2; i <= A; i++)
    {
        for (j = 2; j <= B; j++)
        {
            dp[i][j] = INT_MAX;
            low = 1;
            high = j;
            while (low < high)
            {
                mid = low + high;
                mid = mid / 2;
                dp[i][j] = min(dp[i][j], 1 + max(dp[i][j - mid], dp[i - 1][mid - 1]));
                if (dp[i - 1][mid - 1] < dp[i][j - mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    return dp[A][B];
}