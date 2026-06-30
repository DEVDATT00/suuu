class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int maxof1 = 0 ;
        int maxof2 = 0 ;
        for(int i = 0 ; i < nums1.size() ; i++){
            maxof1 = max(maxof1 , nums1[i]);
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            maxof2 = max(maxof2 , nums2[i]);
        }
        vector<int>first(maxof1+1,0);
        vector<int>second(maxof2+1,0);
        for(int i = 0 ; i < nums1.size() ; i++){
            first[nums1[i]]++;
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            second[nums2[i]]++;
        }
        vector<int>count;
        for(int i = 0 ; i <= min(maxof1,maxof2) ; i++){
            if(first[i] > 0 && second[i] > 0){
                for(int j = 0 ; j < min(first[i],second[i]) ; j++){
                    count.push_back(i);
                }
            }
        }
        return count;
    }
};