#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

int getMax(int arr[], int n) //Función para obtener el elemento de máximo valor en el arreglo
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int output[n], i, count[10] = {0};
    
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int exp, m;
    m = getMax(arr, n);
    
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


/***************************************************************************************/

int main()
{
    cout << "\tTIEMPOS DE EJECUCIÓN DE RADIX SORT" << endl << endl;
    
    
    
    
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
    radixSort(diez, n); //Ordena el arreglo con RADIX SORT y toma el tiempo
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 10 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    
    
    n = 100;
    int cien[n];
    ifstream fileCien("100.txt");
    if(fileCien.is_open())//Abrir archivo para 100 digitos aleatorios no repetidos
    {
        for(int i = 0; i < n; ++i)
        {
            fileCien >> cien[i];//Rellenar arreglo de 100 digitos aleatorios no repetidos
        }
    }
    t = clock();
    radixSort(cien, n);//Ordena el arreglo con RADIX SORT y toma el tiempo
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
    radixSort(mil, n);
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
    radixSort(diezMil, n);
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
    radixSort(cienMil, n);
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
    radixSort(millon, n);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 1000000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    */
    
    return 0;
}
