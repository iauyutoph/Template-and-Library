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

class UnionFind {
    public:
    int par[500000], siz[500000];

    //clear関数：par配列、siz配列の初期化
    void clear(int n) {
        rep0(i, n + 1) par[i] = -1, siz[i] = 1;
        return;
    }

    //root関数：xの親を求める
    int root(int x) {
        while (true) {
            if (par[x] == -1) break;
            x = par[x];
        }
        return x;
    }

    //unite関数：点aと点bを相互に結ぶ
    void unite(int a, int b) {
        int rootA = root(a);
        int rootB = root(b);
        if (rootA == rootB) return;

        if (siz[rootA] >= siz[rootB]) {
            par[rootB] = rootA;
            siz[rootA] += siz[rootB];
        }
        else {
            par[rootA] = rootB;
            siz[rootB] += siz[rootA];
        }
        return;
    }

    //judge関数：点aと点bが連結であるか判定
    bool judge(int a, int b) {
        int rootA = root(a);
        int rootB = root(b);
        if (rootA == rootB) return true;
        else return false;
    }

    //get_siz関数：点aを含む連結成分の頂点数を答える
    int get_siz(int a) {
        int rootA = root(a);
        return siz[rootA];
    }
};

UnionFind UF;

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}
