#include <stdlib.h>
#include <stdio.h>      //scanf et printf

#define MAX 200
#define FALSE 0
#define TRUE 1

typedef int bool;
typedef struct {
    int nbEffectif;
    double tab[MAX];
} TTabReel; 

//returne vrai si V apparaît dans le tableau et faux sinon
bool etrePresent (TTabReel T, double V){
    bool present;
    int i = 0; 
    present = FALSE;

    while(!present && i<T.nbEffectif)
    {
        present = (T.tab[i] == V);
        i++;
    }
    return present;
}


TTabReel initialiserTableReelTousDifferents()
{
    TTabReel resu;
    int n, i;
    double x;
    do {
        printf("Donnez le nombre d'éléments du tableau >0 et <= à %d \n", MAX);
        scanf("%d", &n);
    } while (n <0 || n>MAX);
    resu.nbEffectif = 0;
    printf("Donnez le premier élément du tab\n");
    scanf("%lf", &(resu.tab[resu.nbEffectif]));

    for (int i = 1; i <= n; i++)
    {
        do{
            printf("Donnez un élément du tab\n");
            scanf("%lf", &(x));
        } while (etrePresent(resu,x));
        resu.tab[resu.nbEffectif] = x;
        resu.nbEffectif = resu.nbEffectif;
    }
    
    return resu;
}


int main(){
    TTabReel T1;
    int i;
    T1 = initialiserTableReelTousDifferents();

    for (i = 0; i < T1.nbEffectif; i++)
    {
        printf("T1[%d] = %lf", i, T1.tab[i]);
    }
    //T3 = initialiserTableReelTousDifferents(T1) + initialiserTableReelTousDifferents(T2);
    return 0;
}