#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> incidenceMatrix(const vector<pair<int, int>>& edges, const vector<int>& edgeFrequencies, int numVertices);

int main() {
    int verticesCount = 4;
    vector<pair<int, int>> vertexPairs = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };
    vector<int> edgeFrequencies = { 1, 2, 1, 1, 2 };

    vector<vector<int>> incMatrix = incidenceMatrix(vertexPairs, edgeFrequencies, verticesCount);

    for (const auto& i : incMatrix) {
        for (int value : i) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> incidenceMatrix(const vector<pair<int, int>>& edges, const vector<int>& edgeFrequencies, int numVertices) {
    int size = edges.size();
    vector<vector<int>> incMatrix(numVertices, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        int vert1 = edges[i].first;
        int vert2 = edges[i].second;
        int frequency = edgeFrequencies[i];

        incMatrix[vert1][i] = frequency;
        incMatrix[vert2][i] = frequency;
    }

    return incMatrix;
}

