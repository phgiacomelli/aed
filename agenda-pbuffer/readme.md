# Paulo Henrique Anesi Giacomelli - M2

## Agenda pBuffer

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
| int | size_t | char[50] | char[50] | [lista de pessoas] |

| operação | tamanhoListaDePessoasEmBytes | nomeTemp | emailTemp | listaDePessoas |

