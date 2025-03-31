#include "projeto.h"
#include "stdio.h"
#include "string.h"

int criarTarefa(ListaDeTarefas *lt){
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;
    
	Tarefa *t=&lt->tarefas[lt->qtd];

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);
    getchar();

    printf("Entre com a categoria da tarefa: ");
    scanf(" %[^\n]", t->categoria);

    printf("Entre com a descricao da tarefa: ");
    scanf(" %[^\n]", t->descricao);

    lt->qtd++;

    return 0;
}

int deletarTarefa(ListaDeTarefas *lt){
   if (lt->qtd == 0)
   return 1;
   
   int pos;
   printf("Entre com a posicao que deseja deletar: ");
   scanf("%d", &pos);
   
   if (pos <0 || pos >= lt->qtd)
   return 2;
   
   for (; pos<lt->qtd-1; pos++){
   	lt->tarefas[pos].prioridade=lt->tarefas[pos+1].prioridade; 
	   strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao); 
	   strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);

   }
   
    lt->qtd--;
	return 0;
}

int listarTarefas(ListaDeTarefas *lt){
	if(lt->qtd == 0){
	    printf("Não existem tarefas para serem listadas.");
        return 1;
    }
	
    char categoria[100];
    printf("Digite a categoria que deseja listar (vazio para listar todas): ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);

    size_t len = strlen(categoria);
    if (len > 0 && categoria[len - 1] == '\n') {
        categoria[len - 1] = '\0';
    }

    int i;
    int encontrou = 0;
    for (i = 0; i < lt->qtd; i++) {
        if (strlen(categoria) == 0 || strcmp(lt->tarefas[i].categoria, categoria) == 0) {
            printf("Pos: %d \t Prioridade: %d \t Categoria: %s\n", i,
                   lt->tarefas[i].prioridade, lt->tarefas[i].categoria);
            printf("Descricao: %s\n", lt->tarefas[i].descricao);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Não existe nenhuma tarefa na categoria digitada.\n");
    }

    return 0;
}

int carregarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
   return 1;
   
   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int salvarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "wb");
   if (fp == NULL){
    perror("Erro ao abrir o arquivo para escrita");
    return 1;
   }
   
   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int exportarTarefas(ListaDeTarefas *lt) {
    if (lt->qtd == 0) {
        printf("Erro: não existem tarefas para serem exportadas.\n");
        return 1;
    }

    char nomeArquivo[100];
    printf("Digite o nome do arquivo para exportar: ");
    scanf("%s", nomeArquivo);

    if (strstr(nomeArquivo, ".txt") == NULL) {
        strcat(nomeArquivo, ".txt");
    }

    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo para escrita.");
        return 1;
    }

    char categoria[100];
    printf("Digite a categoria que deseja exportar (vazio para exportar todas): ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    
    size_t len = strlen(categoria);
    if (len > 0 && categoria[len - 1] == '\n') {
        categoria[len - 1] = '\0';
    }

    int encontrou = 0;
    for (int i = 0; i < lt->qtd; i++) {
        if (strlen(categoria) == 0 || strcmp(lt->tarefas[i].categoria, categoria) == 0) {
            fprintf(fp, "Prioridade: %d, Categoria: %s, Descricao: %s\n",
                    lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].descricao);
            encontrou = 1;
        }
    }

    fclose(fp);
    
    if (!encontrou) {
        printf("Nenhuma tarefa encontrada para a categoria informada, o arquivo está vazio.\n");
    } else {
        printf("Tarefas exportadas para %s\n", nomeArquivo);
    }

    return 0;
}

void exibeMenu(){
    printf("menu\n");
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
	printf("3. Listar tarefa\n");
    printf("4. Exportar tarefas\n");
	printf("0. Sair\n");
	}

