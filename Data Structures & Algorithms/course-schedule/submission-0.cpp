class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> incoming_edges(numCourses, 0);

        for (const vector<int>& prereq : prerequisites) {
            adj_list[prereq[1]].push_back(prereq[0]);
            ++incoming_edges[prereq[0]];
        }

        deque<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (incoming_edges[i] == 0) {
                stk.push_back(i);
            }
        }

        int courses_processed = 0;
        while (!stk.empty()) {
            int node = stk.back();
            stk.pop_back();
            ++courses_processed;

            for (int edge_node : adj_list[node]) {
                --incoming_edges[edge_node];
                if (incoming_edges[edge_node] == 0) {
                    stk.push_back(edge_node);
                }
            }
        }

        return courses_processed == numCourses;
    }
};
