#include <iostream>
#include<cmath>

using std::abs;
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
void comer(char**, int, int, int);
int evaluar(char**);
void writeResult(int);

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
				comer(tablero,moverx,movery,turno);
				if(evaluar(tablero)!=4){

				}
			}else if(dosEspacios(tablero, moverx,movery,x,y)){
				mover(tablero,moverx,movery,x,y,turno);
				comer(tablero,moverx,movery,turno);		
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
				comer(tablero,moverx,movery,turno);
			}else if(dosEspacios(tablero, moverx,movery,x,y)){
				mover(tablero,moverx,movery,x,y,turno);
				comer(tablero,moverx,movery,turno);
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
	
	if(((x==verx-1)&&(y==very-1))||((x==verx+1)&&(y==very+1))){
                opcion=true;
        }else if(((x==verx+1)&&(y==very-1))||((x==verx-1&&(y==very+1)))){
                opcion=true;
        }else if(((x==verx)&&(y==very-1))||((x==verx)&&(y==very+1))){
                opcion=true;
        }else if(((x==verx-1)&&(y==very))||((x==verx+1)&&(y==very))){
                opcion=true;
        }else{
		opcion==false;
	}
	return opcion;
}

bool dosEspacios(char** tab, int x, int y, int verx, int very){
	bool answer;
	if(((x==verx-2)&&(y==very-2))||((x==verx+2)&&(y==very+2))){
                answer=true;
        }else if(((x==verx+2)&&(y==very-2))||((x==verx-2)&&(y==very+2))){
                answer=true;
        }else if(((x==verx)&&(y==very-2))||((x==verx)&&(y==very+2))){
		answer=true;
	}else if(((x==verx-2)&&(y==very))||((x==verx+2)&&(y==very))){
		answer=true;
	}else{
		answer=false;
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

void comer(char** tab, int x, int y, int player){
	if(((x!=0)&&(y!=0))||((x!=0)&&(y!=6))||((x!=6)&&(y!=6))||((x!=6)&&(y!=0))){
		for(int i = x-1; i<=x+1;i++){
			for(int j = y-1; j<=y+1;j++){
				if(player==1){
					if(tab[i][j]=='#'){
						tab[i][j]='+';
					}
				}else if(player==2){
                                        if(tab[i][j]=='+'){
                                                tab[i][j]='#';
                                        }
                                }
			}
		}
	}else if(x==0&&y==0){
		for(int i = 0; i<=x+1;i++){
                        for(int j = 0; j<=y+1;j++){
                                if(player==1){
                                        if(tab[i][j]=='#'){
                                                tab[i][j]='+';
                                        }
                                }else if(player==2){
                                        if(tab[i][j]=='+'){
                                                tab[i][j]='#';
                                        }
                                }
                        }
                }


	}else if(x==0&&y==6){
                for(int i = x-1; i<=x;i++){
                        for(int j = y; j<=y+1;j++){
                                if(player==1){
                                        if(tab[i][j]=='#'){
                                                tab[i][j]='+';
                                        }
                                }else if(player==2){
                                        if(tab[i][j]=='+'){
                                                tab[i][j]='#';
                                        }
                                }
                        }
                }


        }else if(x==6&&y==6){
                for(int i = x-1; i<=x;i++){
                        for(int j =y-1 ; j<=y;j++){
                                if(player==1){
                                        if(tab[i][j]=='#'){
                                                tab[i][j]='+';
                                        }
                                }else if(player==2){
                                        if(tab[i][j]=='+'){
                                                tab[i][j]='#';
                                        }
                                }
                        }
                }


        }else if(x==6&&y==0){
                for(int i = 0; i<=x+1;i++){
                        for(int j = y-1; j<=y;j++){
                                if(player==1){
                                        if(tab[i][j]=='#'){
                                                tab[i][j]='+';
                                        }
                                }else if(player==2){
                                        if(tab[i][j]=='+'){
                                                tab[i][j]='#';
                                        }
                                }
                        }
                }


        }



}

int evaluar(char** tab){
	int contmas=0, contnum=0,contesp=0;

	for(int i=0; i<7;i++){
		for(int j = 0; j<7;j++){
			if(tab[i][j]=='+')
				contmas++;
		        else if(tab[i][j]=='#')
				contnum++;
			else if(tab[i][j]==' ')
				contesp++;			
	}

	if(contesp==0){
		if(contmas>contnum){
			return 1;
		}else if(contnum>contmas){
			return 2;
		}else if(contnum==contmas){
			return 3;
		}
	}else if(contmas==0){
		return 2;
	}else if(contnum==0){
		return 1;
	}else{
		return 4;
	}
}
}

void writeResult(int num){
	if(num==1){
		cout<<"Ha ganado el jugador 1"<<endl;
	}else if(num==2){
		cout<<"Ha ganado 3l jugador 2"<<endl;
	}else if(num==3){
		cout<<"Ha habido un empate"<<endl;
	}
}
