//https://leetcode.com/problems/rotting-oranges/
//ну короче, представим клетку апельсинов как граф. Для начала посчитаем все свежие апельсины. 
//затем обратное действие. Будем уменьшать свежесть, и через bfs находим гнилые апельсины. Для bfs будем использовать 
//обозначения свежести каждого апельсина и в  конце если свежесть апельсина не изменилась, вернем -1
typedef pair<int, int> coord;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		vector<coord> rotten;
		for (int i = 0; i < grid.size(); i++){
			for (int j = 0; j < grid[i].size(); j++){
				if (grid[i][j]) {
					if (grid[i][j] == 2) {
						rotten.push_back({ i,j });
					}
				}
			}
		}
		bool hadFresh = true;
		int counter = 0;
		while (hadFresh) {
			hadFresh = false;
			int rSize = rotten.size();
			for (int i = rSize - 1; i >= 0; i--){
				coord c = rotten[i];
				for (auto a : vector<coord>{ {-1,0}, {1,0},{0,1},{0,-1} }){
					int x = c.first + a.first;
					int y = c.second + a.second;
					if (x > -1 && y > -1 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
						grid[x][y] = 2;
						rotten.push_back({ x, y });
						hadFresh = true;
					}
				}

			}
			counter++;
		}
		for (int i = 0; i < grid.size(); i++){
			for (int j = 0; j < grid[i].size(); j++){
				if (grid[i][j]){
					if (grid[i][j] == 1){
						return -1;
					}
				}
			}
		}
		return counter - 1;
	}
};
