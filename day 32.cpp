class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            // Case when array is already sorted
            if (arr[low] <= arr[high]) 
                return low;
            
            int mid = low + (high - low) / 2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;
            
            // Check if mid is minimum
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) 
                return mid;
            
            // Decide which side to go
            if (arr[mid] >= arr[low]) {
                // Left part is sorted, go right
                low = mid + 1;
            } else {
                // Right part is sorted, go left
                high = mid - 1;
            }
        }
        return 0;
    }
};
// prblm:https://www.geeksforgeeks.org/problems/rotation4723/1
