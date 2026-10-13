class TrieNode:
    def __init__(self):
        self.children = dict()

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        self.terminal = "#"

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.children[self.terminal] = None

    def search(self, word: str) -> bool:
        def dfs(node, word, idx):
            if idx == len(word):
                return self.terminal in node.children
            if word[idx] == ".":
                for child in node.children:
                    if child != self.terminal and dfs(node.children[child], word, idx + 1):
                        return True
            if word[idx] in node.children:
                return dfs(node.children[word[idx]], word, idx + 1)
            return False
        
        return dfs(self.root, word, 0)