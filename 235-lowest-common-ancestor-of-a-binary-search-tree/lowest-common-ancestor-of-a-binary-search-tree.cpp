/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &ans)
{
    if(root==nullptr)return 0;
    int left=solve(root->left,p,q,ans);
    int right=solve(root->right,p,q,ans);
    int self=0;
    if(root==p||root==q)self=1;
    int total=self+left+right;
    if(total==2&&ans==nullptr)
    {
        ans=root;
    }
    return total;

}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        solve(root,p,q,ans);
        return ans;
        
    }
};