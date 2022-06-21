int Solution::numDistinct(string S, string T)
{
    int m = T.length();
    int n = S.length();
    if (m > n)
        return 0; // impossible for subsequence
    vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
    for (int k = 0; k <= n; k++)
        path[0][k] = 1; // initialization

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            path[i][j] = path[i][j - 1] + (T[i - 1] == S[j - 1] ? path[i - 1][j - 1] : 0);
        }
    }

    return path[m][n];
}