#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* z, const int n, const int Low, const int High,int i)
{
    if (i < n)
    {
        z[i] = Low + rand() % (High - Low + 1);
            return Create(z, n, Low, High, i + 1);
    }
}

void Print(int* z, const int n,int i)
{
    cout << "z[i] = " << z[i] << setw(4) << endl;
    if (i < n - 1)
        Print(z, n, i + 1);
    else
        cout << endl;
}

int Max(int* z, const int n, int i, int max)
{
    if (z[i] > max)
        max = z[i];
    if (i < n - 1)
        return Max(z, n, i + 1, max);
    else
        return max;
}

int LastDod(int* z, const int n,int i,int k)
{
    if (i < n)
    {
        if (z[i] > 0)
        {
            LastDod(z, n, i + 1, i);
            return k + LastDod(z, n, k + 1,i);
        }
        else
        {
            return LastDod(z, n, i + 1,k);
        }
    }
     return 0;
}

int Sum(int* z, const int n,int i,int k)
{
    if (i < LastDod(z,n,i,k))
    {
        return z[i] + Sum(z, n, i + 1,k);
    }
    return 0;
}

int Compress(int* z, const int n, int a, int b, int i, int j,int k)
{
    if (i < n)
    {
        k = n - j;
        if (z[i] < a || z[i] > b)
        {
            z[i - j] = z[i];
            return Compress(z, n, a, b, i + 1, j,k);
        }
        else
        {
            return Compress(z, n, a, b, i + 1, j+1,k);
        }
    }
   
    if (k < n)
    {
        z[k] = 0;
        return Compress(z, n, a, b, i, j,k+1);
    }
    return 0;
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    int Low = -10;
    int High = 10;
    cout << "n = "; cin >> n;
    int* z = new int[n];
    int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    Create(z, n, Low, High,0);
    Print(z, n,0);
    cout << "max = " << Max(z, n,0,0) << endl;
    cout << "S = " <<Sum(z, n, 0,0) << endl;
    Compress(z, n, a, b, 0,0,0);
    Print(z, n,0);
    return 0;
}