#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <stdlib.h>

typedef struct {
    char** sprites;
    size_t sprite_num;
    size_t sprite_length;
} scene_t;

scene_t* scene_create(size_t number_of_sprites, size_t size_of_sprite);
void scene_delete(scene_t* scene);

#endif