#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[]){
	int size=12;
	int***arreglo= new int**[size];
	for (int i = 0; i < size; ++i){
		arreglo[i]=new int*[12];
	}
	for (int i = 0; i < size; ++i){
		for (int i = 0; i < size; ++i){
			arreglo[i][j]= new int[12];
		}
	}
	return 0;
}