class Solution {
public:
    string sortVowels(string s) {
        map<char, int> freq;
        map<char, int> first;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u') {

                freq[s[i]]++;

                if(first.find(s[i]) == first.end()) {
                    first[s[i]] = i;
                }

                s[i] = '-';
            }
        }

        vector<char> vowels;


        for(auto p : freq) {
            vowels.push_back(p.first);
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {

            if(freq[a] != freq[b])
                return freq[a] > freq[b];

            return first[a] < first[b];
        });

        int k = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '-') {

                while(freq[vowels[k]] == 0) {
                    k++;
                }

                s[i] = vowels[k];
                freq[vowels[k]]--;
            }
        }

        return s;
    }
};