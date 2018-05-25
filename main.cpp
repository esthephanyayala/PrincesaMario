#include <iostream>

using namespace std;

void creaMapa (char mat[50][50], int n){
 for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        mat[i][j]='O';
        }
    }
}

void desplegarMapa(char mat [50][50], int n){
for (int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cout << mat[i][j]<< "  ";
    }
    cout<<endl;
}
}

bool libreDerecha (char mat[50][50], int posFila,int posColum){
if (mat[posFila][posColum+1]=='O')
    return true;
else
    return false;
}

bool libreAbajo (char mat[50][50], int posFila, int posColum){
if (mat[posFila+1][posColum]=='O')
    return true;
else
    return false;
}

bool avanza (char mat[50][50],int posFila, int posColum, int n){
    if (libreDerecha(mat,posFila,posColum) && libreAbajo(mat,posFila, posColum)){
        return avanza(mat,posFila,posColum+1, n) ||  avanza (mat,posFila+1,posColum, n);
    }
    else if (libreDerecha(mat,posFila,posColum)){
        return avanza(mat,posFila,posColum+1, n);
    }
    else if (libreAbajo(mat,posFila,posColum)){
        return avanza(mat,posFila+1,posColum, n);
    }

    if (posFila==n-1 && posColum==n-1)
    return true;
    else
        return false;
}
int main()
{
    char mat[50][50];
    int n,x,fila,columna;

    cout<<"TAMAÑO MATRIZ"<<endl;
    cin>>n;


    cout<<"CUANTAS X QUIERES"<<endl;
    cin>>x;
    creaMapa(mat,n);
    for(int k=1;k<=x; k++){
        cout<<"POSICION DONDE QUIERES TU X"<<endl;
        cin>>fila;
        cin>>columna;
        mat[fila][columna]='X';
    }


    desplegarMapa(mat,n);
    if (avanza(mat,0,0,n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;





}
