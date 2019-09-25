//https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int N) {
    auto s = pow(5,0.5);
    auto l = (1+s)/2 ;
    auto r = (1-s)/2 ;
    	    return round((pow(l,N)-pow(r,N))/s);
        }

		    
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().fib(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
