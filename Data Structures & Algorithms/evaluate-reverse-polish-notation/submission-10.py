class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num_stack = []
        for token in tokens:
            if token == "+":
                right = num_stack.pop()
                left = num_stack.pop()
                num_stack.append(left + right)
            elif token == "-":
                right = num_stack.pop()
                left = num_stack.pop()
                num_stack.append(left - right)
            elif token == "/":
                right = num_stack.pop()
                left = num_stack.pop()
                num_stack.append(int(left / right))
            elif token == "*":
                right = num_stack.pop()
                left = num_stack.pop()
                num_stack.append(left * right)
            else:
                num_stack.append(int(token))
        return num_stack[0]