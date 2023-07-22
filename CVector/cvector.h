#ifndef __CVECTOR_H__
#define __CVECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

typedef struct {
    char * data;
    size_t size, capacity, elem_size;
} cvector ;

cvector cv_create ( size_t size );
bool allocate_if_necessary ( cvector * cv );
size_t cv_size ( cvector * cv );
bool cv_emplace_back ( cvector * cv, void * elem );
void* cv_at ( cvector * cv, size_t index );
void cv_destroy ( cvector * cv );

#ifdef CVECTOR_IMPLEMENTATIONS

cvector cv_create ( size_t size ) {
    cvector cv = {
        .data = NULL,
        .size = 0,
        .capacity = 0,
        .elem_size = size
    };
    return cv;
}

bool allocate_if_necessary ( cvector * cv ) {
    if ( cv->size == cv->capacity ) {
        cv->capacity = (cv->capacity == 0 ? 1 : cv->capacity * 2);
        cv->data = (char*) realloc ( cv->data, cv->capacity * cv->elem_size );
        if ( errno == ENOMEM ) {
            return false;
        }
    }
    return true;
}

size_t cv_size ( cvector * cv ) {
    return cv->size;
}

bool cv_emplace_back ( cvector * cv, void * elem ) {
    if ( !allocate_if_necessary ( cv ) ) return false;
    memcpy ( cv->data + ( cv->size * cv->elem_size ), elem, cv->elem_size );
    cv->size++;
    return true;
}

void* cv_at ( cvector * cv, size_t index ) {
    if ( index > cv->size ) {
        fprintf ( stderr, "Indexing out of size\n" );
        return NULL;
    }
    return cv->data + ( index * cv->elem_size );
}

void cv_destroy ( cvector * cv ) {
    if ( cv->data != NULL )
        free ( cv->data );
    cv->data = NULL;
    cv->size = 0;
    cv->capacity = 0;
    cv->elem_size = 0;
}
#endif // CVECTOR_IMPLEMENTATIONS

#endif // __CVECTOR_H__
