//https://leetcode.com/problems/word-ladder-ii/
/*Идея состоит в том, чтобы сначала использовать BFS для поиска от beginWord до endWord и 
одновременно генерировать сопоставление «слово-ребенок».
Затем используем DFS для создание последовательностей.*/
//
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        graph g;
        vector<vector<string>> paths;
        vector<string> path = {beginWord};
        if (buildGraph(g, beginWord, endWord, dict)) {
            findPaths(g, beginWord, endWord, path, paths);
        }
        return paths;
    }
private:
    typedef unordered_map<string, vector<string>> graph;
    
    bool buildGraph(graph& g, string beginWord, string endWord, unordered_set<string>& dict) {
        unordered_set<string> todo;
        todo.insert(beginWord);
        while (!todo.empty()) {
            if (todo.find(endWord) != todo.end()) {
                return true;
            }
            for (string word : todo) {
                dict.erase(word);
            }
            unordered_set<string> temp;
            for (string word : todo) {
                string parent = word;
                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            g[parent].push_back(word);
                        }
                    }
                    word[i] = c;
                }
            }
            swap(todo, temp);
        }
        return false;
    }
    
    void findPaths(graph& g, string beginWord, string endWord, vector<string>& path, vector<vector<string>>& paths) {
        if (beginWord == endWord) {
            paths.push_back(path);
        } else {
            for (string child : g[beginWord]) {
                path.push_back(child);
                findPaths(g, child, endWord, path, paths);
                path.pop_back();
            }
        }
    }
};
