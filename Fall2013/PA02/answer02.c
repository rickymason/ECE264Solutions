#include "pa02.h"

/**
 * Count the number of characters in a null-terminated string 's' 
 * (not counting the null character).
 *
 * Example: my_strlen("foo") should yield 3.
 */
int my_strlen(const char * s)
{
	int i =0;
	
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}

/**
 * Count the number of occurrences of a particular character 'c' in a
 * null-terminated string 's'.
 *
 * Example: my_countchar("foo", 'o') should yield 2.
 */
int my_countchar(const char * s, char c)
{
	int i = 0;
	int count_char = 0;
	
	while(s[i] != '\0')
	{
		if(s[i] == c)
		{
			count_char++;
		}
		i++;
	}
    return count_char;
}

/**
 * Convert an entire null-terminated string 's' to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that yields
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) yields "FOOBAR".
 */
void my_strupper(char * s)
{
	int i = 0;
	
	while(s[i] != '\0')
	{
		if(isalpha(s[i]))
		{
			s[i] = toupper(s[i]);
		}
		i++;
	}
}

/**
 * Convert an entire null-terminated string 's' to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that yields
 * the lowercase version of a character 'c'.
 *
 * Example: char foobar[10] = "FOOBAR";
 * my_strupper(foobar) yields "foobar".
 */
void my_strlower(char * s)
{
	int i = 0;
	
	while(s[i] != '\0')
	{
		if(isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
		}
		i++;
	}
}

/**
 * Copy the contents of a null-terminated string 's2' into the memory
 * pointed to by 's1'.  Any existing data in 's1' will be overwritten by
 * the contents of 's2'.  Note: you can assume that there is sufficient
 * memory available in 's1'.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "foo") yields "foo".
 */
void my_strcpy(char * s1, const char * s2)
{
	int i = 0;
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

/**
 * Copy the first 'n' characters of a null-terminated string 's2' into the
 * memory pointed to by 's1'. Any existing data in 's1' will be
 * overwritten by the contents of 's2'.  Note: you can assume that there
 * is sufficient memory available in 's1'.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "foo", 1) yields "f".
 */
void my_strncpy(char * s1, const char * s2, int num)
{
	int i = 0;
	
	while(s2[i] != '\0' && i < num)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}


/** 
 * Concatenate (append) the contents of a null-terminated string 's2'
 * onto the end of the null-terminated string 's1'.  Note: you can
 * assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar") yields "foobar".
 */
void my_strcat(char * s1, const char * s2) 
{
	int s1_length = 0;
	int s2_index = 0;
	
	while(s1[s1_length] != '\0')
	{
		s1_length++;
	}
	
	while(s2[s2_index] != '\0')
	{
		s1[s1_length + s2_index] = s2[s2_index];
		s2_index++;
	}
	s1[s1_length + s2_index] = '\0';
}

/** 
 * Concatenate (append) the first n characters of a null-terminated
 * string 's2' onto the end of the null-terminated string 's1'.  Note: you
 * can assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar", 1) yields "foob".
 */
void my_strncat(char * s1, const char * s2, int num)
{
   	int s1_length = 0;
	int s2_index = 0;
	
	while(s1[s1_length] != '\0')
	{
		s1_length++;
	}
	
	while(s2[s2_index] != '\0' && s2_index < num)
	{
		s1[s1_length + s2_index] = s2[s2_index];
		s2_index++;
	}
	s1[s1_length + s2_index] = '\0';
}

/**
 * Return a pointer to the first occurrence of a null-terminated
 * substring 's2' in a null-terminated string 's1'.  If 's2' does not appear
 * in 's1', the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will yield 0 (NULL).
 * Example(2): my_strstr("foobar", "bar") will yield a pointer to the
 * "bar" portion of the "foobar" argument.
 */

const char *my_strstr(const char * s1, const char * s2)
{
	int string_length_s2 =0;
	int s1_index = 0;
	int s2_index = 0;
	char* found_loc;
	
	while(s2[string_length_s2] != '\0')
	{
		string_length_s2++;
	}
	
	while (s1[s1_index] != '\0')
	{
		if(s1[s1_index] == s2[0])
		{
			found_loc = (char*) & s1[s1_index];
			
			while(s2[s2_index] != '\0')
			{
				if(s1[s1_index+s2_index] == s2[s2_index])
				{
					s2_index++;
				}
			}
		}
		s1_index++;
	}
	
	if(s2_index == string_length_s2)
	{	
		return(found_loc);
	}
	else				
	{
		return NULL;
	}
}



/**
 * Insert a null-terminated string s2 in the null-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "foo";
 * my_strinsert(foo, "bar", 0) yields "barfoo".
 * 
 * Example(2): char foo[10] = "foo";
 * my_strinsert(foo, "bar", 100) yields "foobar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
	int s1_length = 0;
	int s2_length = 0;
	int s1_index = 0;
	int counter = 0;

	while(s1[s1_length] != '\0')
	{
		s1_length++;
	}
	
	while(s2[s2_length] != '\0')
	{
		s2_length++;
	}
	
	for(s1_index = s1_length; s1_index >= pos; s1_index--)
	{
		s1[s1_index + s2_length] = s1[s1_index];
	}

	for(counter = 0; counter < s2_length; counter++)
	{
		s1[counter + pos] = s2[counter];
	}
}

/**
 * Delete a portion of the null-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "foobar";
 * my_strdelete(foo, 3, 3) yields "foo".
 *
 * Example(2): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 3) yields "bar".
 * 
 * Example(3): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 34) yields "".
 * 
 * Example(4): char foo[10] = "foobar";
 * my_strdelete(foo, 2, 30) yields "fo";
 */
void my_strdelete(char *s, int pos, int length)
{
	int string_length = 0;
	int char_position = 0;
	
	while(s[string_length] != '\0')
	{
		string_length++;
	}
	
	for(char_position = pos; char_position < string_length; char_position++)
		{
			s[char_position] = s[char_position + length];
		}
	s[char_position] = '\0';
}

