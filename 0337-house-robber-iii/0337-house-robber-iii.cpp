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
    int rob(TreeNode* root) {
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return make_pair(0, 0);
            auto [leftRob, leftNotRob] = dfs(node->left);
            auto [rightRob, rightNotRob] = dfs(node->right);
            int robCurrent = node->val + leftNotRob + rightNotRob;
            int notRobCurrent = max(leftRob, leftNotRob) + max(rightRob, rightNotRob);
            return make_pair(robCurrent, notRobCurrent);
        };
        auto [robRoot, notRobRoot] = dfs(root);
        return max(robRoot, notRobRoot);
    }
};