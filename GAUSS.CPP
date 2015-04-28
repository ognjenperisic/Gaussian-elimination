/************************************************************************/
//  Gaussov metod eliminacije za resavanje sistema linearnih jednacina  //
//  copyright Ognjen Perisic 30.12.2000                                 //
//  Razvojno okruzenje:  Turbo C++ 1.0, 486,100MHz, 20Mb RAM            //
//                       Windows 97                                     //
/************************************************************************/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

const MAX=10;
typedef float niz[MAX][MAX];
typedef float res[MAX];

void Promena(niz,int); //Funkcija koja od matrice pravi trougaonu matricu
void Resavanje(niz,res,int); //Funkcija koja izracunava resenja sistema linearnih jednacina
void Ispis(niz,int);   //Funkcija za ispisivanje matrice
void Kopiranje(niz,niz,int); //Funkcija za kopiranje matrica


void main()
{
  niz sj;
  res resenja;
  int velicina,i,j;
  char string1[256];

  clrscr();
  cout<<"Unesite velicinu sistema linearnih jednacina :";
  cin>>velicina;

  for(i=0;i<velicina;i++){
   for(j=0;j<(velicina+1);j++){
      if (j<velicina) {cout<<"Element "<<i+1<<" "<<j+1<<" :";}
      else{cout<<"Slobodni clan "<<i+1<<" jednacine :";}
      cin>>sj[i][j];
     }
  }

  clrscr();
  cout<<"\n";
  Ispis(sj,velicina);
  Promena(sj,velicina);

  cout<<"\n\n";

  Resavanje(sj,resenja,velicina);

  cout<<"Resenja ovog sistema linearnih jednacina!\n\n";
  for(i=0;i<velicina;i++){
  printf("resenje %d : %10.4f\n",i+1,resenja[i]);
  }
}


void Promena(niz sistem,int broj)
{
  int i,j,k,m;
  niz pomoc;
  Kopiranje(sistem,pomoc,broj);
  for (i=0;i<(broj-1);i++){
   for (j=i+1;j<broj;j++){
    for (k=i;k<(broj+1);k++){
      sistem[j][k]=pomoc[j][k]-(pomoc[j][i]/pomoc[i][i])*pomoc[i][k];
    }
   }
   Kopiranje(sistem,pomoc,broj);
  }
}



void Ispis(niz sistem,int broj)
{
  int i,j;
  for(i=0;i<broj;i++){
   for(j=0;j<(broj+1);j++){
      printf("%7.2f ",sistem[i][j]);
     }
     cout<<"\n";
  }
}



void Kopiranje(niz Sistem,niz temp,int broj)
{
  int i,j;
  for(i=0;i<broj;i++){
   for(j=0;j<(broj+1);j++){
   temp[i][j]=Sistem[i][j];
   }
  }
}


void Resavanje(niz sistem,res resenja,int velicina)
{
  int i,j;
  float pomoc;

  for(i=0;i<MAX;i++){resenja[i]=0;}

  for(i=velicina-1;i>-1;i--){
   pomoc=0;
   if (i<(velicina-1)){
     for(j=i+1;j<velicina;j++){
      pomoc=pomoc+resenja[j]*sistem[i][j]/sistem[i][i];
     }
   }
   resenja[i]=sistem[i][velicina]/sistem[i][i]-pomoc;
  }
}