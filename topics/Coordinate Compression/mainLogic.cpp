#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#define ll long long
using namespace std;

void solve() {
   int arr[]={30, 40 ,30 , 50 ,40 , 60 };
   vector<int>vc={30, 40 ,30 , 50 ,40 , 60 };

   // Coordinate Compression(reassigning or indexing)
   // read / sort / assign

    sort(vc.begin(),vc.end());
    vc.erase(unique(vc.begin(),vc.end()),vc.end());

   // for (int i = 0; i < vc.size(); ++i) cout << vc[i] << " " ;

  //  cout << endl ;
    for (int i = 0; i < arr[5]; ++i)
        arr[i] = lower_bound(vc.begin(),vc.end(),arr[i])-vc.begin();


  // this the main used logic (playing with the value and its new index ) 
    for (auto it : arr)
        cout << it << " " ;

    cout << endl ;

    for (auto it : arr) {
        cout << vc[it] << " " ;
    }
}
// u can play using the logic of the indices like if u want the value it self or if you need its mapped index 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
