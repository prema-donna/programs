#include <stdio.h>

int main()
{
    float a[10][10], b[10][10], result[10][10];
	int r1, c1, r2, c2;

    printf("Enter rows and column for first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and column for second matrix: ");
    scanf("%d %d",&r2, &c2);

    // Column of first matrix should be equal to column of second matrix and
    while (c1 != r2)
    {
        printf("Error! column of first matrix not equal to row of second.\n\n");
        printf("Enter rows and column for first matrix: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter rows and column for second matrix: ");
        scanf("%d %d",&r2, &c2);
    }

    // Storing elements of first matrix.
    printf("\nEnter elements of matrix 1:\n");
    for(int i=0; i<r1; ++i){
        for(int j=0; j<c1; ++j)
        {
            printf("Enter elements a%d%d: ",i+1, j+1);
            scanf("%f", &a[i][j]);
        }
	}

    // Storing elements of second matrix.
    printf("\nEnter elements of matrix 2:\n");
    for(int i=0; i<r2; ++i){
        for(int j=0; j<c2; ++j)
        {
            printf("Enter elements b%d%d: ",i+1, j+1);
            scanf("%f",&b[i][j]);
        }
	}

    // Initializing all elements of result matrix to 0
    for(int i=0; i<r1; ++i){
        for(int j=0; j<c2; ++j)
        {
            result[i][j] = 0;
        }
	}

    // Multiplying matrices a and b and
    // storing result in result matrix
    for(int i=0; i<r1; ++i){
        for(int j=0; j<c2; ++j){
            for(int k=0; k<c1; ++k)
            {
                result[i][j]+=a[i][k]*b[k][j];
            }
		}
	}
	
	// Displaying the first input matrix
    printf("\nInput Matrix A:\n");
    for(int i=0; i<r1; ++i){
        for(int j=0; j<c1; ++j)
        {
            printf("%f  ", a[i][j]);
            if(j == c1-1)
                printf("\n\n");
        }
	}
	
	// Displaying the second input matrix
    printf("\nInput Matrix B:\n");
    for(int i=0; i<r2; ++i){
        for(int j=0; j<c2; ++j)
        {
            printf("%f  ", b[i][j]);
            if(j == c2-1)
                printf("\n\n");
        }
	}
	
	// Displaying the result
    printf("\nOutput Matrix (C=A*B):\n");
    for(int i=0; i<r1; ++i){
        for(int j=0; j<c2; ++j)
        {
            printf("%f  ", result[i][j]);
            if(j == c2-1)
                printf("\n\n");
        }
	}
	
    return 0;
}