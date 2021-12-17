/*
Author: Bauz
Tags: interview, XOR problem
*/
#include<bits/stdc++.h>
using namespace std;

map<int, int> dict;
vector<int> arr;
int FindDiffNumber(int n, int m, vector<int>& arr){
    dict.clear();
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
    for (int test = 3; test < 40; test++){
        stringstream ss;
        ss << test;
        string name = ss.str();
//        string name = "3";
        string nameIn = name + ".in";
        string nameOut = name + ".ans";
        freopen(nameIn.c_str(), "r", stdin);
        freopen(nameOut.c_str(), "w", stdout);
    //    int n = 3;
    //    int m = 3;
    //    vector<int> arr = {1, 2, 5, 5, 3, 3, 5, 7, 3, 2};
        int n, m;
        cin >> n >> m;
        arr.resize(n * m + 1);
        for (int i = 0; i < n * m + 1; i++)cin >> arr[i];
        cout << FindDiffNumber(n, m, arr);
    }
}
