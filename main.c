#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 6

typedef struct nodo{
char atual;
struct nodo *no0[2];
struct nodo *no1[2];
bool fim;
} nodo;

bool loop1(char* entrada, int i);


char* lerArquivo(){
char *entrada = malloc(sizeof(int) * TAM);

//pega a entrada do arquivo e passa pro vetor
entrada[0]='0';
entrada[1]='0';
entrada[2]='0';
entrada[3]='1';
entrada[4]='1';
//exemplo pra teste

return entrada;
}

void criaAF(nodo* no){
    no=malloc(sizeof(nodo));
    no->atual='0';
    no->no0[0]=NULL;
    no->no0[1]=NULL;
    no->no1[0]=NULL;
    no->no1[1]=NULL;
}

nodo* procuraNo(nodo *no, char fim){
    nodo *atual = no;
    if(atual->atual==fim)
        return atual;
    if(atual->no0[0]!=NULL && atual->no0[0]->atual!=atual->atual)
            return procuraNo(atual->no0[0],fim);
    else if(atual->no0[1]!=NULL && atual->no0[1]->atual!=atual->atual)
            return procuraNo(atual->no0[1],fim);
    if(atual->no1[0]!=NULL && atual->no1[0]->atual!=atual->atual)
            return procuraNo(atual->no1[0],fim);
    else if(atual->no1[1]!=NULL && atual->no1[1]->atual!=atual->atual)
            return procuraNo(atual->no1[1],fim);
    return NULL;

}

void defineFim(nodo *no, char fim){
    nodo *atual=procuraNo(no,fim);
    atual->fim=true;
}

void insere(nodo *no,char atual, char destino, char condicao){
    nodo *at=procuraNo(no,atual);
    nodo *nod;
    if(procuraNo(no,destino)==NULL){
        switch(condicao){
        case '0':
            nod=malloc(sizeof(nodo));
            nod->atual=atual;
            nod->no0[0]=NULL;
            nod->no0[1]=NULL;
            nod->no1[0]=NULL;
            nod->no1[1]=NULL;
            if(at->no0[0]==NULL)
                at->no0[0]=nod;
            else
                at->no0[1]=nod;
            break;
        case '1':
            nod=malloc(sizeof(nodo));
            nod->atual=atual;
            nod->no0[0]=NULL;
            nod->no0[1]=NULL;
            nod->no1[0]=NULL;
            nod->no1[1]=NULL;
            if(at->no1[0]==NULL)
                at->no1[0]=nod;
            else
                at->no1[1]=nod;
            break;
        }
    }
    else {
        nod=procuraNo(no,destino);
        switch(condicao){
        case '0':
            if(at->no0[0]==NULL)
                at->no0[0]=nod;
            else
                at->no0[1]=nod;
            break;
        case '1':
            if(at->no1[0]==NULL)
                at->no1[0]=nod;
            else
                at->no1[1]=nod;
            break;
    }

}
}

void lerAFD(nodo* no){
int i=0;
nodo* estado;
while(i<TAM){//EOF



}
}

bool testeFim(char* entrada, int i){
    if(entrada[i]=='1' && i+1 == TAM-1){
        return true;
    }
    return false;
}

bool automatoAFN(char* entrada){
    //(0U1)*U1
    int i=0;
    bool flag;
    while(i<TAM){
            //estado 0


        if(entrada[i]=='1'){

            //estado 1
            flag=testeFim(entrada, i);
        }
    i++;
    if(i==TAM-1 && flag == true){
        return true;
    }
    }
    return false;
}

bool loop0(char* entrada, int i){

    if(entrada[i]=='1')
        loop1(entrada,i);

    while(entrada[i]=='0' && i<TAM-1){
        i++;
        if(entrada[i]=='1'){
            return loop1(entrada,i);
        }
    }
return false;
}

bool loop1(char* entrada, int i){

if(entrada[i]=='0')
        loop0(entrada,i);
    while(entrada[i]=='1' && i<TAM){
        i++;
        if(entrada[i]=='0'){
            return loop0(entrada,i);
        }
    }
return true;
}

bool automatoAFD(char* entrada){
    //(0U1)*U1 AFD
    int i=0;
    return loop0(entrada,i);
}

int main()
{
    char *entrada = lerArquivo();
    //char *AFD = lerAFD();
    bool testeAFD = automatoAFD(entrada);
    bool testeAFN = automatoAFN(entrada);
    if(testeAFD == testeAFN){
        printf("foi\n");
    }
    else
        printf("chora");
    free(entrada);
//    free(AFD);
    return 0;
}
