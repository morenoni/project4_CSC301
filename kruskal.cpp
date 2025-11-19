/*
 * CSC-301
 * kruskal.cpp
 * Fall 2025
 *
 * Partner 1: Nicky Moreno Gonzalez
 * Partner 2: Natalie Nardone 
 * Date: Tuesday, November 18, 2025
 */

#include "kruskal.hpp"

using namespace std;

/*
 * find: Finds the what set a given vertex is in.
 * Inputs:
 * - v: the vertex to find the set of
 * - pi: the vector of parent pointers
 * Outputs:
 * - the root of the set that v is in
 */
int find(int v, vector<int> &pi) {
    if (pi[v] != v) {
        pi[v] = find(pi[v], pi);
    }
    return pi[v];
}

/*
 * union_by_rank: unions two sets based on which has better rank
 * Inputs:
 * - u: one of the vertices
 * - v: one of the vertices
 * - rank: the vector of rank values
 * - pi: the vector of parent pointers
 * Outputs: none
 */
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi) {
    int ru = find(u, pi);
    int rv = find(v, pi);
    if (rank[u] < rank[v]){
        pi[ru] = rv;
    } else if (rank[u] > rank[v]) {
        pi[rv] = ru;
    } else {
        pi[ru] = rv;
        rank[rv]++;
    }

}

/*
 * kruskal: finds an MST using Kruskal's algorithm
 * Inputs:
 * - adjList: vector containing the vertices of the graph
 * - edgeList: vector containing the edges of the graph sorted from 
 * smallest to largest
 * Outputs:
 * - mst: vector containing the edges of the MST
 */
vector<Edge> kruskal(vector<Vertex> &adjList, vector<Edge> &edgeList) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need rank values and pi pointers (ints) for the
    // Disjoint Sets. Initialize the rank to 0 and pi to be the vertex labels.
    int n = adjList.size();
    vector<int> rank(n, 0);
    vector<int> pi(n);
    for (int i=0; i<pi.size(); i++) {
        pi[i] = i;
    }
    // loop through all edges from smallest to largest
    for (Edge edge : edgeList) {
        int u = edge.first.label;
        int v = edge.second.label;
        // if the two vertices of the edge are not in the same set, connect them
        if(find(u, pi) != find(v, pi)) {
            union_by_rank(u, v, rank, pi);
            mst.push_back(edge);
            adjList[u].mstNeighbors.push_back(v);
            adjList[v].mstNeighbors.push_back(u);
        }
    }
    return mst;
}