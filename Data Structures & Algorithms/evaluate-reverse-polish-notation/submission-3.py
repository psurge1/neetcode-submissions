class Solution:
    def add(self, a, b):
        return a + b
    def sub(self, a, b):
        return a - b
    def mul(self, a, b):
        return a * b
    def div(self, a, b):
        return a / b
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = {
            "+": self.add,
            "-": self.sub,
            "*": self.mul,
            "/": self.div
        }
        for char in tokens:
            if char in operations:
                vTwo = stack.pop()
                vOne = stack.pop()
                stack.append(int(operations[char](vOne, vTwo)))
            else:
                stack.append(int(char))
            print(stack)
        
        return stack[0]