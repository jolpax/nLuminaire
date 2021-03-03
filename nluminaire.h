#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>



struct luminaireData
{
    uint8_t swtx[8];

    uint16_t panel;
    uint16_t red;
    uint16_t green;
    uint16_t blue;

};

int readCan(void);

extern struct luminaireData nData;
