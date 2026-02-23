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
class Solution{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int x, int y) {
            if (!node) return;
            nodes[x][y].insert(node->val);
            dfs(node->left, x - 1, y + 1);
            dfs(node->right, x + 1, y + 1);
        };
        dfs(root, 0, 0);
        
        vector<vector<int>> ans;
        for (auto& [x, ys] : nodes) {
            vector<int> col;
            for (auto& [y, vals] : ys) {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    // int main() {
    //     // Example usage:
    //     TreeNode* root = new TreeNode(1);
    //     root->left = new TreeNode(2);
    //     root->right = new TreeNode(3);
    //     root->left->left = new TreeNode(4);
};