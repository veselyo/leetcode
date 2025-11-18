class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        left = 0
        right = rows - 1

        while (left <= right):
            middle = left + ((right - left) // 2)
            curr = matrix[middle][0]
            if curr == target:
                return True
            elif curr < target:
                left = middle + 1
            else:
                right = middle - 1

        row = right

        if row < 0:
            return False

        left = 0
        right = cols - 1

        while (left <= right):
            middle = left + ((right - left) // 2)
            curr = matrix[row][middle]

            if curr == target:
                return True
            elif curr < target:
                left = middle + 1
            else:
                right = middle - 1

        return False