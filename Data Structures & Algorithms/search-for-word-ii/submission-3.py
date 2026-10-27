class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.children["."] = None

class TrieNode:
    def __init__(self):
        self.children = dict()

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        
        found = set()
        searched_word = []
        def dfs(row, col, trie_node):
            c = board[row][col]
            if c in trie_node.children:
                searched_word.append(c)
                next_node = trie_node.children[c]
                if "." in next_node.children:
                    found.add("".join(searched_word))
                board[row][col] = "#"

                d_row = [-1, 1, 0, 0]
                d_col = [0, 0, -1, 1]
                for d in range(4):
                    new_row = d_row[d] + row
                    new_col = d_col[d] + col
                    if new_row >= 0 and new_col >= 0 and new_row < height and new_col < width and board[new_row][new_col] != "#":
                        dfs(new_row, new_col, next_node)

                board[row][col] = c
                searched_word.pop()
        
        height = len(board)
        width = len(board[0])
        for row in range(height):
            for col in range(width):
                dfs(row, col, trie.root)
        
        return list(found)