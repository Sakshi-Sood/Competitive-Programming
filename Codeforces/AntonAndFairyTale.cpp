#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long n, long long m) {
    long long k = mid-m;
    return k*(k+1)/2 >= n-m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    if(m >= n){
        cout << n << endl;
        return 0;
    }

    long long l = m+1, h = m+2e9;

    while(l <= h) {
        long long mid = l + (h-l)/2;
        if(check(mid, n, m))
            h = mid-1;
        else    
            l = mid+1;
    }
    cout << l << endl;
}