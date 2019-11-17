//https://leetcode.com/problems/course-schedule/    

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
    // внутренний вектор будет обрабатывать параллельные ребра    
        vector<int> step(numCourses, 0), buf;
        
        for (const auto& item : prerequisites){
            graph[item[1]].push_back(item[0]);
            step[item[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++)
            if (!(step[i]))
                buf.push_back(i);
        for (int i = 0; i < buf.size(); ++i)
            for (const int& obj: graph[buf[i]])
                if (--step[obj] == 0)
                    buf.push_back(obj);
        return buf.size() == numCourses;
    }
};
