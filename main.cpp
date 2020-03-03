#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
class Vector
{
private:
    int numar;
    int* v;
public:
    Vector(int n,int val)   ///constructor pentru initializarea cu un numar dat pe toate componentele
    {
        numar=n;
        v = new int[numar];
        for(int i=0; i<numar; i++)
                v[i]=val;
    }
    Vector(int n,int w[])   ///constructor pentru initializare
    {
        numar=n;
        v = new int[numar];
        for(int i=0;i<numar;i++)
                v[i]=w[i];
    }
    Vector(Vector &p)   ///constructor pentru copiere
    {
        numar=p.numar;
        v = new int[numar];
        for(int i=0;i<numar;i++)
            v[i]=p.v[i];
    }
    ~Vector()   ///destructor
    {
        numar=0;
        delete[] v;
    }
///Deoarece cerinta este neclara in privinta modalitatii de citirea obiectului,am realizat si posibilitatea citirii din fisier
    void citire()
    {
        f>>numar;
        v=new int[numar];
        int i=0;
        while(f>>v[i])
            i++;
        if(i==1)
            for(int i=1;i<=numar;i++)
                v[i]=v[0];
    }
Vector(){
}
///De asemenea, am creat si constructorul "default" de mai sus pentru citirea din fisier

    void afisare()  ///afisare vector memorat
    {
        if(numar>0)
            for(int i=0;i<numar;i++)
                cout<<v[i]<<' ';
        else cout<<"Vectorul e vid!";
        cout<<endl;
    }
    void actualizare(int n,int val) ///reactualizarea numarului de componente si initializarea componentelor cu un numar dat
    {
            numar=n;
            v=new int[numar];
            for (int i=0;i<numar;i++)
                v[i]=val;
    }
    int get_sum()   ///calculul sumei tuturor elementelor vectorului
    {
        int sum=0;
        for(int i=0;i<numar;i++)
            sum+=v[i];
        return sum;
    }
    void get_max()  ///gasirea maximului si a pozitiei lui
    {
        int maxi=v[0];
        int poz=0;
        for(int i=1;i<numar;i++)
            if(maxi<v[i])
            {
                maxi=v[i];
                poz=i;
            }
        cout<<"Maximul este "<<maxi<<" si se afla pe pozitia "<<poz<<endl;
    }
    void sorted()   ///sortarea crescatoare a vectorului
    {
        bool ok=1;
        while(ok)
        {
            ok=0;
            for(int i=0;i<numar-1;i++)
                if(v[i]>v[i+1])
            {
                swap(v[i],v[i+1]);
                ok=1;
            }
        }
    }
    Vector operator = (Vector &p)   ///metoda-operator public de atribuire =
    {
        numar=p.numar;
        v = new int[numar];
        for(int i=0;i<numar;i++)
            v[i]=p.v[i];
    }
    friend Vector operator * (Vector &,Vector &);
};
Vector operator * (Vector &p1,Vector &p2) ///produsul scalar a doi vectori de aceeasi lungime, implementat prin supraincarcarea operatorului *
{
    int res=0;
    for(int i=0;i<p1.numar;i++)
        res+=(p1.v[i])*(p2.v[i]);
    cout<<"Produsul scalar este "<<res<<endl;
}
int main()
{
    ///Exemple de apelari ale constructorilor si metodelor:
    int n=6;
    int m=2;
    int w[]={1,3,7,3,2,4};
    Vector vec1(n,m);
    vec1.afisare();
    Vector vec2(n,w);
    cout<<vec2.get_sum()<<endl;
    Vector vec3(vec2);
    Vector vec4(6,3);
    vec2.afisare();
    vec4.afisare();
    vec4=vec2;
    vec4.afisare();
    vec2*vec4;
    vec2.get_max();
    vec2.sorted();
    vec2.afisare();
    vec2.get_max();
    vec2.actualizare(8,5);
    vec2.afisare();
    vec4.afisare();
    vec3.get_max();
    Vector vec5;
    vec5.citire();
    vec5.afisare();
    return 0;
}
