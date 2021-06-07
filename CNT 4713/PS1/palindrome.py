def Palindrome(word):
	i = 1
	for x in word:
		if x == word[len(word) - i]:
			i+=1
		else:
			quit()
	return(True)
Palindrome("racecar")