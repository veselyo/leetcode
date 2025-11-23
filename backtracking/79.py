class Solution:
    match = False

    def backtrack(self, board, curr_word, word, pos_set, last_row, last_col):
        curr_len = len(curr_word)
        if curr_len == len(word):
            if curr_word == word:
                self.match = True
            return
        
        if last_row - 1 >= 0 and (last_row - 1, last_col) not in pos_set and word[curr_len] == board[last_row - 1][last_col]:
            new_set = pos_set.copy()
            new_set.add((last_row - 1, last_col))
            self.backtrack(board, curr_word + board[last_row - 1][last_col], word, new_set, last_row - 1, last_col)
    
        if last_row + 1 < len(board) and (last_row + 1, last_col) not in pos_set and word[curr_len] == board[last_row + 1][last_col]:
            new_set = pos_set.copy()
            new_set.add((last_row + 1, last_col))
            self.backtrack(board, curr_word + board[last_row + 1][last_col], word, new_set, last_row + 1, last_col)

        if last_col + 1 < len(board[0]) and (last_row, last_col + 1) not in pos_set and word[curr_len] == board[last_row][last_col + 1]:
            new_set = pos_set.copy()
            new_set.add((last_row, last_col + 1))
            self.backtrack(board, curr_word + board[last_row][last_col + 1], word, new_set, last_row, last_col + 1)

        if last_col - 1 >= 0 and (last_row, last_col - 1) not in pos_set and word[curr_len] == board[last_row][last_col - 1]:
            new_set = pos_set.copy()
            new_set.add((last_row, last_col - 1))
            self.backtrack(board, curr_word + board[last_row][last_col - 1], word, new_set, last_row, last_col - 1)

    def exist(self, board: List[List[str]], word: str) -> bool:
        self.match = False

        for row in range(len(board)):
            for col in range(len(board[row])):
                if board[row][col] == word[0]:
                    curr_set = set()
                    curr_set.add((row, col))
                    self.backtrack(board, board[row][col], word, curr_set, row, col)

        return self.match