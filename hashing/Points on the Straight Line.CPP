int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    if (A.size() < 2)
        return A.size();
    int ans = 1;
    unordered_map<double, int> m;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (i == j)
                continue;
            double slope = (B[j] - B[i]);

            if (A[j] - A[i] == 0)
                slope = INT_MAX;
            else
                slope = (double)slope / (A[j] - A[i]);

            m[slope]++;
            ans = max(ans, m[slope]);
        }
        m.clear();
    }
    return ans + 1;
}