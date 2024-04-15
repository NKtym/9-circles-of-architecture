#pragma once
#include <stdio.h> 
#include <unistd.h> 
#include <termios.h> 
#include <fcntl.h>
#include <stdlib.h> 

enum keys{
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_ENTER,
    KEY_ESC,
    KEY_F5,
    KEY_F6,
    KEY_L,
    KEY_S,
    KEY_I,
    KEY_R
};

extern struct termios saved_termios;

int rk_readkey (enum keys *);
int rk_mytermsave ();
int rk_mytermrestore ();
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readvalue (int *value, int timeout);