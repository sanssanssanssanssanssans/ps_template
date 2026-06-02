#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <climits>
#include <cstdint>
using ll = long long;
using pii = std::pair<ll, ll>;
template<typename T>
T input() {T x; std::cin >> x; return x;}
void print(auto... x) {(std::cout << ... << x);}
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
void solve();
int TC_MODE = 0, T = 1;

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    if (TC_MODE) T = input<int>();
    while (T--) solve();
    return 0;
}

void solve() {

}
