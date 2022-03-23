//In this first I do level order transveral and store it in vector then I check every node as LCA
//the last node which can reach both number will be LCA as they are stored in that way!!

bool findSol(TreeNode *A, int B, int C, bool &found1, bool &found2)
{
    if (found1 && found2)
        return true;

    if (!A)
        return false;

    if (A->val == B)
        found1 = true;
    if (A->val == C)
        found2 = true;

    return findSol(A->left, B, C, found1, found2) || findSol(A->right, B, C, found1, found2);
}

int Solution::lca(TreeNode *A, int B, int C)
{
    queue<TreeNode *> q;
    vector<TreeNode *> v;
    q.push(A);
    while (q.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        v.push_back(curr);

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    int pos = -1;
    for (int i = 0; i < v.size(); i++)
    {
        //cout<<v[i]->val<<" ";
        bool a = false, b = false;
        if (findSol(v[i], B, C, a, b))
            pos = i;
    }
    return pos == -1 ? -1 : v[pos]->val;
}