#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph);

int main() {
    vector<vector<int>> graph = { {1, 3}, {3, 2}, {3, 3}, {0, 2} };
    bool bipartite = isBipartite(graph);

    if (bipartite) {
        cout << "The graph is bipartite." << endl;
    }
    else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

bool isBipartite(vector<vector<int>>& graph) {
    int size = graph.size();
    vector<int> color(size, -1); 
    queue<int> vertices;

    for (int i = 0; i < size; ++i) {
        if (color[i] == -1) {
            vertices.push(i);
            color[i] = 0; 

            while (!vertices.empty()) {
                int top = vertices.front();
                vertices.pop();

                for (int c : graph[top]) {
                    if (color[c] == -1) {
                        color[c] = 1 - color[top];
                        vertices.push(c);
                    }
                    else if (color[c] == color[top]) {
                        return false; 
                    }
                }
            }
        }
    }

    return true;
}