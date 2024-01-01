#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_map<string, int> undirectedGraphDegrees(const vector<pair<string, string>>& edges);
vector<pair<string, string>> undirectedVertices();

int main() {
    vector<pair<string, string>> edges = undirectedVertices();
    unordered_map<string, int> vertexDegrees = undirectedGraphDegrees(edges);

    for (const auto& vertexDegree : vertexDegrees) {
        cout << "Vertex " << vertexDegree.first << " has degree " << vertexDegree.second << endl;
    }

    return 0;
}

unordered_map<string, int> undirectedGraphDegrees(const vector<pair<string, string>>& edges) {
    unordered_map<string, int> degrees;

    for (const auto& i : edges) {
        degrees[i.first]++;
        degrees[i.second]++;
    }

    return degrees;
}

vector<pair<string, string>> undirectedVertices() {
    unordered_set<string> vertices;
    string vert1, vert2;
    vector<pair<string, string>> edges;

    while (true) {
        cout << "Enter an edge (two vertices separated by a space,i.e [[a b]] or 'done' to finish): ";
        cin >> vert1 >> vert2;

        if (vert1 == "done" || vert2 == "done") {
            break;
        }

        if (!all_of(vert1.begin(), vert1.end(), ::isalnum) || !all_of(vert2.begin(), vert2.end(), ::isalnum)) {
            cerr << "Invalid Argument: Vertex must be alphanumeric" << endl;
            continue;
        }

        if (vertices.count(vert1) == 0) {
            vertices.insert(vert1);
        }

        if (vertices.count(vert2) == 0) {
            vertices.insert(vert2);
        }

        edges.push_back({ vert1, vert2 });
        cout << "Edge " << vert1 << "-" << vert2 << " added successfully." << endl;
    }

    return edges;
}
