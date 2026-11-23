class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string dev;
        vector<string> tem;
        bool check = false;
    //    false means to say that there are not into arrary
        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = 0 ; j < arr.size()  ; j++){
                if(j != i){
                    if(arr[i] == arr[j]){
                        check = true;
                    // true means to say that string is repeat in array
                        break;
                    }
                }
            }
            if(check == false){
                tem.push_back(arr[i]);
            }
            check = false;
        }
        if(tem.size() >= k){
            return tem[k - 1];
        }
        return dev;
    }
};