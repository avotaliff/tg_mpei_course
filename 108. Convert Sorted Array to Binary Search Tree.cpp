//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
/*Учитывая массив, где элементы сортируются в порядке возрастания, преобразовать его в BST сбалансированный по высоте. Для этой задачи сбалансированное по высоте двоичное дерево определяется как двоичное дерево, в котором глубина двух поддеревьев каждого узла никогда не отличается более чем на 1.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Р Е К У Р С И Я <3 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree (nums, 0, nums.size()-1);
    }
    
    TreeNode* createTree (vector<int>& num, int length, int S){
        if (length>S) return NULL;
        int maxlen = (length+S)/2;
        
        TreeNode* root = new TreeNode(num[maxlen]);
        root->left = createTree(num, length, maxlen-1);
        root->right = createTree(num, maxlen+1, S);
        return root;
        
    }
    
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().sortedArrayToBST(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
