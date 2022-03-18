// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
//  struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* t = q.front();
            q.pop();
            if(t) 
                res += " " + to_string(t->val);
            else{
                res += " null";
                continue;
            }
            q.push(t->left);
            q.push(t->right);
        }
        cout << res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        queue<TreeNode*> parent;
        vector<string> nodes;
        int i, j;
        for( i = 1, j = 1; j < data.size();  j++){
            if(data[j] == ' ' ){
                nodes.push_back(data.substr(i, j - i));
                i = j + 1;
            }
        }
        nodes.push_back(data.substr(i, j - i));
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        parent.push(root);
        int cur = 1;
        while(parent.size()){
            int len = parent.size();
            for(int i = 0; i < len; i ++){
                TreeNode* t = parent.front();
                parent.pop();
                if(nodes[cur] != "null"){
                    TreeNode* left = new TreeNode(stoi(nodes[cur]));
                    t->left = left;
                    parent.push(left);
                }
                cur ++;
                if(nodes[cur] != "null"){
                    TreeNode* right = new TreeNode(stoi(nodes[cur]));
                    t->right = right;
                    parent.push(right);
                }
                cur ++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

