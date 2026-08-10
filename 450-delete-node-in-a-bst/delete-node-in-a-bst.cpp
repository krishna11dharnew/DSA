/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* rightchi(TreeNode*root)
    {
        if(root->right==NULL)return root;
        return rightchi(root->right);
    }
    public:
    TreeNode* helper(TreeNode* root)
    {

    if(root->left == NULL)
        return root->right;

    // if(root->right == NULL)
    //     return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* lastright=rightchi(root->left);
        lastright->right=rightchild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)return root;
        if(root->val==key)return helper(root);
        TreeNode* dummy=root;
        TreeNode*curr=root;
        while(curr)
        {
            if(curr->val>key)
            {
               if(curr->left&&curr->left->val==key)
               {
                curr->left=helper(curr->left);
                break;
               }
               else
               {
                curr=curr->left;
               }
            }
            else
            {
                if(curr->right&&curr->right->val==key)
               {
                curr->right=helper(curr->right);
                break;
               }
               else
               {
                curr=curr->right;
               }

            }
        } 
        return dummy;       
    }

};