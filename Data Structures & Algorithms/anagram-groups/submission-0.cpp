class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Input:
        - vector of strings, each with the same size as the others
        - Constraint: lowercase english characters

        Output:
        - vector of vectors of strings, where each sub vector is a "bucket" of anagrams

        Methodology:
        - sort every string, store the sorted string, original string in an unordered_map with the value being a vector bucket
        - after all words are processed, condense the values of the map into vector of vectors
        
        Methodology Two:
        - since there are only 26 lowercase english characters, maintain a frequency table
        - compare frequency tables of words against a hashmap
        - frequency tables can be initially processed as vectors, and then converted to strings for hashing in the map
        */

        unordered_map<string, vector<string>> buckets;
        for (int wordIndex = 0, n = strs.size(); wordIndex < n; ++wordIndex) {
            string sortedString = strs[wordIndex];
            sort(sortedString.begin(), sortedString.end());
            buckets[sortedString].emplace_back(strs[wordIndex]);
        }

        vector<vector<string>> anagramGroups;
        for (auto& kv : buckets) {
            anagramGroups.push_back(move(kv.second));
        }

        return anagramGroups;
    }
};
