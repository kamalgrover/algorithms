#include <bits/stdc++.h>
using namespace std;

void printA(vector<int>&a){
    const int N = a.size();
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int solve(vector<int>& values , vector<int>& weights, int capacity){
    //TODO
}
int main(){
    int N;
    cin >> N;
    vector<int> a (N,0);
    for (int i = 0 ; i < N ; i++){
        cin >> a[i];
    }   
    printA(a);
    return 0;
}
