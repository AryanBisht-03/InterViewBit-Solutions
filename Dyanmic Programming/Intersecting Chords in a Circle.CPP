vector<long long int> dp;
#define N 1000000007
long long int check_chords(int A)
{
    if (A <= 0)
    {
        return 1;
    }
    if (dp[A] != 0)
    {
        return dp[A] % N;
    }
    else
    {
        for (int i = 1; i <= A; i++)
        {
            dp[A] += ((check_chords(A - i) % N) * (check_chords(i - 1) % N));
            dp[A] = dp[A] % N;
        }
        return dp[A] % N;
    }
}

int Solution::chordCnt(int A)
{
    for (int i = 0; i <= A; i++)
    {
        dp.push_back(0);
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[A] = check_chords(A) % N;
    return dp[A];
}
