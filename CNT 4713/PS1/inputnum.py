x = input("Type in a number.\n")
i = 0
for k in range(int(x)+1):
	if k%3 == 0 or k%5 == 0:
		i += k
print(i)
