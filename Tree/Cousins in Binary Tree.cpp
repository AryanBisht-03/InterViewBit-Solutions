/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findSol(TreeNode *A, map<int, vector<int>> &m, int B, int &val, int level)
{
    if (!A)
        return;

    if ((A->right && A->right->val == B) || (A->left && A->left->val == B))
    {
        val = level + 1;
        return;
    }
    m[level].push_back(A->val);
    findSol(A->left, m, B, val, level + 1);
    findSol(A->right, m, B, val, level + 1);
}

vector<int> Solution::solve(TreeNode *A, int B)
{
    map<int, vector<int>> m;
    int level = 0;
    findSol(A, m, B, level, 0);

    return m[level];
}
