// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int size = flowerbed.size();
//         if(size == 1 && n == 1 && flowerbed[0] == 0)
//             return true;
//         if(size == 2 && n == 1 && flowerbed[0] == 0 && flowerbed[1] == 0)
//             return true;
//         if(size >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0){
//             flowerbed[0] = 1;
//             n--;
//         }
//         if(size >= 2 && flowerbed[size-1] && flowerbed[size-2] == 0){
//             flowerbed[size-1] = 1;
//             n--;
//         }
//         int count = 0;
//         for(int i = 0 ; i < size ; i++){
//             if(!flowerbed[i])
//                 count++;
//             else{ 
//                 if(count > 2 && count % 2 == 1){
//                     n -= (count / 2) - 1;
//                 }
//             }
//         }
//         if(n > 0)
//             return false;
//         return true;
//     }
// };


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for(int i = 0; i < size; i++) {
            if(flowerbed[i] == 0 &&
               (i == 0 || flowerbed[i-1] == 0) &&
               (i == size-1 || flowerbed[i+1] == 0)) {
                
                flowerbed[i] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};