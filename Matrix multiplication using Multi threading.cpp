#include <iostream>
#include<cstdlib>
#include<thread>
#include<mutex>
#define MAX 3

using namespace std;
/*
to perform matrix multiplication using threads
multi threading
two matrices are created with random variables
threads of count of number of rows created and they are executed
in the matrixMultiply function
the matrix A and B and the resultant matrices are displayed using display_matrix function
*/
mutex m;
int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];
int row_count = 0;

void matrixMultiply(void* arg)
{
    int i = row_count++; //to count the row count of the resultant matrix
    int j,k;

    for(j=0;j<MAX;j++)
    {
        for(k = 0;k<MAX;k++)
        {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
void display_matrix(int mat[MAX][MAX])
{
    int i,j;

    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //generate the matrixes with random values
    int i,j;

    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            A[i][j] = rand() % 20;
            B[i][j] = rand() % 20;
        }
    }

    //displaying matrices
    cout<<"Matrix A:"<<endl;
    display_matrix(A);

    cout<<"Matrix B:"<<endl;
    display_matrix(B);

    //multiply matrices
    //declaring the threads of count max
    thread th[MAX];

    //creating 3 threads
    //each thread is doing its own part
    for(i = 0; i < MAX; i++)
    {
        int *ptr;
        th[i] = thread(matrixMultiply,(void*)ptr);
    }

    //joining the threads
    for(i = 0; i < MAX; i++)
    {
        th[i].join();
    }

    //displaying the resultant matrix
    cout<<"Resultant Matrix:"<<endl;
    display_matrix(C);

    return 0;
}
