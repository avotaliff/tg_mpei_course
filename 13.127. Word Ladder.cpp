//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> WORDS (wordList.begin(), wordList.end());
        queue<string> elems;
        elems.push(beginWord);
        int l = 1;
        while (!elems.empty()) {
            int n = elems.size();
            for (int i = 0; i < n; i++) {
                string word = elems.front();
                elems.pop();
                if (word == endWord) {
                    return l;
                }
                WORDS.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (WORDS.find(word) != WORDS.end()) {
                            elems.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            l++;
        }
        return 0;
    }
};
