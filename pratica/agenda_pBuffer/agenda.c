/*

        It's ugly work, at best. But for now, thats fine.

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define END_MENU pBuffer
#define MENU_VAL(buffer) *(( int * ) buffer )

#define END_QNT_P ( pBuffer + sizeof( int ) )
#define QNT_P(buffer) ( *( (int*) ( buffer + sizeof( int ) ) ) )
#define END_NOME sizeof( int )
#define END_TAM_NOME (sizeof(int))

#define BASE_PESSOA ( ( sizeof( int ) + ( sizeof( char ) * 50 ) ) + ( sizeof(int) ) + ( sizeof( int ) + ( sizeof( char ) * 50 ) ))
#define BASE_INICIAL ( sizeof( int ) * 3 )

#define CHAR(b) ((char*)(b))
#define INT(b) ((int*)(b))

#define TAM_BUFFER_VAL(buffer) *( (int *) (buffer + sizeof(int) * 2))




/*
==================================================================================================================================
Estrutura:
(header)
    (int) menu
    (int) quantidade de pessoas
    (int) tamanho do buffer em bytes

(pessoa)
    (int) tamanho do nome
    (*char) nome
    (int) idade
    (int) tamanho do email
    (*char) email
==================================================================================================================================
*/

void addPessoa( void ** pBuffer );
void rmPessoa( void ** pBuffer );
void listaPessoas(void ** pBuffer);
void buscaPessoa( void ** pBuffer );
int getBufferTamanho(void ** pBuffer);
void setBufferTamanho(void ** pBuffer);
void getUltimoEndereco(char ** cursor, void ** pBuffer);


int main(){

    void *pBuffer = NULL;

    pBuffer = calloc( 1, BASE_INICIAL );
    TAM_BUFFER_VAL(pBuffer) += BASE_INICIAL;

    if(pBuffer == NULL){
        printf("erro ao alocar memoria, tem q ver isso ai\n");
    }

    MENU_VAL(pBuffer) = 0;
    QNT_P(pBuffer) = 0;


    while (MENU_VAL(pBuffer) != 5 || MENU_VAL(pBuffer) == 0) {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar Pessoa\n");
        printf("2. Remover Pessoa\n");
        printf("3. Buscar Pessoa\n");
        printf("4. Listar Pessoas\n");
        printf("5. Sair\n");
        printf("---------------------------------------------\n");
        printf("Escolha uma opcao: ");

        if (scanf(" %d", INT(pBuffer)) != 1) {
            MENU_VAL(pBuffer) = 0; 
            while ( (*INT(pBuffer) = getchar()) != '\n' && *INT(pBuffer) != EOF );
        }

        switch (MENU_VAL(pBuffer)) {
        case 1:
            addPessoa(&pBuffer);
            break;
        case 2:
            rmPessoa(&pBuffer);
            break;
        case 3:
            buscaPessoa(&pBuffer);
            break;
        case 4:
            listaPessoas(&pBuffer);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    }
    








    free(pBuffer);
    return 0;
}

void addPessoa( void ** pBuffer ){


    /* --------------------------- CURSOR SHINENIGANS  -----------------------


    MENU_VAL(*pBuffer) = 69;

    QNT_P(*pBuffer) = -11;

    char * cursor;
    getUltimoEndereco(&cursor, pBuffer);
    cursor -= 12;
    printf("\nCursor diz que MENU val = %d", *cursor);


    cursor += 4;
    printf("\nCursor diz que QNT val = %d", *cursor);

    cursor += 4;
    printf("\nCursor diz que buff size val = %d", *cursor);

    QNT_P(*pBuffer) = 0;
     --------------------------- CURSOR SHINENIGANS  -----------------------*/
    


    //---------------------------------- alocamento da template da pessoa ----------------------//

    *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer) + BASE_PESSOA);
    char * cursor;
    getUltimoEndereco(&cursor, pBuffer); cursor -= 12;

    //---------------------- salva o nome no buffer com espaço de template ----------------------//
    printf("\nNome: ");
    scanf(" %49[^\n]", (  CHAR( cursor + BASE_INICIAL + END_TAM_NOME ) ));

    (*( INT( cursor + BASE_INICIAL ))) = 0;
    //---------------------- contagem de caracteres do nome e salva ----------------------//

    while((*CHAR( ( cursor + BASE_INICIAL + END_TAM_NOME ) + (*( INT( cursor + BASE_INICIAL ))) )) != '\0'){

        (*( INT( cursor + BASE_INICIAL)))++;
    }

    //---------------------- cortar o que nao foi usado dos 50 caracteres ----------------------//
    memmove(
        CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL )) + 1,
        CHAR(cursor) + BASE_INICIAL + END_NOME + 50,
        (BASE_INICIAL + BASE_PESSOA) - (BASE_INICIAL + END_NOME + 50)
    );

    *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer) + (BASE_PESSOA - ( 50 - *INT(CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL ))) )));
    //--------------- cursor precisa ser "reapontado" pois perde sua referencia ---------------//
    getUltimoEndereco(&cursor, pBuffer); cursor -= 12;


    //---------------------- le e salva idade no buffer ----------------------//
    printf("\nIdade: ");
    scanf(" %d",
    INT( CHAR(cursor) + BASE_INICIAL + END_NOME +
        *(INT( CHAR(cursor) + BASE_INICIAL )) + 1 )
    );

    

    //---------------------- le e salva email no buffer com espaço de template ----------------------//
    printf("\nemail: ");
    scanf(" %49[^\n]", ( CHAR(( INT( CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL )) + 1 + sizeof(int) * 2) )) ));


    //---------------------- conta os caracteres do email e salva ----------------------//
    *( INT( CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL )) + 1 + sizeof(int) ) ) = 0;

    while( (*( CHAR(( INT( CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL )) + 1 + sizeof(int) * 2) )) + *( INT( CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL )) + 1 + sizeof(int) ) ) )) != '\0'){
        (*( INT( CHAR(cursor) + BASE_INICIAL + END_NOME + *(INT( CHAR(cursor) + BASE_INICIAL )) + 1 + sizeof(int) ) ))++;
    }


    *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer) + sizeof(int) + *(INT(CHAR(cursor)+BASE_INICIAL)) + 1 + sizeof(int) + sizeof(int) + *(INT(CHAR(cursor)+BASE_INICIAL+sizeof(int)+*(INT(CHAR(cursor)+BASE_INICIAL))+1+sizeof(int))) + 1);
    getUltimoEndereco(&cursor, pBuffer); cursor -= 12;


    //----------------- incrementa o QNT_P e atualiza o tamanho do buffer (importante) -----------------//
    (QNT_P(*pBuffer))++;
    setBufferTamanho(pBuffer);
    //printf("\n Tamanho pBuffer (bytes): %d\n", TAM_BUFFER_VAL(*pBuffer));




}

void rmPessoa( void ** pBuffer ){

    if(QNT_P(*pBuffer) == 0){
        printf("\nNao ha ninguem para remover.\n");
        return;
    }

    //------------ aloca + 50 bytes ---------------//
    *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer) + (sizeof(char) * 50) );
    
    char * nomeSearch; 
    getUltimoEndereco(&nomeSearch, pBuffer); 
    
    printf("\nNome da pessoa a remover: ");
    scanf(" %49[^\n]", nomeSearch);


    //------------ ponteiro apontando pro final do header ---------------//
    char *cursor = CHAR(*pBuffer) + BASE_INICIAL;
    char *endComecoPessoa = NULL; 
    
    MENU_VAL(*pBuffer) = QNT_P(*pBuffer); 
    

    //------------ itera sobre as pessoas procurando o culpado ---------------//
    for (; MENU_VAL(*pBuffer) > 0; ( MENU_VAL(*pBuffer) )--) {
        
        cursor += sizeof(int); 

        if (endComecoPessoa == NULL && strcmp(nomeSearch, cursor) == 0){
            endComecoPessoa = cursor - sizeof(int); 
            MENU_VAL(*pBuffer) = 1; 
        }
        
        if (endComecoPessoa == NULL) {
            cursor += *INT(cursor - sizeof(int)) + 1; 
            cursor += sizeof(int);  
            cursor += sizeof(int);  
            cursor += *INT(cursor - sizeof(int)) + 1; 
        }
    }
    
    //------------ se nao encontrar, chore ---------------//
    if (endComecoPessoa == NULL) {
        printf("\nPessoa nao encontrada.\n");
        *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer));
        return;
    }

    //------------ comeca a contagem do endereco do fim da pessoa ---------------//

    char *endFimDaPessoa = endComecoPessoa;

    endFimDaPessoa += sizeof(int); 
    endFimDaPessoa += *INT(endFimDaPessoa - sizeof(int)) + 1; 
    endFimDaPessoa += sizeof(int); 
    endFimDaPessoa += sizeof(int); 
    endFimDaPessoa += *INT(endFimDaPessoa - sizeof(int)) + 1; 
    
    //------------ encontrado o endereco do fim da pessoa ---------------//


    //------------ ponteiro pro final do buffer pra ajudar nos calcs ---------------//
    char *endOfAllData;
    getUltimoEndereco(&endOfAllData, pBuffer); 

    //------------ cuidar se nao vai explodir ao remover algo maior que o buffer ---------------//
    if ((size_t)(endOfAllData - endFimDaPessoa) > 0) {
        //------------ no inicio da pessoa, insere o final dela ---------------//
        memmove(endComecoPessoa, endFimDaPessoa, (size_t)(endOfAllData - endFimDaPessoa));
    }
    

    //---- decrementa OFICIALMENTE a pessoa da lista e recalcula o tamanho do buffer --------//
    (QNT_P(*pBuffer))--; 

    TAM_BUFFER_VAL(*pBuffer) = BASE_INICIAL; 
    setBufferTamanho(pBuffer); 

    //---- oficialmente "chuta" a pessoa da memoria --------//
    *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer));

    printf("\nPessoa removida com sucesso.\n");
}

void buscaPessoa( void ** pBuffer ){

    if(QNT_P(*pBuffer) == 0){
        printf("\nNao ha usuarios para pesquisar");
        return;
    }

    *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer) + sizeof(char) * 50 );
    char * nomeSearch;
    getUltimoEndereco(&nomeSearch, pBuffer);
    
    printf("\nNome do usuario a buscar: ");
    scanf(" %49[^\n]", nomeSearch);

    MENU_VAL(*pBuffer) = QNT_P(*pBuffer);

    char *cursor = CHAR(*pBuffer);

    cursor += BASE_INICIAL;

    for (; MENU_VAL(*pBuffer) > 0; ( MENU_VAL(*pBuffer) )--) {

        cursor += sizeof(int);

        if (strcmp(nomeSearch, cursor) == 0){

            printf("\n==============-  Pessoa encontrada  -===============\n");
            printf("Nome: %s\n", cursor);

            cursor += *INT(cursor - sizeof(int)) + 1;

            
            printf("Idade: %d\n", *INT(cursor));
            

            cursor += sizeof(int) * 2;

            printf("e-mail: %s\n", cursor);

            cursor += *INT(cursor - sizeof(int)) + 1;

            printf("======================================================================\n");

            *pBuffer = realloc(*pBuffer, TAM_BUFFER_VAL(*pBuffer));
            return;

        }


        cursor += *INT(cursor - sizeof(int)) + 1;
        cursor += sizeof(int) * 2;
        cursor += *INT(cursor - sizeof(int)) + 1;

    }


    printf("\nNao foi possivel encontrar a pessoa\n");
    
}

void listaPessoas( void ** pBuffer ){


    //---------------------- Se nao tem ninguem, nao tem ninguem... ----------------------//
    if( QNT_P(*pBuffer) == 0 ){
        printf("Sem pessoas na lista.\n");
        return;
    }


    //------------ usa o menu como contador pq ele nao serve pra muita coisa mesmo ---------------//
    MENU_VAL(*pBuffer) = QNT_P(*pBuffer);


    //------------ coloca o cursor no inicio do buffer + base inicial ---------------//
    char *cursor = CHAR(*pBuffer);

    cursor += BASE_INICIAL;

    //------------ itera por todos os campos (QNT_P) vezes ---------------//
    printf("======================================================================\n");
    for (; MENU_VAL(*pBuffer) > 0; ( MENU_VAL(*pBuffer) )--) {

        cursor += sizeof(int);

        printf("Nome: %s\n", cursor);

        cursor += *INT(cursor - sizeof(int)) + 1;

        
        printf("Idade: %d\n", *INT(cursor));
        

        cursor += sizeof(int) * 2;

        printf("e-mail: %s\n", cursor);

        cursor += *INT(cursor - sizeof(int)) + 1;

        printf("======================================================================\n");
    }

}

void getUltimoEndereco(char ** cursor, void ** pBuffer){
    

    MENU_VAL(*pBuffer) = QNT_P(*pBuffer);
    
    *cursor = CHAR(*pBuffer);
    *cursor += BASE_INICIAL;

    for (; MENU_VAL(*pBuffer) > 0; ( MENU_VAL(*pBuffer) )--) {

        //printf("\nTexto: %d\n", *(*cursor));
        *cursor += sizeof(int);
        //printf("\nTexto: %s\n", (*cursor));
        *cursor += *(INT(*cursor - sizeof(int))) + 1;
        //printf("\nTexto: %d\n", *(*cursor));
        *cursor += sizeof(int);
        //printf("\nTexto: %d\n", *(*cursor));
        *cursor += sizeof(int);
        //printf("\nTexto: %s\n", (*cursor));
        *cursor += *(INT(*cursor - sizeof(int))) + 1;
    }

    //printf("\nnao explodiu ainda\n");
}

void setBufferTamanho(void ** pBuffer){

/*     static int count = 0;

    //printf("\n------chamado %dx------\n", count);
    count++;
 */
    MENU_VAL(*pBuffer) = QNT_P(*pBuffer);
    
    char * cursor = CHAR(*pBuffer);
    cursor += BASE_INICIAL;

    //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));

    for (; MENU_VAL(*pBuffer) > 0; ( MENU_VAL(*pBuffer) )--) {

        //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));

        TAM_BUFFER_VAL(*pBuffer) += sizeof(int);
        cursor += sizeof(int);
        //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));

        TAM_BUFFER_VAL(*pBuffer) += *(INT(cursor - sizeof(int))) + 1;
        cursor += *(INT(cursor - sizeof(int))) + 1;
        //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));


        TAM_BUFFER_VAL(*pBuffer) += sizeof(int);
        cursor += sizeof(int);
        //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));

        TAM_BUFFER_VAL(*pBuffer) += sizeof(int);
        cursor += sizeof(int);
        //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));


        TAM_BUFFER_VAL(*pBuffer) += *(INT(cursor - sizeof(int))) + 1;
        cursor += *(INT(cursor - sizeof(int))) + 1;

        //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));

        //printf("\nsetBuffersize roda nx");
    }

    //printf("\nTamanho atual: %d", TAM_BUFFER_VAL(*pBuffer));

}