https://leetcode.com/problems/broken-calculator/
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (Y <= X) return X - Y;
        if (Y % 2 == 1) return brokenCalc (X, Y + 1) + 1; 
        else
        return brokenCalc (X, Y / 2) + 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int X = stringToInteger(line);
        getline(cin, line);
        int Y = stringToInteger(line);
        
        int ret = Solution().brokenCalc(X, Y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
