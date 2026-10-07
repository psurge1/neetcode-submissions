class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        """
        track the last occurence of every character
        iterate through the string and greedily add characters to the current window
        for the current window, track the max last occurence among the characters in the current window
        once we reach an index such that it is equal to the max last occurence, we can safely store that window size in our result as that is the smallest substring size completely encapsulating all characters within it
        repeat the steps above until we reach the end of the string
        """
        last_occurence = [0] * 26
        n = len(s)
        for i in range(n):
            last_occurence[ord(s[i]) - ord("a")] = i
        
        result = []
        window_size = 0
        end = 0
        for i in range(n):
            window_size += 1
            end = max(end, last_occurence[ord(s[i]) - ord("a")])
            if i == end:
                result.append(window_size)
                window_size = 0
        return result