class Solution:

    def encode(self, strs: List[str]) -> str:
        encoding = ""
        for s in strs:
            encoding += f"{len(s)}#{s}"
        return encoding

    def decode(self, s: str) -> List[str]:
        strs = []
        ptr = 0
        while ptr < len(s):
            strlen = ""
            while s[ptr] != '#':
                strlen += s[ptr]
                ptr += 1
            strlen = int(strlen)
            tempStr = ""
            for idx in range(ptr + 1, ptr + strlen + 1):
                tempStr += s[idx]
            strs.append(tempStr)
            ptr += strlen + 1
        return strs
