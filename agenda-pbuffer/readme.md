# Agenda pBuffer

Faça uma agenda com o seguinte menu:    
1- Adicionar Pessoa (Nome, Idade, email)  
2- Remover Pessoa  
3- Buscar Pessoa  
4- Listar todos  
5- Sair  
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.
 
**Regras:**

- Nenhuma variável pode ser declarada em todo o programa, somente ponteiros.   
- Todos os dados do programa devem ser guardados dentro do pBuffer. Nem mesmo como parâmetro de função. 
- Não pode usar struct em todo o programa.
- Só pode utilizar ponteiros que apontam para dentro do pBuffer.  
  
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)  

**Ideia:**  
o buffer vai ser composto por:   
| int | int | int | char[50] | char[50] | [lista de pessoas] |

| operação | qtdPessoas | idadeTemp | nomeTemp |  | emailTemp | listaDePessoas

Utilizei esta abordagem pois acredito ser menos sucetível a erros. Primeiramente lemos os valores de uma nova pessoa, e adicionamos nas variáveis temporárias. Entao adicionamos na lista de pessoas, apenas se essa pessoa ainda nao existe na lista. Neste caso nao precisamos realocar a memória sem antes verificar se a pessoa já nao esta na lista.
