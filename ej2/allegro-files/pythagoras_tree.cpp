//pythagoras tree
#include <unistd.h>
#include<allegro.h>
#include<queue>
#include<cmath>
#define winw 1080
#define winh 720

using namespace std;
BITMAP *buffer;

struct Tbranch{
    double x,y;
    double angle;//N=0 E=pi/2 S=pi W=3pi/2
    double l;};
    
void drawtree(double x,double y,double l,double factor/*proportion of the root to its branch*/,double angle/*radians*/){
    queue<Tbranch>bque;
    Tbranch inp;inp.x=x;inp.y=y;inp.angle=0;inp.l=l;
    bque.push(inp);
    while(!bque.empty()){
        usleep(100);
        Tbranch u;u=bque.front();bque.pop();
        double x1=u.x+u.l*sin(u.angle);
        double y1=u.y-u.l*cos(u.angle);
        line(buffer,int(u.x),int(u.y),int(x1),int(y1),0xffffff);
    blit(buffer,screen,0,0,0,0,winw,winh);
    // save_bitmap("C:/tree.bmp",buffer,0);
        if(u.l*factor>5){
            Tbranch b;
            b.x=x1;b.y=y1;
            b.l=u.l*factor;
            b.angle=u.angle+angle;
            bque.push(b);
            b.angle=u.angle-angle;
            bque.push(b);}}}

int main(){ 
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,winw,winh,0,0);
    buffer=create_bitmap(winw,winh);
    clear_to_color(buffer,0);

    drawtree(winw/2,winh,40,0.85,M_PI/12);
        
    blit(buffer,screen,0,0,0,0,winw,winh);
    save_bitmap("C:/tree.bmp",buffer,0);
	
    readkey();
    destroy_bitmap(buffer);
    return(0);}