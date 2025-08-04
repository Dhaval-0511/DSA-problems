class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int lo = 0, hi = arr.size() - 1;
        int ans = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= x) {
                ans = mid;  // current number can be answer, but let's look further right
                lo = mid + 1;
            } else {
                hi = mid - 1;  // need a smaller number
            }
        }
        return ans;
    }
};


class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int lo = 0, hi = arr.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (arr[mid] >= x) {
                ans = mid;     // possible answer, but search for earlier occurrence
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

// prblm:https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1, https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1