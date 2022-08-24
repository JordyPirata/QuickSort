// QuickSort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alfredo Jordano Anaya Hernández 19100011 5E
#include <iostream>

using namespace std;

void intercambio(int &x, int &y)
{
    int Aux;

    Aux = x;
    x = y;
    y = Aux;
}

void QuickSort(int Arr[], int primero, int ultimo)
{
	int i, j, central,pivote;
	
	central = (primero + ultimo) / 2;
	pivote = Arr[central];
    i = primero;
    j = ultimo;

    do
    {
        while (Arr[i] < pivote)i++;
        while (Arr[j] > pivote)j--;

        if (i <= j)
        {
            intercambio(Arr[i],Arr[j]);      
            i++;
            j--;
        }
        
    }while (i<=j);

    if (primero < j)
    {
        QuickSort(Arr, primero, j);
    }
    if (i < ultimo)
    {
        QuickSort(Arr, i, ultimo);
    }
} 

int main()
{
    int TAM, res, Arr[100],primero = 0;
    bool ban1, ban2;
    
    do
    {
        do
        {
            ban1 = false;
            cout << "Cual es el numero de espacios del arreglo?" << endl;
            cin >> TAM;
            
            if (TAM < 2 || TAM > 100)
            {
                cout << "la cantidad no es aceptada favor de volverla a digitar" << endl;
                ban1 = true;
            }

        } while (ban1 == true);

        cout << "Cuales son los elementos del arreglo?" << endl;

        for (int a = 0; a < TAM; a++)
        {
            cin >> Arr[a];
        }

        QuickSort(Arr,primero,TAM-1);

        for (int a = 0; a < TAM; a++)
        {
            cout << Arr[a]<<" ";
        }
        cout << endl;

        cout << "Desea volver a usar el programa?" << endl;
        cout << "1) si" << endl;
        cout << "2) no" << endl;

        cin >> res;
        if (res == 1)
        {
            ban2 = true;
        }
        else
        {
            ban2 = false;
        }

    }while (ban2 == true);

    return 0;
}