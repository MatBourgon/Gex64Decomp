#ifndef QMARKINTRO_H_
#define QMARKINTRO_H_

typedef struct
{
    short x, y;
    const char* message;
} QMarkIntroMessage;

typedef struct
{
    short x, y;
    short w, h;
    short time;
    short numMessages;
    QMarkIntroMessage messages[0];
} QMarkIntro;

#endif