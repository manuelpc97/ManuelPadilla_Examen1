#include <iostream>

using std::endl;
using std::cout;
using std::cin;

char** declararTablero(int);
void llenarTablero(char**, int);
void mostrarTablero(char**, int);
void pedirDatos(int&, int&);
void clonar(char**,int, int, int);
void verifyChar(int&, int&, int, char**);
bool unEspacio(char**,int, int, int, int);
bool dosEspacios(char**, int,int, int, int);
void mover(char**,int, int, int, int, int);
void validar(char**, int&, int&);

int main(int argc, char*argv[]){
	const int size = 7;
	bool jugar = true;
	int turno = 1;
	int x, moverx;
	int y, movery;

	char** tablero = declararTablero(size);
	llenarTablero(tablero,size);

	while(jugar){
		if(turno == 1){
			cout<<"--------------------------Jugador 1-----------------------------"<<endl;
			mostrarTablero(tablero, size);
			cout<<"Posicion actual "<<endl;
			verifyChar(x,y,turno,tablero);
			cout<<"Posicion adonde quiere ir: "<<endl;
			validar(tablero, moverx,movery);

			if(unEspacio(tablero, moverx,movery, x,y)){
				clonar(tablero,moverx, movery, turno);
			}else if(dosEspacios(tablero, moverx,movery,x,y)){
				mover(tablero,moverx,movery,x,y,turno);		
			}else{
				cout<<"Rango invalido, pierde turno"<<endl;
			}
			
                        turno=2;

		}else if(turno == 2){

			cout<<"--------------------------Jugador 2-----------------------------"<<endl;
                        mostrarTablero(tablero, size);
                        cout<<"Posicion actual "<<endl;
                        verifyChar(x,y,turno,tablero);
                        cout<<"Posicion adonde quiere ir: "<<endl;
                        validar(tablero,moverx,movery);

			if(unEspacio(tablero,moverx,movery,x,y)){
                        	clonar(tablero,moverx, movery, turno);
			}else if(dosEspacios(tablero, moverx,movery,x,y)){
				mover(tablero,moverx,movery,x,y,turno);
			}else{
				cout<<"Rango invalido de espacio, pierde turno"<<endl;
			}
                        turno=1;

		}
	}
	return 0;
}

char** declararTablero(int num){
	char** h =new char*[num];

	for(int i =0;i<num;i++){
		h[i]=new char[num];
	}

	return h;
}

void llenarTablero(char** tab, int num){
	for(int i = 0; i<num;i++){
		for(int j = 0; j<num;j++){
			tab[i][j]=' ';
		}
	}
	tab[0][3]='+';
	tab[6][3]='+';
	tab[3][0]='#';
	tab[3][6]='#';
}
		
	
void mostrarTablero(char** tab, int num){
	for(int i = 0; i<num;i++){
		for(int j = 0; j<num; j++){
			cout<<"["<<tab[i][j]<<"]";
		}
		cout<<endl;
	}	
}

void pedirDatos(int& x, int& y){
	bool salir=true;

	while(salir){
		cout<<"Ingrese la coordenada en x: "<<endl;
	        cin>>x;
        	cout<<"Ingrese la coordenada en y: "<<endl;
        	cin>>y;

		if(x<0 || x>=7){
			cout<<"Datos incorrectos"<<endl;			
		}else if(y<0||y>=7){
			cout<<"Datos incorrectos"<<endl;
		}else{
			salir=false;
		}				
	}

}

void clonar(char** tab, int x, int y, int jugador){
	if(jugador==1)
		tab[x][y]='+';
	else
		tab[x][y]='#';	
}

void verifyChar(int& x, int& y, int player,char** tab){
	bool verify=true;

	while(verify){
		pedirDatos(x,y);
		if(player==1){
			if(tab[x][y]=='+'){
				verify=false;
                        }else{
				cout<<"En este espacio no hay una pieza propia, ingrese de nuevo"<<endl;
			}	
		}else{
			if(player==2){
                        	if(tab[x][y]=='#'){
                                	verify=false;
                        	}else{
                                	cout<<"En este espacio no hay una pieza propia, ingrese de nuevo"<<endl;
                        	}	

		}
	}	

}
}

bool unEspacio(char** tab, int x, int y, int verx, int very){
	bool opcion;
	
	if(x==verx-1||x==very+1){
		opcion=true;
	}else if(y==very+1||y==very-1){
		opcion=true;
	}else{
		opcion==false;
	}
	return opcion;
}

bool dosEspacios(char** tab, int x, int y, int verx, int very){
	bool answer;
	if(abs(x-y)<=2){
                answer=true;
        }else if(y==very+1||y==very-1){
                answer=true;
        }else{
                answer==false;
        }
	return answer;
}

void mover(char** tab, int x, int y, int verx, int very, int jugador){
	if(jugador==1){
		tab[x][y]='+';
		tab[verx][very]=' ';
	}else if(jugador==2){
		tab[x][y]='#';
		tab[verx][very]=' ';
	}


}

void validar(char** tab, int& x, int& y){
	bool seguir =true;
	
	while(seguir){
		pedirDatos(x,y);
		if(tab[x][y]==' '){
			seguir=false;
		}else{
			cout<<"No puede mover a esa posicion"<<endl;
		}		

	}

}

