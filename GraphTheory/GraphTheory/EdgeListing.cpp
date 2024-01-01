#include <iostream>
#include <vector>
#include <map>

using namespace std;

void edgeListUndirectedGraph(const vector<vector<int>>& adjMatrix);
void edgeListDirectedGraph(const vector<vector<int>>& adjMatrix);

int main() {
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "Edge List for Undirected Graph" << endl;
    edgeListUndirectedGraph(adjMatrix);

    cout << "Edge list for Directed Graph" << endl;
    edgeListDirectedGraph(adjMatrix);

    return 0;
}

void edgeListUndirectedGraph(const vector<vector<int>>& adjMatrix) {
    map<pair<int, int>, int> edgeCount;

    int size = adjMatrix.size();

    for (int rows = 0; rows < size; ++rows) {
        for (int cols = 0; cols < size; ++cols) {

            if (adjMatrix[rows][cols] == 1) {
                edgeCount[{rows, cols}]++;
                edgeCount[{cols, rows}]++;  
            }
        }
    }

    for (const auto& i : edgeCount) {
        pair<int, int> edge = i.first;
        int count = i.second;

        cout << "Edge: (" << edge.first << ", " << edge.second << "), Count: " << count << endl;
    }
}

void edgeListDirectedGraph(const vector<vector<int>>& adjMatrix) {
    map<pair<int, int>, int> edgeCount;

    int size = adjMatrix.size();

    for (int rows = 0; rows < size; ++rows) {
        for (int cols = 0; cols < size; ++cols) {

            if (adjMatrix[rows][cols] == 1) {
                edgeCount[{rows, cols}]++;
            }
        }
    }

    for (const auto& i : edgeCount) {
        pair<int, int> edge = i.first;
        int count = i.second;

        cout << "Edge: (" << edge.first << " -> " << edge.second << "), Count: " << count << endl;
    }
}