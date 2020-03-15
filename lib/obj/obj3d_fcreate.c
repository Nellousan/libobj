/*
** EPITECH PROJECT, 2020
** obj3d fcreate
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
#include "obj3d.h"
#include "obj3dalt.h"

static int obj3d_fcreate_vt(obj3d_t *obj3d, char **ar)
{
    size_t i;
    i = obj3d_array_size((void **)obj3d->vt);
    obj3d->vt = realloc(obj3d->vt, sizeof(objVect3lf *) * (i + 2));
    obj3d->vt[i] = malloc(sizeof(objVect3lf));
    obj3d->vt[i]->x = atof(ar[1]);
    obj3d->vt[i]->y = atof(ar[2]);
    obj3d->vt[i + 1] = NULL;
    return 0;
}

static int obj3d_fcreate_vn(obj3d_t *obj3d, char **ar)
{
    size_t i;
    i = obj3d_array_size((void **)obj3d->vn);
    obj3d->vn = realloc(obj3d->vn, sizeof(objVect3lf *) * (i + 2));
    obj3d->vn[i] = malloc(sizeof(objVect3lf));
    obj3d->vn[i]->x = atof(ar[1]);
    obj3d->vn[i]->y = atof(ar[2]);
    obj3d->vn[i]->z = atof(ar[3]);
    obj3d->vn[i + 1] = NULL;
    return 0;
}

static int obj3d_fcreate_v(obj3d_t *obj3d, char **ar)
{
    size_t i;
    i = obj3d_array_size((void **)obj3d->v);
    obj3d->v = realloc(obj3d->v, sizeof(objVect3lf *) * (i + 2));
    obj3d->v[i] = malloc(sizeof(objVect3lf));
    obj3d->v[i]->x = atof(ar[1]);
    obj3d->v[i]->y = atof(ar[2]);
    obj3d->v[i]->z = atof(ar[3]);
    obj3d->v[i + 1] = NULL;
    return 0;
}

static int obj3d_fcreate_f(obj3d_t *obj3d, char **ar)
{
    size_t i;
    char **ar2;
    i = obj3d_array_size((void **)obj3d->f);
    obj3d->f = realloc(obj3d->f,sizeof(objFace_t *) * (i + 2));
    obj3d->f[i] = malloc(sizeof(objFace_t));
    for (int j = 0; ar[j + 1] != NULL; j++) {
        ar2 = obj3d_str_to_array(ar[j + 1], '/');
        obj3d->f[i]->v[j] = atoll(ar2[0]) - 1;
        obj3d->f[i]->vt[j] = atoll(ar2[1]) - 1;
        obj3d->f[i]->vn[j] = atoll(ar2[2] - 1);
        if (ar2 != NULL)
            free(ar2);
    }
    obj3d->f[i + 1] = NULL;
    return 0;
}

static int obj3d_fill(obj3d_t *obj3d, FILE *file)
{
    char *bf = NULL;
    char **ar = NULL;
    size_t n = 0;
    ssize_t size = 0;
    size = getline(&bf, &n, file);
    while (size >= 0) {
        ar = obj3d_str_to_array(bf, '\0');
        if (ar != NULL) {
            if (!strcmp(ar[0], "v"))
                obj3d_fcreate_v(obj3d, ar);
            if (!strcmp(ar[0], "vn"))
                obj3d_fcreate_vn(obj3d, ar);
            if (!strcmp(ar[0], "vt"))
                obj3d_fcreate_vt(obj3d, ar);
            if (!strcmp(ar[0], "f"))
                obj3d_fcreate_f(obj3d, ar);
            free(ar);
            free(bf);
            ar = NULL;
            bf = NULL;
        }
        size = getline(&bf, &n, file);
    }
    return 0;
}

obj3d_t *obj3d_fcreate(char *str)
{
    obj3d_t *obj3d = obj3d_create();
    FILE *file = obj3d_open(str);
    obj3d_fill(obj3d, file);
    fclose(file);
    return obj3d;
}
