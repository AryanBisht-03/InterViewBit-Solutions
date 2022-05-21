string Solution::minWindow(string A, string B)
{
    vector<int> m(256, 0);
    for (auto c : B)
        m[c]++;

    int count = B.size();
    int l = 0, r = 0, f = 0, lmin = INT_MAX;

    bool check = false; // to check at least for 1 time count is reaching 0
    while (r < A.size())
    {
        if (m[A[r]] > 0)
            count--;

        m[A[r]]--;
        r++;
        if (count == 0)
            check = true;
        while (count == 0)
        {
            if (r - l < lmin)
            {
                lmin = r - l;
                f = l;
            }
            if (m[A[l]] >= 0)
                count++;

            m[A[l]]++;
            l++;
        }
    }
    if (check)
        return A.substr(f, lmin);
    else
        return "";
}