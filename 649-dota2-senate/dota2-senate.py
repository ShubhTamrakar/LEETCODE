from collections import deque

class Solution(object):
    def predictPartyVictory(self, senate):
        r = deque()
        d = deque()

        for i, s in enumerate(senate):
            if s == 'R':
                r.append(i)
            else:
                d.append(i)

        while r and d:
            x = r.popleft()
            y = d.popleft()

            if x < y:
                r.append(x + len(senate))
            else:
                d.append(y + len(senate))

        return "Radiant" if r else "Dire"