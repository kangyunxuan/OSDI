#ifndef ADDR_MAILBOX_H
#define ADDR_MAILBOX_H

#define MMIO_BASE       0x3f000000
#define MAILBOX_BASE    (MMIO_BASE + 0x0000b880)

#define MAILBOX_READ    ((volatile unsigned int *)(MAILBOX_BASE))
#define MAILBOX_STATUS  ((volatile unsigned int *)(MAILBOX_BASE + 0x18))
#define MAILBOX_WRITE   ((volatile unsigned int *)(MAILBOX_BASE + 0x20))
#define MAILBOX_PEEK   ((volatile unsigned int *)(MAILBOX_BASE + 0x10))
#define MAILBOX_CONFIG   ((volatile unsigned int *)(MAILBOX_BASE + 0x1c))

#define MAILBOX_EMPTY   0x40000000
#define MAILBOX_FULL    0x80000000

#define MAILBOX_GET_BOARD_REVISION  0x00010002
#define MAILBOX_REQUEST_CODE        0x00000000
#define MAILBOX_REQUEST_SUCCEED     0x80000000
#define MAILBOX_REQUEST_FAILED      0x80000001
#define MAILBOX_TAG_REQUEST_CODE    0x00000000
#define MAILBOX_END_TAG             0x00000000
#endif
