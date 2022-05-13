for _ in range(int(input())):
  n = int(input())
  k = list(map(int, input().split()))
  h = list(map(int, input().split()))
  st = []
  for i in range(n):
    st.append([k[i] - h[i], k[i]])
  st.sort()
  l, r = -1, -1
  ans = 0
  for it in st:
    if it[0] >= r:
      ans += (r - l) * (r - l + 1) // 2
      l, r = it
    else:
      r = max(r, it[1])
  ans += (r - l) * (r - l + 1) // 2
  print(ans)