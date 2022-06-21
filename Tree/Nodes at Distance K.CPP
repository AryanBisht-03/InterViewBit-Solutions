vector<int> res;

void add(TreeNode *root, int dist)
{
    if (!root)
        return;
    if (dist < 0)
        return;
    if (dist == 0)
    {
        res.push_back(root->val);
        return;
    }
    add(root->left, dist - 1);
    add(root->right, dist - 1);
}

int dfs(TreeNode *root, int target, int k)
{
    if (!root)
        return -1;
    if (root->val == target)
    {
        add(root, k);
        return k - 1;
    }
    int left = dfs(root->left, target, k);
    if (left != -1)
    {
        if (left == 0)
            res.push_back(root->val);
        add(root->right, left - 1);
        return left - 1;
    }
    int right = dfs(root->right, target, k);
    if (right != -1)
    {
        if (right == 0)
            res.push_back(root->val);
        add(root->left, right - 1);
        return right - 1;
    }
    return -1;
}

vector<int> Solution::distanceK(TreeNode *root, int target, int k)
{
    res.clear();
    dfs(root, target, k);
    return res;
}