#ifndef __MESSAGING__
#define __MESSAGING__

#include "includeall.h"

#define MAX_LENGTH   128

typedef enum
{
   noError = 0,
   txBufferFull,
   rxBufferFull,
} MessagingErrors_e;

typedef enum
{
   changeColor = 0,
   changePWM,
   cycleLEDs,
   NOPcommand = 0xFF
} Commands_e;

typedef struct
{
   Commands_e cmd;
   uint8_t numBytes;
   uint8_t data[ MAX_LENGTH ];
   uint8_t checksum;
} Message_t;

MessagingErrors_e BuildMessage( Commands_e cmd, uint8_t numBytes, uint8_t * data );
MessagingErrors_e CalculateChecksum( Message_t * msg );
MessagingErrors_e SendMessage( Message_t * msg );
MessagingErrors_e DecodeRxMessage( Message_t * msg );

#endif // __MESSAGING__
