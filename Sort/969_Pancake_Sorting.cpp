// Given an array of integers arr, sort the array by performing a series of pancake flips.

// In one pancake flip we do the following steps:

// Choose an integer k where 1 <= k <= arr.length.
// Reverse the sub-array arr[1...k].
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

// Return the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.

 

// Example 1:

// Input: arr = [3,2,4,1]
// Output: [4,2,4,3]
// Explanation: 
// We perform 4 pancake flips, with k values 4, 2, 4, and 3.
// Starting state: arr = [3, 2, 4, 1]
// After 1st flip (k = 4): arr = [1, 4, 2, 3]
// After 2nd flip (k = 2): arr = [4, 1, 2, 3]
// After 3rd flip (k = 4): arr = [3, 2, 1, 4]
// After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
// Notice that we return an array of the chosen k values of the pancake flips.
// Example 2:

// Input: arr = [1,2,3]
// Output: []
// Explanation: The input is already sorted, so there is no need to flip anything.
// Note that other answers, such as [3, 3], would also be accepted.

//參考 https://mp.weixin.qq.com/s/ljya6zohmdt2TXtzmhBncQ
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        sort(arr,arr.size());
        return res;
    }
    
    void sort(vector<int>& arr, int n){
        if(n==1) return;
        int max_val = 0, max_ind = 0;
        for(int i=0; i<n; i++){
            if(arr[i]>max_val){
                max_val = arr[i];
                max_ind = i;
            }            
        }
        reverse(arr,0,max_ind);
        res.push_back(max_ind+1);
        
        reverse(arr,0,n-1);
        res.push_back(n);
        
        sort(arr,n-1);
    }
    
    void reverse(vector<int>& arr, int i, int j){
        int start = i, end = j;
        while(start<end){
            swap(arr[start],arr[end]);
            start++; end--;
        }    
    }
    
private:
    vector<int> res;
};