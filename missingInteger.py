def missingInt(A):
    for i in range(1,len(A)):
        if i not in A:
            return i
    return 1

A = [1,3,6,4,1,2]
print("The smallest missing int in {} is {}".format(A,missingInt(A)))
A = [-1,-3]
print("The smallest missing int in {} is {}".format(A,missingInt(A)))