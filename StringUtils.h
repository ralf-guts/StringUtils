//
// Created by guts on 7/8/21.
//

#ifndef STRINGUTILS_STRINGUTILS_H
#define STRINGUTILS_STRINGUTILS_H

//---------------------------------------------------------------------------------------------------------------------------
/*!	@function	append_decimal_string
	@abstract	Appends a decimal string to a buffer.

	@param		X		Unsigned decimal number to convert to a string. It will be modified by this macro.
	@param		DST		Pointer to write string to. Will point to end of string on return.

	@discussion

	Example usage:

	char		str[ 32 ];
	char *		dst;
	int			x;

	strcpy( str, "test" );
	dst = str + 4;

	x = 1234;
	append_decimal_string( x, dst );
	strcpy( dst, "end" );

	... str is "test1234end".

    notes:
        do
        {
            // X % 10 to get last single number, e.g. X = 1234, X % 10 = 4
            // char '0' ascii is 48, a single number convert to char
            // *_adsPtr++, * priority > ++, step1 *_adsPtr = '4', step2 _adsPtr++
            *_adsPtr++ = (char)( '0' + ( (X) % 10 ) );

            // X / 10 to remove last single number, e.g. X = 1234, X / 10 = 123
            (X) /= 10;

        }	while( (X) > 0 );
*/
#define	append_decimal_string( X, DST ) \
	do \
	{ \
		char		_adsBuf[ 32 ]; \
		char *		_adsPtr; \
		\
		_adsPtr = _adsBuf; \
		do \
		{ \
			*_adsPtr++ = (char)( '0' + ( (X) % 10 ) ); \
			(X) /= 10; \
		\
		}	while( (X) > 0 ); \
 		\
		while( _adsPtr > _adsBuf ) \
		{ \
			*(DST)++ = *( --_adsPtr ); \
		} \
		\
	}	while( 0 )

#endif //STRINGUTILS_STRINGUTILS_H

int	strcmp_prefix( const char *inStr, const char *inPrefix );

char * strnstr(const char *s, const char *find, size_t slen);