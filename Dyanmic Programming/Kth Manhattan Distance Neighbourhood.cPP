vector<vector<int>> Solution::solve(int A, vector<vector<int>> &B)
{
    vector<vector<vector<int>>> v(B.size(), vector<vector<int>>(B[0].size(), vector<int>(A + 1, 0)));

    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            for (int l = 0; l < B[j].size(); l++)
            {

                if (i == 0)
                {
                    v[j][l][0] = B[j][l];
                    continue;
                }
                int ans = B[j][l];
                if (j > 0)
                    ans = max(ans, v[j - 1][l][i - 1]);
                if (l > 0)
                    ans = max(ans, v[j][l - 1][i - 1]);
                if (j < B.size() - 1)
                    ans = max(ans, v[j + 1][l][i - 1]);
                if (l < B[0].size() - 1)
                    ans = max(ans, v[j][l + 1][i - 1]);

                v[j][l][i] = ans;
            }
        }
    }
    vector<vector<int>> ans(B.size(), vector<int>(B[0].size()));
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
            ans[i][j] = v[i][j][A];
    }
    return ans;
}