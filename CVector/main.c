#include <stdio.h>

#define CVECTOR_IMPLEMENTATIONS
#include "cvector.h"

int main ( int argc, char ** argv ) {
    (void) argc; (void) argv;

    cvector cv = cv_create ( sizeof ( int ) );

    for ( int i = 0; i < 10; i++ ) {
        cv_emplace_back ( &cv, &i );
    }

    for ( int i = 0; i < (int)cv_size ( &cv ); i++ ) {
        printf ( "%d ", *(int*) cv_at ( &cv, (size_t)i ));
    }
    puts ( "" );
    int value = 9;
    printf ( "%d is in vector : %s\n", value,
            cv_contains ( &cv, &value ) ? "True" : "False" );
    value = 12;
    printf ( "%d is in vector : %s\n", value,
            cv_contains ( &cv, &value ) ? "True" : "False" );

    cv_destroy ( &cv );

    return 0;
}
