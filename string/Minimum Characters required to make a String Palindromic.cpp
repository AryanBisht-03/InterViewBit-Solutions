vector<int> computelps(string str)
{
    int M = str.length();
    vector<int> lpsarr(M);

    int len = 0;
    lpsarr[0] = 0; // always start from 0
    int i = 1;
    while (i < M)
    { // imp part - watch abdul bari's video
        if (str[i] == str[len])
        {
            len++;
            lpsarr[i] = len;
            i++;
        }
        else
        { // i never goes back. Only len will
            if (len != 0)
            {
                len = lpsarr[len - 1];
            }
            else
            { // len cant go any back from 0. So move i forward
                lpsarr[i] = 0;
                i++;
            }
        }
    }
    return lpsarr;
}

int Solution::solve(string A)
{
    string revStr = A;
    reverse(revStr.begin(), revStr.end());
    string final = A + "$" + revStr;
    // LPS array using KMP
    vector<int> lps = computelps(final);
    return (A.length() - lps.back()); // shows no. of chars to add
}