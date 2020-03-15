/*
** EPITECH PROJECT, 2020
** Obj header
** File description:
** 
*/

#ifndef OBJ3D_STRUCTS_H
#define OBJ3D_STRUCTS_H

#include <stddef.h>

typedef unsigned int illum_t;

typedef struct objVect3lf_s {
    double x;
    double y;
    double z;
}objVect3lf;

typedef struct objFace {
    size_t v[3];
    size_t vt[3];
    size_t vn[3];
}objFace_t;

typedef struct obj3d {
    objVect3lf **v;
    objVect3lf **vn;
    objVect3lf **vt;
    objFace_t **f;
    illum_t illum;
}obj3d_t;

#endif
