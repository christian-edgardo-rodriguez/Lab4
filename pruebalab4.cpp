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
int menu(int, int);

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int size=12, bandera=1;
	int cantCoor = 15, wave1=3, expansive1=3, wave2=3, expansive2=3;
	bool win=false;
	int***arregloJug1=newArray();
	int***arregloJug2=newArray();
	randomLlenar(arregloJug1, size, cantCoor);
	randomLlenar(arregloJug2, size, cantCoor);
	do{
		if (bandera==1){
			cout<<"---------------MAPA DE SUBMARINOS DEL JUGADOR 1-----------------"<<endl;
			imprimirMatriz(arregloJug1, size);
			cout<<"-----------MAPA DE ATAQUES-------------"<<endl;
			int opcion1=menu(wave1, expansive1);
		}else if(bandera==2){
			cout<<"---------------MAPA DE SUBMARINOS DEL JUGADOR 2-----------------"<<endl;
			imprimirMatriz(arregloJug2, size);
			cout<<"-----------MAPA DE ATAQUES-------------"<<endl;
			int opcion2=menu(wave2, expansive2);
		}
	}while(win==false);
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
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
				for (int k = 0; k < size; ++k){
						array[i][j][k]=0;
					}	
			}	
	}
	for (int i = 0; i < cantCoor; ++i){
		int coordX=rand()%12;
		int coordY=rand()%12;
		int coordZ=rand()%12;
		array[coordX][coordY][coordZ] = 1;
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
int menu(int wave, int expansive){
	int opcion;
	cout<<"1. Ataque Normal"<<endl;
	cout<<"2. Ataque wave en XY"<<endl;
	cout<<"3. Ataque wave en XZ"<<endl;
	cout<<"4. Ataque wave en YZ"<<endl;
	cout<<"5. Ataque expansivo"<<endl;
	cout<<"WAVES DISPONIBLES: "<<wave<<endl;
	cout<<"EXPANSIVAS DISPONIBLES: "<<expansive<<endl;
	cout<<"Ingrese su opcion: ";
	cin>>opcion;
	return opcion;
}