#include "scene.h"

scene_t* scene_create(size_t number_of_sprites, size_t size_of_sprite)
{
    scene_t* scene = (scene_t*) malloc(sizeof(scene_t));
    scene->sprite_num = number_of_sprites;
    scene->sprite_length = size_of_sprite;
    if (!scene)
    {
        return NULL;
    }

    scene->sprites = (char **) malloc(sizeof(char*) * number_of_sprites);
    if (!scene->sprites)
    {
        scene_delete(scene);
        return NULL;
    }

    for (size_t i = 0; i < number_of_sprites; i++)
    {
        scene->sprites[i] = malloc(size_of_sprite);
        if (!scene->sprites[i])
        {
            scene_delete(scene);
            return NULL;
        }
    }
    return scene;
}

void scene_delete(scene_t* scene)
{
    for(size_t i = 0; i < scene->sprite_num; i++)
    {
        free(scene->sprites[i]);
    }
    free(scene->sprites);
    free(scene);
}