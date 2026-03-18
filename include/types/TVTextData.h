#ifndef TTVTEXTDATA_H_
#define TTVTEXTDATA_H_

enum ETVScreenType
{
    ETV_NONE = 0,
    ETV_UNK1 = 1,
    ETV_UNK2 = 2,
    ETV_UNK3 = 3,
    ETV_UNK4 = 4,
    ETV_GILLIGEX = 5,
    ETV_MOOSHOO = 6,
    ETV_GEXZILLA = 7,
    ETV_REZ = 8,
    ETV_HISTORY = 9,
    ETV_TOON = 10,
    ETV_CIRCUIT = 11,
    ETV_HORROR = 12,
    ETV_SCIFI = 13,
    ETV_KUNGFU = 14,
    ETV_REZOPOLIS = 15,
    ETV_BONUS = 16,
    ETV_TITANIC = 17
};

typedef struct
{
    const char* levelId;
    const char* levelName[2];
    const char* channelName[2];
    const short nRedRemotes;
    const short extra;
} TVTextData_t;

extern TVTextData_t TVTextInformation[31];

#endif