string Solution::getPermutation(int A, int B)
{
    int n = A;
    int k = B;
    vector<int> V;
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        V.push_back(i);
    }
    for (int i = 1; i < k; i++)
    {
        next_permutation(V.begin(), V.end());
    }
    for (int i = 0; i < V.size(); i++)
    {
        s = s + to_string(V[i]);
    }
    return s;
}