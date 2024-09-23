#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <tuple>

#define ll long long
#define ull unsigned long long
#define pb emplace_back
using namespace std;
#define mina ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define no cout << "No\n"
#define el '\n'
#define all(x) (x).begin(), (x).end()
const int NOT_COLORED = 0, RED = 1, BLUE = 2;

const int N = 8;
const int INF = numeric_limits<int>::max();
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int dijkstra(int sx, int sy, int ex, int ey) {
    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dist[sx][sy] = 0;
    pq.push({0, sx, sy});

    while (!pq.empty()) 
    {
        auto [cost, x, y] = pq.top();
        pq.pop();

        if (x == ex && y == ey) return cost;
        if (cost > dist[x][y]) continue;

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) 
            {
                int newCost = cost + (x * nx + y * ny);
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }

    return -1;
}

int main() {
    int sx, sy, ex, ey;

    while (cin >> sx >> sy >> ex >> ey) 
    {
        int rs = dijkstra(sx, sy, ex, ey);
        cout << (rs==-1? -1 : rs) << el ;
    }

    return 0;
}
