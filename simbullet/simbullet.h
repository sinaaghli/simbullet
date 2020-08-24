#ifndef SIMBULLET_H__
#define SIMBULLET_H__

#include <btBulletDynamicsCommon.h>

#include <simbullet/version.h>

class simbullet{
public:
    simbullet();
    ~simbullet();
    int dosth(int a);
    int run_example();

    int cnt;
};

#endif// SIMBULLET_H__