class Solution {
    void maintask(vector<vector<int>>& image,int i , int j, int color, int tem){
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
            return ;
        if(image[i][j] != tem){
            return;
        }
        image[i][j] = color;
        maintask(image,i+1,j,color,tem);
        maintask(image,i-1,j,color,tem);
        maintask(image,i,j-1,color,tem);
        maintask(image,i,j+1,color,tem);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int tem = image[sr][sc];
        maintask(image,sr,sc,color,tem);
        return image;
    }
};