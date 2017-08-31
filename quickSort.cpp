#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

int partition(int *array, int lo, int hi) {
    int i,j;
    int v;
    int temp;
    
    v = array[lo];
    i = lo;
    j = hi;
    
    // Mientras no se cruzen los índices
    while (i < j) {
        while ((i < j) && (array[i] <= v)) {
            i++;
        }
        
        while (array[j] > v) {
            j--;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[j];
    array[j] = array[lo];
    array[lo] = temp;
    // La nueva posición del pivot
    return j;
}


// Función recursiva para hacer el ordenamiento
void quickSort(int *array, int lo, int hi)
{
    
    int pivot;
    
    if (lo < hi) {
        pivot = partition(array, lo, hi);
        
        // Ordeno la lista de los menores
        quickSort(array, lo, pivot - 1);
        
        // Ordeno la lista de los mayores
        quickSort(array, pivot + 1, hi);
    }
}

/***************************************************************************************/

int main()
{
    cout << "\tTIEMPOS DE EJECUCIÓN DE QUICK SORT" << endl << endl;
    
    
    
    
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
    quickSort(diez, 0, n-1); //Ordena el arreglo QUICK SORT y toma el tiempo
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
    quickSort(cien, 0, n-1);//Ordena el arreglo con QUICK SORT y toma el tiempo
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
    quickSort(mil, 0, n-1);
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
    quickSort(diezMil, 0, n-1);
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
    quickSort(cienMil, 0, n-1);
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
    quickSort(millon, 0, n-1);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 1000000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    return 0;
}
