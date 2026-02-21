class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        longestPath(root, ans);
        return ans;
    }

    int longestPath(TreeNode* node, int& ans) {
        if (!node) return 0;

        int left = longestPath(node->left, ans);
        int right = longestPath(node->right, ans);

        int leftPath = 0, rightPath = 0;

        if (node->left && node->left->val == node->val)
            leftPath = left + 1;

        if (node->right && node->right->val == node->val)
            rightPath = right + 1;

        ans = max(ans, leftPath + rightPath);

        return max(leftPath, rightPath);
    }
};