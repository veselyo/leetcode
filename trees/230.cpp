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
        int currentIdx = 0;
        int returnVal;
        void inorderSearch (TreeNode* root, int k) {
            if (root->left) inorderSearch(root->left, k);
            currentIdx++;
            if (currentIdx == k) {
                returnVal = root->val;
            }
            if (root->right) inorderSearch(root->right, k);
            return;
        }
    
        int kthSmallest(TreeNode* root, int k) {
            inorderSearch(root, k);
            return returnVal;
        }
    };