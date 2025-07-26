class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        int max_so_far = arr[n-1]; // The rightmost element
        result.push_back(max_so_far);

        // Traverse from right to left (n-2 to 0)
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] >= max_so_far) {
                result.push_back(arr[i]);
                max_so_far = arr[i];
            }
        }
        // As we traversed from right to left, reverse the result to get left to right order
        reverse(result.begin(), result.end());
        return result;
    }
};


// problem:https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1