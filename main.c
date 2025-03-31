#include "projeto.h"
#include "stdio.h"
#include "stdlib.h"

int main(){
ListaDeTarefas lt;

char arquivo[] = "tarefas.bin";
int codigo, opcao;

codigo=carregarTarefas(&lt, arquivo);

if (codigo !=0){
printf("Lista de tarefas não carregada\n");
lt.qtd=0;
}

do{
exibeMenu();
scanf("%d", &opcao);

if(opcao == 0){}
else if(opcao == 1){
    codigo=criarTarefa(&lt);
    if (codigo ==1 )
    printf("Erro ao criar tarefa: Sem espaço disponível\n");
    }
else if(opcao == 2){
    codigo=deletarTarefa(&lt);
    if (codigo ==1 )
    printf("Erro ao deletar tarefa: não existem tarefas para deletar\n");
else if(codigo ==2)
    printf("Erro ao deletar tarefa: posicão inválida\n");
}
else if(opcao == 3){
    codigo=listarTarefas(&lt);
   if (codigo ==2)
   printf("Erro ao listar tarefas: não existem tarefas para serem listadas\n");
}
else if (opcao == 4) {
    exportarTarefas(&lt);
}
else {
	printf("Opção inválida\n");
}
}while (opcao != 0);

codigo=salvarTarefas(&lt,arquivo);
if(codigo ==1)
printf("Erro ao salvar tarefas em arquivo\n");


system ("pause");

}
