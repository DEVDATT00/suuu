class Solution {
public:
    int maxProduct(int n) {
        vector<int>numbers;
        while(n > 0){
            numbers.push_back(n % 10);
            n = n / 10;
        }
        int tem = numbers.size() - 1;
        sort(numbers.begin(),numbers.end());
        return numbers[tem]*numbers[tem - 1];
    }
};