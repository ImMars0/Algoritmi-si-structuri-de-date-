#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>


//using namespace std;
using std::cin;
using std::cout;
using std::endl;

// tipuri de variabile

struct numar{
    //lista simplu inlatuita
    int v; // valoarea din lista
    numar *urm; // legatura catre urmatorul element din lista
}; // structura elemente lista simplu inlantuita

struct numar2{
    //lista dublu inlatuita
    int v; // valoarea din lista
    numar2 *urm; // legatura catre urmatorul element din lista
    numar2 *prec; // legatura catre precedentul element din lista
}; // structura elemente lista simplu inlantuita

// structura pentru liste dublu inlantuite sau pentru cozi
struct lista2{  //coada
   numar2 *prim; // primul element din lista dubla
   numar2 *ultim;// ultimul element din lista dubla
};

//definirea structurii pt adunarea si inmultirea polinoamelor
struct monom{
    int grad; // gradul polinomului
    float coef; //coeficientii polinomului
    monom *urm; // legatura catre urmatorul element din lista dubla

};

//definirea structurii pt a verificarea parantezelor dintr o expresie 
struct paranteza{
    int v;
    paranteza *urm;
};

//definirea structurii pt nodurile grafului 
struct nod{
    int val;
    nod *urm;
};

//definirea structurii pt parcurgerea in adancime 
struct list{
    int val;//numarul nodului 
    list *urm;
    list *L[];//vectorul listelor de noduri 

};


//definirea structurii pt muchiile grafului
struct muchie {
    int nod1;
    int nod2;
    muchie* urm;
};

//definirea structurii pt parcurgerea in latime
struct coada {
    list *prim;
    list *ultim;

};



// Capitol 1
void ec2( float a, float b, float c){
    float delta;
    if(a>0||a<0){
    delta=b*b-4*a*c;
    if(delta<0)
        cout<<"ecuatia nu are sol reala";
    if(delta==0)
cout<<"ecuatia are o singura solutie reala x="<<b/2*a;
if(delta>0)
    cout<<"ecuatia are doua solutii distincte x1="<<(b*b+sqrt(delta))/(2*a)<<"si x2="<<(b*b+sqrt(delta));
    }
    else
        cout<<"ecuatia nu este de gradul 2"<<endl;

}


void inmultire_matrici( int A[20][20], int B[20][20], int C[20][20], int pa, int ka, int pb, int kb ){
    for(int i=0;i<pa;i++){
        for(int j=0;j<kb;j++){
            C[i][j]=0;
            for(int x=0;x<ka;x++)
                C[i][j]+=A[i][x]*B[x][j];

        }
    }
    }



bool nrprim(int m)
{
    bool prim=false;
     int div=2;
        for(int i=2;i<m;i++){
        if(m%i==0)
        div++;
        }

    if(div==2)
    prim=true;

    return prim;
}


void schimbare_baza(int nr, int b){
    int rest,aux, p=1, num=0;
    aux=nr;
while(aux!=0){
            rest=aux%b;
    num=num+rest*p;
    p*=10;
    aux/=b;

    }
cout<<num;

}

// capitolul 2: algoritmi de sortare


void BubbleSort(int n, float x[100])
{
    int ok=true; // ok este true daca sirul este ordonat crescator, este false, altfel
    cout<<endl<<"Sortare Bubble"<<endl<<endl;
    do
    {
        ok=true;
        for(int i=0; i<=n-2; i++)
        {
            if (x[i] > x[i+1])
            {
                ok=false;
                float aux=x[i]; x[i]=x[i+1]; x[i+1]=aux;
            }
        }
    }
    while (not ok);
}

void CountingSort(int n, float w[100])
{
    int v[100] = {0};
    float z[100];
 for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (w[j] <= w[k])
                v[k]++;
            else
                v[j]++;
        }
    }
for (int i = 0; i < n; i++) {
        z[v[i]] = w[i];
    }

    for (int i = 0; i < n; i++) {
        w[i] = z[i];
    }


}

void QuickSort(int s, int d, float x[100])
{
// ordoneaza subsirul x[s], ....x[d]
int i, j;
float pivot,aux;
cout<<""<<endl;
for(i=s;i<=d;i++ )
    cout<<x[i]<<" ";
cout<<endl;
cout<<"s = "<<s<<endl;//primul elemet
cout<<"d = "<<d<<endl;//ultim element
if (s<d)
{
    // alegem pivotul x[s];
    pivot=x[s];
    //cauta poziti corecta a pivotului
    int c=0; //c numara cate elemente sunt mai mici decat pivot
    for (i=s+1; i<=d; i++)
       if (x[i] <= pivot)
         c++;
    // poziti pivotului este s+c
    // aduce pivotul pe pozitia corecta prin interschimbare cu pozitia s
    aux=x[s]; x[s]=x[s+c]; x[s+c]=aux;
    // separa in subsiruri
    i=s;
    j=d;
    // partitionare sir
    while (i<j)
    {
       while (x[i]<pivot) i++;
       while (x[j]>=pivot) j--;
       if (i<j)
       {
         //schimba x[i] cu x[j]
         aux=x[i]; x[i]=x[j]; x[j]=aux;
         if (i<d) i++;
         if (j>s) j--;
       }
    }// end while
    cout<<"i = "<<i<<endl;
    cout<<"j = "<<j<<endl;
    cout<<"Sub sirul: ";
    for(int k=s;k<=d;k++ )
    {
       cout<<x[k]<<" ";
    }
    cout<<endl;
    //elemnetele x[i],...x[i-1] sunt <= cu x[i]
    for(int k=s; k<i; k++)
         cout<<x[k]<<" ";
    cout<<"< "<<x[i]<<" >= ";
    //elementele x[i+1],...x[d] sunt >= cu x[i]
    for(int k=i+1; k<=d; k++)
        cout<<x[k]<<" ";
    cout<<endl;
    cout<<" ++++++++++ "<<endl;
    QuickSort(s,s+c-1,x);
    QuickSort(s+c+1,d,x);
} // end if s<d
} // end alg QuickSort


void SelectionSort(int n, float v[100]){
    //cauta indexul minimului din sir
    int index_min;
    int minim;

    for(int i=0;i<n-1;i++)
    { index_min=i;
    cout<<"pas "<<i<<endl;
     for(int j=i+1;j<n;j++)
    {
        if(v[j]<=v[index_min])
             index_min=j;
        }
        if(index_min!=i){
            int aux;
        aux=v[i];
        v[i]=v[index_min];
        v[index_min]=aux;}

        cout<<"elementul minim al sirului a fost gasit pe pozitia "<<index_min<<endl;
        cout<<"sirul devine "<<endl;
        for(int k=0;k<n;k++)
            cout<<v[k]<<" ";
        cout<<endl;

    }


    }

void interclasare(float x[100], int stg, int mij, int dr) {
int i=stg;
int j=mij+1;
int k=0;
float v[100];


    while (i <= mij && j <= dr) {
        if (x[i]<=x[j]) {
          v[k]=x[i];

          i++;
        } else {
           v[k]=x[j];

          j++;
        }
         k++;
    }

 // Copiaza elementele ramase din subsirul din stanga
    while (i <= mij) {
        v[k] = x[i];
        i++;
        k++;
    }

    // Copiaza elementele ramase din subsirul din dreapta
    while (j <= dr) {
        v[k] = x[j];
        j++;
        k++;
    }


   for(int r=0;r<=k-1;r++)
   x[stg+r]=v[r];
}

void mergeSort(float x[100], int stg, int dr) {
    if (stg<dr) {
        int mij = stg + (dr - stg) / 2;

        mergeSort(x, stg, mij);
        mergeSort(x, mij + 1, dr);

        interclasare(x, stg, mij, dr);
    }
}

// Insertion sort function
void insertionSort(float v[], int n) {


    for (int i = 1; i < n; i++) {

        float aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }


        v[j + 1] = aux;


    }
}

//shell sort function

void shellSort(float v[100], int n){
int pas=n/2;
int i, j, aux;
while(pas>=1){
    i=0;
    while(i+pas<=n-1){
    j=i;
    aux=v[i+pas];
    while(v[j]>aux){
        v[j+pas]=v[j];
        j=j-pas;

    }
   v[j+pas]=aux;
   i++;}
pas=pas/2;

}

}
int getMax(float x[100], int n) {
    int maxVal = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > maxVal) {
            maxVal = x[i];
        }
    }
    return maxVal;
}

void radixSort(float x[100], int n) {
      int maxVal;
    // gaseste val maxima in sir pt a i numara cifrele
     maxVal = getMax(x, n);
    cout<<"elementul cu cele mai multe cifre este "<<maxVal<<endl;
    //se numara cifrele celui mai mare nr
    int M=1;
    float y[100];
    int aux;

    int M1;
    int C[100][10]={0};

    while(maxVal/10!=0){
        M++;
        maxVal=maxVal/10;
    }
        cout<<"elementul cu cele mai multe cifre are "<<M<<" cifre"<<endl;
//se form matricea unde coloanele sunt formate din cifrele numerelor sirului
 for (int i = 0; i < n; i++) {
        aux = static_cast<int>(x[i]);
        for (int j = 0; j < M; j++) {
            //extrage cifrele din nr
            C[i][M - j - 1] = aux % 10;
            aux /= 10;
        }

    cout << "matricea de cifre la pasul " <<i<<"este:"<< endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    for (int d = M - 1; d >= 0; d--) {
        int count[10] = {0};
        float output[100];

        for (int i = 0; i < n; i++) {
            count[C[i][d]]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = C[i][d];
            output[count[digit] - 1] = x[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++) {
            x[i] = output[i];
        }

        for (int i = 0; i < n; i++) {
            aux = static_cast<int>(x[i]);
            for (int j = 0; j < M; j++) {
                C[i][M - j - 1] = aux % 10;
                aux /= 10;
            }
        }

        //cout << "Matricea de cifre dupa sortarea coloanei " << d + 1 << ":" << endl;
        //for (int i = 0; i < n; i++) {
           // for (int j = 0; j < M; j++) {
                //cout << C[i][j] << " ";
           // }
            cout << endl;
        }
    }


    cout << endl;
}


 void cautareBinara(int s, int d, float x[], float y){
int m=(s+d)/2;
//elementul se afla la mijlocul sirului
if(y==x[m])
cout<<"elementul cautat este "<<y<<" si se afla pe pozitia "<<m<<endl;
else {
        if(y<x[m])
        {
            if(s<=m-1){
                    cout<<" elementul cautat se afla in prima jumatate a sirului "<<endl;
                cautareBinara(s,m-1,x,y);}
                else
                cout<<" elementul cautat se afla in a doua jumatate a sirului "<<endl;
                    cautareBinara(s, m-1, x, y);

        }

}



}



void afisareVector(float v[], int n) {
    cout << "elementele vectorului sunt: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";  // Display each element
    }
    cout << endl;  // Move to the next line after printing the vector
}

// functii pentru liste simplu inlantuite

numar *creare_lista()
{
    numar *cap, *u, *c;
    int x, n;
    cout<<"creare lista!"<<endl;
    // creare capat lista
    cout<<"Valoare cap lista x = "; cin>>x;
    cap=new numar;
    cap->v=x;
    cap->urm=NULL;
    u=cap; // ultimul element din lista
    cout<<"Numarul de elemente care se adauga in lista la cearea listei n = "; cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Valoare de adaugat in lista x = "; cin>>x;
        c=new numar;
        c->v=x;
        c->urm=NULL;
        u->urm=c; // stabileste legatura intre ultimul elemnt si noul element adaugat
        u=c; // c devine ultimul element
    }
    return cap;
}

void parcurgere_lista(numar *cap)
{
    numar *c;
    if (cap == NULL)
        cout<<"Lista este vida!"<<endl;
    else
    {
        c=cap;
        while (c != NULL)
        {
            cout<<c->v<<" ";
            c=c->urm;
        }
    }
}

numar *stergere_din_lista(numar *cap)
{
    int cont=0;
    int s;

    numar *c, *p;

    do
    {
        if (cap == NULL)
            cout<<"Lista este vida! Nu sunt valori de sters!"<<endl;
        else
        {
            //sterge elementul cu valoarea s de cate ori apare in lista
            cout<<"Valoare de sters s = ";
            cin>>s;
            int nrs=0; // numara de cate ori am sters s din lista
            // stergem valoarea s daca se afla la inceput la lista
            while (cap->v == s)
            {
                cap=cap->urm;
                nrs++;
                if (cap == NULL)
                    break;
            }
            if (cap !=NULL)
            {
                c=cap->urm;
                p=cap; // precedentul elementului curent c
                while (c!=NULL)
                {
                    if (c->v == s)
                    {
                        // sterge din lista pe c
                        p->urm=c->urm;
                        nrs++;
                        c=c->urm;
                    }
                    else
                    {
                        p=c;
                        c=c->urm;
                    }
                }
            }
            cout<<"Elementul de sters "<<s<<" a fost sters de "<<nrs<<" ori"<<endl;
            cout<<"Lista ramasa este: ";
            parcurgere_lista(cap);
            cout<<endl;
        }
        cout<<"Continua stergerea [0/1]? ";
        cin>>cont;
    }
    while (cont);
    return cap;
}

numar *adaugare_in_lista(numar *cap,int a)
{
    int opa;
    numar *p;
    do
    {
        cout<<endl<<"Tip adaugare:"<<endl;
        cout<<"1. Adaugare la inceput de lista:"<<endl;
        cout<<"2. Adaugare dupa element din interiorul listei:"<<endl;
        cout<<"3. Adaugare la sfarsitul listei:"<<endl;
        cout<<"0. Incheiere adaugare!"<<endl;
        cout<<"Optiune adaugare: "; cin>>opa;
        switch (opa)
        {
       case 1: // adauga la inceput
           p=new numar;
           p->v=a;
           p->urm=cap;
           cap=p;
           parcurgere_lista(cap);
           cout<<endl;
        break;
       case 2: // adauga dupa elemnet cu valoare dat din lista
           // citim valoarea dupa care se adauga
           int y;
           numar *c; // c - elementul curent din lista
           cout<<"Valoare dupa care se face adaugarea y = "; cin>>y;
           c=cap;
           while (c!= NULL)
           {
               if (c->v == y)
               {
                   // adauga valoare a dupa y
                   if (c->urm == NULL) // c este ultimul element din lista
                   {
                       p=new numar;
                       p->v=a;
                       p->urm=NULL;
                       c->urm=p;
                       c=c->urm;
                   }
                   else // c se afla in interiorul listei
                   {
                       p=new numar;
                       p->v=a;
                       p->urm=c->urm;
                       c->urm=p;
                       c=c->urm;
                   }
               }
               c=c->urm;
           }// end while *c
           parcurgere_lista(cap);
           cout<<endl;
        break;
       case 3: // adauga la sfarsitul la listei
           numar *u;
           u=cap;
           //urgem lista pentru a ajunge la ultimul element
           while (u->urm != NULL)
               u=u->urm;
            p=new numar;
            p->v=a;
            p->urm=NULL;
            u->urm=p;
            parcurgere_lista(cap);
            cout<<endl;
        break;
       case 0:
        cout<<"incheiat adaugare!"<<endl;
        break;
       default:
        cout<<"Optiune invalida!"<<endl;
        break;
        }// end switch
    }while(opa);
    return cap;
}

numar *modificare_in_lista(numar *cap, int y, int w)
{
    numar *c;
    for(c=cap; c!=NULL; c=c->urm)
    {
        if (c->v == y)
            c->v=w;
    }
    return cap;
}

numar* sortare_lista(numar* cap) {
    if (cap == NULL || cap->urm == NULL) {
        return cap;
    }
    
    numar *c, *aux;
    bool sortat;
    
    do {
        sortat = true;
        c = cap;
        
        while (c->urm != NULL) {
            if (c->v > c->urm->v) {
                // Swap values
                int temp = c->v;
                c->v = c->urm->v;
                c->urm->v = temp;
                sortat = false;
            }
            c = c->urm;
        }
    } while (!sortat);
    
    cout << "Lista sortata este: ";
    parcurgere_lista(cap);
    cout << endl;
    
    return cap;
}


//functii pt liste dublu inlantuite 

lista2* creare_lista2() {
    lista2* L = new lista2;
    numar2 *p, *u, *c;
    //crearea capetelor listei 
   
    int x; 
    int i;
    int N;
    
    cout << "citeste primul element: ";
    cin >> x; //citeste primul element 
    p = new numar2;
    p->v = x;
    p->prec = NULL;
    p->urm = NULL;
    u = p;
    L->prim = p;
    L->ultim = u;
    cout << "citeste cate elemente se vor auga in lista: ";
    cin >> N;
    cout << "citeste elementele: ";
    for (i = 1; i <= N; i++) {
        cin >> x;
        c = new numar2;
        c->v = x;
        c->urm = NULL;
        c->prec = u;
        u->urm = c;
        u = c;
    }
    L->ultim = u;
    return L;
}

//parcurgere lista dublu inlatuita directa  
void parcurgere_lista2_directa(lista2 *L){
    numar2 *c;
    c=L->prim;
    if(c==NULL)
    cout<<"lista este vida";
    else 
    { while(c!=NULL)
    {cout<<c->v<<" ";
    c=c->urm;}
    }
}

//parcugere lista dublu inlantuita inversa
void parcurgere_lista2_inversa(lista2 *L){
    numar2 *c;
    c=L->ultim;
    if(c==NULL)
    cout<<"lista este vida";
    else
    { while(c!=NULL)
    {cout<<c->v<<" ";
    c=c->prec;}     }}

//adaugare element in lista dublu inlantuita
lista2 *adaugare_in_lista2(lista2 *L, int a) {
    numar2 *p, *u, *c;
    int op;
    do {
        cout << "1. Adaugare la inceput de lista:" << endl;
        cout << "2. Adaugare dupa element din interiorul listei:" << endl;
        cout << "3. Adaugare la sfarsitul listei:" << endl;
        cout << "0. Incheiere adaugare!" << endl;
        cout << "Optiune adaugare: ";
        cin >> op;
        
        switch (op) {
            case 1: // adauga la inceput
                p = new numar2;
                p->v = a;
                p->prec = NULL;
                p->urm = L->prim;
                L->prim->prec = p;
                L->prim = p;
                parcurgere_lista2_directa(L);
                cout << endl;
                break;

            case 2: // adauga dupa element cu valoare data din lista
                int y;
                cout << "Valoare dupa care se face adaugarea y = ";
                cin >> y;
                c = L->prim;
                while (c != NULL) {
                    if (c->v == y) {
                        if (c->urm == NULL) { // c este ultimul element din lista
                            p = new numar2;
                            p->v = a;
                            p->prec = c;
                            p->urm = NULL;
                            c->urm = p;
                            L->ultim = p;
                        } else { // c se afla in interiorul listei
                            p = new numar2;
                            p->v = a;
                            p->prec = c;
                            p->urm = c->urm;
                            c->urm->prec = p;
                            c->urm = p;
                        }
                        c = c->urm;
                    }
                    c = c->urm;
                }
                parcurgere_lista2_directa(L);
                cout << endl;
                break;

            case 3: // adauga la sfarsitul listei
                u = L->ultim;
                p = new numar2;
                p->v = a;
                p->prec = u;
                p->urm = NULL;
                u->urm = p;
                L->ultim = p;
                parcurgere_lista2_directa(L);
                cout << endl;
                break;

            case 0:
                cout << "Incheiere adaugare!" << endl;
                break;

            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    } while (op != 0);
    
    return L;
}

 //stergere din lista dublu inlatuita
lista2 *stergere_din_lista2(lista2 *L, int s)
{
    numar2 *p, *u, *c; 
    int count=0; //numara cate valori se vor sterge din lista
    //incep cu primul element din lista
    p=L->prim;
    u=L->ultim;

    //stergem elementele din capatul listei daca au valoarea s
    while (p->v == s)
    {
        (p->urm)->prec=NULL;
        p=p->urm;
        count++;
    }

    //se actualizeaza capul listei
    L->prim=p;
    //stergem elementele din interiorul listei daca au valoarea s
    c=p->urm;
    while(c!=NULL)
    {
        if (c->v == s)
        {
            (c->prec)->urm=c->urm;
            if (c->urm != NULL)
            {
                (c->urm)->prec=c->prec;
            }
            else
            {
                u=c->prec;
            }
            count++;   
        }
        c=c->urm;
    }
    //se actualizeaza coada listei
    L->ultim=u;
    return L;
}

//modificare element din lista dublu inlatuita
lista2* modificare_in_lista2(lista2 *L, int y, int w) {
    numar2 *c;
    c = L->prim;
    while(c != NULL) {
        if(c->v == y) {
            c->v = w;
        }
        c = c->urm;
    }
    return L;
}



//STIVE
//crearea stivei
numar *creare_stiva(){
    numar *c, *d;
    int x;//primul element din stiva 
    cout<<"dati primul element al stivei  "; cin>>x;

    c=new numar;
    c->v=x;
    c->urm=NULL;//c este capatul stivei 
    int N;
    cout<<"dati cate elemente se vor adauga in stiva "; cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>x;
        d=new numar;
        d->v=x;
        d->urm=c;
        c=d;
    }
    return c;
}

//parcurgerea stivei

void parcurgere_stiva(numar *c)
{ 

   while(c!=NULL)
    {
        cout<<c->v<<" ";
        c=c->urm;
    }
    cout<<endl;


}
           
// adaugare element in stiva 
numar *adaugare_in_stiva(numar *c, int a)
{
    numar *p;
    p=new numar;
    p->v=a;
    p->urm=c;
    c =p;
    return c;
}

//stergere n elemente din coada stivei
numar *stergere_din_stiva(numar *c, int n)
{ 
    numar *p;
    p=c;
    for(int i=1;i<=n;i++)
    {
        p=p->urm;
    }
    c=p;
    return c;
   

}

//COZI

//crearea cozii

lista2* creare_coada() {
    lista2* elem = new lista2;
    numar2 *p, *u, *c;
    
    int x, i, N;
    
    cout << "citeste primul element: ";
    cin >> x;
    p = new numar2;
    p->v = x;
    p->prec = NULL;
    p->urm = NULL;
    u = p;
    elem->prim = p;
    elem->ultim = u;
    cout << "citeste cate elemente se vor adauga in coada: ";
    cin >> N;
    cout << "citeste elementele: ";
    for (i = 1; i <= N; i++) {
        cin >> x;
        c = new numar2;
        c->v = x;
        c->urm = NULL;
        c->prec = u;
        u->urm = c;
        u = c;
    }
    elem->ultim = u;
    return elem;
}
//parcurgerea cozii
void parcurgere_coada(lista2 *elem) {
    numar2 *c;
    c = elem->prim;
    while(c != NULL) {
        cout << c->v << " ";
        c = c->urm;
        //cout << endl;
    }}

    //adaugare element in coada
    lista2 *adaugare_in_coada(lista2 *elem, int a)//a elementul care se adauga
    {
        numar2 *p;
        p = new numar2;
        p->v = a;
        p->prec = elem->ultim;
        p->urm = NULL;
        elem->ultim->urm = p;
        elem->ultim = p;
        return elem;
    }

   //stergere element din coada
lista2 *stergere_din_coada(lista2 *elem, int st) {
    numar2 *p;
    for(int i=1; i<=st; i++) {
        p = elem->prim;
        elem->prim = elem->prim->urm;
        elem->prim->prec = NULL;
        delete p;
    }
    return elem;
}


//interclasarea a doua liste

numar *interclasare_liste(numar *L1, numar *L2) {
  numar *L, *p1,*p2;
  L=new numar;
  if(L1->v<L2->v)
{
    L->v=L1->v;
    L->urm=NULL;
    //p1, p2 variabile de tip numar pt parcurgerea L1 si L2
p1=L1->urm;
p2=L2;

}
else
{
    L->v=L2->v;
    L->urm=NULL;
    p1=L1;
    p2=L2->urm;
}
//u variabila de tip numar in care pastram ultimul element din L
numar *u=L;
//c variabila de tip numar in care cream noul element de aduagat in L 
numar *c;
while(p1!=NULL && p2!=NULL){
    if(p1->v<p2->v)
    { 
        c=new numar;
        c->v=p1->v;
        c->urm=NULL;
        u->urm=c;
        u=c;
        p1=p1->urm;
    }
    else
    {
        c=new numar;
        c->v=p2->v;
        c->urm=NULL;
        u->urm=c;
        u=c;
        p2=p2->urm;
    }
}
//adaugam elementele ramase din L1
if(p1!=NULL)
{
   //atunci au ramas elemente in lista L1 , care vor fi copiate in L
   while(p1!=NULL){
    c=new numar;
    c->v=p1->v;
    c->urm=NULL;
    u->urm=c;
    u=c;
    p1=p1->urm;
   }
}

if(p2!=NULL)
{
    //atunci au ramas elemente in lista L2 , care vor fi copiate in L
    while(p2!=NULL){
    c=new numar;
    c->v=p2->v;
    c->urm=NULL;
    u->urm=c;
    u=c;
    p2=p2->urm;
    }
    parcurgere_lista(L);
    return L;
}


}


//polinoame

//ADUNARE POLINOAME

monom* creare_polinom() {
    monom *cap = NULL, *ultim = NULL;
    int n;
    
    cout << "Cate termeni are polinomul? ";
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        monom* nou = new monom;
        cout << "\nTermenul " << i << ":\n";
        cout << "Grad: ";
        cin >> nou->grad;
        cout << "Coeficient: ";
        cin >> nou->coef;
        nou->urm = NULL;
        
        // Aranjare in ordinea descrescatoare a gradului 
        if (cap == NULL || nou->grad > cap->grad) {
            nou->urm = cap;
            cap = nou;
        } else {
            monom* c = cap;
            while (c->urm != NULL && c->urm->grad > nou->grad) {
                c = c->urm;
            }
            nou->urm = c->urm;
            c->urm = nou;
        }
    }
    
    return cap;
}

//ADUNAREA A DOUA POLINOAME

monom* adunare_polinoame(monom* p1, monom* p2) {
    monom *rezultat = NULL, *ultim = NULL;
    
    while (p1 != NULL && p2 != NULL) {
        monom* nou = new monom;
        
        if (p1->grad == p2->grad) {
            nou->grad = p1->grad;
            nou->coef = p1->coef + p2->coef;
            p1 = p1->urm;
            p2 = p2->urm;
        }
        else if (p1->grad > p2->grad) {
            nou->grad = p1->grad;
            nou->coef = p1->coef;
            p1 = p1->urm;
        }
        else {
            nou->grad = p2->grad;
            nou->coef = p2->coef;
            p2 = p2->urm;
        }
        
        nou->urm = NULL;
        
        if (rezultat == NULL) {
            rezultat = nou;
            ultim = nou;
        }
        else {
            ultim->urm = nou;
            ultim = nou;
        }
    }
    
    while (p1 != NULL) {
        monom* nou = new monom;
        nou->grad = p1->grad;
        nou->coef = p1->coef;
        nou->urm = NULL;
        
        if (rezultat == NULL) {
            rezultat = nou;
            ultim = nou;
        }
        else {
            ultim->urm = nou;
            ultim = nou;
        }
        p1 = p1->urm;
    }
    
    while (p2 != NULL) {
        monom* nou = new monom;
        nou->grad = p2->grad;
        nou->coef = p2->coef;
        nou->urm = NULL;
        
        if (rezultat == NULL) {
            rezultat = nou;
            ultim = nou;
        }
        else {
            ultim->urm = nou;
            ultim = nou;
        }
        p2 = p2->urm;
    }
    
    return rezultat;
}

monom* reducere_termeni(monom* s) {
    if (s == NULL || s->urm == NULL) {
        return s;
    }
   
    monom* c = s;
    while (c != NULL && c->urm != NULL) {
        monom* c1 = c->urm;
        monom* prev = c;
        
        while (c1 != NULL) {
            if (c->grad == c1->grad) {
                c->coef += c1->coef;
                prev->urm = c1->urm;
                delete c1;
                c1 = prev->urm;
            } else {
                prev = c1;
                c1 = c1->urm;
            }
        }
        c = c->urm;
    }
    return s;
}


//INMULTIREA A DOUA POLINOAME 

monom *inmultire(   monom *p1, monom *p2){
    monom *rezultat = NULL; //polinomul rezultat
    monom *ultim = NULL; //ultimul element adaugat in polinomul rezultat

    while (p1 != NULL) {
        monom* nou = new monom;
        nou->grad = p1->grad;
        nou->coef = p1->coef;
        nou->urm = NULL;

        monom* c = p2;
        while (c != NULL) {
            monom* nou2 = new monom;// nou2 va stoca monomul rezultat al inmultirii
            nou2->grad = nou->grad + c->grad;//aduna gradul noului monom la gradul monomului curent
            nou2->coef = nou->coef * c->coef;//inmulteste coeficientul monomului curent cu coeficientul monomului curent
            nou2->urm = NULL;// initializam urmatorul element ca fiind NULL

            if (rezultat == NULL) {
                rezultat = nou2;// daca polinomul rezultat este NULL, atunci nou2 va fi primul element din polinomul rezultat
                ultim = nou2;// ultimul element adaugat in polinomul rezultat va fi nou2
            } else {
                ultim->urm = nou2;// daca polinomul rezultat nu este NULL, atunci ultimul element adaugat in polinomul rezultat va fi nou2
                ultim = nou2;// ultimul element adaugat in polinomul rezultat va fi nou2
            }

            c = c->urm;// trece la urmatorul monom din polinomul p2
        }

        p1 = p1->urm;// trece la urmatorul monom din polinomul p1
    }

    return rezultat;



}



void afisare_polinom(monom* p) {
    if (p == NULL) {
        cout << "0";
        return;
    }

    bool first_term = true;
    while (p != NULL) {
        if (p->coef != 0) {
            // semne
            if (!first_term) {
                if (p->coef > 0) cout << " + ";
                else cout << " ";
            } else if (p->coef < 0) {
                cout << "-";
            }

            // afiseaza coeficienti
            float abs_coef = abs(p->coef);
            if (abs_coef != 1 || p->grad == 0) {
                cout << abs_coef;
            }

            // grad si variabila
            if (p->grad > 0) {
                cout << "x";
                if (p->grad > 1) {
                    cout << "^" << p->grad;
                }
            }
            first_term = false;
        }
        p = p->urm;
    }
    cout << endl;
}

//VERIFICARE PARANTEZE 



void verificare_paranteze() {
    paranteza* stiva = NULL;
    char expresie[100];
    cout << "Introduceti expresia : ";
    cin >> expresie;
    
    for(int i = 0; expresie[i] != '\0'; i++) {
        // Verifică doar parantezele, ignoră alte caractere
        if(expresie[i] != '{' && expresie[i] != '[' && expresie[i] != '(' && 
           expresie[i] != '}' && expresie[i] != ']' && expresie[i] != ')') {
            continue;
        }
        
        if(expresie[i] == '{' || expresie[i] == '[' || expresie[i] == '(') {
            paranteza* nou = new paranteza;
            switch(expresie[i]) {
                case '{': nou->v = 1; break;
                case '[': nou->v = 2; break;
                case '(': nou->v = 3; break;
            }
            nou->urm = stiva;
            stiva = nou;
        }
        else if(expresie[i] == '}' || expresie[i] == ']' || expresie[i] == ')') {
            if(stiva == NULL) {
                cout << "Eroare: Paranteza inchisa fara deschidere corespunzatoare" << endl;
                return;
            }
            
            bool esteValid = false;
            switch(expresie[i]) {
                case '}': esteValid = (stiva->v == 1); break;
                case ']': esteValid = (stiva->v == 2); break;
                case ')': esteValid = (stiva->v == 3); break;
            }
            
            if(!esteValid) {
                cout << "Eroare: Parantezele nu sunt in ordinea corecta" << endl;
                return;
            }
            
            paranteza* temp = stiva;
            stiva = stiva->urm;
            delete temp;
        }
    }
    
    if(stiva == NULL) {
        cout << "Expresie valida: Toate parantezele sunt inchise corect!" << endl;
    } else {
        cout << "Eroare: Exista paranteze ramase nedeschise" << endl;
    }
}


//GRAFURI

//creare graf cu matrice de adiacenta 
void creare_graf() {
    nod *L[100] = {NULL};  
    int nr;
    cout << "Nr de noduri: ";
    cin >> nr;
    
    for(int i=1; i<=nr; i++) { 
        cout << "Lista de adiacenta pentru nodul " << i << ": ";
        int x;
        int count = 0;//numara cate noduri sunt in lista de adiacenta
        cin >> x;
        while(x != 0 && count < nr) {
            // verifica daca nodul x este diferit de nodul curent si daca nu exista deja in lista de adiacenta
            if(x > nr || x < 1 || x == i) {
                cout << "Nod invalid! Introduceti un nod intre 1 si " << nr << " diferit de " << i << ": ";
                cin >> x;
                continue;
            }
            
            // verifica daca nodul x exista deja in lista de adiacenta
            bool exists = false;
            nod *temp = L[i];//temp este un pointer care va parcurge lista de adiacenta
            while(temp != NULL)//verifica daca nodul x exista deja in lista de adiacenta
             {
                if(temp->val == x) {
                    exists = true;
                    break;
                }
                temp = temp->urm;
            }
            
            if(!exists)// daca nodul x nu exista deja in lista de adiacenta
             {
                nod *p = new nod;
                p->val = x;
                p->urm = L[i];
                L[i] = p;
                count++;
            }
            cin >> x;
        }
        if(x != 0) {
            cout << "Numarul maxim de noduri adiacente atins!" << endl;
        }
    }

    for(int i=1; i<=nr; i++) {
        cout << "Nodurile adiacente nodului " << i << ": ";
        nod *p = L[i];
        while(p != NULL) {
            cout << p->val << " ";
            p = p->urm;
        }
        cout << endl;
    }
    //MATRICEA DE ADIACENTA

    //creare matrice de adiacenta
    int mat[100][100] = {0};
    for(int i=1; i<=nr; i++) {
        nod *p = L[i];//p este un pointer care va parcurge lista de adiacenta
        while(p != NULL)//verifica daca nodul x exista deja in lista de adiacenta
         {
            mat[i][p->val] = 1;
            p = p->urm;
}
}

///afisare matrice de adiacenta
cout << "Matricea de adiacenta:" << endl;
for(int i=1; i<=nr; i++) {
    for(int j=1; j<=nr; j++) {
        cout << mat[i][j] << " ";
    }
cout<<endl;

}
}



//Reprezentare graf prin lista de noduri adiacente 
void creare_graf_lista_noduri() {
    nod *L[100] = {NULL};  // lista de noduri adiacente
    int nr;
    cout << "Nr de noduri: ";
    cin >> nr;
    //citire lista de adiacenta
    for(int i=1; i<=nr; i++) {
        cout << " Lista de adiacenta pentru nodul " << i << ": ";
        int x;
        int count = 0;//numara cate noduri sunt in lista de adiacenta
        cin >> x;
        
        while(x != 0 && count < nr) {
            if(x > nr || x < 1 || x == i) {
                cout << "Nod invalid! Introduceti un nod intre 1 si " << nr << " diferit de " << i << ": ";
                cin >> x;
                continue;
            }
            
            bool exists = false;//verifica daca nodul x exista deja in lista de adiacenta
            nod *temp = L[i];//temp este un pointer care va parcurge lista de adiacenta
           //verifica daca nodul x exista deja in lista de adiacenta
            while(temp != NULL) {
                if(temp->val == x) {
                    exists = true;
                    break;
                }
                temp = temp->urm;
            }
            
            if(!exists) {
                nod *p = new nod;
                p->val = x;
                p->urm = L[i];
                L[i] = p;
                count++;
            }
            cin >> x;
        }
        
        if(x != 0)//daca numarul de noduri adiacente este mai mare decat numarul maxim de noduri
         {
            cout << "Numarul maxim de noduri adiacente atins!" << endl;
        }
    }

    // afisare lista de adiacenta
    cout << "\nLista de adiacenta:" << endl;
    for(int i=1; i<=nr; i++) {
        cout << " Nodul " << i << ": ";
        nod *p = L[i];//p este un pointer care va parcurge lista de adiacenta
        while(p != NULL) {
            cout << p->val << " ";
            p = p->urm;
        }
        cout << endl;
    }
}


//REPREZENTAREA GRAFURILOR PRIN LISTA DE MUCHII

void creare_graf_lista_muchii() {
    muchie* L = NULL;
    int nr_noduri, nr_muchii;
    
    cout << "Numarul de noduri: ";
    cin >> nr_noduri;
    cout << "Numarul de muchii: ";
    cin >> nr_muchii;
    
    cout << "Introduceti muchiile (nod1 nod2):\n";
    for(int i = 1; i <= nr_muchii; i++) {
        int x, y;
        cout << "Muchia " << i << ": ";
        cin >> x >> y;
        
        if(x > nr_noduri || y > nr_noduri || x < 1 || y < 1 || x == y) {
            cout << "Muchie invalida! Introduceti alte noduri intre 1 si " << nr_noduri << ": ";
            i--;
            continue;
        }
        
        muchie* p = new muchie;
        p->nod1 = x;
        p->nod2 = y;
        p->urm = L;
        L = p;
    }
    
    cout << "\nLista muchiilor:\n";
    muchie* p = L;
    while(p != NULL) {
        cout << "(" << p->nod1 << "," << p->nod2 << ") ";
        p = p->urm;
    }
    cout << endl;
}

//PARCURGEREA IN ADANCIME A GRAFURILOR (recursiv )

void DFS(int nod_curent, bool vizitat[], numar* lista[], int nr_noduri) // DFS = Depth-First Search
{
    vizitat[nod_curent] = true; // Marcam nodul curent ca fiind vizitat
    cout << nod_curent << " "; // Afisam nodul curent
    
    numar* p = lista[nod_curent]; // p este un pointer care parcurge lista de adiacenta a nodului curent
    while (p != NULL) { // Cat timp lista de adiacenta nu s-a terminat
        if (!vizitat[p->v]) { // Daca nodul legat nu a fost vizitat
            DFS(p->v, vizitat, lista, nr_noduri); // Apelam recursiv DFS pentru nodul vecin
        }
        p = p->urm; // Trecem la urmatorul nod din lista de adiacenta
    }
}

void parcurgere_adancime() {
    numar* lista[100] = {NULL}; // Vector de liste de adiacenta initializat cu NULL
    bool vizitat[100] = {false}; // Vector de noduri vizitate initializat cu false
    int nr_noduri;
    
    cout << "Nr de noduri: ";
    cin >> nr_noduri; // Citim numarul de noduri
    
    // Construim lista de adiacenta pentru fiecare nod
    for (int i = 1; i <= nr_noduri; i++) {
        cout << "Lista de adiacenta pentru nodul " << i << ": ";
        int x;
        int count = 0;
        cin >> x;
        
        while (x != 0 && count < nr_noduri) { // Citim nodurile vecine pana introducem 0 sau depasim numarul de noduri
            if (x > nr_noduri || x < 1 || x == i) { // Verificam daca nodul vecin este valid
                cout << "Nod invalid! Introduceti un nod intre 1 si " << nr_noduri << " diferit de " << i << ": ";
                cin >> x;
                continue; // Revenim la inceputul buclei pentru un alt nod
            }
            
            bool exists = false; // Verificam daca nodul vecin exista deja in lista de adiacenta
            numar* temp = lista[i];
            while (temp != NULL) {
                if (temp->v == x) { // Nodul deja exista
                    exists = true;
                    break;
                }
                temp = temp->urm; // Continuam sa verificam urmatoarele noduri
            }
            
            if (!exists) { // Daca nodul nu exista in lista
                numar* p = new numar; // Cream un nou nod
                p->v = x; // Setam valoarea nodului
                p->urm = lista[i]; // Adaugam nodul la inceputul listei
                lista[i] = p; // Actualizam lista de adiacenta
                count++;
            }
            cin >> x; // Citim urmatorul nod vecin
        }
    }
    
    int start;
    cout << "Nod de start pentru parcurgere: ";
    cin >> start; // Nodul de pornire pentru parcurgerea in adancime
    
    cout << "Parcurgerea in adancime pornind din nodul " << start << ": ";
    DFS(start, vizitat, lista, nr_noduri); // Apelam functia DFS
    cout << endl;
}

//PARCURGEREA IN LATIME A GRAFURILOR

bool viz[100]; // Vector global pentru nodurile vizitate
coada* c;      // Structura de coada pentru parcurgerea in latime

void latime(list* L[], int nod) {
    coada* c = new coada; // Initializam coada
    c->prim = NULL;
    c->ultim = NULL;
    
    // Adaugam nodul de start in coada
    list* nou = new list;
    nou->val = nod;
    nou->urm = NULL;
    c->prim = nou;
    c->ultim = nou;
    
    viz[nod] = 1; // Marcam nodul de start ca vizitat
    cout << nod << " "; // Afisam nodul de start
    
    while (c->prim != NULL) { // Cat timp coada nu este goala
        int nodCurent = c->prim->val; // Scoatem primul nod din coada
        list* p = L[nodCurent]; // Luam lista de adiacenta a nodului curent
        
        while (p != NULL) { // Parcurgem lista de adiacenta
            if (!viz[p->val]) { // Daca nodul vecin nu a fost vizitat
                // Adaugam nodul vecin in coada
                list* nou = new list;
                nou->val = p->val;
                nou->urm = NULL;
                c->ultim->urm = nou;
                c->ultim = nou;
                viz[p->val] = 1; // Marcam nodul vecin ca vizitat
                cout << p->val << " "; // Afisam nodul vecin
            }
            p = p->urm; // Trecem la urmatorul nod vecin
        }
        
        // Stergem nodul procesat din coada
        list* temp = c->prim;
        c->prim = c->prim->urm;
        delete temp;
    }
    delete c; // Eliberam memoria pentru coada
}

void parcurgere_in_latime() {
    list* L[100] = {NULL}; // Vector de liste de adiacenta
    int nr_noduri;
    
    cout << "Nr de noduri: ";
    cin >> nr_noduri; // Citim numarul de noduri
    
    // Construim listele de adiacenta
    for (int i = 1; i <= nr_noduri; i++) {
        cout << "Lista de adiacenta pentru nodul " << i << ": ";
        int x;
        cin >> x;
        while (x != 0) { // Citim nodurile vecine pana introducem 0
            if (x > nr_noduri || x < 1) { // Verificam daca nodul vecin este valid
                cout << "Nod invalid! Introduceti un nod intre 1 si " << nr_noduri << ": ";
                cin >> x;
                continue;
            }
            // Adaugam nodul vecin in lista de adiacenta
            list* p = new list;
            p->val = x;
            p->urm = L[i];
            L[i] = p;
            cin >> x;
        }
    }
    
    for (int i = 1; i <= nr_noduri; i++) {
        viz[i] = 0; // Initializam vectorul de vizitati cu 0
    }
    
    cout << "Parcurgerea in latime este: ";
    for (int i = 1; i <= nr_noduri; i++) {
        if (viz[i] == 0) { // Daca nodul nu a fost vizitat
            latime(L, i); // Apelam functia de parcurgere in latime
        }
    }
    cout << endl;
}

// Functia pentru verificarea existentei unui drum intre doua noduri

bool existaDrum(list* L[], int start, int final, bool vizitat[]) {
    if (start == final) return true; // Daca nodul de start este acelasi cu cel final, returnam true
    
    vizitat[start] = true; // Marcam nodul de start ca vizitat
    list* p = L[start]; // Luam lista de adiacenta a nodului de start
    
    while (p != NULL) { // Parcurgem lista de adiacenta
        if (!vizitat[p->val]) { // Daca nodul vecin nu a fost vizitat
            if (existaDrum(L, p->val, final, vizitat)) { // Verificam recursiv daca exista drum spre nodul final
                return true;
            }
        }
        p = p->urm; // Trecem la urmatorul nod vecin
    }
    return false; // Daca nu gasim drum, returnam false
}

void verificare_drum_noduri() {
    list* L[100] = {NULL};  // Initializam un vector de liste pentru reprezentarea grafului (liste de adiacenta).
    int nr_noduri;          // Variabila pentru a retine numarul de noduri din graf.

    cout << "Nr de noduri: ";  // Afisam un mesaj pentru a cere utilizatorului numarul de noduri.
    cin >> nr_noduri;          // Citim numarul de noduri de la utilizator.

    for(int i = 1; i <= nr_noduri; i++) {  // Parcurgem toate nodurile pentru a construi listele de adiacenta.
        cout << "Lista de adiacenta pentru nodul " << i << ": ";  // Cerem vecinii nodului curent.
        int x;                // Variabila pentru a citi fiecare vecin introdus.
        cin >> x;             // Citim primul vecin al nodului curent.
        while(x != 0) {       // Continuam sa citim vecini pana cand se introduce 0 (semn de terminare).
            if(x > nr_noduri || x < 1) {  // Verificam daca vecinul introdus este un nod valid (intre 1 si nr_noduri).
                cout << "Nod invalid! Introduceti un nod intre 1 si " << nr_noduri << ": ";  // Mesaj de eroare.
                cin >> x;  // Citim un alt nod vecin.
                continue;  // Reluam bucla fara a adauga nodul invalid in lista.
            }
            list* p = new list;  // Cream un nou nod de lista pentru vecinul introdus.
            p->val = x;          // Setam valoarea vecinului.
            p->urm = L[i];       // Legam noul nod la inceputul listei de adiacenta a nodului curent.
            L[i] = p;            // Actualizam capul listei de adiacenta pentru nodul curent.
            cin >> x;            // Citim urmatorul vecin.
        }
    }

    int start, final;  // Variabile pentru nodul de start si nodul final.
    cout << "Introduceti nodul de start: ";  // Cerem utilizatorului sa introduca nodul de start.
    cin >> start;                            // Citim nodul de start.
    cout << "Introduceti nodul final: ";     // Cerem utilizatorului sa introduca nodul final.
    cin >> final;                            // Citim nodul final.

    bool vizitat[100] = {false};  // Initializam un vector de vizitati pentru a marca nodurile vizitate.
    if(existaDrum(L, start, final, vizitat)) {  // Verificam daca exista drum intre nodul de start si cel final.
        cout << "Exista drum intre nodurile " << start << " si " << final << endl;  // Afisam mesaj daca exista drum.
    } else {
        cout << "Nu exista drum intre nodurile " << start << " si " << final << endl;  // Afisam mesaj daca nu exista drum.
    }
}



int main() // PROGRAM PRINCIPAL
{
    int op, op1, op2, op3;

    // pentru ordonare de siruri
     int n;
     float v[100], w[100];

    do  // reia meniu principal pana la exit
    {
    // meniu principal
    cout << "PROGRAME SDA "<< endl;
    cout<<"1. Probleme diverse"<<endl;
    cout<<"2. Algoritmi de sortare"<<endl;
    cout<<"3. Liste dinamica"<<endl;
    cout<<"4. Grafuri"<<endl;
     // se vor adauga optiuni
    cout<<"0. Exit program."<<endl;

    cout<<"Optiune : "; cin>>op;

    switch (op) // switch pentruoptiune meniu principal
    {

    case 1: //Probleme diverse (laborator 1)
       do
       {
        cout<<endl<<"Probleme diverse"<<endl;
        cout<<"1.1. Rezolvarea ecuatiei de gradul al doilea"<<endl;
        cout<<"1.2. Inmultire de matrici"<<endl;
        cout<<"1.3. Verificare numar prim"<<endl;
        cout<<"1.4. Schimbare baza numar natural"<<endl;
        cout<<"1.0. Exit probleme diverse!"<<endl;

        cout<<"Optiune probleme diverse : "; cin>>op1;

        switch (op1)
        {
            case 1:
                  float a, b ,c;
    cout<<"sa se rezolve ec de gradul 2: a*x^2+b*x+c=0, unde ";
cout<<"a="; cin>>a;
cout<<"b="; cin>>b;
cout<<"c="; cin>>c;

                ec2(a,b,c);
                break;

           case 2:
                int pa,ka,pb, kb;
int A[20][20],B[20][20], C[20][20];
cout<<"dati nr de linii pt matricea A: ";
cin>>pa;
cout<<"dati nr de coloane pt matricea A: ";
cin>>ka;
cout<<"dati nr de linii pt matricea B: ";
cin>>pb;
cout<<"dati nr de coloane pt matricea B: ";
cin>>kb;
cout<<endl;

if(pa==kb){
        cout<<"introduceti matricele"<<endl;;
for(int i=0;i<pa;i++){
        for(int j=0;j<ka;j++){
            cout<<"A["<<i<<"]["<<j<<"]=";
        cin>>A[i][j];
        }}
        cout<<endl;
for(int i=0;i<pb;i++){
        for(int j=0;j<kb;j++){
            cout<<"B["<<i<<"]["<<j<<"]=";
        cin>>B[i][j];
        }}

inmultire_matrici(A,B,C,pa,ka, pb,kb);
for(int i=0;i<pa;i++){
        for(int j=0;j<kb;j++){
        cout<<C[i][j]<<"  ";
        }
        cout<<endl;}
}
else
    cout<<"nu se poate calcula produsul matricelor date";
                break;

            case 3:
                {int n;
                cout<<"n="; cin>>n;
                int ok=nrprim(n); //ok=0 nu e numar prim
                if (ok==0)
                    cout<<"Numarul "<<n<<" nu e numar prim "<<endl;
                else
                    cout<<"Numarul "<<n<<" este numar prim "<<endl;
                }
                break;

           case 4:
               int nr, baz;
         cout<<"dati numarul care se va trece din baza 10 in baza b ";
cin>>nr;
cout<<endl<<" dati baza b ";
cin>>baz;
cout<<endl<<"nr in baza data este";

                schimbare_baza(nr, baz);
                break;

            case 0:
                cout<<"A terminat submeniu 1"<<endl<<endl;
                break;

            default :
                cout<<"Optiune invalida!"<<endl;
                break;

        }
       } while(op1!=0);
       break;

    case 2: //algoritmi de sortare
       {
        // citim sirul
        cout<<"n= ";cin>>n;
        cout<<"Sirul este: ";
        for(int i=0;i<n;i++)
            cin>>v[i];

       do
       {
        cout<<endl<<"Algoritmi de sortare"<<endl;//facut
        cout<<"2.1. Algoritm Bubble Sort "<<endl;//facut
        cout<<"2.2. Counting Sort "<<endl;//facut
        cout<<"2.3. Selection Sort "<<endl;//facut
        cout<<"2.4. Quicksort "<<endl;//facut
        cout<<"2.5. Merge Sort "<<endl;//facut4
        cout<<"2.6. Insertion Sort "<<endl;//facut
        cout<<"2.7. Shell Sort "<<endl;//facut
        cout<<"2.8. Radix Sort "<<endl;//facut
        cout<<"2.9. Cautarea intr-un sir ordonat "<<endl;
        cout<<"2.0. Exit algoritmi de sortare!"<<endl;


        cout<<"Optiune algoritmi de sortare: "; cin>>op2;
        switch (op2)
        {
            case 1: //Bubble Sort
               {
                   cout<<endl<<"Vectorul initial este:"<<endl;
                   for(int i=0; i<n; i++)
                      cout<<v[i]<<" ";
                   cout<<endl;
                   for(int i=0; i<n; i++)
                      w[i]=v[i];
                   BubbleSort(n,w);// w este vectorul ordonat
                   cout<<"Vectorul ordonat cu BubbleSort este:"<<endl;
                   for(int i=0; i<n; i++)
                      cout<<w[i]<<" ";
                   cout<<endl;
                }
                break;

            case 2:
                // CountingSort()
                {
                   for(int i=0; i<n; i++)
                    w[i]=v[i];
                   CountingSort(n,w);// w este vectorul ordonat
                   cout<<"Vectorul ordonat cu CountingSort este:"<<endl;
                   for(int i=0; i<n; i++)
                      cout<<w[i]<<" ";
                   cout<<endl;
                }
                break;

            case 3:
                //SelectionSort()
{ for(int i=0; i<n; i++)
                      w[i]=v[i];
    SelectionSort(n,w);
    cout<<"Vectorul ordonat cu SelectionSort este:"<<endl;
     for(int i=0; i<n; i++)
                      cout<<w[i]<<" ";
                   cout<<endl;
}
  break;

                case 4:
                // QuickSort()
                {
                   for(int i=0; i<n; i++)
                      w[i]=v[i];
                cout<<endl<<"vectorul dat initial este:"<<endl;
                 for(int i=0; i<n; i++)
                    cout<<v[i]<<" ";
                 cout<<endl;

                   QuickSort(0,n-1,w);// w este vectorul ordonat
                   cout<<"Vectorul ordonat cu QuickSort este:"<<endl;
                   for(int i=0; i<n; i++)
                      cout<<w[i]<<" ";
                   cout<<endl;
                }
                break;

                case 5:
                //MergeSort-sortare prin interclasare
                {

                            mergeSort(v, 0, n - 1);
                            cout << "Vectorul ordonat cu Merge Sort este: ";
                             for(int i=0; i<n; i++)
                      cout<<v[i]<<" ";
                   cout<<endl;

                }

                break;

                case 6:
                //insertionSort
                { cout<<"initial ";
                    afisareVector(v,n);
                    insertionSort(v,n);
                    cout<<endl<<"dupa insertion sort ";
                    afisareVector(v,n);
                }
  break;

              case 7:
                //shellSort
                { cout<<"initial ";
                    afisareVector(v,n);
                    shellSort(v,n);
                    cout<<endl<<"dupa shell sort ";
                    afisareVector(v,n);
                }
  break;

  case 8:
                //radixSort
                { cout<<"initial ";
                    afisareVector(v,n);
                    radixSort(v,n);
                    cout<<endl<<"dupa radix sort ";
                    afisareVector(v,n);
                }
  break;

   case 9:
                //cautarea binara(cautare intr un sir ordonat
                { cout<<"initial ";
                    afisareVector(v,n);
                    radixSort(v,n);
                    cout<<endl<<"dupa sortare sirul este  ";
                    afisareVector(v,n);
                    int element;
                    cout<<"elementul care se cauta ";
                    cin>>element;
                    cout<<" elementul cautat este "<<element<<endl;
                    if(element < v[0] || element > v[n-1])
                        cout<<"elementul cautat nu se afla in sir";
                    else
                        cautareBinara(0, n-1, v, element);

                }
  break;





            case 0:
                cout<<"A terminat submeniu 2"<<endl<<endl;
                break;

            default :
                cout<<"Optiune invalida!"<<endl;
                break;


        }
       } while(op2!=0);
       }
       break;

    case 3: //Liste dinamice
    {
        do
       {
        cout<<endl<<"Liste dinamice"<<endl;
        cout<<"3.1. Liste simplu inlantuite "<<endl;
        cout<<"3.2. Liste dublu inlantuite "<<endl;
        cout<<"3.3. Stive "<<endl;
        cout<<"3.4. Cozi "<<endl;
        cout<<"3.5. Aplicatia 1: Adunarea si inmultirea a doua polinoame "<<endl;
        cout<<"3.6. Aplicatia 2: Interclasarea a doua liste ordonate "<<endl;
        cout<<"3.7. Aplicatia 3: Verificarea parantezelor intr-o expresie aritmetica "<<endl;
        cout<<"3.0. Exit liste dinamice!"<<endl;


        cout<<"Optiune liste dinamice: "; cin>>op3;
        switch (op3)
        {
            case 1: //liste simplu inlatuite
             {
                numar *lista;

                // creare lista
                lista=creare_lista();
                cout<<"Lista dupa creare este: ";
                parcurgere_lista(lista);
                cout<<endl;
                // adaugare in lista
                int ad;
                cout<<"citeste valoare de adaugat: "; cin>>ad;
                lista=adaugare_in_lista(lista,ad);
                cout<<"Lista dupa adaugare este: ";
                parcurgere_lista(lista);
                cout<<endl;
                // stergere din lista
                lista=stergere_din_lista(lista);
                cout<<"Lista dupa stergere este: ";
                parcurgere_lista(lista);
                cout<<endl;
                // modificare element in lista
                int y,w;
                cout<<"Modificare a elementului y = "; cin>>y;
                cout<<"cu valoarea w = ";cin>>w;
                lista=modificare_in_lista(lista,y,w);
                cout<<"Lista dupa modificare este: ";
                parcurgere_lista(lista);
                cout<<endl;
                break;
                }


            case 2: // Liste dublu inlatuite
                { 

                    lista2 *lista;
                    // creare lista dublu inlantuita
                    lista=creare_lista2();
                    cout<<"Lista parcursa direct dupa creare este: ";
                    parcurgere_lista2_directa(lista);
                    cout<<endl<<"lista parcursa inversa dupa creare este: ";
                    parcurgere_lista2_inversa(lista);
                    cout<<endl;
                    // adaugare in lista
                    int ad;
                    cout<<"citeste valoare de adaugat: "; cin>>ad;
                    lista=adaugare_in_lista2(lista,ad);
                    cout<<"Lista dupa adaugare este: ";
                    parcurgere_lista2_directa(lista);
                    cout<<endl;
                    // stergere din  lista
                    int st;
                    cout<<" citeste valoare de sters: "; cin>>st;
                    stergere_din_lista2(lista,st);

                    cout<<"lista dupa stergere este: ";
                    parcurgere_lista2_directa(lista);
                    cout<<endl;
                    // modificare element in lista
                    int y,w;
                    cout<<"Modificare a elementului y = "; cin>>y;
                    cout<<"cu elementul w= "; cin>>w;   
                    lista=modificare_in_lista2(lista,y,w);
                    parcurgere_lista2_directa(lista);

                  break;

                }
              
 
            case 3: // stive
            { 
            numar *stiva;           
            // creare stiva
            stiva=creare_stiva();
          cout<<"Stiva dupa creare este: ";
          parcurgere_stiva(stiva);
          cout<<endl;
          // adaugare in stiva
          int ad;
          cout<<"citeste valoare de adaugat: "; cin>>ad;
          stiva=adaugare_in_stiva(stiva,ad);
          cout<<"Stiva dupa adaugare este: ";
          parcurgere_stiva(stiva);
          cout<<endl;
          // stergere din stiva
          int st;
          cout<<" citeste cate valori sevor sterge : "; cin>>st;

          stiva=stergere_din_stiva(stiva, st);
          cout<<"Stiva dupa stergere este: ";
          parcurgere_stiva(stiva);
          cout<<endl;

                
          break; }
           
           case 4: // cozi
           {//creare coada 
         lista2 *coada;
           coada=creare_coada();
           cout<<"Coada dupa creare este: "<<endl;
           parcurgere_coada(coada);
           cout<<endl;
           //adaugare in coada
           int ad;
           cout<<"citeste valoare de adaugat: "; cin>>ad;
           coada=adaugare_in_coada(coada,ad);
           cout<<"Coada dupa adaugare este: "<<endl;
           parcurgere_coada(coada);
           cout<<endl;
           // stergere din coada
           int st;
           cout<<" citeste cate valori sevor sterge : "; cin>>st;
           coada=stergere_din_coada(coada, st);
           cout<<"Coada dupa stergere este: "<<endl;
           parcurgere_coada(coada);

           
            break;
           }
           
           case 5://aplicatia 1- adunarea si inmultirea a 2 polinoame
           { 
            //primul polinom
           cout << "Crearea primului polinom:\n";
           monom* polinom1 = creare_polinom();
          
           //al doilea polinom
           cout << "Crearea celui de-al doilea polinom:\n";
           monom* polinom2 = creare_polinom();
           
           //afisarea polinoamelor
           cout << "Polinomul 1 creat este: ";
           afisare_polinom(polinom1);
           cout << "Polinomul 2 creat este: ";
           afisare_polinom(polinom2);

           //suma celor 2 polinoame
           cout << "Suma celor 2 polinoame este: ";
           monom* suma = adunare_polinoame(polinom1, polinom2);
           afisare_polinom(suma);
           //reducerea termenilor asemenea
         suma = reducere_termeni(suma);
         cout << "Suma dupa reducere: ";
        afisare_polinom(suma);

           //inmultirea celor 2 polinoame
           cout << "Produsul celor 2 polinoame este: ";
           monom* produs = inmultire(polinom1, polinom2);
           afisare_polinom(produs); 
           //reducerea termenilor asemenea
           produs = reducere_termeni(produs);
           cout << "Produs dupa reducere: ";
           afisare_polinom(produs);



           
            break;
           }

           case 6://interclasarea a 2 liste4
           { //creare lista 1 si 2
              numar *lista1;
              lista1=creare_lista();
              numar *lista2;
              lista2=creare_lista();

            cout<<endl<<endl;

                //afisarea listelor
                cout<<"Lista1 dupa creare este: ";
                parcurgere_lista(lista1);
                cout<<endl<<"Lista2 dupa creare este: ";
                parcurgere_lista(lista2);
                cout<<endl<<endl;

                //ordonare liste
                cout<<"prima";
                lista1=sortare_lista(lista1);
                cout<<"a doua ";
                lista2=sortare_lista(lista2);
            
               
                cout<<endl;
                //interclasare liste
                cout<<"Lista dupa interclasare este: ";
                numar *lista3=interclasare_liste(lista1,lista2);
                cout<<endl;
              
              
                
            break;}
           
           case 7: // Verificarea parantezelor
{
    verificare_paranteze();
    break;
}

            case 0:
                cout<<"A terminat submeniu 2"<<endl<<endl;
                break;

            default :
                cout<<"Optiune invalida!"<<endl;
                break;

        }
       } while(op3!=0);
        break;}
       break;


  case 4: //Grafuri
{
    int op4;
    do {
        cout << endl << "Grafuri" << endl;
        cout << "4.1. Reprezentare graf prin matricea de adiacenta "<< endl;
        cout<<"4.2. Reprezentare graf prin lista de noduri adiacenre (noduri intre care exista muchii) "<<endl;
        cout<<"4.3. Reprezentare grafuri prin lista de muchii"<<endl;
        cout<<"4.4. Parcurgere graf: in adancime."<<endl;
        cout<<"4.5.  Parcurgere graf: in latime."<<endl;
        cout<<"4.6. Verificare existenta drum intre oricare doua noduri"<<endl;
        cout << "4.0. Exit grafuri!" << endl;

        cout << "Optiune grafuri: "; 
        cin >> op4;

        switch (op4) {
            case 1:{
            //creare graf utilizand lista de noduri adiancente nodului i
            cout << "Creare graf cu lista de adiacenta" << endl;    
                creare_graf();}
                break;

             case 2: {
                //reprezentare graf cu lista de noduri adiancente nodului i
                cout << "Reprezentarea grafului:" << endl;
                creare_graf_lista_noduri();
                break;
            }

            case 3: {
                //reprezentarea grafurilor prin lista de muchii
                cout << "Reprezentarea grafului:" << endl;
                creare_graf_lista_muchii();
                break;
            }
        case 4: {
                //parcurgere graf in adancime
                cout << "Parcurgere in adancime" << endl;
                parcurgere_adancime();
                break;
            }
      case 5: {
    //parcurgere graf in latime
    cout << "Parcurgere in latime" << endl;
    parcurgere_in_latime();
    break;
}

    

         case 6: {
    cout << "Verificare existenta drum intre doua noduri" << endl;
    verificare_drum_noduri();
    break;
}




        

            case 0:
                cout << "Exit submeniu grafuri" << endl;
                break;

            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    } while (op4 != 0);
    break;
}



    case 0: // end Meniu principal
        cout<<"Bye! Bye!"<<endl;
        break;

    default :
        cout<<"Optiune invalida!"<<endl;
        break;
    }
    // clrscr();
    }while(op!=0); // end meniu principal

    return 0;
}
