#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int***newArray();
void deletePunteros(int***,int);
void randomLlenar(int***, int, int);
void imprimirMatriz(int***, int);

int main(int argc, char const *argv[]){
	int size=12;
	int cantCoor = 15;
	int***arregloJug1=newArray();
	int***arregloJug2=newArray();
	randomLlenar(arregloJug1, size, cantCoor);
	randomLlenar(arregloJug2, size, cantCoor);
	imprimirMatriz(arregloJug1, size);
	cout<<"--------------------------------"<<endl;
	imprimirMatriz(arregloJug2, size);
	deletePunteros(arregloJug1, size);
	deletePunteros(arregloJug2 ,size);
	return 0;
}
int***newArray(){
	int size=12;
	int***arreglo= new int**[size];
	for (int i = 0; i < size; ++i){
		arreglo[i]=new int*[12];
	}
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			arreglo[i][j]= new int[12];
		}
	}//fin new
	return arreglo;
}
void deletePunteros(int*** arreglo, int size){
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			delete[] arreglo[i][j];
		}
	}
	for (int i = 0; i < size; ++i)
	{
		delete[] arreglo[i];
	}
	delete[] arreglo;//fin delete
}
void randomLlenar(int*** array, int size, int cantCoor){
	srand(time(NULL));
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
				for (int k = 0; k < size; ++k){
						array[i][j][k]=0;
					}	
			}	
	}
	for (int i = 0; i < cantCoor; ++i){
		while(validCoor){
			int coordX=rand()%12;
			int coordY=rand()%12;
			int coordZ=rand()%12;
			if (array[coordX][coordY][coordZ] == 1){
				validCoor = true;
			}else{
				array[coordX][coordY][coordZ] = 1;
				validCoor = false;
			}
	    }
	    validCoor= true;
	}
}
void imprimirMatriz(int*** array, int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			for (int k = 0; k < size; ++k){
				if (array[i][j][k]==1){
					cout<<"("<<i<<", "<<j<<", "<<k<<")"<<endl;
				}
			}
			
		}
		
	}
}