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

class LazySegmentTree {
    public:
    int siz = 1;
    long long data[1000000], lazy[1000000]; //0-indexed

    //clear関数：data配列の初期化
    int clear(int n) {
        while (siz < n) siz *= 2;

        rep0(i, 2 * siz) data[i] = INF, lazy[i] = -INF;
        return siz;
    }

    //divide関数：lazy配列に入った要素を下へ分割する
    void divide(int pos) {
        if (lazy[pos] != -INF) {
            data[pos] = lazy[pos];
            if (pos < siz) lazy[2 * pos] = lazy[pos], lazy[2 * pos + 1] = lazy[pos];
            lazy[pos] = -INF;
        }
        return;
    }

    //update関数：区間[l,r)の配列に操作を行う（デフォ：xに変更）
    //main関数ではL = 1,R = siz + 1, pos = 1とすること
    void update(int l, int r, int L, int R, int pos, long long x) {
        divide(pos);
        if (l <= L and R <= r) {
            lazy[pos] = x;
            divide(pos);
            return;
        }
        if (R <= l or r <= L) return;
        int m = (L + R) / 2;
        update(l, r, L, m, pos * 2, x);
        update(l, r, m, R, pos * 2 + 1, x);
        data[pos] = min(data[pos * 2], data[pos * 2 + 1]);
        return;
    }

    //answer関数：区間[l,r)の配列に対するクエリに答える(デフォ：最小値)
    //main関数ではL = 1,R = siz + 1, pos = 1とすること
    long long answer(int l, int r, int L, int R, int pos) {
        divide(pos);
        if (l <= L and R <= r) return data[pos];
        if (R <= l or r <= L) return INF;
        int m = (L + R) / 2;
        return min(answer(l, r, L, m, 2 * pos), answer(l, r, m, R, 2 * pos + 1));
    }
};

LazySegmentTree LST;

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}
