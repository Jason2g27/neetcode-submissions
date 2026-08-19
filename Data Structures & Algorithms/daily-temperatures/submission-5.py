class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        i = 0;
        n = len(temperatures)
        res = [0] * n
        while i < len(temperatures):
            while len(stack) != 0 and temperatures[i] > stack[-1][0]:
                temp, index = stack[-1]
                stack.pop()
                res[index] = i - index
            stack.append((temperatures[i], i))
            i+=1
        return res

