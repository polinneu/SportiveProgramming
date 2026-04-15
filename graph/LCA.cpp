#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <queue>
std::vector<std::vector<long long>> g;
std::vector<std::vector<long long>> up;
std::vector<long long> prev, depth;
std::vector <bool> used;
const int LOG = 18;

void precount (long long v) {
    up[v][0] = prev[v];
    for (long long k = 1; k < LOG; k++) {
        if (up[v][k-1] != -1) up[v][k] = up[up[v][k - 1]][k - 1];
    }
}
void dfs_precount (long long v, long long dep) {
    used[v] = true;
    depth[v] = dep;
    precount(v);
    for (auto u : g[v]) {
        if (!used[u]) dfs_precount(u, dep + 1);
    }
}
long long lift (long long v, long long h) {
    for (long long k = 0; k < LOG; k++) {
        if (h & (1 << k)) {
            v = up[v][k];
            if (v == -1) break;
        }
    }
    return v;
}
long long lca (long long a, long long b) {
    if (depth[a] < depth[b]) std::swap(a, b);
    a = lift(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (long long k = LOG - 1; k >= 0; --k) {
        if (up[a][k] != up[b][k]) {
            a = up[a][k];
            b = up[b][k];
        }
    }
    return up[a][0];
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n, m;
    std::cin >> n >> m;
    g.resize(n + 1);
    prev.resize(n + 1);
    up.resize(n + 1);
    depth.resize(n + 1);
    used.resize(n + 1);
    prev[0] = -1;
    for (long long i = 1; i < n; ++i) {
        std::cin >> prev[i];
        g[prev[i]].push_back(i);
    }
    for (long long i = 0; i < n; ++i) {
        up[i].resize(LOG);
    }
    dfs_precount(0, 0);
    while (m--) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << lca(a, b);
    }


}
