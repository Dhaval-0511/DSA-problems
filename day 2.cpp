class Solution {
  public:
    
        // code here
        int getSecondLargest(vector<int> &arr){
        int largest = -1,secondLargest = -1;
        
        for(int num : arr){
            if(num > largest){
                secondLargest = largest;
                largest = num;
            }else if(num>secondLargest && num < largest ){
                secondLargest = num;
            }
        }
        return secondLargest ;
    }
};

prblm: https://www.geeksforgeeks.org/problems/second-largest3735/1