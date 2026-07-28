#include <stdio.h>
#define MAX 100

void read(int rows, int cols, int matrix[MAX][MAX]);
void convert(int rows, int cols, int matrix[MAX][MAX], int compact[MAX][3]);
void display(int compact[MAX][3]);
void simple(int compact[MAX][3], int trans[MAX][3]);
void fast(int compact[MAX][3], int trans[MAX][3]);

int main() 
{
    int matrix[MAX][MAX];
    int compact[MAX][3];
    int trans[MAX][3];
    int rows, cols;
    int choice;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    read(rows, cols, matrix);

    convert(rows, cols, matrix, compact);
    printf("\nCompact Form: ");
    display(compact);

    printf("\nChoose Transpose Method:\n");
    printf("1. Simple Transpose\n");
    printf("2. Fast Transpose\n");

    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:	simple(compact, trans);
            	printf("\nResult: ");
            	display(trans);
            	break;

        case 2: fast(compact, trans);
            	printf("\nResult: ");
            	display(trans);
            	break;

        default: printf("\nInvalid choice!\n");
            	 break;
    }

    return 0;
}

void read(int rows, int cols, int matrix[MAX][MAX]) 
{
    printf("Enter matrix elements: \n");
    for (int i=0; i<rows; i++) 
    {
        for (int j=0; j<cols; j++) 
	{
            scanf("%d", &matrix[i][j]);
        }
    }
}

void convert(int rows, int cols, int matrix[MAX][MAX], int compact[MAX][3]) 
{
    int k = 1;
    for (int i=0; i<rows; i++) 
    {
        for (int j=0; j<cols; j++) 
	{
            if (matrix[i][j]!=0) 
	    {
                compact[k][0] = i;            
                compact[k][1] = j;            
                compact[k][2] = matrix[i][j]; 
                k++;
            }
        }
    }
    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = k - 1;
}

void display(int compact[MAX][3]) 
{
    printf("\nRow\tCol\tValue\n");
    for (int i=0; i<=compact[0][2]; i++) 
    {
        printf("%d\t%d\t%d\n", compact[i][0], compact[i][1], compact[i][2]);
    }
}

void simple(int compact[MAX][3], int trans[MAX][3]) 
{
    int totalCols = compact[0][1];
    int totalVal = compact[0][2];
    int k = 1;
    trans[0][0] = compact[0][1];
    trans[0][1] = compact[0][0];
    trans[0][2] = totalVal;
    for (int i=0; i<totalCols; i++) 
    {
        for (int j=1; j<=totalVal; j++) 
	{
