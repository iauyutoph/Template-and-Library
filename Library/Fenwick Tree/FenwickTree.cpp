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

int e() {return 0;} //単位元
int op(int a, int b) {return a + b;} //演算
int inv(int a) {return -a;} //逆元

template<class S, S (*op)(S, S), S (*e)(), S (*inv)(S)>
struct FenwickTree {
    public:

    int siz = 1;
    vector<S> data; //1-indexed

    void clear(int n) {
        siz = n;
        data.assign(siz + 1, e());
        return;
    }

    S ans_prefix(int r) {
        S ans = e();
        for (int i = r; i > 0; i-= (i & -i)) ans = op(data[i], ans);
        return ans;
    }

    S answer(int l, int r) {
        S ans = e();
        ans = op(ans_prefix(r), ans);
        ans = op(inv(ans_prefix(l - 1)), ans);
        return ans;
    }

    void update(int pos, S x) {
        S now = answer(pos, pos);
        for (int i = pos; i <= siz; i += (i & -i)) data[i] = op(data[i], inv(now)), data[i] = op(data[i], x);
        return;
    }
};

FenwickTree<int, op, e, inv> BIT; //intは場合に応じて書き換える

void solve() {
    return;
}

void sample() {
    int n, q; cin >> n >> q; //n:配列の大きさ,q:クエリ数
    BIT.clear(n); //data配列の初期化
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos, x; cin >> pos >> x;
            BIT.update(pos, x); //A[pos]をxに更新
        }
        else {
            int l, r; cin >> l >> r;
            cout << BIT.answer(l, r - 1) << el; //区間[l,r-1]のクエリに答える
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
