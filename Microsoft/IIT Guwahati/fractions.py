class Solution:
   def solve(self, fractions):
   import math

   d = {}
   ans = 0
   for i in fractions:
      x = i[0]
      y = i[1]
      g = math.gcd(x, y)
      x /= g
      y /= g
      temp_x = y - x
      temp_y = y
      if (temp_x, temp_y) in d:
         ans += d[(temp_x, temp_y)]
         d[(x, y)] = d.get((x, y), 0) + 1
      return ans

ob = Solution()
fractions = [[2, 7],[3, 12],[4, 14],[5, 7],[3, 4],[1, 4]]
print(ob.solve(fractions))