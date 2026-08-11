class Solution {
    int binaraysearch(vector<int>& arr, int start, int end, int value) {
        if (value < arr[0])
            return -1;
        if (value > arr[end])
            return end + 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == value)
                return mid;
            else if (arr[mid] < value)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i = binaraysearch(arr, 0, n - 1, x);
        vector<int> ans;
        if (i == -1) {
            for (int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        } else if (i == n) {
            for (int i = n - k; i < n; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }
        int left = i - 1;
        int right = i;

        while (k > 0) {
            if (left < 0) {
                right++;
            } else if (right >= n) {
                left--;
            } else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            } else {
                right++;
            }

            k--;
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};