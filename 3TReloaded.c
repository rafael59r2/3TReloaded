/*
     __________ ____      _                 _          _
    |___ /_   _|  _ \ ___| | ___   __ _  __| | ___  __| |
      |_ \ | | | |_) / _ \ |/ _ \ / _` |/ _` |/ _ \/ _` |
     ___) || | |  _ <  __/ | (_) | (_| | (_| |  __/ (_| |
    |____/ |_| |_| \_\___|_|\___/ \__,_|\__,_|\___|\__,_|


    Copyright (C) 2016  Rafael Romao <zeboneyo@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define ANO 2016
#define AUTOR "Rafael Romao"
#define NOME "3Treloaded"
char s(int r){
    if(r == 1){
        return 88;
    }
    if(r == 0){
         return 79;
    }
    if(r == 2){
        return 32;
    }
    return 32;
    }
void initmsg(){
time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm.tm_year + 1900);
int i;
for (i = 0;i < sizeof(NOME)-1;  i++) putchar('*');
    printf("****\n");
    printf("* %s *\n",NOME);
i= 0;
for (i = 0;i < sizeof(NOME)-1;i++) putchar('*');
    printf("****\n");
    printf("Copyright (C) %s %s <zeboneyo@gmail.com>\n",s, AUTOR);
}

int main()
{
    int pvez;
    int vez;
    int A[3] = {2,2,2};
    int B[3] = {2,2,2};
    int C[3] = {2,2,2};

    bool tespaco(int *var){
    int n;
    for(n = 0;n<sizeof(var);n++){
        if(var[n] == 2){
            return true;
        }
    }
    return false;
    }
    bool ganhou(int n){
    if(A[0] == n && A[1] == n && A[2] == n){//n--
        return true;                        //n--
    }                                       //n--
    if(B[0] == n && B[1] == n && B[2] == n){//-n-
        return true;                        //-n-
    }                                       //-n-
    if(C[0] == n && C[1] == n && C[2] == n){//--n
        return true;                        //--n
    }                                       //--n
    if(A[0] == n && B[1] == n && C[2] == n){//n--
        return true;                        //-n-
    }                                       //--n
    if(A[2] == n && B[1] == n && C[0] == n){//--n
        return true;                        //-n-
    }                                       //n--
    if(A[0] == n && B[0] == n && C[0] == n){//nnn
        return true;                        //---
    }                                       //---
    if(A[1] == n && B[1] == n && C[1] == n){//---
        return true;                        //nnn
    }                                       //---
    if(A[2] == n && B[2] == n && C[2] == n){//---
        return true;                        //---
    }                                       //nnn
    return false;
    }
    void mostrar(){
    printf("\n\n\t| |A|B|C| |\n");
    printf("\t|1|%c|%c|%c|1|\n",s(A[0]),s(B[0]),s(C[0]));
    printf("\t| |-----| |\n");
    printf("\t|2|%c|%c|%c|2|\n",s(A[1]),s(B[1]),s(C[1]));
    printf("\t| |-----| |\n");
    printf("\t|3|%c|%c|%c|3|\n",s(A[2]),s(B[2]),s(C[2]));
    printf("\t| |A|B|C| |\n");
    }
        char x;
        int y;

        void inserir(int l){
            void retry(){
                printf("Zona %c%d já está em uso !",x,y);
                inserir(l);
                }
                if (pvez == 0) {
                  getchar();
                  fflush(stdin);
                }
        printf("\nLetra:");
        scanf("%c",&x);
                if(toupper(x) == 'E'){
            printf("Jogador %c desistiu\n", s(l));
            exit(0);
        }
        printf("\nNumero:");
        scanf("%d",&y);
        if(toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C'){
            printf("%c%d é invalido!",x,y);
            inserir(l);
            return;
        }
        if(toupper(x) == 'A'){
                if(A[y-1] == 2){
                A[y-1] = l;
                }else{
                retry();
                return;
                }
        }
        if(toupper(x) == 'B'){
                if(B[y-1] == 2){
                B[y-1] = l;
                }else{
                retry();
                return;
                }
        }
        if(toupper(x) == 'C'){
                if(C[y-1] == 2){
                C[y-1] = l;
                }else{
                retry();
                return;
                }
        }

        }
        initmsg();
        mostrar();
    while(1){
    srand(time(0));
    pvez = rand()%3;
    if(pvez == 1){
       puts("\nX é o primeiro a jogar");
       inserir(1);
       pvez = 0;
       vez = 0;
       break;
    }
    if(pvez == 2){
       puts("\nO é o primeiro a jogar");
       inserir(0);
       pvez = 0;
       vez = 1;
       break;
    }

    }
    mostrar();

    while(1){
        printf("\nÉ a vez de %c\n", s(vez));
        inserir(vez);
        mostrar();
        if(!ganhou(vez)){
        if(tespaco(A) || tespaco(B) || tespaco(C)){
        if(vez == 1){
            vez = 0;
            }
            else{
            vez = 1;
            }
        }else{
        puts("Empate!");
        break;
        }

    }else{
printf("Jogador %c Ganhou!\n",s(vez));

break;
    }
    }

        return 0;
}
