//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) { 
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;
    }
};
/*0 на конце может дать число 10=2*5. Двойку рассматривать не будем,т.к. двойка будет показателем не только начилия в числе нуля, но и  четности числа, а четных чисел много. Рассмотрим числа, получающиеся умнжением на 5 Это в первую очередь кратные 5 числа, но ведь есть числа, которые получаются умножением пятерки на еще какое-то колличество пятерок.Таким образом имеем, что ноль получается в том случае если мы делим на 5 в какой-либо степени.
*/

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
