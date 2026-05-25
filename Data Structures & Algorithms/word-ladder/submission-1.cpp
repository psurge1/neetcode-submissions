class Solution {
private:
    bool isTransformable(const string& one, const string& two) {
        int numDifferences = 0;
        for (int i = 0; i < one.size(); ++i) {
            if (one[i] != two[i]) {
                ++numDifferences;
            }
        }
        return numDifferences == 1;
    }

    int findLengthOfShortestPath(const string& begin, const string& end, const unordered_map<string, vector<string>>& graph) {
        queue<string> nodes;
        nodes.push(begin);
        unordered_set<string> visited;
        visited.insert(begin);
        int pathLength = 0;
        while (!nodes.empty()) {
            ++pathLength;
            for (int i = 0, n = nodes.size(); i < n; ++i) {
                string node = nodes.front();
                nodes.pop();
                if (node == end) {
                    return pathLength;
                }
                if (graph.find(node) != graph.end()) {
                    for (const string& neighbor : graph.at(node)) {
                        if (!visited.contains(neighbor)) {
                            visited.insert(neighbor);
                            nodes.push(neighbor);
                        }
                    }
                }
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
        Details:
            words can be transformed if only one character needs to be changed

        Inputs:
            begin word
            end word
            all words in wordlist are the same length
        
        Output:
            length of shortest path to transform begin word to end word

        Approach:
            create a graph where each edge denotes that a word is "transformable"

        */

        unordered_map<string, vector<string>> transformable;
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isTransformable(wordList[i], wordList[j])) {
                    transformable[wordList[i]].push_back(wordList[j]);
                    transformable[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if (transformable.find(beginWord) == transformable.end()) {
            for (int i = 0; i < wordList.size(); ++i) {
                if (isTransformable(wordList[i], beginWord)) {
                    transformable[wordList[i]].push_back(beginWord);
                    transformable[beginWord].push_back(wordList[i]);
                }
            }
        }

        return findLengthOfShortestPath(beginWord, endWord, transformable);
    }
};
