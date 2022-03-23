int Solution::solve(vector<string> &A)
{
    int s = A.size(), len = A[0].length();
    int b[len][3], t[len][3], l[len][3], r[len][3];
    for (int i = 0; i < len; i++)
    {
        b[i][0] = -1, t[i][0] = s;
        b[i][1] = -1, t[i][1] = s;
        b[i][2] = -1, t[i][2] = s;
        for (int j = 0; j < s; j++)
        {
            if (A[j][i] == 'r')
            {
                t[i][0] = min(t[i][0], j);
                b[i][0] = max(b[i][0], j);
            }
            if (A[j][i] == 'g')
            {
                t[i][1] = min(t[i][1], j);
                b[i][1] = max(b[i][1], j);
            }
            if (A[j][i] == 'b')
            {
                t[i][2] = min(t[i][2], j);
                b[i][2] = max(b[i][2], j);
            }
        }
    }

    int m0 = len, m1 = len, m2 = len;
    for (int i = 0; i < len; i++)
    {
        if (t[i][0] != s)
            m0 = min(m0, i);
        if (t[i][1] != s)
            m1 = min(m1, i);
        if (t[i][2] != s)
            m2 = min(m2, i);

        l[i][0] = m0;
        l[i][1] = m1;
        l[i][2] = m2;
    }

    m0 = -1, m1 = -1, m2 = -1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (t[i][0] != s)
            m0 = max(m0, i);
        if (t[i][1] != s)
            m1 = max(m1, i);
        if (t[i][2] != s)
            m2 = max(m2, i);

        r[i][0] = m0;
        r[i][1] = m1;
        r[i][2] = m2;
    }

    int ans = 0;
    for (int m = 0; m < len; m++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i == j || k == i || k == j)
                        continue;
                    if (t[m][i] == s || b[m][j] == -1)
                        continue;
                    int base = b[m][j] - t[m][i] + 1;
                    int height = 0;
                    height = max(m - l[m][k] + 1, r[m][k] - m + 1);
                    ans = max(ans, (int)ceil(1.0 * (base * height) / 2));
                }
            }
        }
    }

    return ans;
}