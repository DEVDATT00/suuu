class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>pos;
        for(int x:nums){
            if(x>=0)
            pos.push_back(x);
        }
        int n=pos.size();
        if(n==0)
        return nums;
        k=k%n;
        rotate(pos.begin(),pos.begin()+k,pos.end());
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=pos[j];
                j++;
            }
        }
        return nums;
    }
};