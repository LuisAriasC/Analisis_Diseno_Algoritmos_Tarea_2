#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item) //Creación de un nodo con struct
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void guardar_Inorden(Node *root, int arr[], int &i){ //Función que reccorre el arbol en inorden
    //y que guarda cada elemento recorrido en el arreglo arr
    if (root != NULL)
    {
        guardar_Inorden(root->left, arr, i);
        arr[i++] = root->data;
        guardar_Inorden(root->right, arr, i);
    }
}

Node* create_Tree(Node* node, int data) //Inserta un elemento en el BST.
{
    if (node == NULL) {
        return newNode(data); //Si el arbol (ramificación) está vacío, crea el nuevo nodo
    }
    
    //En caso de que el nodo ya esté creado, este se recorre al hijo izquierdo o derecho
    if (data < node->data)
        node->left  = create_Tree(node->left, data);
    else if (data > node->data)
        node->right = create_Tree(node->right, data);
    
    return node;
}

void binary_treeSort(int arr[], int n) //Función que transforma el arreglo arr en un BST
{
    struct Node *root = NULL;
    
    root = create_Tree(root, arr[0]);
    for (int i=1; i<n; i++)
        create_Tree(root, arr[i]);
    
    int i = 0; //El valor de i se iniciliza a 0 para ordenar el arreglo con el arbol
    guardar_Inorden(root, arr, i);
}

/***************************************************************************************/

int main()
{
    cout << "\tTIEMPOS DE EJECUCIÓN DE BINARY TREE SORT" << endl << endl;
    
    
    
    
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
    binary_treeSort(diez, n); //Ordena el arreglo con BINARY TREE SORT y toma el tiempo
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
    binary_treeSort(cien, n);//Ordena el arreglo con BINARY TREE SORT y toma el tiempo
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
    binary_treeSort(mil, n);
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
    binary_treeSort(diezMil, n);
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
    binary_treeSort(cienMil, n);
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
    binary_treeSort(millon, n);
    t = clock() - t;
    t = ((float)t)*1000;
    printf("- 1000000 elementos: %f milisegundos.\n",((float)t)/CLOCKS_PER_SEC);
    
    
    return 0;
}
