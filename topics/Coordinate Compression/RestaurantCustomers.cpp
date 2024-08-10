#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct CoordinateCompression {
private:
    vector<ll> init;

    void compress(vector<ll>& v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

public:
    CoordinateCompression(vector<ll>& v) {
        init = v;
        compress(init);
    }

    int index(ll val) {
        return lower_bound(init.begin(), init.end(), val) - init.begin();
    }
    // Get the compressed index of a value

    ll initVal(int idx) {
        return init[idx];
    }
    // Get the original value at a compressed index
};

// This is an easy partial sum problem.
// However, the main challenge lies in handling large constraints: l and r can be up to 10^18, but our memory limit for the array is around 10^6.
// Given the constraints that n (number of intervals) won't exceed 10^5, it's possible to use coordinate compression effectively.
// Coordinate compression allows us to map the potentially large numbers to a smaller range, e.g., 0, 1, 2, ..., up to 2 * n in the worst case scenario(2*10^5).
// If n were extremely large (e.g., 10^18), this solution would not be feasible due to memory constraints.

void problem() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    vector<ll> idx;

    // Read input and collect all time points for compression
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        idx.push_back(l[i]);
        idx.push_back(r[i]);
    }

    // Initialize the CoordinateCompression with all collected time points
    CoordinateCompression co(idx);

    // Assign the new compressed indices for l and r
    // Step: read / sort / assign
    for (int i = 0; i < n; ++i) {
        l[i] = co.index(l[i]);
        r[i] = co.index(r[i]);
    }

    // Using a difference array to compute partial sums
    vector<int> par(2 * n + 1, 0);

    for (int i = 0; i < n; ++i) {
        par[l[i]]++;
        par[r[i] + 1]--;
    }

    // Calculate prefix sums to find the maximum number of customers at any time
    for (int i = 1; i < 2 * n + 1; ++i) {
        par[i] += par[i - 1];
    }

    cout << *max_element(par.begin(), par.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        problem();
    }

    return 0;
}
