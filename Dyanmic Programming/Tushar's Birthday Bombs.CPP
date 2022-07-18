vector<int> Solution::solve(int A, vector<int> &B)
{
    int n = B.size();

    vector<int> dp(A + 1, 0), index(A + 1);

    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= B[j])
            {
                if (dp[i - B[j]] + 1 > dp[i])
                {
                    dp[i] = dp[i - B[j]] + 1;
                    index[i] = j;
                }
            }
        }
    }

    vector<int> ans;

    int val = A;

    while (val > 0 && val >= B[index[val]])
    {
        ans.push_back(index[val]);
        val = val - B[index[val]];
    }

    return ans;
}