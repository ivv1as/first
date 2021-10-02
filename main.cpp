#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

struct team{
    string name;
    long long z;
    long long f;
};

bool operator<(team lh, team rh){
    if(lh.z==rh.z){
        if(lh.f==rh.f){
            return lh.name<rh.name;
        }
        return lh.f<rh.f;
    }
    return lh.z>rh.z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<team> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].name >> a[i].z >> a[i].f;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        cout << a[i].name << '\n';
    }
}
