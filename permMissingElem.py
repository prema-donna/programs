def missingVar(A):
	for i in range(1,len(A)+1):
		if i not in A:
			return i
	return -1

A = [2,3,1,5]
print("Missing element in {} is {}".format(A,missingVar(A)))
	