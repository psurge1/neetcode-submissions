class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        characterLocations = dict()
        longestLength = 0

        l = 0
        r = 0
        n = len(s)
        while r < n:
            if s[r] in characterLocations:
                # save the current length if it is the longest
                # update the index of the repeated character
                # remove every character of s between l and 1 + idx of repeated character from the index tracking hashmap
                longestLength = max(longestLength, r - l)
                oldIdx = characterLocations[s[r]]
                while l <= oldIdx:
                    characterLocations.pop(s[l])
                    l += 1
            characterLocations[s[r]] = r
            r += 1
        
        # must also save the length of the ending positions of r and l for the tail string
        longestLength = max(longestLength, r - l)
        
        return longestLength