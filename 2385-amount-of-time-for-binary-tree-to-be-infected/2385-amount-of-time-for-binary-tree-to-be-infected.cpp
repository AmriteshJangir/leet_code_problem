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
        unordered_map<int, vector<int>> g;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto n=q.front(); q.pop();
            if(n->left){
                g[n->val].push_back(n->left->val);
                g[n->left->val].push_back(n->val);
                q.push(n->left);
            }
            if(n->right){
                g[n->val].push_back(n->right->val);
                g[n->right->val].push_back(n->val);
                q.push(n->right);
            }
        }

        unordered_set<int> vis;
        queue<int> qq;
        qq.push(start);
        vis.insert(start);

        int time=-1;
        while(!qq.empty()){
            int sz=qq.size();
            time++;
            while(sz--){
                int cur=qq.front(); qq.pop();
                for(int x:g[cur])
                    if(!vis.count(x))
                        vis.insert(x),qq.push(x);
            }
        }
        return time;
    }
};