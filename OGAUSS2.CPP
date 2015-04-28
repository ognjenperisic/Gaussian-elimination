/************************************************************************/
//  Gaussov metod eliminacije za resavanje sistema linearnih jednacina  //
//  Objektno orijentisana verzija algoritma                             //
//  copyright Ognjen Perisic 31.12.2000                                 //
//  Razvojno okruzenje:  Turbo C++ 1.0, 486,100MHz, 20Mb RAM            //
//                       Windows 97                                     //
/************************************************************************/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

const MAX=10;
typedef float niz[MAX][MAX];
typedef float res[MAX];

// Osnovna klasa

class Sistem
{

    public:

    // konstruktor
       Sistem();

    // opste metode
       Sistem operator=(const Sistem &rhs);
       int DajVelicinu() const { return velicina;}
       void PostaviVelicinu(int vel) { velicina=vel; }
       float DajClan(int i,int k) const { float temp; temp=sj[i][k]; return temp;}
       void PostaviClan(int i, int k,float broj) {sj[i][k]=broj;}
       void Unos();
       void Promena();
       void Resavanje();
       void Ispis();
       void IspisResenja();

    private:
       niz  sj;
       res resenja;
       int velicina;
};


// Konstruktor klase Sistem
Sistem::Sistem()
{
 for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
     sj[i][j]=0;
     }
    resenja[i]=0;
  }
  velicina=0;
}



// Operator = klase Sistem
Sistem  Sistem::operator=(const Sistem &rhs)
{
  if  (this == &rhs)  // ako je adresa objekta jednaka adresi objekta koji
		      // se navodi kao argument onda se vraca
      return *this;   // objekat cija je ovo metoda
  int max=velicina;
  velicina=rhs.velicina;
  for(int i=0;i<max;i++){
    for(int j=0;j<=max;j++){
    sj[i][j]=rhs.sj[i][j];
    }
  }
}




// Funkcija za unos sistema jednacina
void Sistem::Unos()
{
  for(int i=0;i<velicina;i++){
   for(int j=0;j<(velicina+1);j++){
      if (j < velicina) {cout<<"Element "<<i+1<<" "<<j+1<<" :";}
      else{cout<<"Slobodni clan "<<i+1<<" jednacine :";}
      cin>>sj[i][j];
     }
  }
}




// Funkcija za ispis sistema
void Sistem::Ispis()
{
  for(int i=0;i<velicina;i++){
   for(int j=0;j<(velicina+1);j++){
      printf("%7.2f ",sj[i][j]);
     }
     cout<<"\n";
  }
}



// Funkcija za promenu sistema u trougaoni oblik
void Sistem::Promena()
{
  int i;
  float pom;
  Sistem pomoc=*this;
  for (i=0;i<(velicina-1);i++){
   for (int j=i+1;j<velicina;j++){
    for (int k=i;k<(velicina+1);k++){
      sj[j][k]=pomoc.sj[j][k]-(pomoc.sj[j][i]/pomoc.sj[i][i])*pomoc.sj[i][k];
    }
   }
   pomoc=*this;
  }
  for(i=0;i<MAX;i++){resenja[i]=0;}
  for(i=velicina-1;i>-1;i--){
   pom=0;
   if (i<(velicina-1)){
     for(int j=i+1;j<velicina;j++){
      pom=pom+resenja[j]*sj[i][j]/sj[i][i];
     }
   }
   resenja[i]=sj[i][velicina]/sj[i][i]-pom;
  }
}



// Funkcija koja na osnovu trougaone matrice pronalazi resenja sistema
//void Sistem::Resavanje()
//{
//  float pomoc;

//}



// Funkcija koja ispisuje gotova resenja sistema
void Sistem::IspisResenja()
{
  cout<<"Resenja ovog sistema linearnih jednacina!\n\n";
  for(int i=0;i<velicina;i++){
    printf("resenje %d : %10.4f\n",i+1,resenja[i]);
  }
}




// Glavni program
void main()
{
  int velicina;
  Sistem sj; //Sistem jednacina

  do
  {
    clrscr();
    cout<<"GAUSSOV sistem za resavanje sistema linearnih jednacina\n\n";
    cout<<"Unesite velicinu sistema linearnih jednacina (max 10) :";
    cin>>velicina;
  } while ((velicina>MAX) || (velicina<0));

  sj.PostaviVelicinu(velicina);
  sj.Unos();

  clrscr();
  sj.Ispis();
  cout<<"\n\n";

  sj.Promena();
//  sj.Resavanje();
  sj.IspisResenja();
  getche();
}