#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <queue>
std::vector<std::vector<long long>> g;
std::vector<long long> prev, depth, tin, tout;
std::vector <bool> used;
const int LOG = 20;
long long Time = 0;
void dfs_precount (long long v, long long dep) {
    used[v] = true;
    depth[v] = dep;
    tin[v] = Time++;
    for (auto u : g[v]) {
        if (!used[u]) dfs_precount(u, dep + 1);
    }
    tout[v] = Time++;
}
long long lca (long long a, long long b) {
    if (depth[a] > depth[b]) std::swap(a, b);
    while (!(tin[a] < tin[b] && tout[a] > tout[b])) a = prev[a];
    return a;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n, m;
    std::cin >> n >> m;
    g.resize(n + 1);
    prev.resize(n + 1, -1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    depth.resize(n + 1);
    used.resize(n + 1);
    for (long long i = 1; i < n; ++i) {
        long long a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        prev[b] = a;
    }
    long long root;
    for (long long i = 1; i <= n; ++i) {
        if (prev[i] == -1) root = i;
    }
    dfs_precount(root, 0);
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << a << " " << b << " " << lca(a, b) << "\n";
    }


}
