
# Projeto1_CriarTarefas

João Vitor Alves Escudeiro 24.224.010-9 \
Felipe Pellizzari Vaz Gabriel 24.224.005-9

O projeto é um gerenciador tarefas que permite ao usuário criar, listar, deletar e exportar tarefas. Cada tarefa possui uma prioridade, uma categoria e uma descrição. O programa armazena as tarefas em um arquivo binário, assim o usuário pode carregar e salvar os dados.


## Problemas corrigidos

- Foi corrigido um problema onde as strings armazenadas nas variáveis de categoria e descrição estavam ficando com uma quebra de linha no final. Isso acontecia porque a função fgets() inclui essa quebra ao pressionar Enter. Foi resolvido adicionando um código que remove essa quebra de linha sempre que a entrada do usuário é armazenada.

- Foi adicionado limites na prioridade. Antes, o usuário poderia inserir qualquer número, mas a prioridade deveria estar entre 1 e 10. Foi feito um loop que impede valores inválidos e informa o usuário caso ele digite algo fora do intervalo correto.

- Foi feito um tratamento de erros na função main(). O programa agora verifica se a lista de tarefas foi carregada corretamente. Se houver falha ao carregar ou salvar as tarefas, o código imprime mensagens de erro.

- Os tamanhos da categoria e descrição estavam definidos diretamente dentro do código, o que poderia dificultar futuras modificações. Para corrigir isso, foram criadas constantes com #define, permitindo que os tamanhos sejam ajustados de forma mais simples.


## Funções implementadas

- A função listarTarefas() foi modificada para permitir que o usuário filtre as tarefas por categoria. Agora, ao listar as tarefas, o programa solicita que o usuário digite uma categoria. Se o usuário inserir uma categoria existente, apenas as tarefas correspondentes serão exibidas, se deixar a entrada vazia, todas as tarefas serão listadas. Para capturar essa entrada, foram usados fgets em vez de scanf, porque ele deixa capturar strings com espaços e detectar quando o usuário apenas pressiona enter.

- Foi adicionada a função exportarTarefas(), que nos deixa salvar as tarefas em um arquivo de texto. O usuário informa o nome do arquivo e pode escolher exportar todas as tarefas ou apenas de uma categoria específica. Para isso, foi usado fopen no modo de escrita ("w") e percorrendo a lista de tarefas, salvando apenas aquelas que correspondem à categoria escolhida.

- O programa carrega e salva as tarefas em um arquivo binário usando as funções carregarTarefas() e salvarTarefas(). A função carregarTarefas() abre o arquivo no modo "rb" (leitura binária) e carrega os dados na estrutura de lista de tarefas. Se o arquivo não existir, a lista começa vazia. A função salvarTarefas() abre o arquivo no modo "wb" (escrita binária) e grava a lista de tarefas nele.


## Forma de compilação e execução do código

- Para compilar o código utilize ```gcc -o projeto main.c projeto.c projeto.h``` no terminal.

- Para executar o projeto no terminal utilize ```./projeto.exe``` após a compilação.