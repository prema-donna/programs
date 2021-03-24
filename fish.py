def fishAlive(A, B):
    survivals = 0
    stack = []

    for i in range(0,len(A)):
        if B[i] == 0:
            while len(stack) != 0:
                if stack[-1] > A[i]:
                    break
                else:
                    stack.pop()
            else:
                survivals += 1
        else:
            stack.append(A[i])

    survivals += len(stack)
    return survivals

A = [4, 3, 2, 1, 5]
B = [0, 1, 0, 0, 0]
print(fishAlive(A,B))
