#ifndef NOTE_H
#define NOTE_H

class Note {
public:
    int data;
    Note *right;
    Note *left;
    Note *parent;
    int height;
};

#endif