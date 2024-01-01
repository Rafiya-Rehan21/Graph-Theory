#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_map<string, int> getInDegrees(const vector<pair<string, string>>& edges);
unordered_map<string, int> getOutDegrees(const vector<pair<string, string>>& edges);
vector<pair<string, string>> directedVertices();

int main() {
    vector<pair<string, string>> edges = directedVertices();

    unordered_map<string, int> inDegrees = getInDegrees(edges);
    unordered_map<string, int> outDegrees = getOutDegrees(edges);

    for (const auto& i : inDegrees) {
        cout << "Vertex " << i.first << " has in-degree " << i.second << endl;
    }

    for (const auto& j : outDegrees) {
        cout << "Vertex " << j.first << " has out-degree " << j.second << endl;
    }

    return 0;
}


unordered_map<string, int> getInDegrees(const vector<pair<string, string>>& edges) {
    unordered_map<string, int> inDegrees;

    for (const auto& i : edges) {
        inDegrees[i.second]++;
    }

    return inDegrees;
}

unordered_map<string, int> getOutDegrees(const vector<pair<string, string>>& edges) {
    unordered_map<string, int> outDegrees;

    for (const auto& j : edges) {
        outDegrees[j.first]++;
    }

    return outDegrees;
}

vector<pair<string, string>> directedVertices() {
    unordered_set<string> vertices;
    string vert1, vert2;
    vector<pair<string, string>> edges;

    while (true) {
        cout << "Enter a directed edge (source vertex followed by destination vertex, or 'done' to finish): ";
        cin >> vert1;

        if (vert1 == "done") {
            break;  
        }

        cin >> vert2;

        if (!all_of(vert1.begin(), vert1.end(), ::isalnum) || !all_of(vert2.begin(), vert2.end(), ::isalnum)) {
            cerr << "Invalid Argument: Vertex must be only alphanumeric characters." << endl;
            continue;
        }

        if (vertices.count(vert1) == 0) {
            vertices.insert(vert1);
        }

        if (vertices.count(vert2) == 0) {
            vertices.insert(vert2);
        }

        edges.push_back({ vert1, vert2 });
        cout << "Directed edge " << vert1 << "->" << vert2 << " added successfully." << endl;
    }

    return edges;
}
