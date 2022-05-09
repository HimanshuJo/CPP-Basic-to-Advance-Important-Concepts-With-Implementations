def solve_13(N1, N3):
  """長さ 1, 3 の棒しか存在しない場合"""
  ANS = 0
  # (1, 1, 3)
  k = min(N1//2, N3)
  N1 -= 2 * k
  N3 -= k
  ANS += k
  # (1, 1, 1, 1, 1)
  ANS += N1 // 5
  return ANS

def solve_12(N1, N2):
  """長さ 1, 2 の棒しか存在しない場合"""
  ANS = 0
  # (1, 2, 2)
  k = min(N1, N2//2)
  N1 -= k
  N2 -= 2 * k
  ANS += k
  # (1, 1, 1, 2)
  if N1 >= 3 and N2 >= 1:
    N1 -= 3
    N2 -= 1
    ANS += 1
  # (1, 1, 1, 1, 1)
  ANS += N1 // 5
  return ANS

def solve(N2, N3, N4):
  N1, N2, N3 = N2, N4, N3//2
  ANS = 0
  
  k = min(N2, N3)
  N2 -= k
  N3 -= k
  ANS += k
  
  if N2 == 0:
    ANS += solve_13(N1, N3)
  else:
    ANS += solve_12(N1, N2)
  
  return ANS

T = int(input())
for _ in range(T):
  N2, N3, N4 = map(int, input().split())
  print(solve(N2, N3, N4))