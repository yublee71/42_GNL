#include <stddef.h>
#include <stdlib.h>

size_t ft_wordcount(char const *s, char c)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    if (s[i] != c)
        count++;
    i++;
    while(s[i])
    {
        if (s[i - 1] == c && s[i] != c)
            count++;
        i++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    size_t wordcount;
    size_t charcount;
    size_t  i;
    char **result;

    wordcount = ft_wordcount(s, c);
    i = 0;
    if (wordcount == 0)
        return (NULL);
    result = malloc (wordcount * sizeof(char *));
    if (!result)
        return (NULL);
    while (*s && i < wordcount)
    {
        charcount = 0;
        while(*s++ != c)
            charcount++;
        if (charcount)
        {
            result[i] = (char *)malloc(charcount + 1);
            if(!result[i])
                return (NULL);
            result[i][charcount] = '\0';
        }
        while (--charcount >=0)
            result[i][charcount] = *(--s);            
        i++;
        while (*s++ !=c)
            ;
    }
}

#include <stdio.h>

int main(void)
{
    char **result;
    result = ft_split("abc", 'b');
    printf("%s", result[1]);
}