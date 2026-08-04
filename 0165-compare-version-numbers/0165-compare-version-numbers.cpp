class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> first;
        vector<int> second;
        int i = 0;
        int tem = 0;
        while (i < version1.length()) {
            if (version1[i] == '.') {
                first.push_back(tem);
                i++;
                tem = 0;
                continue;
            }
            tem = tem * 10 + (version1[i] - '0');
            i++;
        }
        first.push_back(tem);
        tem = 0;
        i = 0;
        while (i < version2.length()) {
            if (version2[i] == '.') {
                second.push_back(tem);
                i++;
                tem = 0;
                continue;
            }
            tem = tem * 10 + (version2[i] - '0');
            i++;
        }
        second.push_back(tem);
        i = 0;
        while (i < first.size() && i < second.size()) {
            if (first[i] < second[i])
                return -1;
            if (first[i] > second[i])
                return 1;
            i++;
        }

        while (i < first.size()) {
            if (first[i] > 0)
                return 1;
            i++;
        }

        while (i < second.size()) {
            if (second[i] > 0)
                return -1;
            i++;
        }

        return 0;
    }
};