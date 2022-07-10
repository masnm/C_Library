#include <stdio.h>
#include <stdint.h>

#include "cqueue.h"

void mprint ( void* v )
{
	printf ( "%d ", *(int*)v );
}

int main ( int argc, char** argv )
{
	cqueue que = cqueue_create ( sizeof(int) );
	cqueue_reserve ( &que, (size_t)16 );
	printf ( "\n\n\n\n\n" );
	for ( int i = 0 ; i < 20 ; ++i ) {
		cqueue_push ( &que, &i );
		//cqueue_print ( &que, mprint );
	}
	// cqueue_make_empty ( &que );
	cqueue_print ( &que, mprint );
	printf ( "\n\n\n\n\n" );
	while ( !cqueue_empty ( &que ) ) {
		cqueue_pop ( &que );
		cqueue_print ( &que, mprint );
	}
	// void *elem;
	// foreach_element ( vec, elem ) {
	// 	printf ( "%d\n", *(int*)elem );
	// }
	// printf ( "at: %d\n", *(int*)cvector_at ( &vec, 5 ) );
	// // while ( !cvector_empty(&vec) ) cvector_pop_back ( &vec );
	// printf ( "front: %d\n", *(int*)cvector_front ( &vec ) );
	// printf ( "back: %d\n", *(int*)cvector_back ( &vec ) );
	// printf ( "ref: %p\n", vec.ref );
	// printf ( "data: %p\n", cvector_data ( &vec ) );
	// printf ( "ref: %p\n", vec.ref );
	// cvector_destroy ( &vec );

	return 0;
}
