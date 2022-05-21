vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    int n = A.size();
    int m = B.size();
    unordered_map<string, int> mp; // string to count
    for (int i = 0; i < m; i++)
    {
        mp[B[i]]++;
    }
    vector<int> ans;
    int max_len = B[0].size() * m;
    int len = B[0].size();
    for (int i = 0; i < n; i++)
    {
        unordered_map<string, int> m = mp; // string to count
        int j = i;
        while (j < n && m.size())
        {
            string a = A.substr(j, len);
            if (m.find(a) != m.end())
            {
                m[a]--;
                j += len;
                if (m[a] == 0)
                    m.erase(a);
            }
            else
                break;
        }
        if (j - i == max_len)
        {
            ans.push_back(i);
        }
    }
    return ans;
}