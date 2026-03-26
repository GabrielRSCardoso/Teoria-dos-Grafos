#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n;

int base;
vector<int> next_digit;
vector<int> circuit;

void dfs(int u) {
    stack<int> stk;
    stk.push(u);
    while (!stk.empty()) {
        int v = stk.top();
        if (next_digit[v] < 10) {
            int d = next_digit[v]++;
            int w = (v * 10 + d) % base;
            stk.push(w);
        } else {
            circuit.push_back(v);
            stk.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n && n != 0) {
        base = 1;
        for (int i = 0; i < n - 1; i++) base *= 10;

        int num_nodes = base;

        next_digit.assign(num_nodes, 0);
        circuit.clear();

        dfs(0);


        reverse(circuit.begin(), circuit.end());

        string result = "";

        if (n > 1) {
            string prefix = to_string(circuit[0]);
            while ((int)prefix.size() < n - 1) prefix = "0" + prefix;
            result += prefix;
        }

        if (n == 1) {
            result = "0123456789";
        } else {
            for (int i = 0; i + 1 < (int)circuit.size(); i++) {
                result += (char)('0' + circuit[i + 1] % 10);
            }
        }

        cout << result << "\n";
    }

    return 0;
}