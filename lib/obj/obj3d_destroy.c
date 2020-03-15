/*
** EPITECH PROJECT, 2020
** obj destroy
** File description:
** 
*/

#include <stdlib.h>
#include "obj3d.h"

static void obj3d_destroy_node(void **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}

void obj3d_destroy(obj3d_t *obj3d)
{
    obj3d_destroy_node((void **)obj3d->v);
    obj3d_destroy_node((void **)obj3d->vn);
    obj3d_destroy_node((void **)obj3d->vt);
    obj3d_destroy_node((void **)obj3d->f);
    free(obj3d);
    return;
}
