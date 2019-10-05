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
/*Алгоритм будет, очевидно, рекурсивным. Проверять будем каждый узел первого дерева и соответствующий ему узел второго дерева*/
     bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL)  return true;    
        //если узлы обеих деревьев пустые, то деревья, ясное дело, совпадают 
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;       
        //если один из узлов пуст, то они, ясное дело,деревья не совпадают
        //если же первые два условия не выполняются, переходим к новой паре узлов и рассмотрим уже их val's
        else {
        //если величины узлов не совпадают, то деревья не совпадают
            if(p->val != q ->val) return false; 
        //если величины совпадают, значи все ок и можно переходить к следующему узлу
            else  
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);            
        }
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* p = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* q = stringToTreeNode(line);
        
        bool ret = Solution().isSameTree(p, q);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
