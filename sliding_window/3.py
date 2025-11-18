class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        curr_chars = set()
        left = 0
        right = 0
        n = len(s)
        max_len = 0
        
        while (left < n and right < n):
            while (s[right] in curr_chars):
                curr_chars.remove(s[left])
                left += 1

            curr_chars.add(s[right])
            right += 1
            max_len = max(max_len, len(curr_chars))

        return max_len