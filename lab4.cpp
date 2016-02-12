#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int***newArray();
void deletePunteros(int***,int);
void randomLlenar1(int***, int, int);
void randomLlenar2(int***, int, int);
void imprimirMatriz(int***, int);
int menu(int, int);

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int x1,y1,z1,x2,y2, z2;
	int size=12, bandera=1;
	int cantCoor = 15, wave1=3, expansive1=3, wave2=3, expansive2=3, cantJUG1 = 14, cantJUG2 = 14;
	bool win=false;
	int***arregloJug1=newArray();
	int***arregloJug2=newArray();
	randomLlenar1(arregloJug1, size, cantCoor);
	randomLlenar2(arregloJug2, size, cantCoor);
	do{
		if (bandera==1){
			cout<<"---------------MAPA DE SUBMARINOS DEL JUGADOR 1-----------------"<<endl;
			imprimirMatriz(arregloJug1, size);
			cout<<"-----------MAPA DE ATAQUES-------------"<<endl;
			cout << "NUMERO DE SUBMARINOS ENEMIGOS" << cantJUG2 << endl;
			int opcion1=menu(wave1, expansive1);
			if (opcion1 == 1){
				cout << "x: ";
				cin>>x1;
				cout << "y: ";
				cin>>y1;
				cout << "z: ";
				cin>>z1;
				if (arregloJug2[x1][y1][z1]==1){
					cout<<"("<<x1<<", "<<y1<<", "<<z1<<") ha sido destruido. "<<endl;
					cantJUG2--;
					arregloJug2[x1][y1][z1]=0;
					bandera=2;
				}else
					cout<<"No destrui nada"<<endl;
					bandera=2;
			}else if (opcion1 == 2){
				while(wave1!=0){
					cout<<"z: ";
					cin>>z1;
					for (int i = 0; i < size; ++i){
						for (int j = 0; j < size; ++j){
							if (arregloJug2[i][j][z1]==1){
								cout<<"("<<i<<", "<<j<<", "<<z1<<") ha sido destruido. "<<endl;
								cantJUG2--;
								arregloJug2[i][j][z1]=0;
							}else
								cout<<"No destrui nada"<<endl;
						}
					}
					wave1--;
					bandera=2;
					break;
				}
				if (wave1==0){
					cout<<"Ya no tiene mas waves."<<endl;
					bandera=2;
				}
			}else if (opcion1 == 3){
				while(wave1!=0){
					cout<<"y: ";
					cin>>y1;
					for (int i = 0; i < size; ++i){
						for (int j = 0; j < size; ++j){
							if (arregloJug2[i][y1][j]==1){
								cout<<"("<<i<<", "<<y1<<", "<<j<<") ha sido destruido. "<<endl;
								cantJUG2--;
								arregloJug2[i][y1][j]=0;
							}else
								cout<<"No destrui nada"<<endl;
						}
					}
					wave1--;
					bandera=2;
					break;
				}
				if (wave1==0){
					cout<<"Ya no tiene mas waves."<<endl;
					bandera=2;
				}	
			}else if(opcion1 == 4){
				while(wave1!=0){
					cout<<"x: ";
					cin>>x1;
					for (int i = 0; i < size; ++i){
						for (int j = 0; j < size; ++j){
							if (arregloJug2[x1][i][j]==1){
								cout<<"("<<x1<<", "<<i<<", "<<j<<") ha sido destruido. "<<endl;
								cantJUG2--;
								arregloJug2[x1][i][j]=0;
							}else
								cout<<"No destrui nada"<<endl;
						}
					}
					wave1--;
					bandera=2;
					break;
				}
				if (wave1==0){
					cout<<"Ya no tiene mas waves."<<endl;
					bandera=2;
				}
			}else if (opcion1 == 5){
				while(expansive1!=0){

				}
				if (expansive1==0){
					cout<<"Ya no tiene mas expansives."<<endl;
					bandera=2;
				}
			}else{
				cout <<"No es una opcion -_-!!!" << endl;
			}
			if (cantJUG2==0){
				cout << "Ganaste!!!" << endl;
				win = true;
				break;
			}
			bandera=2;
		}else if(bandera==2){
			cout<<"---------------MAPA DE SUBMARINOS DEL JUGADOR 2-----------------"<<endl;
			imprimirMatriz(arregloJug2, size);
			cout<<"-----------MAPA DE ATAQUES-------------"<<endl;
			cout << "NUMERO DE SUBMARINOS ENEMIGOS" << cantJUG2 << endl;
			int opcion2=menu(wave2, expansive2);
			if (opcion2 == 1){
				cout << "x: " ;
				cin>>x2;
				cout << "y: " ;
				cin>>y2;
				cout << "z: " ;
				cin>>z2;
				if (arregloJug1[x2][y2][z2]==1){
					cout<<"("<<x2<<", "<<y2<<", "<<z2<<") ha sido destruido. "<<endl;
					cantJUG1--;
					arregloJug1[x2][y2][z2]=0;
					bandera=1;
				}else
					cout<<"No destrui nada"<<endl;
					bandera=1;
			}else if (opcion2 == 2){
				while(wave2!=0){
					cout<<"z: ";
					cin>>z2;
					for (int i = 0; i < size; ++i){
						for (int j = 0; j < size; ++j){
							if (arregloJug1[i][j][z2]==1){
								cout<<"("<<i<<", "<<j<<", "<<z2<<") ha sido destruido. "<<endl;
								cantJUG1--;
								arregloJug1[i][j][z2]=0;
							}else
								cout<<"No destrui nada"<<endl;
						}
					}
					wave2--;
					bandera=1;
					break;
				}
				if (wave2==0){
					cout<<"Ya no tiene mas waves."<<endl;
					bandera=1;
				}	
			}else if (opcion2 == 3){
				while(wave2!=0){
					cout<<"y: ";
					cin>>y2;
					for (int i = 0; i < size; ++i){
						for (int j = 0; j < size; ++j){
							if (arregloJug1[i][y2][j]==1){
								cout<<"("<<i<<", "<<y2<<", "<<j<<") ha sido destruido. "<<endl;
								cantJUG1--;
								arregloJug1[i][y2][j]=0;
							}else
								cout<<"No destrui nada"<<endl;
						}
					}
					wave2--;
					bandera=1;
					break;
				}
				if (wave2==0){
					cout<<"Ya no tiene mas waves."<<endl;
					bandera=1;
				}
			}else if(opcion2 == 4){
				while(wave2!=0){
					cout<<"x: ";
					cin>>x2;
					for (int i = 0; i < size; ++i){
						for (int j = 0; j < size; ++j){
							if (arregloJug1[x2][i][j]==1){
								cout<<"("<<x2<<", "<<i<<", "<<j<<") ha sido destruido. "<<endl;
								cantJUG1--;
								arregloJug1[x1][i][j]=0;
							}else
								cout<<"No destrui nada"<<endl;
						}
					}
					wave2--;
					bandera=1;
					break;
				}
				if (wave2==0){
					cout<<"Ya no tiene mas waves."<<endl;
					bandera=1;
				}
			}else if (opcion2 == 5){
				while(expansive2!=0){

				}
				if (expansive2==0){
					cout<<"Ya no tiene mas expansives."<<endl;
					bandera=1;
				}
			}else{
				cout <<"No es una opcion -_-!!!" << endl;
			}
			if (cantJUG1==0){
				cout << "Ganastes!!!" << endl;
				win = true;
				break;
			}
			bandera=1;
		}
	}while(win==false);
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
void randomLlenar1(int*** array, int size, int cantCoor){
	bool validCoor;
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
void randomLlenar2(int*** array, int size, int cantCoor){
	bool validCoor;
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