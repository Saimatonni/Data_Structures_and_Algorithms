//30

#include<bits/stdc++.h>
using namespace std;


#define dvg(x) cout<<#x<<" "<<x<<endl;
#define dvg2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define pcs pair<char, string>

int const N = 1e5 + 10;
int freq[1024];
int cnt[1024];

int children[N][2];
class point{
public:
	int data;
	int freq;
	int id;
	point(){

	}
}v[N];


class cmp{
public:
	bool operator () (const point p1, const point p2)
	{
		if(p1.freq == p2.freq) return p2.data > p2.data;
		return p1.freq > p2.freq;
	}
};

vector<pcs> ans;

void dfs(int id, int num)
{
	if(v[id].data != 1000000){
		cnt[v[id].data] = num;
		return;
	}

	if(children[id][0] != -1) dfs(children[id][0], num + 1);
	if(children[id][1] != -1) dfs(children[id][1], num + 1);
}

int main()
{
	for(int i = 0; i < N; i++) children[i][0] = children[i][1] = -1;

 	priority_queue<point, vector<point>, cmp> pq;


 	int n;
 	cin>>n;
 	int id = 0;
 	string s;
 	getline(cin, s);
 	getline(cin, s);
 	//cout<<s<<endl;
 	for(int i = 0; i < s.size(); i++){
 		freq[s[i]]++;
 	}
 	for(int i = 0; i < 1024; i++) if(freq[i])
 	{
 		point p;
 		p.data = i;
 		p.freq = freq[i];
 		p.id = id;
 		v[id] = p;
 		pq.push(p);
 		id++;
 	}

 	while(pq.size() > 1)
 	{
 		point pl = pq.top();
 		pq.pop();
 		point pr = pq.top();
 		pq.pop();

 		point p;
 		p.freq = pr.freq + pl.freq;
 		p.data = 1000000;
 		p.id = id;
 		pq.push(p);
 		v[id] = p;
 		children[id][0] = pl.id;
 		children[id][1] = pr.id;
 		id++;

 	}
 	dfs(id - 1, 0);

 	int ans = 0;
 	for(int i = 0; i < n; i++) ans += cnt[s[i]];
 	cout<<ans<<endl;



}
