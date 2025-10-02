#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "scene/scene.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))


void read_scenes_from_file(const char *filename, scene_t* scene);
void draw_sprites(void *args);

int main(int argc, char *argv[])
{
    size_t num_sprites = 7;
    size_t sprite_length = 500;
    char *filename = "/usr/share/terminal-saver/sprites.dat";
    if (argc == 4) {
        filename = argv[1];
        num_sprites = atoi(argv[2]);
        sprite_length = atoi(argv[3]);
    } else if (argc != 1) {
        printf("ERROR! Either start the program without arguments, or\nterminal-saver <sprite-file> <number_of_sprites> <sprite_length>");
    }
    
    scene_t* scene = scene_create(num_sprites, sprite_length);
    read_scenes_from_file(filename, scene);

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, (void *)draw_sprites, scene) != 0)
    {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    // Main thread work can be done here

    pthread_join(thread_id, NULL);

    scene_delete(scene);
    return EXIT_SUCCESS;
}

void read_scenes_from_file(const char *filename, scene_t* scene)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    size_t sprite_num = 0;
    while(fgets(line, 256, file) != NULL)
    {
        if(strncmp(line, "\n", 1) == 0) // Skip empty lines
        {
            sprite_num++;
            continue;
        }
        
        strncat(scene->sprites[sprite_num], line, strlen(line));
    }
    fclose(file);
}

void draw_sprites(void *args)
{
    scene_t* scene = (scene_t*) args;
    size_t sprite_num = 0;
    struct timespec request = {0, 200000000};
    struct timespec remaining = {0, 0};

    system("clear");
    while (1)
    {
        if (sprite_num >= scene->sprite_num)
        {
            sprite_num = 0;
        }
        printf("%s\n", scene->sprites[sprite_num]);
        nanosleep(&request, &remaining);
        gotoxy(0, 0);
        sprite_num++;
    }

}