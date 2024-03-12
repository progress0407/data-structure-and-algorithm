n = int(input())

asc_mp = {chr(n): 0 for n in range(ord('a'), ord('z') + 1) }

li=[]
for i in range(n):
    li.append(input())

for w in li:
    ch = w[0]
    asc_mp[ch] += 1

li2=[]
for k,v in asc_mp.items():
    if v >= 5:
      li2.append(k)

ans = ''.join(sorted(li2))

if len(ans) >= 1:
    print(ans)
else:
    print('PREDAJA')
