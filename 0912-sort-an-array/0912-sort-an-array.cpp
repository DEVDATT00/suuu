// this is best algo for sorting which is heap sort O(nlogn)time and space is
// O(1)
class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};
// // merge sort done other sort is after this
// class Solution {
//     void mergemain(vector<int>&nums, int begin , int mid , int end){
//         vector<int>tem;
//         int i = begin;
//         int j = mid + 1;
//         while( i <= mid && j <= end){
//             if(nums[i] <= nums[j]){
//                 tem.push_back(nums[i++]);
//             }
//             else{
//                 tem.push_back(nums[j++]);
//             }
//         }
//         // remaing elements are pushed into tem
//         while(i <= mid){
//             tem.push_back(nums[i++]);
//         }
//         while(j <= end){
//             tem.push_back(nums[j++]);
//         }
//         for(int k = begin ; k <= end ; k++){
//             nums[k] = tem[k - begin];
//         }
//     }
//     void merge(vector<int>&nums,int begin , int end){
//         if(begin >= end)
//             return;

//         // finding middle part from where can partition into two part
//         int mid = begin + ( end - begin ) / 2;

//         // now part left side
//         merge(nums,begin,mid);

//         // now part right side
//         merge(nums,mid+1,end);

//         // i do two part now time to merge both
//         mergemain(nums,begin,mid,end);
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         merge(nums,0,nums.size()-1);
//         return nums;
//     }
// };

// // this solve using quick sort worst case O(n^2)
// class Solution {
//     int getpivot(vector<int> &nums, int start , int end){
//         int p = nums[end];
//         int j = start - 1;
//         for(int i = start ; i < end ; i++){
//             if(nums[i] < p){
//                 j++;
//                 swap(nums[i],nums[j]);
//             }
//         }
//         swap(nums[j+1],nums[end]);
//         return j + 1;
//     }
//     void quicksort(vector<int> & nums , int start , int end){
//         if(start >= end)
//             return;
//         int pivot = getpivot(nums,start,end);
//         quicksort(nums,start,pivot-1);
//         quicksort(nums,pivot+1,end);
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         quicksort(nums,0,nums.size()-1);
//         return nums;
//     }
// };