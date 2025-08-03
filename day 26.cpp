class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == k)
                return mid;
            else if (arr[mid] < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

// prblm:https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1