int Solution::cnttrue(string A)
{
    int n = A.size();
    int t[n][n], f[n][n], mod = 1003;
    memset(t, 0, sizeof(t));
    memset(f, 0, sizeof(f));

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 'T')
            t[i][i] = 1;
        if (A[i] == 'F')
            f[i][i] = 1;
    }

    for (int len = 3; len <= n; len += 2)
    {
        for (int left = 0; left <= n - len; left++)
        {
            int right = left + len - 1;
            for (int op = left + 1; op < right; op += 2)
            {
                if (A[op] == '^')
                {
                    t[left][right] += (t[left][op - 1] * f[op + 1][right] + f[left][op - 1] * t[op + 1][right]) % mod;
                    f[left][right] += (t[left][op - 1] * t[op + 1][right] + f[left][op - 1] * f[op + 1][right]) % mod;
                }
                else if (A[op] == '&')
                {
                    t[left][right] += (t[left][op - 1] * t[op + 1][right]) % mod;
                    f[left][right] += (t[left][op - 1] * f[op + 1][right] + f[left][op - 1] * t[op + 1][right] + f[left][op - 1] * f[op + 1][right]) % mod;
                }
                else if (A[op] == '|')
                {
                    t[left][right] += (f[left][op - 1] * t[op + 1][right] + t[left][op - 1] * f[op + 1][right] + t[left][op - 1] * t[op + 1][right]) % mod;
                    f[left][right] += (f[left][op - 1] * f[op + 1][right]) % mod;
                }
            }
        }
    }

    return t[0][n - 1] % mod;
}