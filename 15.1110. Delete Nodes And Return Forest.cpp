//https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    void rec(vector<TreeNode*> &x, TreeNode* &tree, vector<int> & y){
        if (tree->left!=nullptr) rec(x, tree->left, y);
        if (tree->right!=nullptr) rec(x, tree->right, y);
        if (y.size()!=0){
            bool fl=false;
            int i=0;
            while (i<y.size() && !(fl))
                if (tree->val == y[i]) fl=true;
            else i++;
            if (fl){
                if (tree->left!=nullptr) x.push_back(tree->left);
                if (tree->right!=nullptr) x.push_back(tree->right);
                y.erase(y.begin()+i);
                tree=nullptr;}
        }
    }

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> x(0);
    rec(x,root,to_delete);
    if (root!=nullptr) x.insert(x.begin(),root);
    return x;
}
};
