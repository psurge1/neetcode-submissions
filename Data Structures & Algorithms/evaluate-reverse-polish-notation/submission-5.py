class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
            "/": lambda x, y: x / y
        }
        for char in tokens:
            if char in operations:
                vTwo = stack.pop()
                vOne = stack.pop()
                stack.append(int(operations[char](vOne, vTwo)))
            else:
                stack.append(int(char))
        
        return stack[0]