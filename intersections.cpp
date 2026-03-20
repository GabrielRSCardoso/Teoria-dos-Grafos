/*In a certain city there are N intersections connected by one-way and two-way streets. It is a modern city, and several of the streets have tunnels or overpasses. 
Evidently it must be possible to travel between any two intersections. More precisely given two intersections V and W it must be possible to travel from V to W and from W to V.
Your task is to write a program that reads a description of the city street system and determines whether the requirement of connectedness is satisfied or not.

Input
The input contains several test cases. The first line of a test case contains two integers N and M, separated by a space, indicating the number of intersections (2 ≤ N ≤ 2000) and number of streets (2 ≤ M ≤ N(N−1)/2). 
The next M lines describe the city street system, with each line describing one street. A street description consists of three integers V, W and P, separated by a blank space, where V and W are distinct identifiers for intersections (1 ≤ V, W ≤ N , V ≠ W ) and P can be 1 or 2; if P = 1 the street is one-way, and traffic goes from V to W; if P = 2 then the street is two-way and links V and W. 
A pair of intersections is connected by at most one street.
The last test case is followed by a line that contains only two zero numbers separated by a blank space.

Output
For each test case your program should print a single line containing an integer G, where G is equal to one if the condition of connectedness is satisfied, and G is zero otherwise.*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, graph, visited);
        }
    }
}

bool isStronglyConnected(int N, vector<vector<int>>& graph, vector<vector<int>>& rev) {
    vector<bool> visited(N + 1, false);

    dfs(1, graph, visited);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) return false;
    }

    fill(visited.begin(), visited.end(), false);
    dfs(1, rev, visited);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    while (N != 0 || M != 0) {
        vector<vector<int>> graph(N + 1);
        vector<vector<int>> rev(N + 1);

        for (int i = 0; i < M; i++) {
            int V, W, P;
            cin >> V >> W >> P;

            graph[V].push_back(W);
            rev[W].push_back(V);

            if (P == 2) {
                graph[W].push_back(V);
                rev[V].push_back(W);
            }
        }

        cout << (isStronglyConnected(N, graph, rev) ? 1 : 0) << "\n";

        cin >> N >> M;
    }

    return 0;
}