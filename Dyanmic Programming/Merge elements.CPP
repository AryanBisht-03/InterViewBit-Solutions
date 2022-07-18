int find(vector<int> &arr, int l, int r, vector<int> &pre, vector<vector<int>> &dp)
{
    int n = arr.size();
    // if(l < 0 || l > r|| r >= n) return INT_MAX/4;

    if (l == r)
        return 0; // merging single element cost is 0
    int res = INT_MAX;
    if (dp[l][r] != -1)
        return dp[l][r];
    for (int i = l; i < r; i++)
    {
        // i -> (0,i) ,(i+1,r);
        int lc = find(arr, l, i, pre, dp);
        int rc = find(arr, i + 1, r, pre, dp);
        int curr = pre[r];
        if (l != 0)
            curr = curr - pre[l - 1];

        curr = curr + lc + rc;

        res = min(res, curr);
    }
    dp[l][r] = res;
    return res;
}

int Solution::solve(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> pre(n, 0);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];

    int res = find(arr, 0, n - 1, pre, dp);
    return res;
}