/*
 * CSC-301
 * tsp.cpp
 * Fall 2025
 *
 * Partner 1: Nicky Moreno Gonzalez
 * Partner 2: Natalie Nardone 
 * Date: Thursday, November 20, 2025
 */

#include "tsp.hpp"

using namespace std;

/*
 * tsp: Creates a traveling salesmen tour of the MST using a DFS.
 * Input:
 * - adjList: Vector of Vertices in the graph
 * - start: The starting Vertex for the tour
 * Output:
 * - tour: vectore of the TSP tour.
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;
    
    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);
    int startLabel = start.label;
    stack<int> s;
    s.push(startLabel);

    // DFS loop
    while (!s.empty()){
        int curr = s.top();
        s.pop();
        if (visited[curr] == false) {
            visited[curr] = true;
            tour.push_back(curr);
            for (int neighbor : adjList[curr].mstNeighbors) {
                s.push(neighbor);
            }
        }
    }
    tour.push_back(startLabel);
    return tour;
}