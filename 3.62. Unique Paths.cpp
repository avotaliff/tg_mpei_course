//https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector <int>> buf (m , vector <int> (n , 1));
        //матрица первый столбец - вектор размером m, в каждой строчке вектор единичный размером n
        //просто посчитаем всевозможные шаги 
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                buf [i][j] = buf[i-1][j]+buf[i][j-1];
            }
        }
        
        return buf [m-1][n-1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
