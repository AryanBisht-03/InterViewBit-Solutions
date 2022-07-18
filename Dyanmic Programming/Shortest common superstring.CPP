int commonPrefixSuffix(string s1, string s2)
{
    int ans = 0;
    for (int i = min(s1.size(), s2.size()); i > 0; i--)
    {
        if (s1.substr(s1.size() - i) == s2.substr(0, i))
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int Solution::solve(vector<string> &A)
{
    int n = A.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    vector<vector<int>> match(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            match[i][j] = commonPrefixSuffix(A[i], A[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[1 << i][i] = A[i].size();
    }
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) > 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if ((i & (1 << k)) > 0 && k != j)
                    {
                        int len = dp[i ^ (1 << j)][k] + A[j].substr(match[k][j]).size();
                        if (dp[i][j] == 0 || len < dp[i][j])
                        {
                            dp[i][j] = len;
                        }
                    }
                }
            }
        }
    }
    int last = (1 << n) - 1, ans = dp[last][0];
    for (int i = 1; i < n; i++)
    {
        if (ans > dp[last][i])
        {
            ans = dp[last][i];
        }
    }
    return ans;
}
