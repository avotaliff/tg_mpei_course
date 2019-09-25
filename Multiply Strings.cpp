//https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
    if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") 
    return "0";
    string res;
    const int SIZEOFV=num1.size()+num2.size();
    vector <int> buf(SIZEOFV,0); //вектор, содержащий максимальный результат нашего умножения
        for (int i=num1.size()-1; i > -1; i--){
            for (int j=num2.size()-1; j > -1; j--){
                 int locRes = (num1[i] - '0') * (num2[j] - '0');
                //ребята из группы подсказали, что так можно перевести в int...
                 buf[i+j+1] += locRes; 
                //т.к.мы начинаем перемножать с конца, то и результат запишем в самый конец вектора
            }    
        }
        //теперь наш вектор состоит из чиселок, среди которых есть числа >10, избавимся от этого
    int snesti = 0;
    int chislo = 0;
//да, я называю переменные на русском и што! идем по вектору и делаем переносики
        for (int i = SIZEOFV-1; i>-1; i--){
            chislo = (buf[i]+snesti)%10; //формируем цифру
            snesti = (buf[i]+snesti)/10; //старший разряд, если двузначное переносим
            buf[i]= chislo;             //младший разряд оставляем
        }
         for (int i = 0; i < SIZEOFV; i++){
            res += to_string(buf[i]);
         }
        size_t valid_begin = res.find_first_not_of('0');
         res = res.substr(valid_begin);// не знаю, как это работает, но мне нужно было избавиться от лишних нулей в векторе 
        return res;
        
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
