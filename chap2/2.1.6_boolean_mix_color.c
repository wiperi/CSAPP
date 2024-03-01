#include <stdio.h>

#define BLACK 0b000
#define WHITE 0b111
#define GREEN 0b010
#define CYAN 0b011
#define RED 0b100
#define MAGENTA 0b101
#define YELLOW 0b110
#define BLUE 0b001

void show_color(int color) {
    switch (color) {
        case BLACK:
            printf("BLACK\n");
            break;
        case WHITE:
            printf("WHITE\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        case CYAN:
            printf("CYAN\n");
            break;
        case RED:
            printf("RED\n");
            break;
        case MAGENTA:
            printf("MAGENTA\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
        case BLUE:
            printf("BLUE\n");
            break;
        default:
            printf("UNKNOWN\n");
            break;
    }
}

int main(int argc, char* argv[]) {
    show_color(RED ^ MAGENTA);
    show_color(YELLOW & CYAN);
    show_color(BLUE | GREEN);
    return 0;
}