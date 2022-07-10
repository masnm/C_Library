#include <stdio.h>
#include <stdint.h>

#include "cvector.h"

void plus ( void* ref )
{
	*(int*)ref += 1;
}

void print ( void* ref )
{
	printf ( "%d ", *(int*)ref );
}

int main ( int argc, char** argv )
{
	cvector vec = cvector_create ( sizeof(int) );
	cvector_reserve ( &vec, 16 );
	for ( int i = 0 ; i < 20 ; ++i ) {
		cvector_emplace_back ( &vec, &i );
		printf ( "%d %zd\n", i, vec.capacity );
	}
	cvector_for_each ( &vec, print );
	printf ( "\n" );
	cvector_for_each ( &vec, plus );
	cvector_for_each ( &vec, print );
	printf ( "\n" );
	// void *elem;
	// foreach_element ( vec, elem ) {
	// 	printf ( "%d\n", *(int*)elem );
	// }
	printf ( "at: %d\n", *(int*)cvector_at ( &vec, 5 ) );
	// while ( !cvector_empty(&vec) ) cvector_pop_back ( &vec );
	printf ( "front: %d\n", *(int*)cvector_front ( &vec ) );
	printf ( "back: %d\n", *(int*)cvector_back ( &vec ) );
	printf ( "ref: %p\n", vec.ref );
	printf ( "data: %p\n", cvector_data ( &vec ) );
	printf ( "ref: %p\n", vec.ref );
	cvector_destroy ( &vec );

	return 0;
}
