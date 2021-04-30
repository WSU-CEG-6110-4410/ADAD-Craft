#ifndef _world_h_
#define _world_h_

typedef void (*world_func)(int, int, int, int, void *);

void create_world(int p, int q, world_func func, void *arg);

int spawn_plants(double freq, int index, int num, int x, int z);

#endif
