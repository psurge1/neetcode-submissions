// (weight, edge node)
using edge = tuple<int, int>;
using min_heap = priority_queue<edge, vector<edge>, greater<edge>>;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> neighbors(n + 1);

        for (const vector<int>& time : times) {
            neighbors[time[0]].push_back({time[2], time[1]});
        }

        min_heap heap;
        vector<int> cost(n + 1, INT_MAX);

        heap.emplace(0, k);
        cost[0] = 0;
        cost[k] = 0;

        while (!heap.empty()) {
            auto [weight, node] = heap.top();
            heap.pop();
            
            if (weight <= cost[node]) {
                cost[node] = weight;
                for (const auto& [edgeWeight, edgeNode] : neighbors[node]) {
                    if (weight + edgeWeight < cost[edgeNode]) {
                        heap.emplace(weight + edgeWeight, edgeNode);
                        cost[edgeNode] = weight + edgeWeight;
                    }
                }
            }
        }

        int maxTime = 0;
        for (int time : cost) {
            maxTime = max(maxTime, time);
        }
        if (maxTime == INT_MAX) {
            return -1;
        }
        return maxTime;
    }
};
