#ifndef ERRORS_H
#define ERRORS_H
// Function of return error pages
// THIS HERE
#include <unistd.h>
#include "confs.h"
#include "motor.h"
void client_error(int fd, int status, char *msg, char *longmsg){
    char buf[MAXLINE];
    sprintf(buf, "HTTP/1.1 %d %s\r\n", status, msg);
    sprintf(buf + strlen(buf),
            "Content-length: %lo\r\n\r\n", strlen(longmsg));
    sprintf(buf + strlen(buf), "%s", longmsg);
    writen(fd, buf, strlen(buf));
}
#endif
