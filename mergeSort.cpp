#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}



/***************************************************************************************/

int main()
{
    cout << "\tTIEMPOS DE EJECUCIÓN DE COCKTAIL SORT" << endl << endl;
    
    
    
    
    int n = 10;
    int i;
    int diez[n];
    ifstream fileDiez("10.txt");
    if(fileDiez.is_open()) //Abrir archivo para 10 digitos aleatorios no repetidos
    {
        for(int i = 0; i < n; ++i)
        {
            fileDiez >> diez[i]; //Rellenar arreglo de 10 digitos aleatorios no repetidos
        }
    }
    clock_t t;
    t = clock();
    mergeSort(diez, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 10 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    
    
    n = 100;
    int cien[n];
    ifstream fileCien("100.txt");
    if(fileCien.is_open())
    {
        for(int i = 0; i < n; ++i)
        {
            fileCien >> cien[i];
        }
    }
    t = clock();
    mergeSort(cien, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 100 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    
    
    n = 1000;
    int mil[n];
    ifstream fileMil("1000.txt");
    if(fileMil.is_open())
    {
        for(i = 0; i < n; ++i)
        {
            fileMil >> mil[i];
        }
    }
    t = clock();
    mergeSort(mil, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 1000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    
    
    n = 10000;
    int diezMil[n];
    ifstream fileDiezMil("10000.txt");
    if(fileDiezMil.is_open())
    {
        for(i = 0; i < n; ++i)
        {
            fileDiezMil >> diezMil[i];
        }
    }
    t = clock();
    mergeSort(diezMil, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 10000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    
    
    n = 100000;
    int cienMil[n];
    ifstream fileCienMil("100000.txt");
    if(fileCienMil.is_open())
    {
        for(i = 0; i < n; ++i)
        {
            fileCienMil >> cienMil[i];
        }
    }
    t = clock();
    mergeSort(cienMil, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 100000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    
    /* STACK OVERFLOW
    n = 1000000;
    int millon[n];
    ifstream fileMillon("1000000.txt");
    if(fileMillon.is_open())
    {
        for(i = 0; i < n; ++i)
        {
            fileMillon >> millon[i];
        }
    }
    t = clock();
    mergeSort(millon, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 1000000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    */
    
    return 0;
}
