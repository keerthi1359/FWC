#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

int main(void)
{
    int A, B;
    bool Q;
    DDRD = 0b00000000;
    PORTD = 0xFC;  

    DDRB = 0b00100000;

    while (1)
    {

        A = (PIND & (1 << PIND2)) == (1 << PIND2);
        B = (PIND & (1 << PIND3)) == (1 << PIND3);
        Q = (!A) || B;
        PORTB = (Q << 5);
        _delay_ms(10);
    }
    return 0;
}
