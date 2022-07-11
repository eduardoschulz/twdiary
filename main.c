#include <stdio.h>
#include <stdlib.h>
#include <time.h> //https://en.wikipedia.org/wiki/C_date_and_time_functions
#include <stdbool.h>
#include <string.h>

main(){
    char passCheck[64];
    char passwd[] = "senha123";
    printf("senha do diario: ");
    scanf("%s",&passCheck);
    if(strcmp(passCheck,passwd) != 0){
        printf("Senha errada, saindo...\n");
        exit(1);
    }
    FILE *file; //ponteiro do tipo arquivo
    char texto[280]; // cria uma array com a capacidade de 280 caracteres
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);

    c_time_string = ctime(&current_time);

    printf("Data: %s", c_time_string);


    file = fopen("./.cal.txt", "a");

    if(file == NULL){
        printf("Erro, Arquivo não encontrado");
        exit(1);
    }

    char token[] = "&"; //caractere que faz o split de uma string
    
    printf("Escreva um resumo do seu dia em um tweet(280 caracteres): ");
    scanf("%s", &texto);

    //talvez um for que varre a string seja melhor nesse caso
    char *ptr = strtok(texto, token); //strtok retorna um ponteiro se o token(nesse caso &) for encontrado se nao retorna NULL
    //para funcionalidade de titulo
    //    for (int i = 0; i < strlen(texto); i++)

    fprintf(file, "\n%s\n%s", c_time_string, texto); //
    fclose(file);


    
}