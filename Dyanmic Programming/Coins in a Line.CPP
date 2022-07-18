int findSol(vector<vector<int>> &v, vector<int> A, int i, int j)
{
    if (i > j)
        return 0;
    if (v[i][j] != -1)
        return v[i][j];

    int x = A[i] + min(findSol(v, A, i + 2, j), findSol(v, A, i + 1, j - 1));
    int y = A[j] + min(findSol(v, A, i + 1, j - 1), findSol(v, A, i, j - 2));
    return v[i][j] = max(x, y);
}

int Solution::maxcoin(vector<int> &A)
{
    vector<vector<int>> v(A.size(), vector<int>(A.size(), -1));

    return findSol(v, A, 0, A.size() - 1);
}