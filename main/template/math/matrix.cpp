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

const int mod = 1000000007;
struct matrix {
    int n,m;
    std::vector<std::vector<int>> arr;
    matrix(int n, int m, int val = 0) : n(n), m(m), arr(n, std::vector<int>(m, val)) {}
    static matrix identity(int n) {
        matrix I(n, n);
        for (int i=0; i<n; i++) I.arr[i][i] = 1;
        return I;
    }
    std::vector<int>&operator[](int i){return arr[i];}
    const std::vector<int>&operator[](int i)const{return arr[i];}
    matrix operator* (const matrix&o) const {
        matrix result(n, o.m);
        for(int i=0; i<n; i++) for (int k=0; k<m; k++) if(arr[i][k]) for (int j=0; j<o.m; j++) result.arr[i][j] = (result.arr[i][j] + arr[i][k] * o.arr[k][j]) % mod;
        return result;
    }
    matrix pow(int exp) {
        matrix base = *this, result = identity(n);
        while(exp) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};
