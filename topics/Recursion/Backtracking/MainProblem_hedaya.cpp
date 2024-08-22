#include <iostream>
#define ll long long
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define S second
#define F first
#define MP make_pair
#define PI 3.14159265
using namespace std;
ll M = 1e9 + 7;
#define rall(my) my.rbegin(), my.rend()
#include <utility>
#include <map>
#define mina ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define el endl
#define input(x)      \
    for (auto &i : x) \
    cin >> i
#define print(x)       \
	for (auto i : x)   \
	cout << i << " "; \
	cout << endl;
#define print2(x)      \
	for (auto i : x)   \
	cout << i << endl;
#define print3(x)      \
	for (auto i : x)   \
	cout << i << " ";
   

/*
 ============================
 input sample :  
 ============================
  4 4
  R...
  .#..
  ...#
  ...c
  =================
  output sample : = 
  =================
  RRDDDR
  DDRRDR
  DDRDRR
  DDDRRR

  */

char grid[10][10];
int n, m; 
string s;
void rec(int r , int c )
{
	// base case
    if (r == n - 1 and c == m - 1)
    {
		cout << s << endl;
        return; 
    }

    // transition

    if (c+ 1 < m && grid[r][c+1] != '#')
    {
		s.pb('R');
        rec(r , c+1);
		s.pop_back();
    }

    if (r + 1 < n && grid[r + 1][c] != '#')
    {
        s.pb('D');
        rec(r + 1, c);
        s.pop_back();
    }
}


//we are doing recursion /*nigga*/  
void solve() {
    
    /*
    * 
    R...
    .#..
    ...#
    ...c

    */
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j]; 
        }

    }
    rec(0, 0);
}

int main() {
        
    mina;
    int in = 1;
  //   cin >> in; // Uncomment this line if you want to read multiple test cases
    while (in--) {
        solve();
    }
    return 0;
}
