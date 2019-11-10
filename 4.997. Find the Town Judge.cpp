//https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
        int findJudge(int N, vector<vector<int>>& trust) {
        //на вход подается матрица доверия
        unordered_set <int> PeopleWitchTrust;
        unordered_map <int, int> ColOfTrust;
            for (size_t i=0; i<size(trust); i++){
                PeopleWitchTrust.insert(trust[i][0]);
                ColOfTrust[trust[i][1]]++;
            }                  
            for (int i=1; i<=N; i++)
                if (!PeopleWitchTrust.count(i) && ColOfTrust[i] == N-1) 
                return i;            
        return -1;
    }
};
