#include "uart.h"
#include "shell.h"

void main(){
    uart_init();
    char buffer[MAX_CMD_LENGTH];
    while(1){
        uart_put("# ");
        shell_cmd_read(buffer);
        shell_cmd_exec(buffer);


    }
}
