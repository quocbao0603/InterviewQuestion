/*
Author: Bauz
Tags: interview, XOR problem
*/
#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE 32

int FindUniqueNumber(int n, int m, vector<int>& arr){
    int result = 0;
    int x, sum;

    for (int i = 0; i < INT_SIZE; i++){
        sum = 0;
        x = (1 << i);
        for (int j = 0; j < arr.size(); j++){
            if (arr[j] & x) sum++;
        }
        if (sum % m != 0){
            result |= x;
        }
    }
    return result;
}

int main(){
//    int n = 3;
//    int m = 3;
//    vector<int> arr = {2, 2, 5, 5, 3, 3, 5, 7, 3, 2};
    int n, m;
    cin >> n >> m;
    arr.resize(n * m + 1);
    for (int i = 0; i < n * m + 1; i++)cin >> arr[i];
    cout << FindUniqueNumber(n, m, arr);
}
