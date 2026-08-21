class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        open = 0
        used = 0
        res = []
        def create(cur, open, used):
            if used == n:
                res.append(cur)
                return
            if open + used is n:
                cur += open * ')'
                res.append(cur)
                return
            create(cur+'(', open+1, used)
            if(open > 0):
                create(cur+')', open-1, used+1)
        create("", 0, 0)
        return res


        