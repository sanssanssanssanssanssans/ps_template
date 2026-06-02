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

const double eps = 1e-7;
int sign(double x) {return x < -eps ? - 1 : x > eps;}
bool zero(double x) {return !sign(x);}
bool eq(double x, double y) {return zero(x - y);}

struct pos {
    double x, y;
    pos(): x(0.0), y(0.0) {}
    pos(double x, double y) : x(x), y(y) {}
    pos operator + (const pos& other) const {return pos(x + other.x, y + other.y); }
    pos operator - (const pos& other) const {return pos(x - other.x, y - other.y); }
    pos operator * (const double& a) const {return pos(x * a, y * a); }
    pos operator / (const double& a) const {return pos(x / a, y / a); }
    double operator * (const pos& other) const {return x * other.x + y * other.y;}
    double operator / (const pos& other) const {return x * other.y - y* other.x;}
    bool operator == (const pos& other) const {return zero(x - other.x) && zero(y - other.y);}
    bool operator != (const pos& other) const {return !zero(x - other.x) || !zero(y - other.y);}
    bool operator < (const pos& other) const {
        if (!zero(x - other.x)) return x < other.x;
        return y < other.y;
    }
    bool operator <= (const pos& other) const {return *this < other || *this == other;}
};
