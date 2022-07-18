int Solution::wordBreak(string A, vector<string> &B)
{
    vector<vector<int>> v(A.size() + 1, vector<int>(A.size() + 1, 0));
    set<string> s;

    for (string c : B)
        s.insert(c);

    for (int i = 1; i < A.size() + 1; i++)
    {
        if (s.find(A.substr(i - 1, 1)) != s.end())
            v[i][i] = 1;
    }

    for (int i = A.size() - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < A.size() + 1; j++)
        {
            string t = A.substr(i - 1, j - i + 1);
            if (s.find(t) != s.end())
                v[i][j] = 1;
            else
            {
                for (int l = i; l <= j; l++)
                {
                    if (v[i][l] && v[l + 1][j])
                    {
                        v[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    return v[1][A.size()];
}
