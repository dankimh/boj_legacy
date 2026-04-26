#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

struct MatrixChainHuShing {
    static constexpr int MAXV = 200005;

    struct Arc {
        int l = 0, r = 0;
        int low = 0;
        int64 base = 0;
        int64 prod = 0;
        int64 num = 0, den = 0;

        bool encloses(const Arc& other) const {
            return l <= other.l && other.r <= r;
        }
        int64 support() const {
            return num / den;
        }
        bool operator<(const Arc& other) const {
            return support() < other.support();
        }
    };

    int m = 0;
    int arcCnt = 0;
    int heapCnt = 0;

    Arc arc[MAXV];
    int heapId[MAXV];
    int subSize[MAXV];
    int64 w[MAXV];
    int64 pref[MAXV];
    vector<int> tree[MAXV];
    vector<Arc> cover[MAXV];
    priority_queue<Arc> heaps[MAXV];

    void reset(int nVertices) {
        m = nVertices;
        arcCnt = 0;
        heapCnt = 0;

        fill(pref, pref + m + 2, 0);
        fill(heapId, heapId + m + 2, 0);
        fill(subSize, subSize + m + 2, 0);

        for (int i = 0; i <= m + 1; ++i) {
            tree[i].clear();
            cover[i].clear();
            while (!heaps[i].empty()) heaps[i].pop();
        }
    }

    int newArc(int l, int r) {
        int id = ++arcCnt;
        arc[id].l = l;
        arc[id].r = r;
        arc[id].low = (w[l] < w[r] ? l : r);
        arc[id].prod = w[l] * w[r];
        arc[id].base = pref[r] - pref[l] - arc[id].prod;
        arc[id].num = arc[id].den = 0;
        return id;
    }

    void buildLaminarTree(const vector<pair<int,int>>& cand) {
        vector<int> st;
        newArc(1, m + 1); // root = 1

        for (auto [l, r] : cand) {
            int id = newArc(l, r);
            while (!st.empty() && arc[id].encloses(arc[st.back()])) {
                tree[id].push_back(st.back());
                st.pop_back();
            }
            st.push_back(id);
        }

        while (!st.empty()) {
            tree[1].push_back(st.back());
            st.pop_back();
        }
    }

    void buildCandidates() {
        vector<int> st;
        vector<pair<int,int>> raw, cand;

        for (int i = 1; i <= m; ++i) {
            while ((int)st.size() >= 2 && w[st.back()] > w[i]) {
                raw.push_back({st[(int)st.size() - 2], i});
                st.pop_back();
            }
            st.push_back(i);
        }

        while ((int)st.size() >= 4) {
            raw.push_back({1, st[(int)st.size() - 2]});
            st.pop_back();
        }

        for (auto [l, r] : raw) {
            if (l == 1 || r == 1) continue;
            cand.push_back({l, r});
        }

        buildLaminarTree(cand);
    }

    void normalize(vector<int64>& dim) {
        int pos = min_element(dim.begin(), dim.end()) - dim.begin();
        rotate(dim.begin(), dim.begin() + pos, dim.end());

        for (int i = 1; i <= m; ++i) w[i] = dim[i - 1];
        w[m + 1] = w[1];
        w[0] = 0;

        for (int i = 1; i <= m + 1; ++i) {
            pref[i] = pref[i - 1] + w[i] * w[i - 1];
        }
    }

    int64 minNeighborCost(int node) {
        if (node == 1) return w[1] * w[2] + w[1] * w[m];

        Arc& cur = arc[node];
        if (cur.low == cur.l) {
            if (cover[cur.l].empty() || !cur.encloses(cover[cur.l].back())) {
                return w[cur.l] * w[cur.l + 1];
            }
            return cover[cur.l].back().prod;
        } else {
            if (cover[cur.r].empty() || !cur.encloses(cover[cur.r].back())) {
                return w[cur.r] * w[cur.r - 1];
            }
            return cover[cur.r].back().prod;
        }
    }

    void pushArc(int node, const Arc& a) {
        heaps[heapId[node]].push(a);
        cover[a.l].push_back(a);
        cover[a.r].push_back(a);
    }

    void popTop(int node) {
        const Arc& top = heaps[heapId[node]].top();
        cover[top.l].pop_back();
        cover[top.r].pop_back();
        heaps[heapId[node]].pop();
    }

    void mergeHeaps(int node) {
        int heavy = -1;
        for (int child : tree[node]) {
            if (heavy == -1 || subSize[heavy] < subSize[child]) heavy = child;
        }

        heapId[node] = heapId[heavy];
        auto& dst = heaps[heapId[node]];

        for (int child : tree[node]) {
            if (child == heavy) continue;
            auto& src = heaps[heapId[child]];
            while (!src.empty()) {
                dst.push(src.top());
                src.pop();
            }
        }
    }

    void dfs(int node) {
        Arc& cur = arc[node];
        subSize[node] = 1;

        if (tree[node].empty()) {
            heapId[node] = ++heapCnt;
            cur.den = cur.base;
            cur.num = w[cur.low] * (cur.den + cur.prod - minNeighborCost(node));
            pushArc(node, cur);
            return;
        }

        cur.den = cur.base;
        for (int child : tree[node]) {
            dfs(child);
            subSize[node] += subSize[child];
            cur.den -= arc[child].base;
        }

        cur.num = w[cur.low] * (cur.den + cur.prod - minNeighborCost(node));
        mergeHeaps(node);

        auto& pq = heaps[heapId[node]];

        while (!pq.empty() && pq.top().support() >= w[cur.low]) {
            cur.den += pq.top().den;
            popTop(node);
            cur.num = w[cur.low] * (cur.den + cur.prod - minNeighborCost(node));
        }

        while (!pq.empty() && cur.support() <= pq.top().support()) {
            cur.den += pq.top().den;
            cur.num += pq.top().num;
            popTop(node);
        }

        pushArc(node, cur);
    }

    int64 solve(vector<int64> dim) {
        // dim = [p0, p1, ..., pN], matrices = N
        int nMatrix = (int)dim.size() - 1;
        if (nMatrix <= 1) return 0;

        reset((int)dim.size());
        normalize(dim);
        buildCandidates();
        dfs(1);

        int64 ans = 0;
        auto& pq = heaps[heapId[1]];
        while (!pq.empty()) {
            ans += pq.top().num;
            pq.pop();
        }
        return ans;
    }
};

static MatrixChainHuShing solver;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> dim;
    dim.reserve(N + 1);

    int64 r, c;
    cin >> r >> c;
    dim.push_back(r);
    dim.push_back(c);

    for (int i = 2; i <= N; ++i) {
        cin >> r >> c;
        dim.push_back(c);
    }

    cout << solver.solve(dim) << '\n';
    return 0;
}