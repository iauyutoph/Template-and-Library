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

int e() {return -INF;} //単位元
int op(int a, int b) {return max(a, b);} //演算

template<class S, S (*op)(S, S), S (*e)()>
struct SegmentTree {
    private:
    int siz = 1;
    vector<int> data;
    
    public:
    void clear(int n) {
        while (siz < n) siz *= 2;

        data.assign(2 * siz + 1, e());
        return;
    }

    void update(int pos, long long x) {
        pos += siz - 1;
        data[pos] = x;

        while (pos > 1) {
            pos /= 2;
            data[pos] = op(data[2 * pos], data[2 * pos + 1]);
        }

        return;
    }

    S answer(int l, int r) {
        l += siz - 1, r += siz - 1;

        S ansl = e(), ansr = e();
        while (l < r) {
            if (l & 1) ansl = op(ansl, data[l++]);
            if (r & 1) ansr = op(data[--r], ansr);
            l >>= 1, r >>= 1;
        }

        return op(ansl, ansr);
    }
};

SegmentTree<int, op, e> seg; //intの部分は状況に応じて書き換える

void sample() {
    int n, q; cin >> n >> q; //n:配列の要素数,q:クエリ数
    seg.clear(n); //seg.clear(n):segtreeにおける配列を設定する
    rep1(i, n) seg.update(i, 0); //seg.update(i, 0):segtreeにおけるdata[i]の要素を0に変更する(加算などの場合は中身を書き換える)
    while(q--) { //q回繰り返す
        int type; cin >> type;
        if (type == 1) {
            int a, x; cin >> a >> x;
            seg.update(a, x); //data[a]をxに変更する(加算などの場合は中身を書き換える)
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.answer(l, r) << el; //seg.answer(l, r):[l,r)の区間のクエリに答える
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}
