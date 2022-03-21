#ifndef _UARTZ_H_
#define _UARTZ_H_

#ifdef __cplusplus
extern "C"{
#endif

int uart_flush(int fd);

int uart_set(int fd, int baudrate);

int uart_open(const char *name);

int uart_close(int fd);

int uart_receive(int fd, char *rb, int count);

int uart_send(int fd, char *tb, int count);

#ifdef __cplusplus
}
#endif

#endif /* _UARTZ_H_ */
