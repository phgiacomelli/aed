#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_SIZE ( sizeof( char ) * 50 )
#define BUFFER_INITIAL_SIZE ( sizeof( int ) + sizeof( size_t ) + STR_MAX_SIZE * 2 )
// choice, peopleDataSize, tempName, tempEmail
// int, size_t, char[50], char[50]

void  Menu( void* pBuffer );
void* GetPersonByEmail( void* pBuffer );
void  ClearStdinBuffer( void );
void  AddPerson( void** pBuffer );
void  PrintPerson( void* pBuffer );
void  ListPeople( void* pBuffer );
void  DeletePerson( void** pBuffer );

int main() {
	void* pBuffer = malloc( BUFFER_INITIAL_SIZE );

	if( !pBuffer ) {
		printf( "Memória insuficiente!\n" );
		return 1;
	}

	memset( pBuffer, 0, BUFFER_INITIAL_SIZE );

	while( 1 ) {
		int* choice = ( int* )pBuffer;

		if( *choice == 5 )
			break;

		Menu( pBuffer );

		switch( *choice ) {
		case 1:
			printf( "\n---[ 1. ADICIONAR PESSOA ]---\n" );
			AddPerson( &pBuffer );
			break;
		case 2:
			printf( "\n---[ 2. REMOVER PESSOA ]---\n" );
			DeletePerson( &pBuffer );
			break;
		case 3:
			printf( "\n---[ 3. BUSCAR PESSOA POR EMAIL ]---\n" );
			PrintPerson( pBuffer );
			break;
		case 4:
			printf( "\n---[ 4. LISTAR TODAS AS PESSOAS ]---\n" );
			ListPeople( pBuffer );
			break;
		case 5:
			printf( "\nSaindo da agenda... Até logo!\n\n" );
			break;
		}
	}

	free( pBuffer );
	return 0;
}

void Menu( void* pBuffer ) {
	int* choicePtr = ( int* )pBuffer;

	do {
		printf( "\n" );
		printf( "╔════════════════════════╗\n" );
		printf( "║     Agenda pBuffer     ║\n" );
		printf( "╠════════════════════════╣\n" );
		printf( "║ 1 ▸ Adicionar Pessoa   ║\n" );
		printf( "║ 2 ▸ Remover Pessoa     ║\n" );
		printf( "║ 3 ▸ Buscar Pessoa      ║\n" );
		printf( "║ 4 ▸ Listar Todas       ║\n" );
		printf( "║ 5 ▸ Sair               ║\n" );
		printf( "╚════════════════════════╝\n" );
		printf( "Escolha uma opção: " );
		scanf( "%d", choicePtr );
	} while( *choicePtr < 1 || *choicePtr > 5 );
	getchar();
}

void ClearStdinBuffer() {
	while( 1 ) {
		switch( getchar() ) {
		case '\n':
		case EOF:
			return;
		}
	}
}

void* GetPersonByEmail( void* pBuffer ) {
	size_t* peopleDataSize = ( size_t* )( ( char* )pBuffer + sizeof( int ) );

	if( !*peopleDataSize )
		return NULL;

	char* tempEmail = ( char* )( ( char* )pBuffer + BUFFER_INITIAL_SIZE - STR_MAX_SIZE );

	void* personPtr = ( char* )pBuffer + BUFFER_INITIAL_SIZE;
	void* peopleEnd = ( char* )personPtr + *peopleDataSize;

	while( personPtr < peopleEnd ) {
		char* currentName  = ( char* )( ( char* )personPtr + sizeof( int ) );
		char* currentEmail = ( char* )( currentName + strlen( currentName ) + 1 );

		if( strcmp( currentEmail, tempEmail ) == 0 )
			return personPtr;

		personPtr = ( void* )( ( char* )currentEmail + strlen( currentEmail ) + 1 );
	}

	return NULL;
}

void AddPerson( void** pBuffer ) {
	char* tempName	= ( char* )( ( char* )*pBuffer + sizeof( int ) + sizeof( size_t ) );
	char* tempEmail = ( char* )( tempName + STR_MAX_SIZE );

	printf( "Nome: " );
	scanf( " %49[^\n]", tempName );
	ClearStdinBuffer();

	printf( "Email: " );
	scanf( " %49[^\n]", tempEmail );
	ClearStdinBuffer();

	if( GetPersonByEmail( *pBuffer ) != NULL ) {
		printf( "Já existe uma pessoa com este email!" );
		memset( tempName, 0, STR_MAX_SIZE * 2 );
		return;
	}

	size_t* peopleDataSize = ( size_t* )( ( char* )*pBuffer + sizeof( int ) );
	// pBuffer = tamanho_fixo + tamanho_pessoas + 1 int + (nome+\0) + (email+\0)
	void* tempBuffer = realloc( *pBuffer, BUFFER_INITIAL_SIZE + *peopleDataSize + sizeof( int ) + ( strlen( tempName ) + 1 ) + ( strlen( tempEmail ) + 1 ) );

	if( !tempBuffer ) {
		printf( "Memória insuficiente!" );
		return;
	}

	*pBuffer = tempBuffer;

	peopleDataSize = ( size_t* )( ( char* )*pBuffer + sizeof( int ) );
	tempName	   = ( char* )( ( char* )*pBuffer + sizeof( int ) + sizeof( size_t ) );
	tempEmail	   = ( char* )( tempName + STR_MAX_SIZE );

	int*  age	= ( int* )( ( char* )*pBuffer + BUFFER_INITIAL_SIZE + *peopleDataSize );
	char* name	= ( char* )( ( char* )age + sizeof( int ) );
	char* email = ( char* )( name + ( ( strlen( tempName ) + 1 ) * sizeof( char ) ) );

	strcpy( name, tempName );
	strcpy( email, tempEmail );

	printf( "Idade: " );
	scanf( "%d", age );
	ClearStdinBuffer();

	*peopleDataSize += sizeof( int ) + ( strlen( tempName ) + 1 ) + ( strlen( tempEmail ) + 1 );

	memset( tempName, 0, STR_MAX_SIZE * 2 );
}

void PrintPerson( void* pBuffer ) {
	size_t* peopleDataSize = ( size_t* )( ( char* )pBuffer + sizeof( int ) );
	char*	tempName	   = ( char* )( ( char* )peopleDataSize + sizeof( size_t ) );
	char*	tempEmail	   = ( char* )( tempName + STR_MAX_SIZE );
	printf( "\nEmail: " );
	scanf( " %49[^\n]", tempEmail );
	ClearStdinBuffer();

	void* personPtr = GetPersonByEmail( pBuffer );

	if( personPtr == NULL ) {
		printf( "\nPessoa não encontrada!\n" );
		memset( tempEmail, 0, STR_MAX_SIZE );
		return;
	}

	int*  age	= ( int* )personPtr;
	char* name	= ( char* )( ( char* )personPtr + sizeof( int ) );
	char* email = ( char* )( name + strlen( name ) + 1 );

	printf( "\nNome: %s\n", name );
	printf( "Email: %s\n", email );
	printf( "Idade: %d\n", *age );

	memset( tempEmail, 0, STR_MAX_SIZE );
}

void ListPeople( void* pBuffer ) {
	size_t* peopleDataSize = ( size_t* )( ( char* )pBuffer + sizeof( int ) );

	if( !*peopleDataSize ) {
		printf( "\nNão há nenhuma pessoa na lista!\n" );
		return;
	}

	void* personPtr = ( char* )pBuffer + BUFFER_INITIAL_SIZE;
	void* peopleEnd = ( char* )personPtr + *peopleDataSize;

	while( personPtr < peopleEnd ) {
		int*  age	= ( int* )personPtr;
		char* name	= ( char* )( ( char* )personPtr + sizeof( int ) );
		char* email = ( char* )( name + strlen( name ) + 1 );

		printf( "\nNome: %s\n", name );
		printf( "Email: %s\n", email );
		printf( "Idade: %d\n", *age );

		personPtr = ( void* )( ( char* )email + strlen( email ) + 1 );
	}
}

void DeletePerson( void** pBuffer ) {
	size_t* peopleDataSize = ( size_t* )( ( char* )*pBuffer + sizeof( int ) );
	char*	tempName	   = ( char* )( ( char* )peopleDataSize + sizeof( size_t ) ); // Não utilizado de fato, apenas para o calculo do tempEmail
	char*	tempEmail	   = ( char* )( tempName + STR_MAX_SIZE );

	printf( "\nEmail: " );
	scanf( " %49[^\n]", tempEmail );
	ClearStdinBuffer();

	void* personPtr = GetPersonByEmail( *pBuffer );

	if( personPtr == NULL ) {
		printf( "\nPessoa não encontrada!\n" );
		memset( tempEmail, 0, STR_MAX_SIZE );
		return;
	}
	char* name	= ( char* )( ( char* )personPtr + sizeof( int ) );
	char* email = ( char* )( name + strlen( name ) + 1 );

	// ptr para o inicio dos dados da proxima pessoa
	void* nextPerson = ( void* )( ( char* )email + strlen( email ) + 1 );

	// final da lista de pessoas
	void* peopleEnd = ( void* )( ( char* )*pBuffer + BUFFER_INITIAL_SIZE + *peopleDataSize );

	*peopleDataSize -= ( sizeof( int ) + ( strlen( name ) + 1 ) + ( strlen( email ) + 1 ) );

	// verificamos, para nao mover "pra frente"
	if( nextPerson < peopleEnd ) {
		memmove( personPtr, nextPerson, ( char* )peopleEnd - ( char* )nextPerson );
	}
	// memmove vai mover x bytes (3o param.) da memoria, a partir do 2o elemento, para a posicao do primeiro elemento
	//  ou seja, pega do nextPerson até o final da lista, e move tudo para tras, ate chegar na posicao de personPtr
	//  o que equivale a trazer os dados para tras, sobrescrevendo a pessoa que deveria ser removida

	memset( tempEmail, 0, STR_MAX_SIZE );

	void* tempBuffer = realloc( *pBuffer, BUFFER_INITIAL_SIZE + *peopleDataSize );
	if( !tempBuffer ) {
		printf( "Memória insuficiente!" );
		return;
	}

	*pBuffer = tempBuffer;

	printf( "\nPessoa removida!\n" );
}
