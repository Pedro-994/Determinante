#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <iomanip>
#include<cmath>
#define MAX 100
using namespace std;

void Tamanio(long double [][MAX],int );
void Llenar(long double [][MAX],int );
void MostrarMatriz(long double [][MAX],int );
void EvaluarNulo(long double [][MAX],int );
int Ceros(long double [][MAX],int);
int Igualdad(long double [][MAX],int);
double Determinante(long double [][MAX],int);
void Reducir(long double [][MAX],int);
void IntercambioDeRenglones (long double [][MAX],int,int);

int i,j,det0=1,l,k;
long double det=0,aux;

int main(){

int n;
setlocale(LC_ALL,"spanish");

cout<<"\tCalculo de Determinantes.\n\nNota: Solo se puede realizar el calculo de determinantes para matrices de tamaño nxn.\n\nIngrese el tamaño de la matriz: ";
cin>>n;

long double A[MAX][MAX];
Tamanio(A,n);
system("pause");
}

void Tamanio(long double A[][MAX],int n){

    while(n<1){
        cout<<"\nNo es posible realizar el calculo de una matriz de la dimension ingresada\nIngrese nuevamente un valor: ";
        cin>>n;
    }
    cout<<"\n\tLlenado de la matriz\nIngrese los datos de la matriz.\n\nPosicion\t Valor\n";
    Llenar(A, n);
    EvaluarNulo(A,n);
    if (det0!=0)
        cout<<"\n\t\t\tDeterminante = "<<setprecision(0)<<Determinante(A,n)<<"\n\n\n";
}

void Llenar(long double A[][MAX],int n){

    for (i=0;i<n;i++)
        for (j=0;j<n;j++){
            cout<<"("<<i+1<<") ("<<j+1<<")\t\t ";
            //A[i][j]=rand() % (0-10);
            cin>>A[i][j];
        }
    system("cls");
    cout<<"\tMatriz ingresada.\n\n";
    MostrarMatriz(A,n);

}

void MostrarMatriz(long double A[][MAX],int n){

    for (i=0;i<n;i++){
        cout<<"\t";
        for (j=0;j<n;j++){
                if(A[i][j]- int(A[i][j])==0)
                    cout<<fixed<<setprecision(0)<<setw(6)<< A[i][j]<<" ";
                else
                    cout<<fixed<<setprecision(2)<<setw(6)<< A[i][j]<<" ";
        }
        cout<<"\n\n\n";
    }
}

void EvaluarNulo(long double A[][MAX],int n){

    Ceros(A,n); //Todos los elementos de una fila (o una columna) son nulos.
    Igualdad(A,n); //Posee dos filas (o columnas) iguales.
}

int Ceros(long double A[][MAX],int n){

    int fceros=0,cceros=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(A[i][j]==0)//Filas.
                fceros++;
            if(A[j][i]==0)//Columnas.
                cceros++;
        }
        if(fceros==n || cceros==n){
            cout<<"\nPor propiedad de los determinantes, si todos los elementos de una fila (o una columna) son nulos el determinate es 0\n";
            det0=0;
            break;
        }else{
            fceros=0;
            cceros=0;
        }
    }
return det0;
}

int Igualdad(long double A[][MAX],int n){

    int col=0,fil=0,k;
    for (i=0;i<n-1;i++){
        for (k=i+1;k<n;k++){
            for(j=0;j<n;j++){
                if(A[i][j]==A[k][j])
                    fil++;
                if(A[j][i]==A[j][k])
                    col++;
            }
            if(fil==n || col==n){
                cout <<"\nPor propiedad de los determinantes, si se poseen dos filas (o columnas) iguales. El determinate de la matriz es 0\n";
                det0=0;
                break;
            }else{
                fil=0;
                col=0;
            }
        }
        if(fil==n || col==n)
            break;
    }
return det0;
}

double Determinante(long double A[][MAX],int n){

    if(n==1)
        det=A[0][0];
    else{
        Reducir(A,n);
        det=A[0][0];
        for(i=1;i<n;i++)
            det=det * A[i][i];
    }
return det;
}

void Reducir(long double A[][MAX],int n){

    int fi;
    double div=0;
    for(fi=0;fi<n-1;fi++){ // Fila a evaluar.
        for(j=fi;j<n;j++){// Primer elemento Diagonal Principal.
            if(A[fi][fi]==0)// Verifica si el elemento inicial de la matriz principal es = 0.
                IntercambioDeRenglones(A,n,fi);
            cout<<"\nReduccion de la Fila: "<<fi+1<<" \n";
            for(k=fi+1;k<n;k++){ //conversion a 0 elementos de la matriz inferior
                if(A[k][fi]!=0){
                    div=A[k][fi] / A[fi][fi];
                    //cout<<"Se Divide el valor de la fila: "<<k+1<<" Columna "<<fi+1<<" Entre: "<<A[fi][fi]<<"\n";
                    //cout<<"Se realiza resta de los valores del renglon "<<k+1<<"\n";
                    for(l=fi;l<n;l++){
                        if(A[k][l]== A[k][fi])
                            A[k][l]=0;
                        else
                            A[k][l] = A[k][l] - div * A[fi][l];
                    }
                }
           }
           MostrarMatriz(A,n);
        }
    }
}

void IntercambioDeRenglones(long double A[][MAX],int n,int fi){

    k=fi+1;
    do{
        aux=A[k][j];
        if(aux!=0){
            break;
        }
        k++;
    }while(k!=n);  // busca un elemento que contenga valor distinto a 0 en la misma columna
    cout<<"Intercambio de renglones "<< fi+1 << " por "<< k+1 <<"\n";
    for(l=0;l<n;l++){
        aux = A[k][l];
        A[k][l] = -1 * A[fi][l];
        A[fi][l] = aux;
        if(l==n-1)
            MostrarMatriz(A,n);
    } // fin ciclo if
}
