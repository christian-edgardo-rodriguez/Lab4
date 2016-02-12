#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int***newArray();
void deletePunteros(int***,int);

int main(int argc, char const *argv[]){
	int size=12;
	int***arregloJug1=newArray();
	int***arregloJug2=newArray();
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