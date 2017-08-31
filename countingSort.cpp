#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

void countingSort(int arr[], int sz) {
    int i, j, k;
    int idx = 0;
    int min, max;
    
    min = max = arr[0];
    for(i = 1; i < sz; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }
    
    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;
    
    for(i = 0; i < sz; i++) B[arr[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) arr[idx++] = i;
    
    
    delete [] B;
}



/***************************************************************************************/

int main()
{
    cout << "\tTIEMPOS DE EJECUCIÓN DE COUNTING SORT" << endl << endl;
    
    
    
    
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
    countingSort(diez, n); //Ordena el arreglo con COUNTING SORT y toma el tiempo
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
    countingSort(cien, n);//Ordena el arreglo con COUNTING SORT y toma el tiempo
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
    countingSort(mil, n);
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
    countingSort(diezMil, n);
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
    countingSort(cienMil, n);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 100000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    

    
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
    countingSort(millon, n);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 1000000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
     
    
    return 0;
}
