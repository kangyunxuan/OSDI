#include "uart.h"
#include "shell.h"
#define CMD_COUNT (sizeof(cmd_list) / sizeof(cmd_list[0]))

typedef struct CLI_cmd{
    char *name;
    char *description;
    void (*func)();
} CLI_cmd;

CLI_cmd cmd_list[] = {
    {"help", "print all available command", print_help},
    {"hello", "print hello world", print_hello_world},
    {"reboot", "reboot the system", reboot_system},
};


//strcmp
void shell_cmd_read(char *buffer){
    unsigned int length = 0;

    buffer[0] = '\0';

    while(1){
        char c = uart_read();
        if(c >= 32 && c <= 126){
            // Reserve one byte for the string terminator.
            if(length < MAX_CMD_LENGTH - 1){
                buffer[length++] = c;
                uart_write(c);
            }
        }
        else if(c == '\n'){
            buffer[length] = '\0';
            uart_put("\n");
            break;
        }
        else if(c == 127 || c == '\b'){
            if(length > 0){
                length--;
                // Move left, erase the character, and move left again.
                uart_put("\b \b");
            }
        }
    }
}
int cmd_strcmp(const char *p1, const char *p2) {
    const unsigned char *s1 = (const unsigned char *)p1;
    const unsigned char *s2 = (const unsigned char *)p2;
    unsigned char c1, c2;
    do {
        c1 = *s1++;
        c2 = *s2++;
        if(c1 == '\0') {
            return c1-c2;
        }
    } while (c1 == c2);
    return (c1-c2);
}

void shell_cmd_exec(char* buffer){
    for(unsigned int i = 0; i < CMD_COUNT; i++){
        if(cmd_strcmp(buffer, cmd_list[i].name) == 0){
            cmd_list[i].func();
            return;
        }
    }
    uart_put("Unknown command: ");
    uart_put(buffer);
    uart_put("\r\n");

}
//help: print all available command
void print_help(){
    for(unsigned int i = 0; i < CMD_COUNT; i++){
        uart_put(cmd_list[i].name);
        uart_put("\t\t: ");
        uart_put(cmd_list[i].description);
        uart_put("\r\n");
    }
}

//hello: print hello world
void print_hello_world(){
    uart_put("Hello World!\n");
}
//reboot: reboot the system
void reboot_system(){
    uart_put("rebooting...\n");
}
