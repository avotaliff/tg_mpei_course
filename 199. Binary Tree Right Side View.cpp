//https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> res;
        if (root == NULL) return res;
            //cоздадим очередь, хранящую пары узел-значение
            //pair как я поняла, это нечто похожее на ассоциативный массив, но в нашем случае его использовать невыгодно (это дольше по времени) и неудобно
             queue <pair <TreeNode*,int> > que;   
             int lev = 1;
            
            //функция make_pair(е1 , е2) создает пару со значениями е1 и е2
             que.push (make_pair(root,lev));
             vector <vector <int >> location;
            
            while (que.empty() == NULL){
// front - это первый элемент, аналог begin, но begin - это указатель на первый элемент
            pair <TreeNode*,int> p = que.front();
                
            if (location.size()<p.second) location.push_back(vector<int>());
            
            location[p.second-1].push_back(p.first->val);
            que.pop();
                
            if (p.first->left) que.push(make_pair(p.first->left,p.second+1));                       if (p.first->right) que.push(make_pair(p.first->right,p.second+1));
                
        } 
            for(int i=0; i<location.size(); ++i) 
                res.push_back(location[i][location[i].size()-1]);
            
        return res;    
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().rightSideView(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
