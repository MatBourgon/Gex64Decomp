#ifndef TG2STRING_H_
#define TG2STRING_H_

typedef union
{
    char cstr[8];
    unsigned int raw[2];
} G2String;

// tomsons26: May be a memcmp; todo: test when memcmp found
#define G2STRING(x) ((G2String*)(x))
#define G2String_Compare_EQ(a, b) (G2STRING(a)->raw[0] == G2STRING(b)->raw[0] && G2STRING(a)->raw[1] == G2STRING(b)->raw[1])
#define G2String_Compare_NEQ(a, b) (G2STRING(a)->raw[0] != G2STRING(b)->raw[0] || G2STRING(a)->raw[1] != G2STRING(b)->raw[1])

// Rotating/playful animated text, like "CATCH THE TRAIN"
#define ANIMATED_3DTEXT(x) ("#2"x)

#endif