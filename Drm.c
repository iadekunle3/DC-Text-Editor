#include <unistd.h>
#include <termios.h>
#include <stdlib.h>


struct termios orig_termios; // 0

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO); //c_lflag used to flip echo attribute
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}

