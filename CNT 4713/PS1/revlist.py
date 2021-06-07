def RevList(list):
	listlength = len(list) - 1
	revlist = [0] * len(list)
	for position in range(len(list)):
		revlist[listlength] = list[position]
		listlength = listlength - 1
	return(revlist)

RevList([1,2,3,4,5])