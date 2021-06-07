MaxNum = 200
nthprime = 0
for num in range(2,MaxNum):
	if num > 1:
		for i in range(2,num):
			if (num % i) == 0:
				break
		else:
			if nthprime != 30:
				print(num)
				nthprime+=1
			else:
				quit()
	