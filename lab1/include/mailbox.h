#ifndef MAILBOX_H
#define MAILBOX_H

extern volatile unsigned int mailbox[16];

typedef enum {
    MAILBOX_CHANNEL_POWER = 0,
    MAILBOX_CHANNEL_FRAMEBUFFER = 1,
    MAILBOX_CHANNEL_VIRTUAL_UART = 2,
    MAILBOX_CHANNEL_VCHIQ = 3,
    MAILBOX_CHANNEL_LEDS = 4,
    MAILBOX_CHANNEL_BUTTONS = 5,
    MAILBOX_CHANNEL_TOUCHSCREEN = 6,
    MAILBOX_CHANNEL_UNUSED_1 = 7,
    MAILBOX_CHANNEL_PROPERTY_TAGS_ARM_TO_VC = 8,
    MAILBOX_CHANNEL_PROPERTY_TAGS_VC_TO_ARM = 9
} mailbox_channel_t;

//https://github.com/raspberrypi/firmware/wiki/Mailbox-property-interface
typedef enum {
    MAILBOX_TAG_GET_FIRMWARE_VERSION = 0x00000001,

    MAILBOX_TAG_GET_BOARD_MODEL = 0x00010001,
    MAILBOX_TAG_GET_BOARD_REVISION = 0x00010002,
    MAILBOX_TAG_GET_BOARD_MAC_ADDRESS = 0x00010003,
    MAILBOX_TAG_GET_BOARD_SERIAL = 0x00010004,
    MAILBOX_TAG_GET_ARM_MEMORY = 0x00010005,
    MAILBOX_TAG_GET_VC_MEMORY = 0x00010006,
    MAILBOX_TAG_GET_CLOCKS = 0x00010007,
} mailbox_tag_t;

void get_board_revision();
unsigned int mailbox_call(unsigned int message, unsigned char channel);

#endif