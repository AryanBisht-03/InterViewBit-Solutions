int Solution::solve(vector<vector<int>> &A)
{
    if (A.size() == 0)
        return 0;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 1; j < A[0].size(); j++)
            A[i][j] = A[i][j] + A[i][j - 1];
    }

    int count = 0;
    for (int c1 = 0; c1 < A[0].size(); c1++)
    {
        for (int c2 = c1; c2 < A[0].size(); c2++)
        {
            unordered_map<int, int> m;
            m[0] = 1;
            int sum = 0;
            for (int row = 0; row < A.size(); row++)
            {
                sum += A[row][c2] - (c1 > 0 ? A[row][c1 - 1] : 0);
                if (m.find(sum) != m.end())
                    count += m[sum], m[sum]++;
                else
                    m[sum] = 1;
            }
        }
    }
    return count;
}