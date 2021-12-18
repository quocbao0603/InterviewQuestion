/*
Author: Bauz
Tags: interview, XOR problem
*/
#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE 32
vector<int> arr;
int FindUniqueNumber(int n, int m, vector<int>& arr){
    int ones = 0, twos = 0;

    int common_bit_mask;
    for (int i = 0; i < arr.size(); i++) {

        // "ones & arr[i]" gives the bits in both one & arr[i]
        twos = twos | (ones & arr[i]);

        // xor new bits with previous 'ones' with bit appearing odd time
        ones = ones ^ arr[i];

        // The common_bit_mask are those bits appear third time, it shouldn't be in "ones" and "twos"
        common_bit_mask = ~(ones & twos);

        // Remove common bits in ones & twos
        ones &= common_bit_mask;
        twos &= common_bit_mask;
    }

    return ones;
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
