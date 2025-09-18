#include <windows.h>  // Beep ke liye
#include <stdio.h>

int main() {
    printf("Alarm aa raha hai!\n");
    Beep(750, 300); // 750 Hz frequency, 300 milliseconds
    return 0;
}
