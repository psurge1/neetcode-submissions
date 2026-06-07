using Edge = pair<int, int>;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
        Inputs:
        - list of cartesian points on a grid (all possible integer values)
        - each point is a vector with two elements

        Outputs:
        - the integer cost of the minimum cost to connect all points on the grid
        
        Misc:
        - the cost to connect two points is the manhattan distance between them

        Prim's algorithm
        - take a start point
        - mark it as visited
        - add all outgoing edges to a heap
        - add the minimum cost edge to connect a new undiscovered point
        - add that edge's outgoing edges to a heap
        - continue until all points are visited
        */

        int numPoints = points.size();
        vector<vector<Edge>> pointGraph(numPoints);

        for (int pOne = 0; pOne < numPoints; ++pOne) {
            for (int pTwo = pOne + 1; pTwo < numPoints; ++pTwo) {
                int manhattanDist = abs(points[pOne][0] - points[pTwo][0]) + abs(points[pOne][1] - points[pTwo][1]);
                pointGraph[pOne].push_back({manhattanDist, pTwo});
                pointGraph[pTwo].push_back({manhattanDist, pOne});
            }
        }

        vector<bool> visited(numPoints, false);
        priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
        minHeap.push({0, 0});

        int totalCost = 0;
        while (!minHeap.empty()) {
            Edge minEdge = minHeap.top();
            minHeap.pop();

            int cost = minEdge.first;
            int node = minEdge.second;

            if (!visited[node]) {
                totalCost += cost;
                for (const Edge& edge : pointGraph[node]) {
                    minHeap.push(edge);
                }
                visited[node] = true;
            }
        }

        return totalCost;
    }
};
