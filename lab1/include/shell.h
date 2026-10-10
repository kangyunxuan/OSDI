#ifndef __SHELL_H
#define __SHELL_H

#define MAX_CMD_LENGTH 128

//strcmp
void shell_cmd_read(char *buffer);
void shell_cmd_exec(char* buffer);
void print_help();
void print_hello_world();
void reboot_system();
int cmd_strcmp(const char *p1, const char *p2);

#endif