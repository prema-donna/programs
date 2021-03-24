def matMult(matA, matB):
    if len(matA[0]) != len(matB): #check compatibility
        print("matrices are not compatible for matrix multiplication. Exiting now....")
        return

    res = [] #result matrix
    for i in range(len(matA)): #iterate over rows of matA
        res.append([0]*len(matB[0])) #append the number of columns of matB

    for i in range(len(matA)): #iterate by row of matA
        for j in range(len(matB[0])): #iterate by column of matB
            for k in range(len(matB)): #iterating by the rows of matB
                res[i][j] += matA[i][k] * matB[k][j]

    print(res)

if __name__ == "__main__":
    matA = [[12, 7, 3], [4, 5, 6], [7, 8, 9]]
    matB = [[5, 8, 1, 2], [6, 7, 3, 0], [4, 5, 9, 1]]
    matMult(matA, matB)
