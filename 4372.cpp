#include <cstdio>
#include <cstring>
#include <algorithm>

template <typename Tp>Tp Max(const Tp &a, const Tp &b) {return a > b ? a : b;}
template <typename Tp>Tp Min(const Tp &a, const Tp &b) {return a < b ? a : b;}

template <typename Tp>void Read(Tp &x) {
	Tp in = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch=='-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {in = in * 10 + ch-'0'; ch = getchar();}
	x = in * f;
}

const int SN = 100000 + 10;

const int SM = SN * 40 + 10;

int head[SN], size[SN], f[SN], num, ALL, n, m;

struct Edge {
	int v, next;
}E[SN << 1];

void Add_E(int u, int v) {
	E[++num].v = v, E[num].next = head[u], head[u] = num;
}

char s[3];

namespace Tree {

	int size[SN], top[SN], fa[SN], son[SN], d[SN];

	void Dfs(int u) {

		size[u] = 1;

		for(int i = head[u]; i; i = E[i].next) {
			int to = E[i].v;
			if(to == fa) continue ;
			d[to] = d[u] + 1, dis[to] = dis[u] + E[i].w;
			fa[to] = u;
			Dfs(to, u);
			size[u] += size[to];
			if(size[son[u]] < size[to]) son[u] = to;
		}
	}

	void Dfs(int u, int t) {

		top[u] = t;

		if(son[u]) Dfs(son[u], t);

		for(int i = head[u]; i; i = E[i].next) {
			int to = E[i].v;
			if(to != son[u] && to != fa[u])
				Dfs(to, to);
		}
	}
	
	int Query(int x, int y) {
		int ans = 0;
		while(top[x] != top[y]) {
			if(d[x] > d[y]) std :: swap(x, y);
			ans += d[y] - d[top[y]];
			y = fa[top[y]];
		}
		if(d[x] > d[y]) std :: swap(x, y);
		ans += d[y] - d[x];
		return ans;
	}
}

namespace Seg {

	int rot[SN], sum[SM], add[SM], lson[SM], rson[SM], TIME;

	void Modify(int QL, int QR, int C, int l, int r, int &rt) {
		if(!rt) rt = ++TIME;

		if(QL <= l && QR >= r) {
			sum[rt] += (r - l + 1) * C, add[rt] += C;
			return ;
		}
		
		int mid = (l + r) >> 1;

		pushdown(l, r, rt);
		
		if(QL <= mid) Modify(QL, QR, C, l, mid, lson[rt]);
		if(QR > mid) Modify(QL, QR, C, mid + 1, r, rson[rt]);

		sum[rt] = sum[lson[rt]] + sum[rson[rt]];
	}

	int Query(int QL, int QR, int l, int r, int rt) {
		if(!rt) return ;

		if(QL <= l && QR >= r) return sum[rt];
		
		int ans = 0, mid = (l + r) >> 1;

		pushdown(l, r, rt);
		
		if(QL <= mid) ans += Query(QL, QR, l, mid, lson[rt]);
		if(QR > mid) ans += Query(QL, QR, mid + 1, r, rson[rt]);

		return ans;
	}
}

void Getroot(int u, int fa) {

	size[u] = 1, f[u] = 0;

	for(int i = head[u]; i; i = E[i].next) {
		int to = E[i].v;
		if(vis[to] || to == fa) continue ;
		Getroot(to, u);
		size[u] += size[to];
		f[u] = Max(f[u], size[to]);
	}

	f[u] = Max(f[u], ALL - size[u]);

	if(f[u] < f[root]) root = u;
}

void Dfs(int u) {
	vis[u] = 1;

	for(int i = head[u]; i; i = E[i].next) {
		int to = E[i].v;
		if(vis[to]) continue ;
		root = 0, ALL = size[to];
		Getroot(to);
		p[root] = u;
		Dfs(root);
	}
	
}

void Query(int x) {

	int now = x, ans = 0;

	while(now) {

		
	}

	return ans;
}

void Modify() {

}

int main() {
	int x, y, z;
	
	Read(n), Read(m);

	for(int i = 1; i < n; i++) {
		Read(x), Read(y);
		Add_E(x, y), Add_E(y, x);
	}

	f[0] = 0x3f3f3f, ALL = n;

	Getroot(1, 0);

	Dfs(1);

	Tree :: Dfs(1);

	Tree :: Dfs(1, 1);

	while(m--) {

		scanf("%s", s + 1);

		if(s[1] == 'Q') Read(x), Query(x);
		else {
			Read(x), Read(y), Read(z);
			Modify(x, y, z);
		}

	}

	return 0;
}
