//https://leetcode.com/problems/permutation-sequence/submissions/
/*Решение задачи поспрашивала у ребят, которые ее решали и плюсом чекнула обсуждения данной задачи. Проще всего ее решить и написать по математическому алгоритму, который имеет математическое доказательство. Вооот. А еще решение, которое мы разбирали в классе действует перебором, что работает бтв медленнее. */
class Solution {
public:
    string getPermutation(int n, int k) {
        string res; //результат - k-ая перестановка
        string nums = "123456789";//множество чисел возможной последовательности
        const  int f[] = {1,1,2,6,24,120,720,720*7,720*7*8}; 
        //кол-во возможных перестановок (n!)
        --k;
        //не считая первой (начальной) перестановки
        for (int i = n; i >= 1; --i) { //идем с конца введенной последовательности
/*следующий алгоритм позволяет отыскать k-ую перестановку,
где j+1 - это искомая цифра последовательности.*/
            int j = k / f[i - 1]; 
            k %= f[i - 1];
            res.push_back(nums[j]);
/*т.к. найденая цифра может стоять в перестановке лишь один раз, мы удаляем ее из 
множества возможных чисел для последуюших перестановок*/
            nums.erase(nums.begin() + j);
        }
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
