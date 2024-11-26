#include <bits/stdc++.h>
using namespace std;

int n;
int x[201];
vector <int> id1;
vector <int> idOdd, idEven;

#define MAXN 200001

int maxint = ~0U>>1;
int flow;
int pi[MAXN+1], v[MAXN+1];
int S, T;

struct etype
{
	int t, c;
	etype* next;
	etype* pair;
	etype(){next=0;}
	etype(int _t, int _c, etype* _n){t=_t, c=_c, next=_n;}
}*e[MAXN+1], *eb[MAXN+1], *Pe, *Pool;

int aug(int w, int lim)
{
	int t;
	v[w] = 1;
	if(w == T)
	{
		flow += lim;
		return lim;
	}
	for(etype *& i=e[w]; i; i = i->next)
		if(i->c && !v[i->t] && pi[w] == pi[i->t] + 1)
			if(t = aug(i->t, min(lim, i->c)))
				return i->c -= t, i->pair->c += t, t;
	return 0;
}

bool fix()
{
	int t = maxint;
	for(int i = S; i <= T; i++)
		if(v[i])
		{
			for(etype *j = eb[i]; j; j = j->next)
				if(j->c && !v[j->t])
					t = min(t, pi[j->t] + 1 - pi[i]);
		}
	if(t == maxint)
		return 0;

	for(int i = S; i <= T; i++)
		if(v[i])
			e[i] = eb[i], pi[i] += t;
	return 1;
}

etype* addedge(int s, int t, int c)
{
	etype * ret;
	++Pe;
	ret = Pe;
	Pe->t = t, Pe->c = c, Pe->next = e[s];
	e[s] = Pe;
	++Pe;
	Pe->t = s, Pe->c = 0, Pe->next = e[t];
	e[t] = Pe;
	e[s]->pair=e[t];
	e[t]->pair=e[s];
	return ret;
}

void prepare()
{
	if(Pool == NULL)
		Pool = new etype[1000001];
	Pe = Pool;
	memset(e, 0, sizeof(e));
}

int MaxFlow()
{
	flow = 0;
	memcpy(eb, e, sizeof(e));
	memset(pi, 0, sizeof(pi));
	do
	{
		do
		memset(v, 0, sizeof(v));
		while(aug(S, maxint));
	}
	while(fix());
	return flow;
}

/*  Note
	1. Set maxNodes here: #define MAXN 200001
	2. Set maxEdges here: Pool = new etype[1000001];
	3. S must be the min id, T must be the max id
*/

/*  Eaxmple
	prepare();
	S = 1, T = 2;
	addedge(1, 2, 3);
	cout << MaxFlow() << endl;
*/

int isPrime(int x)
{
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

vector <int> e2[201];
etype *flowEdge[201][201];
bool visited[201];

int MAIN()
{
	cin >> n;
	int nOdd = 0, nEven = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if(x[i] > 1 && x[i] % 2 == 0)
		{
			nEven ++;
			idEven.push_back(i);
		}
		if(x[i] > 1 && x[i] % 2 == 1)
		{
			nOdd ++;
			idOdd.push_back(i);
		}
	}
	int needOne = nEven - nOdd;
	int oneIn = 0, oneOut = 0;
	for(int i = 1; i <= n; i++)
		if(x[i] == 1)
		{
			if(needOne > 0)
			{
				idOdd.push_back(i);
				oneIn ++;
				needOne --;
			}
			else
			{
				id1.push_back(i);
				oneOut ++;
			}
		}
	
	if((oneIn == false && (oneOut == 1 || oneOut == 2)) || (idOdd.size() != idEven.size()))
	{
		cout << "Impossible" << endl;
		return 0;
	}
	//cout << oneIn << " / " << oneOut << endl;

	int eachSide = idOdd.size();
	S = 1;
	T = 2 * (1 + eachSide);
	prepare();
	for(int i = 0; i < eachSide; i++)
		addedge(S, 2 + i, 2);
	for(int i = 0; i < eachSide; i++)
		addedge(2 + eachSide + i, T, 2);
	for(int i = 0; i < eachSide; i++)
		for(int j = 0; j < eachSide; j++)
			if(isPrime(x[idOdd[i]] + x[idEven[j]]))
			{
				if(x[idOdd[i]] == 1 && oneIn > 0 && oneOut > 0)
				{
					flowEdge[i][j] = addedge(2 + i, 2 + eachSide + j, 2);
				}
				else
					flowEdge[i][j] = addedge(2 + i, 2 + eachSide + j, 1);
				//cout << i << " " << j << " : " << x[idOdd[i]] << " + " << x[idEven[j]] << endl;
			}
			else
				flowEdge[i][j] = NULL;
	int f = MaxFlow();

	if(f != 2 * eachSide)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		vector< vector <int> > ans, one;
		if(id1.size() != 0)
		{
			if(oneIn > 0)
				one.push_back(id1);
			else
				ans.push_back(id1);
		}
		for(int i = 0; i < eachSide; i++)
			for(int j = 0; j < eachSide; j++)
				if(flowEdge[i][j] != NULL)
					if(flowEdge[i][j] -> pair -> c > 0)
					{
						int a = idOdd[i];
						int b = idEven[j];
						e2[a].push_back(b);
						e2[b].push_back(a);
					}
		memset(visited, false, sizeof(visited));
		for(int i = 1; i <= n; i++)
			if(visited[i] == false && e2[i].size() > 0)
			{
				vector <int> t;
				int cur = i;
				visited[cur] = true;
				t.push_back(i);
				while(true)
				{
					if(visited[e2[cur][0]] == false)
						cur = e2[cur][0];
					else if(e2[cur].size() > 1 && visited[e2[cur][1]] == false)
						cur = e2[cur][1];
					else
						break;
					t.push_back(cur);
					visited[cur] = true;

				}
				int pos1 = -1;
				for(int j = 0; j < t.size(); j++)
					if(x[t[j]] == 1)
						pos1 = j;
				if(pos1 == -1 || oneIn == false || oneOut == false)
					ans.push_back(t);
				else
				{
					vector <int> t2;
					for(int j = pos1; j < t.size(); j++)
						t2.push_back(t[j]);
					for(int j = 0; j < pos1; j++)
						t2.push_back(t[j]);
					one.push_back(t2);
				}
			}

		if(one.size() > 0)
		{
			vector <int> t;
			for(int i = 0; i < one.size(); i++)
				for(int j = 0; j < one[i].size(); j++)
					t.push_back(one[i][j]);
			ans.push_back(t);
		}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].size() << " ";
			for(int j = 0; j < ans[i].size(); j++)
			{
				cout << ans[i][j] << (j == ans[i].size() - 1 ? "\n" : " ");
			}
		}
	}
	
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
