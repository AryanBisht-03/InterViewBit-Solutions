// LPS(a) == LCS(a,reverse(a)) that means Longest Palindromic Subsequence is nothing but Longest common subsequence with two string as
// a and reverse of a.
int Solution::solve(string A)
{
    int ans = 0;
    vector<vector<int>> v(A.size() + 1, vector<int>(A.size() + 1, 0));
    string s = A;
    reverse(s.begin(), s.end());

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == A[i])
                v[i + 1][j + 1] = v[i][j] + 1;
            else
                v[i + 1][j + 1] = max(v[i][j + 1], v[i + 1][j]);
        }
    }
    return v[A.size()][A.size()];
}

// Method 2 (Main Method)
int findSol(string A, int i, int j, vector<vector<int>> &v)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (v[i][j] != -1)
        return v[i][j];

    if (A[i] == A[j])
        v[i][j] = findSol(A, i + 1, j - 1, v) + 2;
    else
        v[i][j] = max(findSol(A, i + 1, j, v), findSol(A, i, j - 1, v));

    return v[i][j];
}

int Solution::solve(string A)
{
    vector<vector<int>> v(A.size(), vector<int>(A.size(), -1));
    return findSol(A, 0, A.size() - 1, v);
}

// Method 3

int Solution::solve(string s)
{
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}
