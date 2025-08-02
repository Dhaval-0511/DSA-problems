class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1; // Look right
            } else {
                right = mid;    // Keep mid as a candidate
            }
        }
        // left is the smallest index where arr[left] >= target, or arr.size() if no such value
        return left;
    }
};


class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;  // arr[mid] is too small or equal; move right
            } else {
                right = mid;     // arr[mid] > target; keep as candidate
            }
        }
        // left is the index of the first element > target, or arr.size() if no such value
        return left;
    }
};


// prblm:https://www.geeksforgeeks.org/problems/implement-upper-bound/1,,https://www.geeksforgeeks.org/problems/implement-lower-bound/1