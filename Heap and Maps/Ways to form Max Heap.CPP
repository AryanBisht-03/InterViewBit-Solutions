#define MOD ((int)1e9 + 7)
#define ll long long

int Solution::solve(int n)
{
    ll ans[n + 1] = {0};
    memset(ans, 0, sizeof(ans));
    ll c[n][n];
    memset(c, 0, sizeof(c));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
            {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ll total_nodes = 0; // all the nodes assuming perfect and complete binary tree
        ll level = 1;
        ll complete_nodes = 0;    // all the nodes with full levels
        ll current_nodes = i - 1; // leaving the top element, as it is the largest
        while (total_nodes < current_nodes)
        {
            complete_nodes = total_nodes;
            total_nodes += (1 << level);
            level++;
        }
        ll left_nodes = 0, right_nodes = 0;
        ll last_nodes = current_nodes - complete_nodes;
        ll last_full_nodes = (total_nodes - complete_nodes);
        if (last_nodes >= last_full_nodes / 2)
        {
            left_nodes = last_full_nodes / 2;
            right_nodes = (current_nodes - complete_nodes - last_full_nodes / 2);
        }
        else
        {
            left_nodes = current_nodes - complete_nodes;
            right_nodes = 0;
        }
        left_nodes += complete_nodes / 2;
        right_nodes += complete_nodes / 2;
        ans[i] = c[current_nodes][left_nodes];
        ans[i] = (ans[i] * ans[left_nodes]) % MOD;
        ans[i] = (ans[i] * ans[right_nodes]) % MOD;
    }
    return ans[n];
}
