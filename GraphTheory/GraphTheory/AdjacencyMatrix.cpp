#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjacencyMatrix(const vector<pair<int, int>>& edges, int numVertices);
vector<vector<int>> adjacencyMatrixDirected(const vector<pair<int, int>>& edges, int numVertices);

int main() {
    int numVertices = 4;
    vector<pair<int, int>> edgePairs = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };

    vector<vector<int>> adjMatrix = adjacencyMatrix(edgePairs, numVertices);
    vector<vector<int>> adjMatrixDirected = adjacencyMatrixDirected(edgePairs, numVertices);

    cout << "For Undirected Edges" << endl;
    for (const auto& row : adjMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    cout << "For Directed Edges" << endl;
    for (const auto& row : adjMatrixDirected) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> adjacencyMatrix(const vector<pair<int, int>>& edges, int numVertices) {
    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    for (const auto& i : edges) {
        int rows = i.first;
        int cols = i.second;

        adjMatrix[rows][cols] = 1;
        adjMatrix[cols][rows] = 1;
    }

    return adjMatrix;
}

vector<vector<int>> adjacencyMatrixDirected(const vector<pair<int, int>>& edges, int numVertices) {
    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    for (const auto& i : edges) {
        int rows = i.first;
        int cols = i.second;

        adjMatrix[rows][cols] = 1;
    }

    return adjMatrix;
}
