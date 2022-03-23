//Using Trie

struct Trie
{
    char c;
    bool finish;
    Trie *v[26] = {NULL};
    Trie(char a)
    {
        c = a;
        finish = false;
    }
};

vector<int> Solution::solve(string A, vector<string> &B)
{
    Trie *root = new Trie(' ');
    vector<pair<int, int>> ans;
    Trie *curr = root;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '_')
            curr->finish = true, curr = root;
        else
        {
            int idx = A[i] - 'a';
            if (!curr->v[idx])
                curr->v[idx] = new Trie(A[i]);
            curr = curr->v[idx];
        }
    }
    curr->finish = true;
    for (int i = 0; i < B.size(); i++)
    {
        int val = 0;
        bool check = true;
        curr = root;
        for (int j = 0; j < B[i].size(); j++)
        {
            if (B[i][j] == '_')
            {

                if (check)
                {
                    for (int i = 0; i < 26; i++)
                        if (curr->v[i])
                            check = false;

                    if (check || curr->finish)
                        val++;
                }
                curr = root, check = true;
            }
            else if (check)
            {

                int idx = B[i][j] - 'a';
                if (!curr->v[idx])
                    check = false;
                curr = curr->v[idx];
            }
        }
        if (check)
        {

            for (int i = 0; i < 26; i++)
                if (curr->v[i])
                    check = false;

            if (check || curr->finish)
                val++;
        }

        ans.push_back({val, i});
    }
    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b)
         {
             if (a.first > b.first || (a.first == b.first && a.second < b.second))
                 return true;
             return false;
         });

    vector<int> v;
    for (int i = 0; i < ans.size(); i++)
        v.push_back(ans[i].second);

    return v;
}