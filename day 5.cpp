class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k= k %n; //case where k>n

        auto reverse=[](vector<int>& arr,int start,int end){
            while(start<end){
                swap(arr[start],arr[end]);
                start++;
                end--;
            }
        };
        reverse(nums,0,n-1); // 1. reverse entire array
        reverse(nums,0,k-1); // 2. reverse first k ele
        reverse(nums,k,n-1); // 3. reverse remaining n-k element;
    }
};

//prblm : https://leetcode.com/problems/rotate-array