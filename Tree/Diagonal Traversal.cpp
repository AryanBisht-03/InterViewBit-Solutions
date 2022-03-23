/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findSol(map<int, vector<int>> &m, TreeNode *A, int level)
{
    if (!A)
        return;

    m[level].push_back(A->val);
    findSol(m, A->left, level + 1);
    findSol(m, A->right, level);
}

vector<int> Solution::solve(TreeNode *A)
{
    map<int, vector<int>> m;
    findSol(m, A, 0);
    vector<int> ans;
    for (auto it : m)
        ans.insert(ans.end(), it.second.begin(), it.second.end());

    return ans;
}