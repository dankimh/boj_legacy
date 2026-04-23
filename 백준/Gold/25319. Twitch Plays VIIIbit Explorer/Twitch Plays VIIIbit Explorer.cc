
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag,
						 tree_order_statistics_node_update>
	ordered_set;

#define LF '\n'
#define SP ' '

typedef long long ll;
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
int n, m, k, a, b, c, d, cnt;
int tmp, tmp1, tmp2, tmp3;

int mp[60][60];
vpii v[30];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s, ans;

void init() {}

string move(pii now, pii nxt) {
	string res;
	for (int i = 0; i < nxt.first - now.first; i++) res += "D";
	for (int i = 0; i < nxt.second - now.second; i++) res += "R";
	for (int i = 0; i < now.first - nxt.first; i++) res += "U";
	for (int i = 0; i < now.second - nxt.second; i++) res += "L";
	return res;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			mp[i][j] = s[j] - 'a';
			v[mp[i][j]].push_back({i, j});
		}
	}
	cin >> s;
	pii now = {0, 0};
	// get
	while (1) {
		bool flag = 1;
		string tmp_ans;
		pii pre_now = now;
		for (int i = 0; i < k; i++) {
			// cout << s[i] << LF;
			if (v[s[i] - 'a'].empty()) {
				// cout << "!!!\n";
				flag = 0;
				now = pre_now;
				break;
			}
			pii nxt = v[s[i] - 'a'].back();
			v[s[i] - 'a'].pop_back();
			// cout << nxt.first << SP << nxt.second << LF;
			tmp_ans += move(now, nxt);
			tmp_ans += "P";
			now = nxt;
		}
		if (!flag) break;
		ans += tmp_ans;
		cnt++;
	}
	// go end
	ans += move(now, {n - 1, m - 1});
	cout << cnt << SP << ans.size() << LF << ans;
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