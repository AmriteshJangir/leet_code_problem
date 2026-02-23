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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode *startNode = nullptr;
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            if (n->val == start) startNode = n;
            if (n->left)  { parent[n->left] = n;  q.push(n->left); }
            if (n->right) { parent[n->right] = n; q.push(n->right); }
        }
        if (!startNode) return 0;
        unordered_set<TreeNode*> seen;
        q.push(startNode);
        seen.insert(startNode);
        int minutes = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool moved = false;
            while (sz--) {
                auto n = q.front(); q.pop();
                for (TreeNode* nei : {n->left, n->right, parent[n]}) {
                    if (nei && !seen.count(nei)) {
                        seen.insert(nei);
                        q.push(nei);
                        moved = true;
                    }
                }
            }
            if (moved) ++minutes;
        }
        return minutes;
    }
};