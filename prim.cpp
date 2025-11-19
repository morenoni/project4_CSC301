/*
 * CSC-301
 * prim.cpp
 * Fall 2025
 *
 * Partner 1: Nicky Moreno Gonzalez
 * Partner 2: Natalie Nardone 
 * Date: Tuesday, November 18, 2025
 */

#include "prim.hpp"

using namespace std;

/*
 * getMin
 */
int getMin(vector<double> &cost, vector<bool> &visited) {
   int len = cost.size();
   int minIndex = -1;
   double minCost = numeric_limits<double>::infinity();

   for (int i = 0; i < len; i++) {
       if (cost[i] < minCost && !visited[i]) {
           minCost = cost[i];
           minIndex = i;
       }
   }
   return minIndex;
}

/*
 * isEmpty
 */
bool isEmpty(vector<bool> &visited) {
   for (bool visit : visited) {
       if (!visit) {
           return false;
       }
   }
    return true;
}

/*
 * prim
 */
vector<Edge> prim(vector<Vertex> &adjList, vector<double> &adjMat) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need a visited flag, a 'cost' for Prim's, and the
    // prev values to track the MST. Store these in seperate vectors.
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<double> cost(n, numeric_limits<double>::infinity());
    vector<int> prev(n, -1);
    int start = 0;
    cost[start] = 0; // Start at vertex 0.
    visited[start] = true;
    
    for (int neighbor : adjList[start].neighbors) {
        cost[neighbor] = adjMat[start * n + neighbor];
        prev[neighbor] = start;
    }

    while(!isEmpty(visited)) {
        int curr = getMin(cost, visited);
        visited[curr] = true;

        int parent = prev[curr];
        double weight = adjMat[parent * n + curr];
        Edge newEdge(adjList[parent], adjList[curr], weight);
        mst.push_back(newEdge);

        adjList[parent].mstNeighbors.push_back(curr);
        adjList[curr].mstNeighbors.push_back(parent);

        for (int neighbor : adjList[curr].neighbors) {
            double edgeWeight = adjMat[curr * n + neighbor];
            if (!visited[neighbor] && edgeWeight < cost[neighbor]) {
                cost[neighbor] = edgeWeight;
                prev[neighbor] = curr;
            }
        }
    }
    return mst;
}