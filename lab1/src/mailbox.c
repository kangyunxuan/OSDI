//mailbox components: registers, channels, and messages.
//Get the hardware’s information by mailbox and print them, 
//you should at least print board revision and ARM memory base address and size.
#include "addr/addr_mailbox.h"
#include "mailbox.h"

volatile unsigned int mailbox[16] __attribute__((aligned(16)));

unsigned int mailbox_call(unsigned int message, unsigned char channel) {
    // Combine the message address (upper 28 bits) with channel number (lower 4 bits)
    unsigned int data = (message & ~(0xF)) | (channel & 0x0F);

    // Wait until Mailbox 0 is not full
    while ((*MAILBOX_STATUS & MAILBOX_FULL)) {
    }

    // Write the data to Mailbox 1
    *MAILBOX_WRITE = data;

    //read the data from mailbox 0 until the value is the same as you wrote in step 1
    while(1){
        while ((*MAILBOX_STATUS & MAILBOX_EMPTY)) {
        }
        if(data == *MAILBOX_READ && mailbox[1] == MAILBOX_REQUEST_SUCCEED){ 
            return 1;
        }
    }
    return 0;
}

// void get_board_revision(){
//   unsigned int mailbox[7];
//   mailbox[0] = 7 * 4; // buffer size in bytes
//   mailbox[1] = MAILBOX_REQUEST_CODE;
//   // tags begin
//   mailbox[2] = MAILBOX_GET_BOARD_REVISION; // tag identifier
//   mailbox[3] = 4; // maximum of request and response value buffer's length.
//   mailbox[4] = MAILBOX_TAG_REQUEST_CODE;
//   mailbox[5] = 0; // value buffer
// mailbox[6] = 0;
//   // tags end
//   mailbox[7] = MAILBOX_END_TAG;

//   mailbox_call(mailbox, MAILBOX_CHANNEL_PROPERTY_TAGS_ARM_TO_VC); // message passing procedure call, you should implement it following the 6 steps provided above.

// }

