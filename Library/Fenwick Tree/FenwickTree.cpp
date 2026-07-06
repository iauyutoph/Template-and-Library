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

//文字cのABC/abc文字列内でのitrを求める
int char_itr(char c, string ABC_abc) {
    int ans = 0;
    rep0(i, 26) if (c == ABC_abc[i]) ans = i;
    if (ABC_abc[ans] != c) ans = -1;
    return ans;
}

//x^nを求める
ull power(ull x, ull n) {
    ull ans = 1;
    while (n > 0) {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

//x^nをmod998244353で求める
ull modpower(ull x, ull n) {
    ull ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

//xのmod998244353における逆元を求める
ll modinv(ll x) {
    return modpower(x, mod - 2);
}

class FenwickTree {
    public:

    int siz = 1;
    long long data[1000000]; //1-indexed

    //clear関数：data配列の初期化
    void clear(int n) {
        siz = n;
        rep1(i, siz) data[i] = 0;
        return;
    }

    //add関数：a_posに操作を行う（デフォ：xを加算）
    void add(int pos, long long x) {
        for (int i = pos; i <= siz; i += (i & -i)) data[i] += x;
        return;
    }

    //answer関数：区間[1,R]の配列に対するクエリに答える（デフォ：総和）
    long long answer(int R) {
        long long ans = 0;
        for (int i = R; i > 0; i -= (i & -i)) ans += data[i];
        return ans;
    }
};

FenwickTree BIT;

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}
