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
            if (compact[j][1] == i) 
	    {
                trans[k][0] = compact[j][1]; 
                trans[k][1] = compact[j][0]; 
                trans[k][2] = compact[j][2]; 
                k++;
            }
        }
    }
}

void fast(int compact[MAX][3], int trans[MAX][3]) 
{
    int loc, i, col_no;
    int columns = compact[0][1];
    int non_zeros = compact[0][2];
    int total[MAX];
    int index[MAX];
    for (i=0; i<columns; i++) 
    {
        total[i] = 0;
    }
    for (i=1; i<=non_zeros; i++) 
    {
        col_no = compact[i][1];
        total[col_no]++;
    }
    index[0] = 1;
    for (i=1; i<=columns; i++) 
    {
        index[i] = index[i - 1] + total[i - 1];
    }
    trans[0][0] = compact[0][1]; 
    trans[0][1] = compact[0][0]; 
    trans[0][2] = compact[0][2]; 
    for (i=1; i<=non_zeros; i++) 
    {
        col_no = compact[i][1];
        loc = index[col_no];
        trans[loc][0] = compact[i][1]; 
        trans[loc][1] = compact[i][0]; 
        trans[loc][2] = compact[i][2]; 
        index[col_no]++;
    }
}
