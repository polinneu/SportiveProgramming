#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <chrono>
#include <queue>
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector <std::vector<std::pair<long long, long long>>> g(n + 1);
    std::vector<long long> dp(n + 1, 1e18);
    for (long long i = 0; i < m; ++i) {
        long long a, b, w;
        std::cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    dp[1] = 0;
    for (long long way = 0; way < n; ++way) {
        for (long long v = 1; v <= n; ++v) {
            for (auto [u, w]: g[v]) {
                if (dp[v] + w < dp[u]) {
                    dp[u] = dp[v] + w;
                }
            }
        }
    }
    for (long v = 1; v <= n; ++v) {
        if (dp[v] == 1e18) {
            std::cout << 30000 << " ";
        } else std::cout << dp[v] << " ";
    }
}
