#ifndef TSIGNAL_H_
#define TSIGNAL_H_

struct Instance_s;

typedef int(*SignalHandlerFunc)(struct Instance_s* /*instance*/, void* /*signal*/);

typedef struct
{
    SignalHandlerFunc func;
    short length;
    short onlyPlayer;
} SignalHandler;

// PS1 has 105 signals, this has about 114-115
extern SignalHandler D_80078664[];

#endif