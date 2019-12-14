//https://leetcode.com/problems/rectangle-area/
//не знаю, примут ли эту задачу, решенную именно таким способом, но 
//это простйшее, что пришло мне на ум
//ЭТО БЫЛО НЕ ТАК УЖ ПРОСТО, КЛЯТИ РУНТАЙМ ЭРРОРЫ
class Solution {
public: 
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int buf=0;
            if (C<=E || A>=G || B>=H || D<=F )
            return (C-A)*(D-B)+(G-E)*(H-F);
        else
        {
            vector <int> h;
            h.push_back(A);
            h.push_back(C);
            h.push_back(E);
            h.push_back(G);

            vector <int> v;
            v.push_back(B);
            v.push_back(D);
            v.push_back(F);
            v.push_back(H);

            sort(h.begin(), h.end());
            sort(v.begin(), v.end());

            buf = -(h[2] - h [1]) * (v[2] - v[1]);
            buf=(C-A)*(D-B)+buf+(G-E)*(H-F);
            return buf;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int A = stringToInteger(line);
        getline(cin, line);
        int B = stringToInteger(line);
        getline(cin, line);
        int C = stringToInteger(line);
        getline(cin, line);
        int D = stringToInteger(line);
        getline(cin, line);
        int E = stringToInteger(line);
        getline(cin, line);
        int F = stringToInteger(line);
        getline(cin, line);
        int G = stringToInteger(line);
        getline(cin, line);
        int H = stringToInteger(line);
        
        int ret = Solution().computeArea(A, B, C, D, E, F, G, H);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
