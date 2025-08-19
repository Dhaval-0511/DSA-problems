#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) cin >> arr[i];

        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;

        // Sort array with custom comparator
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a < b;  // smaller element first when freq equal
            return freq[a] > freq[b]; // higher freq first
        });

        // Output sorted array
        for (int x : arr) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

// prblm:https://leetcode.com/problems/sort-characters-by-frequency