n = int(input())

if ((n%3!=0) and (n%5!=0) and (n%7!=0)):
	print('null')
else:
	print("It's divisible by ",end="")
	lst = 0
	for i in [3,5,7]:
		if (n%i == 0):
			if (lst):
				print(',',end="")
			print(i,end="")
			lst = 1
	print()

