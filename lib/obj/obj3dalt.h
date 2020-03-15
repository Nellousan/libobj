/*
** EPITECH PROJECT, 2020
** alt 
** File description:
** 
*/

#ifndef OBJ3DALT
#define OBJ3DALT

char **obj3d_str_to_array(char *str, char c);
size_t obj3d_array_size(void **ar);
FILE *obj3d_open(char *filepath);
obj3d_t *obj3d_create(void);

#endif
