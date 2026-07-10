class Solution {
public:
    string defangIPaddr(string address) {
        string navi;
        for(int i = 0 ; i < address.length() ; i++){
            if(address[i] == '.'){
                navi.append("[.]");
            }else{
                navi.push_back(address[i]);
            }
        }
        return navi;
    }
};