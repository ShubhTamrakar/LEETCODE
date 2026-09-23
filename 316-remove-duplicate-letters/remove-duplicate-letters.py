class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        count = {}

        # Count how many times each character occurs
        for ch in s:
            count[ch] = count.get(ch, 0) + 1

        stack = []
        seen = set()

        for ch in s:

            count[ch] -= 1

            # Already used
            if ch in seen:
                continue

            # Remove bigger characters if they occur again later
            while stack and ch < stack[-1] and count[stack[-1]] > 0:
                removed = stack.pop()
                seen.remove(removed)

            stack.append(ch)
            seen.add(ch)

        return ''.join(stack)