#include <iostream>
#include <string.h>

void se_repeta(char s[100]){
    int repet[256];
    for(int i=0;i<256;i++) repet[i] = 0;
    for(int i=0;i<strlen(s);i++) repet[s[i]]++;
    for(int i=0;i<256;i++) if(repet[i]>1){
            printf("Caracterul %c apare de %d ori.\n",i,repet[i]);
        }


}


void inlocuire_caractere(char s[100]){
    for(int i=0;i<strlen(s);i++)
        if(s[i]<'a'||s[i]>'z') s[i] = ' ';
}

char uppercase(char s){
    if(s>='a'&& s <='z') return s-'a'+'A';
}


void capitalizare(char s[100]){
    s[0]= uppercase(s[0]);
    for(int i=1;i<strlen(s);i++){
        if(s[i]==' ') s[i+1] = uppercase(s[i+1]);
    }
}

int main() {
    char s[100];
    printf("Introduceti un sir de caractere: ");
    gets(s);
    printf("Lungimea siruli este: %d\n", (int) strlen(s));
    se_repeta(s);

    inlocuire_caractere(s);
    printf("Sirul formatat este: %s\n",s);
    capitalizare(s);
    printf("Sirul capitalizat este: %s\n",s);

    FILE *f;
    f = fopen("output.txt","rw+");
    fprintf(f,"Sirul obitnut este %s",s);
    return 0;
}