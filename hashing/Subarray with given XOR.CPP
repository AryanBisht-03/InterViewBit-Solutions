int Solution::solve(vector<int> &A, int B)
{
    int ans = 0;
    vector<int> p(A.size());
    p[0] = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        p[i] = p[i - 1] ^ A[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++)
    {
        if (p[i] == B)
            ans++;
        if (mp.find(p[i] ^ B) != mp.end())
        {
            ans += mp[p[i] ^ B];
        }
        mp[p[i]]++;
    }

    return ans;
}
