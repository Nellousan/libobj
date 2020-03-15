/*
** EPITECH PROJECT, 2020
** obj3d create
** File description:
** 
*/

#include <stdlib.h>
#include "obj3d.h"

obj3d_t *obj3d_create(void)
{
    obj3d_t *obj3d = malloc(sizeof(obj3d_t));
    obj3d->v = NULL;
    obj3d->vn = NULL;
    obj3d->vt = NULL;
    obj3d->f = NULL;
    obj3d->illum = -1;
    return obj3d;
}
