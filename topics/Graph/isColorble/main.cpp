/*
 * -> this is coded by Mina Demyan
 * NOTES
 * For a bipartite graph with sets RED and BLUE containing
 * ( r ) and ( b ) nodes respectively
 * , the maximum number of edges is ( r * b ).
 */
using namespace std;
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#include <utility>
#include <map>
#define mina ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define el '\n'
#include <string>
#include "queue"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include "deque" // for the topological sorting
using namespace std;
const int N = 1e5 + 5;
const int NOT_COLORED = 0, RED = 1, BLUE = 2;
//bool vis[N] ;
int n ;
vector<int>adj[N];
int color[N];
void bfs(int node)
{
    queue<int> q ;
    q.push(node);
    color[node] = RED ;
    while(q.size())
    {
        int u = q.front() ;
        q.pop() ;
        for (auto v : adj[u])
        {
            if (color[v]==NOT_COLORED)
            {
                color[v] = (color[u]==RED?BLUE:RED) ;
                q.push(v);
            }

        }

    }

}





int main()
{
    cin >> n ;
    int a , b ;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b ;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1);
    ll r {}, bu {};
    for (int i = 1; i <= n; ++i) {
        if (color[i]==RED) r++;
        else if ( color[i]==BLUE) bu++;
    }
    ll rs = bu*r -(n- 1);
    cout << rs << el;
}
