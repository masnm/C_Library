#include <stdio.h>
#include <stdint.h>

#include "cstack.h"

void mprint ( void* v )
{
	printf ( "%d ", *(int*)v );
}

int main ( int argc, char** argv )
{
	cstack cst = cstack_create ( sizeof(int) );
	printf ( "\n\n\n\n\n" );
	for ( int i = 0 ; i < 20 ; ++i ) {
		cstack_push ( &cst, &i );
		cstack_print ( &cst, mprint );
	}
	printf ( "\n\n\n\n\n" );
	while ( !cstack_empty ( &cst ) ) {
		cstack_pop ( &cst );
		cstack_print ( &cst, mprint );
	}
	cstack_destroy ( &cst );

	return 0;
}
