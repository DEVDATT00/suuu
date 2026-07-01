// this is solve with recursion and also solve with loop
// class Solution {
// public:
//     int search2(vector<int>& nums, int target, int s, int e) {
//         if (s > e) {
//             return -1;  
//         }

//         int mid = s + (e - s) / 2;

//         if (nums[mid] == target) {
//             return mid;
//         } 
//         else if (nums[mid] > target) {
//             return search2(nums, target, s, mid - 1);
//         } 
//         else {
//             return search2(nums, target, mid + 1, e);
//         }
//     }

//     int search(vector<int>& nums, int target) {
//         return search2(nums, target, 0, nums.size() - 1);
//     }
// };



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0 ;
        int e = (nums.size())-1;
        int mid ;
        while(s <= e){
            mid = s + (e - s) / 2;
            if(target == nums[mid]){
                return mid;
            }
            if(target < nums[mid]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return -1;
    }
};