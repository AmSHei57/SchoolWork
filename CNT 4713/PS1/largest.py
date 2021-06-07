def Largest(list):
	i = 0
	for position in range(len(list)):
		if list[position] > i:
			i = list[position]
	return(i)

Largest([489,15412,4968516541,12,2139865198,265])