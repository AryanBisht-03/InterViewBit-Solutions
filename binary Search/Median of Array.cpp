double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return findMedianSortedArrays(B, A); // Swapping to make A smaller

    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA = (leftAsize > 0)
                        ? A[leftAsize - 1]
                        : INT_MIN; // checking overflow of indices
        int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}