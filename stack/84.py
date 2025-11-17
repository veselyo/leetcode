class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stk = []
        max_height = 0
        n = len(heights)
        for i in range(n):
            if not stk:
                stk.append((i, heights[i]))
            elif stk[-1][1] <= heights[i]:
                stk.append((i, heights[i]))
            else:
                max_extend_idx = 0
                while(stk and stk[-1][1] > heights[i]):
                    top = stk.pop()
                    max_height = max((i - top[0]) * top[1], max_height)
                    max_extend_idx = top[0]

                if not stk:
                    stk.append((max_extend_idx, heights[i]))
                elif stk[-1][1] < heights[i]:
                    stk.append((max_extend_idx, heights[i]))

        while stk:
            top = stk.pop()
            max_height = max((n - top[0]) * top[1], max_height)

        return max_height