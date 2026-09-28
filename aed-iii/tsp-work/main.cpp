#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

constexpr int MAX = INT_MAX / 1024;

using namespace std;

vector<vector<int>> file2Matrix(const string& filename);
void heldKarp(const vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& parent);
pair<int, int> findBestCostAndLast(const vector<vector<int>>& matrix, const vector<vector<int>>& dp);
vector<int> findPath(const vector<vector<int>>& parent, int bestLast);

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Use: " << argv[0] << " <input file>\n";
        return 1;
    }

    vector<vector<int>> matrix = file2Matrix(argv[1]);

    vector<vector<int>> dp(1 << matrix.size(), vector<int>(matrix.size(), MAX));
    vector<vector<int>> parent(1 << matrix.size(), vector<int>(matrix.size(), -1));

    heldKarp(matrix, dp, parent);

    auto [bestCost, bestLast] = findBestCostAndLast(matrix, dp);

    vector<int> path = findPath(parent, bestLast);

    for (int i = 0; i < path.size(); i++)
        cout << path[i] << ((i == path.size() - 1) ? "" : "-> ");

    cout << endl;
    cout << "Best Cost: " << bestCost << endl;

    return 0;
}

vector<vector<int>> file2Matrix(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return {};
    }

    vector<vector<int>> matrix;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int value;
        while (ss >> value) row.push_back(value);
        matrix.push_back(row);
    }

    return matrix;
}

void heldKarp(const vector<vector<int>>& matrix,
              vector<vector<int>>& dp,
              vector<vector<int>>& parent) {
    // ou mask = 1 || Inicializei assim p mostrar que o vertice 0 é o inicial
    int mask = 1 << 0;

    dp[mask][0] = 0;
    for (; mask < (1 << matrix.size()); mask += 2) {
        for (int i = 0; i < matrix.size(); i++) {
            if (!(mask & (1 << i))) continue;

            if (dp[mask][i] == MAX) continue;

            for (int j = 0; j < matrix.size(); j++) {
                if (mask & (1 << j)) continue;

                int newMask = mask | (1 << j);

                int newCost = dp[mask][i] + matrix[i][j];

                if (newCost < dp[newMask][j]) {
                    dp[newMask][j] = newCost;
                    parent[newMask][j] = i;
                }
            }
        }
    }
}

pair<int, int> findBestCostAndLast(const vector<vector<int>>& matrix,
                                   const vector<vector<int>>& dp) {
    int fullMask = (1 << matrix.size()) - 1;
    int bestCost = INT_MAX;
    int bestLast = -1;

    for (int i = 1; i < matrix.size(); i++) {
        if (dp[fullMask][i] == MAX) continue;

        int cost = dp[fullMask][i] + matrix[i][0];
        if (cost <= bestCost) {
            bestCost = cost;
            bestLast = i;
        }
    }

    return pair<int, int>(bestCost, bestLast);
}

vector<int> findPath(const vector<vector<int>>& parent,
                     int bestLast) {
    vector<int> path;

    int current = bestLast;
    int currentMask = parent.size() - 1;

    while (current != 0) {
        path.push_back(current);

        int prev = parent[currentMask][current];

        currentMask ^= (1 << current);

        current = prev;
    }

    path.push_back(0);
    reverse(path.begin(), path.end());
    path.push_back(0);

    return path;
}
