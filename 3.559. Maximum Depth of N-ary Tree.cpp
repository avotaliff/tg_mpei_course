//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    //каждый объект-узел хранит вектор своих детей - подузелков. 
    Node() {} //конструктор по умолчанию
              //конструктор параметризованный
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        int maxGlub = 0;
        // ditya (ДИТЯ) - это подузелок.
        for (auto ditya: root->children){
            //будем для каждого узла перебирать вектор его подузелков, искать рекурсивно самую большую глубину дитятка и 
            int glubDitya = maxDepth (ditya);
            if (glubDitya > maxGlub){
                maxGlub = glubDitya;
            }
        }
        return 1+maxGlub;
    }
};
 
