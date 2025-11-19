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
 * getMin: gets the minimum unvisited cost vertex.
 * Inputs:
 * - cost: vector of costs for each vertex
 * - visited: vector of visited values.
 * Outputs:
 * - minIndex: index of the vertext with the minimum cost
 * that is unvisited.
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
 * isEmpty: checks if all vertices have been visited.
 * Inputs:
 * - visited: vector of visited values.
 * Outputs:
 * - false, if there are unvisited vertices. True otherwise.
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
 * prim: finds an MST using Prim's algorithm
 * Inputs:
 * - adjList: vector containing the vertices of the graph
 * - adjMat: vector containing the weights of the edges of the graph
 * Outputs:
 * - mst: vector containing the edges of the MST
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
    
    // Sets the cost and previous values for the neighbors of the start vertex.
    for (int neighbor : adjList[start].neighbors) {
        cost[neighbor] = adjMat[start * n + neighbor];
        prev[neighbor] = start;
    }

    // Loop thorugh remaining vertices.
    while(!isEmpty(visited)) {
        int curr = getMin(cost, visited);
        visited[curr] = true;

        // Adding the new Edge to the MST.
        int parent = prev[curr];
        double weight = adjMat[parent * n + curr];
        Edge newEdge(adjList[parent], adjList[curr], weight);
        mst.push_back(newEdge);

        adjList[parent].mstNeighbors.push_back(curr);
        adjList[curr].mstNeighbors.push_back(parent);

        // Update cost and previous values for neighbors of curr
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