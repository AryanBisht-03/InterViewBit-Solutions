bool check(int i, int j, int n, vector<vector<char>> &a, int k)
{
    for (int c = 0; c < n; c++)
    {
        if (a[c][j] == k + '0' || a[i][c] == k + '0')
            return false;
    }
    int x3 = sqrt(n);
    int x1 = i - i % x3, x2 = j - j % x3;
    for (int c1 = 0; c1 < x3; c1++)
    {
        for (int c2 = 0; c2 < x3; c2++)
        {
            if (a[c1 + x1][c2 + x2] == k + '0')
                return false;
        }
    }
    return true;
}
bool sol(vector<vector<char>> &a, int n, int i, int j)
{
    if (i == n - 1 && j == n)
        return true;
    if (j == n)
    {
        j = 0;
        i++;
    }
    if (a[i][j] != '.')
        return sol(a, n, i, j + 1);
    for (int k = 1; k <= 9; k++)
    {
        if (check(i, j, n, a, k))
        {
            a[i][j] = k + '0';
            if (sol(a, n, i, j + 1))
                return true;
        }
        a[i][j] = '.';
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char>> &a)
{
    int n = a.size();
    int m = a[0].size();
    sol(a, n, 0, 0);
}