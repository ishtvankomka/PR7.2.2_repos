#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
a[rowNo][colNo] = Low + rand() % (High-Low+1); if ( colNo < N-1 )
        CreateRow(a, rowNo, N, Low, High, colNo+1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, N, Low, High, 0);
    if ( rowNo < N-1 )
        CreateRows(a, N, Low, High, rowNo+1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if ( colNo < N-1 )
        PrintRow(a, rowNo, N, colNo+1);
else
cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if ( rowNo < N-1 )
        PrintRows(a, N, rowNo+1);
else
cout << endl;
}
int Sum2(int** a, const int rowCount, const int colCount, int& S, int i, int j, int min, int index);
int Sum1(int** a, const int rowCount, const int colCount, int& S, int i, int j, int min)
{
    if (j < colCount)
    {
        S = Sum2(a, rowCount, colCount, S, 0, j, min, 0);
        return Sum1(a, rowCount, colCount, S, i, j + 2, min);
    }
    return S;
}
int Sum2(int** a, const int rowCount, const int colCount, int& S, int i, int j, int min, int index)
{
    if (i < rowCount)
    {
        if (a[i][j] < a[index][j])
            index = i;
        return Sum2(a, rowCount, colCount, S, i + 1, j, min, index);
    }
    min = a[index][j];
    S += min;
    return S;
}
int main()
{
    srand((unsigned) time(NULL));
    int N = 5;
    int** a = new int*[N];
    for (int i=0; i<N; i++)
        a[i] = new int[N];
    int Low = 1, High = 25;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);
    int S = 0;
    cout << "  " << Sum1(a, N, N, S, 0, 0, High) << endl << endl;
    for (int i=0; i<N; i++)
        delete [] a[i];
    delete [] a;
    return 0;
}
