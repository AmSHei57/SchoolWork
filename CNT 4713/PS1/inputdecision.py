x = input("Type in a number.\n")
y = input("Compute the sum or the product of 1 to the number you typed in? Type Sum for sum and Product for product.\n")

i = 0
j = 1
for k in range(1,int(x)+1):
	if y == "Sum":
		i += k
	elif y == "Product":
		j = j * k

if y == "Sum":
	print(i)
elif y == "Product":
	print(j)

