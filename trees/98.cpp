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
        bool recursiveSearch(TreeNode* root, long minVal, long maxVal) {
            if (root == nullptr) return true;
            if (root->val <= minVal || root->val >= maxVal) return false;
            return (recursiveSearch(root->left, minVal, root->val) && recursiveSearch(root->right, root->val, maxVal));
        }
        bool isValidBST(TreeNode* root) {
            return recursiveSearch(root, LONG_MIN, LONG_MAX);
        }
    };