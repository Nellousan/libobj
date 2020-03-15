/*
** EPITECH PROJECT, 2020
** str to arra
** File description:
** 
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

size_t obj3d_array_size(void **ar)
{
    size_t i = 0;
    if (ar == NULL)
        return i;
    for (; ar[i] != NULL; i++);
    return i;
}

static int obj3d_str_to_array_words(char *str, int len)
{
    int words = 0;
    words += (str[0] != '\0') ? 1 : 0;
    for (int i = 1; i < len; i++)
        words += (str[i] != '\0' && str[i - 1] == '\0') ? 1 : 0;
    return words;
}

char **obj3d_str_to_array(char *str, char c)
{
    int words = 0;
    int j = 0;
    char **array;
    int len;
    if (str == NULL)
        return NULL;
    len = strlen(str);
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == c) ? '\0' : str[i];
    words = obj3d_str_to_array_words(str, len);
    if (words == 0)
        return NULL;
    array = malloc(sizeof(char *) * (words + 1));
    if (str[0] != '\0') {
        array[0] = &str[0];
        j++;
    } for (int i = 1; i < len; i++)
          if (str[i] != '\0' && str[i - 1] == '\0') {
              array[j] = &str[i];
              j++;
          }
    array[j] = NULL;
    return array;
}
