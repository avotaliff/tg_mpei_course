//https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (copies.find(node) == copies.end()){
            copies[node] = new Node (node->val, {});
            for (Node* neighbors : node -> neighbors){
                copies[node] -> neighbors.push_back(cloneGraph(neighbors));
            }
        }
        return copies[node];
    }
    private:
        unordered_map<Node*, Node*> copies;
};
