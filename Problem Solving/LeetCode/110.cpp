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
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }

    bool solve(TreeNode* node) {

    	if(node == NULL)
    		return true;

    	int left  = getHeight(node->left);
    	int right = getHeight(node->right);

    	if(abs(right-left) > 1) {
    		return false;
    	}

    	return solve(node->left) && solve(node->right);

    }

    int getHeight(TreeNode* node) {
    	if(node == NULL) return	0;

    	return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};