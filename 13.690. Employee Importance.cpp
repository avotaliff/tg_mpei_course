//https://leetcode.com/problems/employee-importance/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
//имеет прямые связи. Нужно найти расстояние от любой вершины к заданной, то есть либо через bfs, либо dfs
//дойдем до id, просуммируем важность. 
//в этой задаче выгоднее всего неупорядоченный словарь использовать
//еще можно очередь и когда будет пуста - ответ, но если ввести доп. функцию, то получим также нужную сумму
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
            for (const auto item: employees){
                map[item->id] = item;
            } 
        return help(map, id);
    }
    
    int help (unordered_map <int, Employee*> map, const int id){
        auto sum = map [id]->importance;
        for (const auto item: map[id]->subordinates){
            sum += help(map, item);
        }
        return sum;
    }
};
