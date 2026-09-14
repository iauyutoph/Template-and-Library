#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using PIL = pair<int, long long>;
using PLI = pair<long long, int>;
using PL = pair<long long, long long>;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
const ll mod = 998244353;
const int INF = 2e9;
const ll INFL = 2e18;
const int dx[5] = {-1, 0, 1, 0}, dy[5] = {0, 1, 0, -1};
#define rep0(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i <= (int)n; i++)
#define rrep0(i, n) for (int i = n - 1; i >= 0; i--)
#define rrep1(i, n) for (int i = n; i > 0; i--)
#define el "\n"
#define coutY cout << "Yes" << el
#define coutN cout << "No" << el
#define all(x) x.begin(), x.end()

template<typename T> bool chmin(T &a, T b) {return ((a > b) ? (a = b, true) : (false));}
template<typename T> bool chmax(T &a, T b) {return ((a < b) ? (a = b, true) : (false));}
template<typename T> 
using pq_greater = priority_queue<T, vector<T>, greater<T>>;
template<typename T> 
using pq_less = priority_queue<T, vector<T>, less<T>>;

int char_itr(char c, string ABC_abc) {//文字cのABC/abc文字列内でのitrを求める
    int ans = -1;
    rep0(i, 26) if (c == ABC_abc[i]) ans = i;
    return ans;
}

ull power(ull x, ull n) {//x^nを求める
    ull ans = 1;
    while (n > 0) {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

ull modpower(ull x, ull n) {//x^nをmod998244353で求める
    ull ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

ll modinv(ll x) {//xのmod998244353における逆元を求める
    return modpower(x, mod - 2);
}

struct Point{
    double x, y;

    Point operator+(const Point &other) const {
        return{x + other.x, y + other.y};
    }
    Point operator-(const Point &other) const {
        return{x - other.x, y - other.y};
    }
};

double vector_siz(Point a) {//ベクトルの大きさの計算
    return sqrt(a.x * a.x + a.y * a.y);
}

double inner_product(Point a, Point b) {//内積の計算
    return a.x * b.x + a.y * b.y;
}

Point projection_vector(Point a, Point b) {//b→からa→への正射影ベクトル
    double k = inner_product(a, b) / (vector_siz(a) * vector_siz(a));
    Point ans; ans.x = a.x * k, ans.y = a.y * k;
    return ans;
}

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned)time(NULL));


    return 0;
}
