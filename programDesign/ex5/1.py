
n,g,r = map(int, input().split())

l = list(map(int, input().split()))

q = int(input())
t = list(map(int, (input().split())))
for i in range(q):
	for j in range(n):
		t[i] += l[j]
		if (t[i]%(r+g) >= g):
			t[i]+=r+g - (t[i]%(r+g))
	t[i]+=l[n]
	print(t[i], end=' ')

print()

