#include <simbullet/simbullet.h>

simbullet::simbullet(){
    cnt++;
}

simbullet::~simbullet(){
    cnt--;
}

int simbullet::dosth(int a){
    a++;
    cnt++;
    return a;
}
