# 学习一门新语言是很痛苦的事情 :(

l = [31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31]

n = int(input())
a = list(map(int, input().strip().split()))

ans = False
for i in range(12):
	feb = 0
	for j in range(n):
		if (l[(i+j)%12] == 28):
			if (a[j]!=28 and a[j]!=29):
				feb=-1
				break
			elif a[j]==29:
				feb+=1
		elif (a[j] != l[(i+j)%12]):
			feb = -1
			break
	if (feb!=-1 and feb<2):
		ans = True
		break

if ans:
	print("Yes")
else:
	print("No")
