#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define LF '\n'
#define SP ' '

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int testcase = 1;
const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
ll n, m, k, a, b, c, d;
int tmp, tmp1, tmp2, tmp3;

vector<ld> v;
vector<pair<bool, pair<ll, ll>>> qs;
ll sign = 1LL;
ll cnt = 0LL;
bool all0 = false;
map<ld, int> mp;

int seg[4 * MAXN];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || r < pos) return;
	if (l == r) {
		seg[node] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(node << 1, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	seg[node] = seg[node << 1] + seg[node * 2 + 1];
}

int query(int node, int l, int r, int s, int e) {
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return seg[node];
	int mid = (l + r) >> 1;
	int q1 = query(node * 2, l, mid, s, e);
	int q2 = query(node * 2 + 1, mid + 1, r, s, e);
	return q1 + q2;
}

void init() {
}

void solve() {
	cin >> n;
	// input qs
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> a >> b;
			qs.push_back({1, {a, b}});
		} else {
			cin >> a;
			qs.push_back({0, {a, 0LL}});
		}
	}
	// ans -> v
	v.push_back((ld)0);
	v.push_back(-((ld)1e18 + 1));
	v.push_back((ld)1e18 + 1);
	for (int i = 0; i < n; i++) {
		if (!qs[i].first) {
			v.push_back((ld)qs[i].second.first);
		}
		ll a = qs[i].second.first;
		ll b = qs[i].second.second;
		if (!a or !b) continue;
		v.push_back(-((ld)b / (ld)a));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		mp[v[i]] = i;
	}
	// for (auto i : v) {
	// 	cout << i << SP;
	// }
	// cout << LF;
	// qu
	for (int i = 0; i < n; i++) {
		auto q = qs[i];
		// 2
		if (!q.first) {
			// cout << all0 << SP << sign << SP << cnt << LF;
			if (all0) {
				cout << "0\n";
			} else {
				ll x = q.second.first;
				auto lo = lower_bound(v.begin(), v.end(), (ld)x);
				ll res = query(1, 1, v.size(), lo - v.begin() + 1, lo - v.begin() + 1);	 // 마지막 변수
				// cout << "res " << res << SP << x << SP << v[lo - v.begin()] << SP << *lo << SP << lo - v.begin() << LF;
				if (*lo == x and res) {
					// if (*lo == x) {
					cout << "0\n";
				} else {
					ll res = query(1, 1, v.size(), 1, lo - v.begin() + 1);	// 마지막 변수
					bool flag = (cnt % 2LL) xor (res % 2LL);
					// cout << "x : " << x << LF;
					// cout << "id : " << lo - v.begin() << LF;
					// cout << "v : " << v[lo - v.begin()] << LF;
					// cout << "res : " << res << LF;
					// cout << "sign : " << sign << LF;
					// cout << "cnt : " << cnt << LF;
					// cout << "flag : " << flag << LF;
					// cout << "signd : " << (sign > 0LL) << LF;

					if (sign > 0LL) flag = !flag;

					if (flag)
						cout << "+\n";
					else
						cout << "-\n";
				}
			}
		}
		// 1
		else {
			ll a = q.second.first;
			ll b = q.second.second;
			// cout << a << SP << b << SP << sign << SP << cnt << LF;
			if (!a and !b) all0 = true;
			if (all0) continue;
			if (!b) {
				update(1, 1, v.size(), mp[(ld)0] + 1, 1);
				// cout << "up " << SP << 0 << mp[(ld)0] << LF;
				// cout << query(1, 1, v.size(), mp[(ld)0] + 1, mp[(ld)0] + 1);
				if (a < 0LL) sign *= -1LL;
				cnt++;
				continue;
			}
			if (!a) {
				if (b < 0LL) sign *= -1LL;
				continue;
			}
			cnt++;
			if (a < 0LL) sign *= -1LL;
			update(1, 1, v.size(), mp[-((ld)b / (ld)a)] + 1, 1);
			// cnt++;
			// cout << "up " << -((ld)b / (ld)a) << SP << mp[-((ld)b / (ld)a)] + 1 << LF;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// cout.setf(ios::fixed), cout.precision(7);
	// srand(time(NULL));

	// cin >> testcase;
	init();
	while (testcase--) solve();
	return 0;
}