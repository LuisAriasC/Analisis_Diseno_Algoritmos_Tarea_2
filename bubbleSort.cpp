#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

void bubbleSort(int a[], int n)
{
    int i,j,temp;
    for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
}

/***************************************************************************************/

int main()
{
    cout << "\tTIEMPOS DE EJECUCIÓN DE BUBBLE SORT" << endl << endl;
    
    
    
    
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
    bubbleSort(diez, n); //Ordena el arreglo con BUBBLE SORT y toma el tiempo
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
    bubbleSort(cien, n);//Ordena el arreglo con BUBBLE SORT y toma el tiempo
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
    bubbleSort(mil, n);
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
    bubbleSort(diezMil, n);
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
    bubbleSort(cienMil, n);
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
    bubbleSort(millon, n);
    t = clock() - t;
     t = ((float)t)*1000;
     printf("- 1000000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
     */
    
    return 0;
}
