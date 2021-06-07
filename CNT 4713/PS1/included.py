def Included(i,list):
	for position in range(len(list)):
		if list[position] == i:
			return(i)

Included(25,[10,25,5,13,64])