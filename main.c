#include <stdio.h>
#include <string.h>

#include "StringUtils.h"

int	strncmp_prefix( const void *inS1, size_t inN, const char *inPrefix )
{
    const unsigned char *		s1;
    const unsigned char *		s2;
    int							c1;
    int							c2;

    s1 = (const unsigned char *) inS1;
    s2 = (const unsigned char *) inPrefix;
    while( inN-- > 0 )
    {
        c1 = *s1++;
        c2 = *s2++;
        if( c2 == 0 ) return(  0 );
        if( c1 < c2 ) return( -1 );
        if( c1 > c2 ) return(  1 );
    }
    if( *s2 != 0 ) return( -1 );
    return( 0 );
}

int main() {
    printf("Hello, World!\n");

    const char * value = "1234567890";
    const char * prefix = "123";

    if ( strncmp_prefix(value, 4, prefix) == 0 )
    {
        printf("same\n");
    }

    return 0;
}
