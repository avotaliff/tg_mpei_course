//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
    long r = x;
    while (pow(r,2) > x)
        r = (r + x/r) / 2;
    return r;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
