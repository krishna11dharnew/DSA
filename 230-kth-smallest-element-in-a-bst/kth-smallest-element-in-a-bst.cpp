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
    void solve(vector<int>&inorder,TreeNode* root)
    {
        if(root==NULL) return;
        solve(inorder,root->left);
        inorder.push_back(root->val);
        solve(inorder,root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // int count = 0;
        // int ans = -1;
        // TreeNode* current = root;

        // while (current != nullptr) {
        //     if (current->left == nullptr) {
        //         // Visit current node
        //         count++;
        //         if (count == k) {
        //             ans = current->val;
        //             break;
        //         }
        //         current = current->right;
        //     } else {
        //         // Find inorder predecessor
        //         TreeNode* predecessor = current->left;
        //         while (predecessor->right != nullptr && predecessor->right != current) {
        //             predecessor = predecessor->right;
        //         }

        //         if (predecessor->right == nullptr) {
        //             // Create thread
        //             predecessor->right = current;
        //             current = current->left;
        //         } else {
        //             // Thread exists — restore and visit
        //             predecessor->right = nullptr;
        //             count++;
        //             if (count == k) {
        //                 ans = current->val;
        //                 break;
        //             }
        //             current = current->right;
        //         }
        //     }
        // }

        // return ans;
         vector<int>inorder;
         solve(inorder,root);
         return inorder[k-1];
    }
};
