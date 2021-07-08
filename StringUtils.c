//
// Created by guts on 7/8/21.
//

#include <stddef.h>
#include <string.h>

#include "StringUtils.h"

//===========================================================================================================================
//	strcmp_prefix
//
//	Like strcmp, but only compares to the end of the prefix string.
//===========================================================================================================================

int	strcmp_prefix( const char *inStr, const char *inPrefix )
{
    int		c1;
    int		c2;

    for( ;; )
    {
        c1 = *( (const unsigned char *) inStr );
        c2 = *( (const unsigned char *) inPrefix );
        if( c2 == '\0' ) break;
        if( c1 < c2 )    return( -1 );
        if( c1 > c2 )    return(  1 );

        ++inStr;
        ++inPrefix;
    }
    return( 0 );
}

//===========================================================================================================================
//	strnstr
//
//	From FreeBSD: Find the first occurrence of find in s, where the search is limited to the first slen characters of s.
//===========================================================================================================================

char * strnstr(const char *s, const char *find, size_t slen)
{
    char c, sc;
    size_t len;

    if ((c = *find++) != '\0') {
        len = strlen(find);
        do {
            do {
                if (slen-- < 1 || (sc = *s++) == '\0')
                    return (NULL);
            } while (sc != c);
            if (len > slen)
                return (NULL);
        } while (strncmp(s, find, len) != 0);
        s--;
    }
    return ((char *)s);
}