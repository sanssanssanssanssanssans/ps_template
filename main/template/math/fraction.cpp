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

struct Fraction {
    ll numeric, denomator;

    Fraction(ll n = 0, ll d = 1) {
        if (d < 0) n = -n, d = -d;
        ll g = gcd(abs(n), d);
        numeric = n / g;
        denomator = d / g;
    }

    bool operator < (const Fraction& other) const {
        return numeric * other.denomator < other.numeric * denomator;
    }

    void print() const {
        std::cout << numeric << "/" << denomator;
    }
};
