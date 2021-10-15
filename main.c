#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 6

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

char* lerAFD(){
char *entrada = malloc(sizeof(int) * 9);

//pega a entrada do arquivo e passa pro vetor
entrada[0]='(';
entrada[1]='0';
entrada[2]='U';
entrada[3]='1';
entrada[4]=')';
entrada[5]='*';
entrada[6]='U';
entrada[7]='1';
//exemplo pra teste

return entrada;
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
    char *AFD = lerAFD();
    bool testeAFD = automatoAFD(entrada);
    bool testeAFN = automatoAFN(entrada);
    if(testeAFD == testeAFN){
        printf("foi\n");
    }
    else
        printf("chora");
    free(entrada);
    free(AFD);
    return 0;
}
