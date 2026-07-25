class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int i , j;
        int tem = image.size();
        for(int k = 0 ; k < tem ; k++){
            reverse(image[k].begin(),image[k].end());
        }
        for(i = 0 ; i < tem ; i++){
            for(j = 0 ; j < tem ; j++){
                image[i][j] = (image[i][j] + 1) % 2;
            }
        }
        return image;
    }
};