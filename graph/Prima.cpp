#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <queue>
struct Edge {
    long long to, w;
    bool operator > (const Edge& other) const {
        return w > other.w;
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<long long, long long>>> g(n + 1);
    for (long long i = 0; i < m; i++) {
        long long a, b, w;
        std::cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    pq.push({1, 0});
    std::vector <bool> used(n + 1, false);
    long long W = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (used[e.to]) continue;
        used[e.to] = true;
        W += e.w;
        for (auto [to, w] : g[e.to]) {
            pq.push({to, w});
        }
    }
    std::cout << W << '\n';
}
