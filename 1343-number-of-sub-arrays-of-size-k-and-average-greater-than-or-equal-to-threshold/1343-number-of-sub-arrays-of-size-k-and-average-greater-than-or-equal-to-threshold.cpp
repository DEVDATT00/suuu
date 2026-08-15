class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        for(int i = 0;i<k;++i){
            sum += arr[i];
        }
        int count = 0;
        if(sum/k >= threshold){
            count++;
        }
      
        for(int j = k;j < arr.size();++j){
            sum = sum - arr[j-k] + arr[j];
            if(sum/k >= threshold){
                count++;
            }
        }
        return count;
    }
};