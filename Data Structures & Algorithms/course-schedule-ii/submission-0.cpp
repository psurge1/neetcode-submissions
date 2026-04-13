class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> incoming_edges(numCourses, 0);

        for (const vector<int>& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            ++incoming_edges[prereq[0]];
        }

        deque<int> stk;
        for (int node = 0; node < numCourses; ++node) {
            if (incoming_edges[node] == 0) {
                stk.push_back(node);
            }
        }

        vector<int> ordering;
        while (!stk.empty()) {
            int node = stk.front();
            stk.pop_front();

            ordering.push_back(node);
            for (int edge_node : adj[node]) {
                --incoming_edges[edge_node];
                if (incoming_edges[edge_node] == 0) {
                    stk.push_back(edge_node);
                }
            }
        }

        if (ordering.size() == numCourses) {
            return ordering;
        }
        return vector<int>{};
    }
};
