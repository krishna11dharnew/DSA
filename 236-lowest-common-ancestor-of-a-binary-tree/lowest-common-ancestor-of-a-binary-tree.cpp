/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
    int solve(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans)
    {
         if(root==nullptr)return 0;
        int left=solve(root->left,p,q,ans);
        int right= solve(root->right,p,q,ans);
        int self=0;
        if(root==p||root==q)self=1;
        int total=right+left+self;
        if(ans==nullptr&&total==2)
        {
            ans=root; 
        }
        return total;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL||root==p||root==q)
        // {
        //     return root;
        // }
        // TreeNode*left=lowestCommonAncestor(root->left,p,q);
        // TreeNode* right=lowestCommonAncestor(root->right,p,q);
        // if(left==NULL) return right;
        // else if(right==NULL) return left;
        // else return root;
        TreeNode* ans=nullptr;
        solve(root,p,q,ans);
        return ans;

        return 0;



    }
};