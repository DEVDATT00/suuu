class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int write = 0;

        while (i < chars.size()) {
            char curr = chars[i];
            int j = i;

            while (j < chars.size() && chars[j] == curr) {
                j++;
            }

            int count = j - i;

            chars[write++] = curr;

            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[write++] = c;
                }
            }

            i = j;
        }

        return write;
    }
};