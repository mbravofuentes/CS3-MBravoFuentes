//Mario Bravo CSI 3
//Falling Apart Kattis
//9/6/2019

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

//sorting array

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.rbegin(), v.rend());

    int a = 0;
    int b = 0;

    for(int i = 0; i < v.size(); i++) {
        if(i % 2 == 0) {
            a += v[i];
        }
        else {
            b += v[i];
        }
    }

    cout << a << " " << b << endl;
}
