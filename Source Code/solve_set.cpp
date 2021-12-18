/*
Author: Bauz
Tags: interview, XOR problem
*/
#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE 32
vector<int> arr;
int FindUniqueNumber(int n, int m, vector<int>& arr){
    unordered_set<int> s(arr.begin(), arr.end());
    long long arr_sum = 0;
    for (int element: arr){
        arr_sum += element;
    }
    long long set_sum = 0;
    unordered_set<int> :: iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
        set_sum += *itr;
    return (1ll * m * set_sum - arr_sum) / (m - 1);
}

int main(){
//    freopen("30.in", "r", stdin);
//    freopen("30.out", "w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int n = 3;
//    int m = 3;
//    vector<int> arr = {2, 2, 5, 5, 3, 3, 5, 7, 3, 2};
    int n, m;
    cin >> n >> m;
    arr.resize(n * m + 1);
    for (int i = 0; i < n * m + 1; i++)cin >> arr[i];
    cout << FindUniqueNumber(n, m, arr);
}
