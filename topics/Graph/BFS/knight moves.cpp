#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
#define pb emplace_back
#define rall(my) my.rbegin(), my.rend()
#define mina ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define el '\n'
#define ll long long

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
bool vis[8][8];
string s, e;

bool valid(int r, int c) {
    return (r >= 0 && c >= 0 && r < 8 && c < 8 && !vis[r][c]);
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<pair<pair<int, int>, int>> q;
    q.push({{s[0] - 'a', s[1] - '1'}, 0});
    vis[s[0] - 'a'][s[1] - '1'] = true;

    while (q.size()) {
        auto [coords, cost] = q.front();
        q.pop();
        int a = coords.first, b = coords.second;

        if (a == e[0] - 'a' && b == e[1] - '1') {
            return cost;
        }

        for (int i = 0; i < 8; ++i) {
            int new_x = a + dx[i];
            int new_y = b + dy[i];
            if (valid(new_x, new_y)) {
                vis[new_x][new_y] = true;
                q.push({{new_x, new_y}, cost + 1});
            }
        }
    }
    return -1;
}

  // ........
  // ..0.0...
  // .0...0..
  // ...0....
  // .0...0..
  //  .0.0...
  // ........
  // ........

int main() {
    mina;
    string l;
    while (getline(cin, l) && !l.empty()) {
        s = l.substr(0, 2);
        e = l.substr(3, 2);
        cout << "To get from " << s << " to " << e << " takes " << bfs() << " knight moves." << el;
    }

    return 0;
}
