int Solution::isMatch(const string &s, const string &p)
{
    int n = s.size(), m = p.size();
    int star = -1, prev_start = 0;
    int i = 0, j = 0;

    for (; i < n;)
    {
        if (s[i] == p[j] || p[j] == '?')
        {
            i++, j++;
        }
        else if (p[j] == '*')
        {
            star = j++;
            prev_start = i;
        }
        else if (star != -1)
        {
            j = star;
            i = ++prev_start;
        }
        else
        {
            return false;
        }
    }

    while (j < m && p[j] == '*')
        j++;

    return (j == m);
}