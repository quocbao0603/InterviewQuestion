/*
Author: Bauz
Tags: interview, XOR problem
*/
#include<bits/stdc++.h>
using namespace std;

map<int, int> dict;
vector<int> arr;
int FindDiffNumber(int n, int m, vector<int>& arr){
    for (int number: arr){
        if (dict.find(number) != dict.end()){
            dict[number]++;
        }
        else dict[number] = 1;
    }
    for (int number: arr){
        if (!(dict[number] == 1 || dict[number] == m)){
            cout << "Something wrong with input!\n";
            assert(false);
        }
    }
    for (int number: arr){
        if (dict[number] == 1){
            return number;
        }
    }
    //for behavior
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (m == 1){
        cout << "M must not be 1!\n";
        assert(false);
    }
    arr.resize(n * m + 1);
    for (int i = 0; i < n * m + 1; i++)cin >> arr[i];
    cout << FindDiffNumber(n, m, arr);
}
