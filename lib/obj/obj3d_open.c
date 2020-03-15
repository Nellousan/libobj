/*
** EPITECH PROJECT, 2020
** file load
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include "obj3d.h"

FILE *obj3d_open(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
        printf("Error loading %s, permission denied\n ", filepath);
    return file;
}
