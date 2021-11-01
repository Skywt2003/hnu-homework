n, L, a = map(int, input().strip().split())

ans = now = 0
for case in range(n):
	t, l = map(int, input().strip().split())
	ans += (t-now)//a
	now=t+l;

ans += (L-now)//a;
print(ans)
