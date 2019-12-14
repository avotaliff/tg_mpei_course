//https://leetcode.com/problems/cheapest-flights-within-k-stops/
//Так, ну, я не очень поняла как это решать с кучами, зато как обычно, нашелся азиат, 
//который решил эту задачку максимально быстро с помощью алгоритма Беллмана — Форда — алгоритм поиска кратчайшего пути во взвешенном графе В отличие от алгоритма Дейкстры, алгоритм Беллмана — Форда допускает рёбра с отрицательным весом. 

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    constexpr int kInfCost = 1e9;
    vector<int> cost(n, kInfCost);
    cost[src] = 0;
    
    for (int i = 0; i <= K; ++i) {
      vector<int> tmp(cost);
      for (const auto& p : flights)
          tmp[p[1]] = min(tmp[p[1]], cost[p[0]] + p[2]);      
      cost.swap(tmp);
    }
    
    return cost[dst] >= kInfCost ? -1 : cost[dst];
  }
};
