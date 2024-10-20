#include <iostream>
#include <iomanip>
#include <istream>
#include <algorithm>
using namespace std;
void create(float* arr, int size, double Min = -20, double Max = 30, int i = 0)
{


    if (i < size)
    {
        arr[i] = Min + rand() * (Max - Min) / RAND_MAX;        
        create(arr, size, Min, Max, i+1);
    }
}


void Print(float* arr, int size,int i=0)
{
    if (i < size) {
        if (arr[i] == -431602080.) arr[i] = 0;

        cout << setw(20) << arr[i];
        Print(arr, size, i+1);
    }
    cout << endl;
}

float sum(float* arr, const int size,float n=0,int i=0)
{
    if (i < size) {
        if (arr[i] > 0) 
            n += arr[i] + sum(arr,size,n,i+1);

        else
        {
            if (i == 0) return 0;
            n -= arr[i-1];
        }
        
    }
    return n;
}


int FindMax(float* arr, const int size,int n_max =0,int i=0) 
{
    if (i < size) {
        if (arr[i] > arr[n_max])
            n_max = i;
        FindMax(arr, size, n_max, i + 1);
    } else
    return n_max;
}
void updateArray(float* arr, int size, float a1, float b1,int i=0)
{
    
    if (i<size)
    {
        if (arr[i] >= a1&&arr[i]<=b1)
        {
            arr[i] = 0;
        }
        updateArray(arr, size, a1, b1, i + 1);
    }
}
void rearrangeArray1(float arr[], int size, int index) {
    if (index == size)
        return;
    arr[index] = 0;
    rearrangeArray1(arr, size, index + 1);
}
void rearrangeArray(float arr[], int size, int index = 0, int i = 0)
{
   
    if (index == size)
    {
        
        rearrangeArray1(arr, size, i);
        return;
    }

    
    if (arr[index] != 0)
    {
        arr[i] = arr[index];
        i++;
    }

    
    rearrangeArray(arr, size, index + 1, i);
}



int main()
{
    srand((unsigned)time(NULL));
    float a, b;
    int n;
    cout << "n = "; cin >> n;
    cout << endl;
    cout << "a = "; cin >> a;
    cout << endl;
    cout << "b = "; cin >> b;
    cout << endl;
    
    int size = n;
    float *arr = new float[n];
    
    create(arr, size);
    Print(arr, size);
    cout << "sum = " << sum(arr, size) << endl;
    int q = FindMax(arr, size);
    
    cout << "max = " << arr[q] << endl;
    updateArray(arr, size, a, b);
    rearrangeArray(arr, size);
    Print(arr, size);
    return 0;
}
