/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:34:58 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/05 10:26:27 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>

# define BUFF_SIZE 32

/*
** libft is a School Library created by Sibonelo Nkosi to conduct some in-depth
**	and challenging Math & Computational calculations and operations.
**	The functions contained herein, will be recreations of the standard
**	C-library, 'ctype.h', 'string.h' & 'math.h' library contained within C.
**
** There will be additional functions contained therein, including structs and
**	macros. The purpose of these is for graphics rendering, algorithm opti-
**	mization, binary tree traversals and (but not limited to) sorting.
** Included in all this are the standard functions of reading user input, store
**	the input and to manipulate the input. Thus other string handling and
**	manipulation and verification functions exist within.
** Lexing & Parsing will be handled by a main, that will call functions within.
**
**
** ************************************************************************ *
**																			*
**									MACROS									*
**																			*
** ************************************************************************ *
**
** The Natural number e
*/
# define M_E 2.78182818284590452354
# define M_LOG2E 1.4426950408889634074
# define M_LOG10E 0.43429448190325182765
# define M_LN2 0.69314718055994530942
# define M_LN10 2.30258509299404568402

/*
** PI
** (1) PI		(2) 0.5 * PI 	(3) 0.25 * PI
** (4) 1 / PI	(5) 2 / PI		(6) SQRT(PI)
*/
# define M_PI 3.14159265358979323846
# define M_PI_2 1.57079632679489661923
# define M_PI_4 0.78539816339744830962
# define M_1_PI 0.31830988618379067154
# define M_2_PI 0.63661977236758134308
# define M_2_SQRTPI 1.12837916709551257390

/*
** SQRT
** (1) SQRT(2)	(2) SQRT(0.5)
*/
# define M_SQRT2 1.41421356237309504880
# define M_SQRT1_2 0.70710678118654752440

/*
** ************************************************************************ *
**									MACROS									*
** ************************************************************************	*
*/
# define FLAGS "hlLjz#0-+ ."
# define PARSE "bBcCdDfFioOpPsSuUxX\%"

/*
** ************************************************************************ *
**									COLOURS									*
** ************************************************************************	*
*/

# define M_RESET	"\033[0m"
# define M_RED	"\033[31m"
# define M_GREEN	"\033[32m"
# define M_YELLOW	"\033[33m"
# define M_BLUE	"\033[34m"
# define M_MAGENTA "\033[35m"
# define M_CYAN	"\033[36m"

/*
** ************************************************************************ *
**																			*
**									VECTORS									*
**																			*
** ************************************************************************ *
*/

typedef	struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

/*
** vector_add - A function to perform basic addition of two vectors in the form
**		of (v1 + v2)
*/
t_vector		vector_add(t_vector v1, t_vector v2);

/*
** vector_subtract - A function to perform basic subtraction between two vectors
**		in the form of (v1 - v2)
*/
t_vector		vector_subtract(t_vector v1, t_vector v2);

/*
** vector_multiply - A basic function to perform basic multiplication between
**		a vector v1 and a value of type double. This is not the cross product.
**		This function returns a vector of (x*value),(y*value) & (z*value).
*/
void			vector_multiply(t_vector v1, double multiple);

/*
** vector_divide - This is a basic function to divide vector v1 by a value of
**		type double. It returns x/value, y/value & z/value.
*/
void			vector_divide(t_vector v1, double divisor);

/*
** vector_magnitude - This is a basic function to obtain the magnitude of a
**		vector, returning a value of type double.
*/
double			vector_magnitude(t_vector v1);

/*
** ************************************************************************ *
**																			*
**								 	LISTS									*
**																			*
** ************************************************************************ *
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** ************************************************************************	*
**									STRUCTURE								*
** ************************************************************************	*
*/
/*
** T_PRINTF - This structure holds all the variables that can either be turned
**		on or off regarding how to format the string that has been passed to it.
** FLAG_MINUS - If this flag is turned to 1. Then it means that the output
**		should be left-justified. The default is right justification.
** FLAG_PLUS - If this flag is turned to 1, it means prints a '+' ahead of the
**		number you wish to output. If it is -1, it means print a '-' ahead
**		of the number you wish to output.
** FLAG_SPACE
*/

typedef struct	s_printf
{
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			flag_hash;
	int			flag_zero;
	int			field_width;
	int			f_return;
	int			precision;
	int			prec_width;
	int			i;
	int			h;
	int			l;
	int			lc;
	int			j;
	int			z;
	char		convert;

}				t_printf;
/*
** More definitions on https://linux.die.net/man/3/vfprintf
*/

/*
** FT_PRINTF - writes the argument operands to standard output, formatted
**		according to the format operand. Format is a format string that is
**		composed of conversion specifications that convert and add the next
**		argument to the output. format can contain backslash-escape sequences.
**		Conversion specifications have the form:
** **********************************
**	%[flag][width][precision][char]	*
** **********************************
**	%FLAG is one of the following options:
**
**	'-'	- Left-justifies the field; default is right justification.
**
**	'+' - Always prefixes a signed value with a sign (+ or -).
**
**	' '/space - Reserves a character position at the start of the string for the
**		minus sign (for negative numbers) or a space (for positive numbers). If
**		both space and - appear as flags, the space flag is ignored.
**
**	'#' - Prefixes octal values with 0 and hexadecimal values with 0x or 0X.
**		For floating-point values, this causes the decimal point always to be
**		displayed even if no characters follow it.
**	'0' - Pads numeric values with leading zeros. If both 0 and - appear as
**		flags, the 0 flag is ignored.
**
**	%WIDTH is the minimum field width of the output field. If the converted
**		value is shorter than the minimum width, ft_printf pads it with spaces
**		or zeros.
**
**	%PRECISION - In a string, precision is the maximum number of bytes to be
**		printed from the string; in a number, the precision is the number of
**		digits to be printed to right of the decimal point in a floating-point
**		value. width or precision can be specified as *, in which case the value
**		is read from the next argument, which must be an integer.
**
**	%CHAR - Each field of the format specification is discussed in detail below.
**		If a percent sign (%) is followed by a character that has no meaning as
**		a format field, the behavior is undefined. One exception to this
**		behavior is %%. To print a percent-sign character, use %%.
**	The type characters and their meanings are given in the following table:
**	"%c"	character
**	"%d"	decimal (integer) number (base 10)
**	"%e"	exponential floating-point number
**	"%f"	floating-point number
**	"%i"	integer (base 10)
**	"%o"	octal number (base 8)
**	"%s"	a string of characters
**	"%u"	unsigned decimal (integer) number
**	"%x"	number in hexadecimal (base 16)
**	"%p"	pointer
**	"%%"	print a percent sign
**	"\%"	print a percent sign
*/

/*
** ************************************************************************ *
**																			*
**									CYTPE.H									*
**																			*
**							THIS IS THE CTYPE LIB							*
**																			*
** ************************************************************************	*
*/

/*
** FT_ISLOWER - Checks a char, input as an int, references the ascii table to
**		see if it is a valid lowercase char
*/
int				ft_islower(int c);

/*
** FT_ISUPPER - Checks a char, input as an int, references the ascii table to
**		see if it is a valid uppercase char
*/
int				ft_isupper(int c);

/*
** FT_ISALPHA - Checks a char, input as an int, references the ascii table to
**		see if it is a valid alphabet. It is the equivalent of
**		(ft_isupper(c) || ft_islower(c))
*/
int				ft_isalpha(int c);

/*
** FT_ISDIGIT - Checks a char, input as an int, references the ascii table to
**		see if it is a valid digit between 0 and 9.
*/
int				ft_isdigit(int c);

/*
** FT_ISALNUM - Checks a char, input as an int, references the ascii table to
**		see if it is a valid digit or letter of the alphabet. It is the
**		equivalent of (ft_isalpha(c) || ft_isdigit(c))
*/
int				ft_isalnum(int c);

/*
** FT_ISBLANK - Checks a char, input as an int, references the ascii table to
**		see if it is a blank space or a tab. It checks for 32 or 9.
*/
int				ft_isblank(int c);

/*
** FT_ISSPACE - Checks a char, input as an int, references the ascii table to
**		see if it is a space, '\f' up to the point of '\v'
*/
int				ft_isspace(int c);

/*
** FT_ISASCII - Checks whether the input is an unsigned char and a valid char
**		in terms of the ASCII table.
*/
int				ft_isascii(int c);

/*
** FT_ISGRAPH - Checks input and references ASCII table for printable
**		character sets excluding space.
*/
int				ft_isgraph(int c);

/*
** FT_ISPUNCT - This function checks whether a character is a punctuation char.
**		A punctuation character is a any graphic character (ft_isgraph)
**		that is not alphanumeric (!(ft_isalnum)). The function returns
**		(1) for true and (0) for false.
*/
int				ft_ispunct(int c);

/*
** FT_ISCNTRL - This function checks whether a character is a control character
**		that cannot be printed. It is the opposite of FT_ISPRINT. It
**		returns a 1 if it is true and a 0 if it is false.
*/
int				ft_iscntrl(int c);

/*
** FT_ISPRINT - Checks input and references ASCII table for printable
**		character sets including space.
*/
int				ft_isprint(int c);

/*
** FT_ISXDIGIT - Checks input and references as to whether it's a hexadecimal
**		digit i.e	0 1 2 3 4 5 6 7 8 9 A B C D E F
**										a b c d e f
*/
int				ft_isxdigit(int c);

/*
** FT_ISIMAX - This function will take an integer as an argument and return 1
**		if the integer is greater than or equal to 2147483647. It will
**		return 0, if it less.
*/
int				ft_isimax(int n);

/*
** FT_ISIMIN - This function will take an integer as an argument and return 1
**		if the integer is less than or equal to -2147483648. It will
**		return 0, if it is more.
*/
int				ft_isimin(int n);

/*
** FT_TOUPPER - This function coverts a lowercase letter to an uppercase let-
**		ter. The function will return the uppercase letter if it is successful,
**		or the original input if it fails.
*/
int				ft_toupper(int c);

/*
** FT_TOLOWER - This function converts an uppercase letter to a lowercase let-
**		ter. The function will return the lowercase letter if it is successful,
**		or the original input if it fails.
*/
int				ft_tolower(int c);

/*
** FT_TOCHAR - This function will take an integer as an argument and
**		return it as a char.
*/
char			ft_tochar(int n);

/*
** FT_TOSTR - This function will take a char as an argument and cast it
**		as a string of length one.
*/
char			*ft_tostr(char s[], char c);

/*
** FT_STR_IS_LOWERCASE - This function checks lexicographically, each character
**		in a given string to determine if it is lowercase. If the entire
**		string is lowercase, the function returns a 1. If one char is
**		not a lowercase letter. It will return a 0.
*/
int				ft_str_is_lowercase(char *str);

/*
** FT_STR_IS_UPPERCASE - This function checks lexicographically, each character
**		in a given string to determine if it is uppercase. If the entire
**		string is uppercase, the function will return a 1. If one char
**		is not uppercase, the function returns a 0.
*/
int				ft_str_is_uppercase(char *str);

/*
** FT_STR_IS_ALPHA - This function checks lexicographically if each current in
**		a given string is a letter of the alphabet. If the entire string
**		is of type alpha, the function will return a 1. If it is not of
**		type alphabet, it will return a 0.
*/
int				ft_str_is_alpha(char *str);

/*
** FT_STR_IS_NUMERIC - This function checks a string, one character at a time
**		to ensure that it consists of only digits between 0 and 9. The
**		function will return 1 if it is true. It will return 0 if the
**		string consists of characters other than digits.
*/
int				ft_str_is_numeric(char *str);

/*
** FT_STR_IS_XNUMERIC - This function checks a string, one character at a time
**		to ensure that it is a valid HEX number. The function will
**		return a 1 if every char in a string is a valid HEX digit. If
**		one char is not a HEX number, it will return 0.
*/
int				ft_str_is_xnumeric(char *str);

/*
** FT_STR_IS_ALNUM - This function checks a string, one character at a time
**		to ensure that it consists of only aplhanumeric characters.
**		If the string only consists of alphanumeric characters, it will
**		return a 1. If one character is not alphanumeric, it will return
**		a 0.
*/
int				ft_str_is_alnum(char *str);

/*
** FT_STR_IS_PRINTABLE - This function checks a string, one character at a time
**		to ensure that it consists of printable characters. If the
**		string consists of only printable characters, then it will
**		return a 1. If one character is not printable, then it will
**		return a 0.
*/
int				ft_str_is_printable(char *str);

/*
** ************************************************************************ *
**																			*
** 									STRING.H								*
**																			*
** ************************************************************************	*
*/

/*
** FT_MEMSET - This funtion writes len bytes of value c (converted to an
**		unsigned char) to the string b. The memset() function returns its
**		first argument
*/
void			*ft_memset(void *b, int c, size_t len);

/*
** FT_BZERO - This function writes zeroes to a byte string. It writes n
**		zeroed bytes to the string s. If n is zero, ft_bzero() does
**		nothing
*/
void			*ft_bzero(void *s, size_t n);

/*
** FT_MEMALLOC - This function allocates with malloc and returns a 'fresh'
**		memory area. The memory allocated is initialized to 0. If the
**		allocation fails, the function returns NULL.
*/
void			*ft_memalloc(size_t size);

/*
** FT_MEMDEL - This function takes as a parameter the address of a memory
**		area that needs to be freed with free, then puts the pointer to
**		NULL
*/
void			ft_memdel(void **ap);

/*
** FT_MEMCPY - This function will copy memory area. It copies n bytes from
**		memory area src to memory area dst. The ft_memcpy() function returns
**		the original value of dst.
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);

/*
** FT_MEMCCPY - This function will copy a byte string until it finds a char.
**		The memccpy() function copies bytes from src to dst. If the char c
**		occurs in the string src. The copy stops and a pointer is returned.
*/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
** FT_MEMMOVE - This function will copy a byte string. It takes len bytes
**		from src to dst. The strings may overlap. The function returns the
**		original value of dst.
*/
void			*ft_memmove(void *dst, const void *src, size_t len);

/*
** FT_MEMCHR - This function will locate the first occurence of c in string
**		s. The function returns a pointer to the byte located, or Null if no
**		such byte exists within n bytes.
*/
void			*ft_memchr(const void *s, int c, size_t n);

/*
** FT_MEMCMP - This function compares byte string s1 against s2. Both strings
**		are assumed to be n bytes long. The function returns zero if the two
**		strings are identical, otherwise it returns the difference. (S1 - S2)
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** FT_STRLEN - This function returns the length of the string input
*/
size_t			ft_strlen(const char *c);

/*
** FT_STRCPY - This function copies the source string and applies it to a
**		destination string, including the '\0' terminator char.
*/
char			*ft_strcpy(char *dst, const char *src);

/*
** FT_STRNCPY - This function copies at most len characters from src to dst.
**		If src is less than len char long, the remainder of dst is filled with
**		'\0' characters. Otherwise dst is not determined.
*/
char			*ft_strncpy(char *dst, const char *src, size_t len);

/*
** FT_STRLCPY - This function copies up to 'dstsize - 1' characters from the
**		string 'src' to 'dst', NUL-terminating the result if dstsize is
**		not 0. The function returns the total length of the string it
**		tried to create. For FT_STRLCPY(), this means the length of src.
**		IF: The return value is >= dstsize, the output string has been
**		truncated.
*/
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** FT_STRCAT - This function will append a copy of a null terminated string
**		s2 to the end of the null terminated string s1. Then it will add a null
**		terminator string '\0'.
*/
char			*ft_strcat(char *dst, const char *src);

/*
** FT_STRNCAT - This function wiil append not more that n characters from
**		string s2 to the end of string s1 and then add the termiantor character
**		'\0'. It will return the pointer s1.
*/
char			*ft_strncat(char *dst, const char *src, size_t n);

/*
** FT_STRLCAT - This function will append string src to string dst if the
**		BUFFER can guarantee NUL-termination and there is room to do. Room for
**		NUL should be included in dstsize.
*/
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
** FT_STRCHR - This function locates the first occurence of c in the string
**		pointed to by s. The function returns a pointer to the located charac-
**		ter. It can also find the '\0' character.
*/
char			*ft_strchr(const char *s, int c);

/*
** FT_STRRCHR - This function locates the last occurence of c in the string
**		pointed to by s. The function returns a pointer to the located charac-
**		ter. It can also fins the '\0' character.
*/
char			*ft_strrchr(const char *s, int c);

/*
** FT_STRLCHR - This function locates the first occurence of c in the string
**		pointed to by s. The function returns the position of the first
**		occurrence of c in the string s.
*/
long			ft_strlchr(const char *s, int c);

/*
** FT_STRCHR_BOOL - This function locates the occurence of c int the string
**		pointed to by s. The function returns a '1' if the char c is found
**		and 0 if it is not found.
*/
int				ft_strchr_bool(const char *s, int c);

/*
** FT_STRSTR - This function locates the first occurrence of the null-
**		terminated string 'needle' in the null terminated string 'haystack'
**		If needle is empty, haystack is returned. If no needle is found then
**		NULL us returned. If found a pointer to first occurrence is returned.
*/
char			*ft_strstr(const char *haystack, const char *needle);

/*
** FT_STRNSTR - This function locates the first occurrence of the string
**		'needle' in the string' haystack up to n characters. It returns hay-
**		stack if needle empty. If no needle is found it returns NULL, if
**		found it will return a pointer to the occurence of needle.
*/
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

/*
** FT_STRLSTR - This function locates the position of the null-terminated
**		string 'needle' in the null terminated string 'haystack'. If the needle
**		is empty, it will return 0.
*/
long			ft_strlstr(const char *haystack, const char *needle);

/*
** FT_STRCASESTR - This function will find the first occurrence of the substring
**		'needle' in the string 'haystack'. The terminating NULL-bytes
**		are not compared. This function does not factor in case of the
**		substring 'needle' or the string 'haystack'.
*/
char			*ft_strcasestr(const char *haystack, const char *needle);

/*
** FT_STRCMP - This function compares characters in a string lexicographically
**		The function returns 0 if the strings are equal, and non-zero if they
**		are not equal.
*/
int				ft_strcmp(const char *s1, const char *s2);

/*
**FT_STRNCMP - This function compares characters in a string up to n charac-
**		ters. The function returns 0 if the strings are equalm and non-zero if
**		they are not equal.
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** FT_STRCASECMP - This function takes two strings and compares them character
**		by character. It will return 0 if the strings are equal and a
**		non-zero integer if there is a difference. The function does not
**		compare according to the case of the character.
*/
int				ft_strcasecmp(const char *s1, const char *s2);

/*
** FT_STRNCASECMP - This function takes two strings and compares them character
**		by character up to n-characters. It will return 0 if the strings
**		are equal and a non-zero integer if there is a difference. The
**		function does not compare according to the case of the character
*/
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);

/*
** FT_STRNEW - This function allocates with malloc and returns a 'fresh'
**		string ending with '\0'. Each character of the string is intialised
**		at '\0'. If the allocation fails the function returns NULL.
*/
char			*ft_strnew(size_t size);

/*
** FT_STRDEL - This function takes as a parameter the address of a
**		strinf that needs to be freed with free, then sets the pointer
**		to NULL.
*/
void			ft_strdel(char **as);

/*
** FT_STRCCLR - This function takes a string as input and sets every
**		character of the string to the value '\0'
*/
void			ft_strclr(char *s);

/*
** FT_STRDUP - This function allocates sufficient memory for a copy of
**		the string s1, does the copy, and returns a pointer to it. If in-
**		sufficient memory is available, NULL is returned.
*/
char			*ft_strdup(const char *s1);

/*
** FT_STRNDUP - This function allocates sufficient memory for a copy
**		of the string s1. The function copies at most n characters from
**		the string s1 always NUL terminating the copied string
*/
char			*ft_strndup(const char *s1, size_t n);

/*
** FT_STREQU - This function performs a lexicographical comparison
**		between s1 and s2. If the 2 strings are identical the function
**		returns 1, or 0 otherwise.
*/
int				ft_strequ(char const *s1, char const *s2);

/*
** FT_STRNEQU - This function performs a lexicographical comparison
**		betwenn s1 and s2 up to 'n characters' or until a '\0' is
**		reached. If the 2 strings are identical, the function returns
**		1, or 0 otherwise.
*/
int				ft_strnequ(char const *s1, char const *s2, size_t n);
/*
** FT_STRREV - This function takes a string as an argument and returns
**		the string in reverse. It does not alter the string it is given but
**		rather returns a new string.
*/
char			*ft_strreverse(char *s);

/*
** FT_STRSPN - This function spans the initial part of the null-terminated str-
**		ing '*s' as long as the characters from '*s' occur in the null_term-
**		inated string 'charset'. The ft_strspn() function returns the number of
**		characters spanned.
*/
size_t			ft_strspn(const char *s, const char *charset);

/*
** FT_STRCSPN - This function spans the initial part of the null-terminated
**		string '*s' as long as the characters from '*s' DO NOT occur in the null
**		terminated string 'charset'. The ft_strcspn() function returns the
**		number of characters spanned.
*/
size_t			ft_strcspn(const char *s, const char *charset);

/*
** FT_STRTOK - This function breaks a string into a sequence of zero or more
**		non-empty tokens. The 'delim' argument specifies a set of bytes
**		that delimit the tokens in the parsed string. Each call to
**		ft_strtok() returns a pointer to a null-terminated string
**		containing the next token. This string does not include the
**		delimitting byte. If no more tokens are found, ft_strtok()
**		returns NULL.
*/
char			*ft_strtok(char *str, const char *delim);

/*
** FT_STRERROR - MISSING FUNCTION
*/

/*
** ************************************************************************	*
** 																			*
**																			*
**									LIBC									*
**																			*
**																			*
** ************************************************************************	*
*/

/*
** FT_ATOI - This function reads a string and returns it as an integer
*/
int				ft_atoi(const char *nptr);

/*
** FT_STRITER - This function applies the function f to each character
**		of the string passed as argument. Each character is passed by
**		address to f to be modified if neccessary.
*/
void			ft_striter(char *s, void (*f)(char *));

/*
** FT_STRITERI - This function applies the function f to each
**		character of the string passed as argument, and passing its index
**		as first argument. Each character is passed by address to f to be
**		be modified if necessary.
*/
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** FT_STRMAP - This function applies the function f to each
**		character given as argument to create a 'fresh' new string (with
**		malloc) resulting from the successive applications of f.
*/
char			*ft_strmap(char const *s, char (*f)(char));

/*
** FT_STRMAPI - This function applies the function f to each character
**		of the string given as argument by giving its index as first
**		argument to create a 'fresh' new string (with malloc) resulting
**		from the successive applications fo f.
*/
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** FT_STRSUB - This funtion allocates (with malloc) and returns a
**		'fresh' string given as argument. The substring begins at index
**		'start' and is of size 'len'. If 'start' and 'len' aren't refer-
**		ing to a valid substring, the behaviour is undefined. If the
**		allocation fails, the function returns NULL.
*/
char			*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** FT_STRJOIN - This function allocates (with malloc) and returns a
**		'fresh' string ending with '\0', result of the concatenation of
**		s1 and s2. If the allocation fails, the function returns NULL.
*/
char			*ft_strjoin(char const *s1, char const *s2);

/*
** FT_STRTRIM - This function allocates (with malloc) and returns a
**		copy of the string given as argument without whitespaces at the
**		beginning or at the end of the string. Whitespaces are \' \', '\n'
**		and '\t'. If s has no whitespaces at the beginning or end. The
**		function returns a copy of s. If the allocation fails, the
**		function returns NULL.
*/
char			*ft_strtrim(char const *s);

/*
** FT_STRLTRIM - This function allocates (with malloc) and returns a
**		copy of the string given as argument without a char of choice at
**		the beginning or at the end of the string. If no char is found at
**		the beginning or end. The function returns a copy of s. If the
**		allocation fails, the function returns NULL.
*/
char			*ft_strtrim_delim(char const *s, char c);

/*
** FT_STRSPLIT - This function allocates (with malloc) and returns an
**		array of 'fresh' strings (all ending with '\0', including the
**		array itself) obtained by splitting s using the character c as a
**		delimiter. If the allocation fails the function returns NULL.
*/
char			**ft_strsplit(char const *s, char c);

/*
** FT_NUMLEN - This function takes an int n as an argument and returns
**		the length of the number of digits as a result of size_t.
*/
size_t			ft_numlen(intmax_t n);

/*
** FT_ITOA - This function will allocate and return a fresh string ending
**		with '\0'. The function returns a string equivalent of the parameter
**		' n', given as argument. It supports negative numbers. If allocation
**		fails, it returns NULL.
*/
char			*ft_itoa(int n);

/*
** FT_PUTCHAR - This function will put a character to the standard output.
**		It is limited to one char and utilises the write function.
*/
void			ft_putchar(char c);

/*
** FT_PUTSTR - This function will print a string to the standard output.
**		It is limited by the '\0' terminator to show the end of the char
**		string.
*/
void			ft_putstr(const char *s);

/*
** FT_PUTENDL - This function will print a string to the standard output
**		followed by a newline char. It is limited by the '\0' terminator
**		to show the end of the char string.
*/
void			ft_putendl(const char *s);

/*
** FT_PUTNBR - This function will output the integer n to the standard
**		output.
*/
void			ft_putnbr(int n);

/*
** FT_PUTCHAR_FD - This function will output the char c to the file
**		descriptor fd.
*/
void			ft_putchar_fd(char c, int fd);

/*
** FT_PUTSTR_FD - This function will output the str s to the file descriptor
**		fd.
*/
void			ft_putstr_fd(const char *s, int fd);

/*
** FT_PUTENDL_FD - This function will output the string s to the file
**		descriptor followed by a newline.
*/
void			ft_putendl_fd(const char *s, int fd);

/*
** FT_PUTNBR_FD - This function will output the integer n to the file
**		descriptor fd.
*/
void			ft_putnbr_fd(int n, int fd);

/*
** FT_STRLOWCASE - This function takes a string as a parameter and converts the
**		char it finds to lowercase, if it is an uppercase char. If it is
**		not possible to do so, either it is a digit or symbol, it will
**		iterate through to the next char until the end of the string.
**		This function will return argument '*str'
*/
char			*ft_strlowcase(char *str);

/*
** FT_STRUPCASE - This function takes a str as a parameter and converts it to
**		uppercase. It returns the string in uppercase when it is done.
*/
char			*ft_strupcase(char *str);

/*
** FT_STRCAPITALIZE - This function takes a string as an argument and converts
**		the first letter to an uppercase letter. It also does this to
**		every letter that occurs after a space. The function returns
**		the string after modifications.
*/
char			*ft_strcapitalize(char *str);

/*
** FT_NUMLEN_BASE - This function takes an int n as an argument and returns
** 		the length of the number of digits as a result of size_t.
**		The function works for base 10 digits. It also works for
**		a base >= 2 and bases <= 16.
*/
int				ft_numlen_base(intmax_t n, int base);

/*
** FT_FORLOOP - This function takes three parameters as argument and converts
**		them to a for-loop type conversion using while loops. The for-loop
**		takes the form: for(i= int a, a < int b, int c)
**		'int a' is the starting point. Named as int begin.
**		'int b' is the condition stop point. Named as int condition.
**		'int c; is the step condition, if, '1' is equal to i++, '-1' is i--;.
*/
void			ft_forloop(int *begin, int condition, int step, void (*f)(int));

/*
**FT_ITOA_BASE - This function converts an integer value to a null-terminated
**		string using the specified base and stores the result in a char
**		array that is allocated using malloc. The base is expressed as a
**		integer, from 2 to 16. The characters comprising the base are
**		the digits from 0 to 9, followed by uppercase letter from A to F
**		For example:
**		base 4 would be "0123" and
**		base 16 "0123456789ABCDEF".
**		If base is 10 and value is negative, the resulting string is
**		preceded with a minus sign (-). With any other base, value is
**		always considered unsigned.
*/
char			*ft_itoa_base(int value, int base);

/*
** FT_PUTNBR_BASE - This function displays a number on the screen in a chosen
**		base system. The number is given in the form of an 'int', and
**		base in the form of a string of characters. The base-system
**		contains all useable symbols to display that number:
**		'0123456789 ' is used for decimal numbers
**		'01' is used for binary.
**		'0123456789ABCDEF' is used for a hexadecimal system.
**		The function can handle negative numbers.
**		Failures that cause function to print NULL.
**		The base needs to be greater in size than 1.
**		The base cannot have the same character twice.
**		The base must be alphanumeric.
*/
void			ft_putnbr_base(int n, int base);

/*
** FT_ATOI_BASE - The function converts the string argument str (base N <= 16)
**		to an integer (base 10) and returns it. The characters recognized
**		in the input are: 0123456789abcdef :
**		Those are, of course, to be trimmed according to the requested
**		base. For example,
**		base 4 recognizes "0123" and
**		base 16 recognizes "0123456789abcdef".
**		Uppercase letters are also recognized: "12fdb3" is the same as
**		"12FDB3". Minus signs ('-') are interpreted only if they are the
**		first character of the string.
*/
int				ft_atoi_base(const char *str, int base);

/*
** FT_ARRAYDUP - This function allocates sufficient memory for a copy of
**		the string s1, does the copy, and returns a pointer to it. If in-
**		sufficient memory is available, NULL is returned.
*/
char			**ft_arraydup(const char **arr);

/*
**	get_next_line - This function takes input from given/chosen file descriptor
**		It takes two parameters as an argument. The first is the file descriptor
**		that will be read, the second is the address of a pointer to a character
**		that will be used to save the line read from the file descriptor. When
**		the reading is complete the function returns its result without '\n'.
*/
int				get_next_line(const int fd, char **line);

/*
** ************************************************************************* *
**                                                                           *
**									MORE LISTS								 *
**																			 *
** ************************************************************************* *
*/

/*
**			THIS PART IS ABOUT LINKED LISTS (STRUCTS)
**
** Below are definitions of what is contained in the struct and their purpose
**
**	This part would not be possible without:
**		https://www.learn-c.org/en/Linked_lists
**		https://www.tutorialspoint.com/cprogramming/c_typedef.htm
**		https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/
**			classes-and-structs/structs
**		https://en.wikipedia.org/wiki/Struct_(C_programming_language)
*/

/*
** content	-	The data contained in the link. The void * allows to store any
**				kind of data.
*/

/*
** content size	-	The size of data stored. The void * type doesn't allow you
**				to know the size of the pointed data, as a consequence, it is
**				necessary to save its size. For instance, the size of the
**				string '42' is 3 bytes and the 32bits integer 42 has a size of
**				4 bytes.
*/

/*
** next	 	-	The next link's address or NULL if it's the last link.
*/

/*
** FT_LSTNEW - Allocates (with malloc) and returns a 'fresh' link. The variables
**			'content' and 'content_size' of the new link are initialised by
**			'copy' of the parameters of the function. If the parameter 'content'
**			is nul, the	variable content is initialised to NULL and the variable
**			'content_size' is initialised to 0 even if the parameter
**			'content_size' isn't. The variable 'next' is initialised to NULL. If
**			the allocation fails, the function returns NULL.
*/
t_list			*ft_lstnew(void const *content, size_t content_size);

/*
** FT_LSTDELONE - Takes as a parameter a link's pointer address and frees the
**			memory of the link's content using the function 'del' given as a
**			parameter, then	frees the link's memory using 'free'. The memory of
**			'next' must not be freed under any circumstance. Finally, the
**			pointer to the link that was just freed must be set to NULL
**			(read ft_memdel).
*/
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
** FT_LSTDEL - Takes as a parameter the address of a pointer to a link and frees
**			the memory of this link and every successor of that link using the
**			functions 'del' and 'free'. Finally the pointer to the link that was
**			just freed must be set to NULL. (read ft_memdel).
*/
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
** FT_LSTADD - This function adds the element 'new' and the beginnning of the
**			list. The function takes the address of a pointer as a parameter,
**			the pointer points to the first link of a list. The second parameter
**			is the link to add at the beginning of the list.
*/
void			ft_lstadd(t_list **alst, t_list *new);

/*
** FT_LSTITER - This function iterates the list 'lst' and applies the function
**			'(f)' to each link. A pointer to the first link is taken as the
**			first parameter. The address of a function to apply to each link of
**			a list is taken as a second parameter.
*/
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** FT_LSTMAP - This function iterates a lst and applies the function '(f)' to
**			each link to create a 'fresh' list (using malloc) as result from the
**			successive applications of '(f)'. If the allocation fails,
**			the function returns NULL.
*/
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ************************************************************************	*
**																			*
** 									MATH.H									*
**																			*
**																			*
***************************************************************************	*
*/

/*
** ************************************************************************ *
**                                                                          *
**								MATHEMATICAL FUNCTIONS					  	*
**                                                                          *
** ************************************************************************ *
*/

/*
** FT_SWAP - This function takes two integers as argument and swaps their
**		respective values around. In this scenario, after running,
**		int *a would be = b, and b would be = a before being changed.
*/
void			ft_swap(int *a, int *b);

/*
** FT_DIV_MOD - This function divides parameters a and b and stores the result
**		in the int pointed by 'div'. It also stores the remainder of the
**		division in the int point by 'mod'.
*/
void			ft_div_mod(int a, int b, int *div, int *mod);

/*
** FT_ULTIMATE_DIV_MOD - This function divides paramaters a and b. The result
**		of this division is stored in the int pointed by a. The
**		remainder of the division is stored in the int pointed by b.
*/
void			ft_ultimate_div_mod(int *a, int *b);

/*
** FT_FACTORIAL - This function finds iteratively, the factorial
**		of a number passed to it as a parameter. If there is an error
**		it will return 0.
*/
int				ft_factorial(int nb);

/*
** FT_POWER - This function returns a the value of a power applied
**		to a number. A power lower than 0, returns 0. Overflows are not
**		handled.
*/
intmax_t		ft_power(intmax_t nb, int power);

/*
** FT_FIBONACCI - This function returns the n-th element of the Fibonacci
**		sequence, the first element being at the 0 index. The sequence
**		starts as '0, 1, 1, 2....' if index is less than 0, the return
**		value is -1.
*/
int				ft_fibonacci(int index);

/*
** FT_SQRT - This function will find and return the square root of a number
**		passed to it as a parameter, if it exists. Otherwise it will
**		return (0);
*/
int				ft_sqrt(int nb);

/*
** FT_ISPRIME - This function will check if a number passed to it as a parameter
**		is a prime number. If it is a prime number, it will return (1),
**		else it will return 0. Negative numbers return (0); 0 and 1 are
**		also not considered to be prime numbers.
*/
int				ft_is_prime(unsigned int nb);

/*
** FT_FIND_NEXT_PRIME - This function will check if a number passed to it as a
**		parameter is a prime number, if it is not. It will return the
**		next prime number after the parameter and return its value.
*/
int				ft_find_next_prime(int nb);

/*
** FT_FABS - This function will return the absolute value of the double number
**		parsed as a parameter. If x is negative, the positive is
**		returned.
*/
double			ft_fabs(double x);

/*
** ************************************************************************** *
**                                                                            *
**								TRIGONOMETRIC FUNCTIONS						  *
**                                                                            *
** ************************************************************************** *
*/

/*
** FT_SIN
*/
double			ft_sine(int deg);

/*
** FT_COSINE
*/
double			ft_cosine(int deg);
/*
** ************************************************************************	*
**									FLAG FUNCTIONS							*
** ************************************************************************	*
*/

/*
** FT_FLAG_SIZE -
*/
void			ft_flag_size(t_printf *my_printf, size_t str_size);

/*
** FT_FLAG_WIDTH -
*/
void			ft_flag_width(t_printf *my_printf, int fd);
void			ft_flag_precision(t_printf *my_printf, char *str, int fd);
void			ft_flag_plus(t_printf *my_printf, int fd);
void			ft_flag_hash(t_printf *my_printf, char *str, int fd);
void			ft_flag_space(t_printf *my_printf, int fd);

/*
** ************************************************************************	*
**									HANDLERS								*
** ************************************************************************	*
*/

/*
** FT_HANDLER_C_CHAR - This is the handler for the char character. It parses the
**		the input into ft_printf and handles the char and only the char leaving
**		the string remainder on 0++;
*/
void			ft_handler_c_char(t_printf *my_printf,
		va_list printf_list, int fd);

/*
** FT_HANDLER_D_INT - This is the handler for parsing integers. The function
**		does not only look at data types of type 'int' only. It will look for
**		integers of type char to type size_t.
*/
void			ft_handler_d_int(t_printf *my_printf,
		va_list printf_list, int fd);

/*
** FT_HANDLER_E_EXPONENT - This function has not been made.
*/
void			ft_handler_e_exponent(t_printf *my_printf, va_list printf_list);

/*
** FT_HANDLER_F_FLOAT - This is the function that handles floating point input.
**		The standard number is parsed as a Double or a LONG Double. The
**		handler parses the %f character with Flags such as l, ll or L & j.
*/
void			ft_handler_f_float(t_printf *my_printf,
		va_list printf_list, int fd);
/*
** FT_HANDLER_O_OCTAL - This is the handler for octal strings. The function
**		does not work with (ft_flag_hash), this function works with the %o
**		conversion method. Check ft_flag_hash for prefix on octal.
*/
void			ft_handler_o_octal(t_printf *my_printf,
		va_list printf_list, int fd);
/*
** FT_HANDLER_B_BINARY - This is the handler for binary strings. The function
**		will wait for a %B or %b flag and convert the base 10 input to base 2.
**		Conversion takes places using a form of *toa_base.
*/
void			ft_handler_b_binary(t_printf *my_printf,
		va_list printf_list, int fd);
/*
** FT_HANDLER_S_STR - This is the handler for strings, either with variables
**		or strings declared in the VA_LIST itself. The function uses a
**		ft_putstr from Libft, and updates the return using FT_STRLEN.
*/
void			ft_handler_s_str(t_printf *my_printf,
		va_list printf_list, int fd);
/*
** FT_HANDLER_U_UNSIGNED_INT - This is the handler for unsigned integers, it
**		checks the variable in the VA_LIST, to pass it to the appropriate,
**		print_handler, this is done by checking which flag is set or read.
*/
void			ft_handler_u_unsigned_int(t_printf *my_printf,
		va_list printf_list, int fd);
/*
** FT_HANDLER_X_HEXADECIMAL - This is the handler for the hexadecimal conversion
**		and it will check the integer that is parsed to it and call the print
**		function that is appropriate for its data-type. The print will return
**		lowercase output.
*/
void			ft_handler_x_hexadecimal(t_printf *my_printf,
		va_list printf_list, int fd);

/*
** FT_HANDLER_P_POINTER - This is the handler for printing out a pointer.
**		This code is very basic and similar code exists in libft. The handler
**		is passed a data structure of type "(void *)", this is then cast
**		explicity to a data type that may output to the standard output.
*/
void			ft_handler_p_pointer(t_printf *my_printf,
		va_list printf_list, int fd);
/*
** FT_HANDLER_CONVERT - This is one of the most imperative functions that exist
**		within ft_printf. The purpose of this function is to obtain the identity
**		of the format character. Upon obtaining this, the function calls the
**		appropriate handler. i.e hexadecimal, octal, string, int etc.
*/
void			ft_handler_convert(t_printf *my_printf,
		va_list printf_list, int fd);

/*
** ************************************************************************	*
**									PRINTERS								*
** ************************************************************************	*
*/
/*
** FT_PRINT_C_CHAR - This function will print a char as given or parsed by
**		variable.
*/
void			ft_print_c_char(t_printf *my_printf, int c, int fd);

/*
** FT_PRINT_D_INT - This function will be called by the ft_handler_d_int
**		function and print an integer and update the return using the STRLEN
**		of the number. The integer is converted to a string prior to output
**		occurring.
*/
void			ft_print_d_int(t_printf *my_printf, intmax_t n, int fd);

/*
** FT_PRINT_E_EXPONENT - This function has not been done.
*/
void			ft_print_e_exponent(t_printf *my_printf, double n);

/*
** FT_PRINT_F_FLOAT - This function is called by the ft_handler_f_float.
**		It works by taking the data-type passed to it. Either a float, double
**		or a long double. It works by casting the significand to one string.
**		It will then use a function that calculates the mantissa beyond the
**		radix and storing it in a second string. It then outputs each string
**		with the radix as the seperator. It takes the length of the output
**		and updates the value in the struct 'f_return'.
*/
void			ft_print_f_float(t_printf *my_printf, double n, int fd);

void			ft_print_lf_float(t_printf *my_printf, long double n, int fd);

/*
** FT_PRINT_O_OCTAL - This function will be called by the ft_handler_o_octal
**		function and print an octal number. The function will convert the
**		inital integer to base 8 and store the value in a data structure of
**		type string(char *) and update the return using the	FT_STRLEN of the
**		string.
*/
void			ft_print_o_octal(t_printf *my_printf, uintmax_t n, int fd);

void			ft_print_b_binary(t_printf *my_printf, uintmax_t n, int fd);

/*
** FT_PRINT_S_STR - This function will be called by the ft_handler_s_str
**		function and it will operate in the same manner as an FT_PUTSTR, which
**		can be found in the LIBFT Library. This function has a strong precision
**		limiter. The call to precision within this function will cause the
**		string (char *) to be truncated. The value F_RETURN contained in the
**		struct is updated with the FT_STRLEN of the output string.
*/
void			ft_print_s_str(t_printf *my_printf, char *str, int fd);
void			ft_print_ws_str(t_printf *my_printf,
		wchar_t *str, int fd);
void			ft_print_u_unsigned_int(t_printf *my_printf,
		uintmax_t n, int fd);
void			ft_print_x_hexadecimal(t_printf *my_printf,
		uintmax_t n, int fd);

void			ft_print_p_pointer(t_printf *my_printf, void *pointer, int fd);
void			ft_print_mod(t_printf *my_printf, int fd);

/*
** ********************************************************************
*/
void			ft_print_out(t_printf *my_printf, char *str, int fd);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *parse_str, ...);
void			ft_flag_check(t_printf *my_printf);
void			ft_convert(t_printf *my_printf, va_list printf_list,
		char *str, int fd);
void			ft_flag_precision(t_printf *my_printf, char *str, int fd);
void			ft_flag_set(t_printf *my_printf, char *str);
void			ft_flag_reset(t_printf *my_printf);
void			ft_error(char *str);

char			*ft_ltoa_base(intmax_t value, int base);

void			ft_putwchar(wchar_t wc);

void			ft_putwstr(wchar_t *wstr);

intmax_t		ft_power_ten(double nb, int power);

int				ft_round_bool(double nbr);

/*
** ************************************************************************	*
**									FILE DESCRIPTORS						*
** ************************************************************************	*
*/

void			ft_putwchar_fd(wchar_t wc, int fd);
void			ft_putwstr_fd(wchar_t *wstr, int fd);

#endif
