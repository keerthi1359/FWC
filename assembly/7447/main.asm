.include "m328pdef.inc"

ldi r16,0b11100011
out DDRD,r16

ldi r17,0b11111111          ; activating pull ups
out PORTD,r17

ldi r16,0b00000001
out DDRB,r16                ; PB0 as output

start:
        in r17,PIND         ; read port D

        ldi r24,0b00000100
        mov r18,r17
        and r18,r24
        ldi r25,0b00000010
loopx:  lsr r18
        dec r25
        brne loopx
.DEF Z = r18

;Taking y (PD3)
        mov r19,r17
        ldi r24,0b00001000
        and r19,r24
        ldi r25,0b00000011
loopy:  lsr r19
        dec r25
        brne loopy
.DEF Y = r19

        ldi r24,0b00010000
        mov r20,r17
        and r20,r24
        ldi r25,0b00000100
loopz:  lsr r20
        dec r25
        brne loopz
.DEF X = r20

        ldi r21,0x00
        ldi r22,0x00
        ldi r23,0x00
.DEF T1 = r21
.DEF T2 = r22
.DEF T3 = r23

        ; T1 = X & (~Y)
        mov T1, Y
        com T1              ; T1 = ~Y (all bits inverted)
        and T1, X           ; T1 = X & ~Y

        ; T2 = (~X) & Y
        mov T2, X
        com T2              ; T2 = ~X
        and T2, Y           ; T2 = ~X & Y

        ; F = T1 | T2
        or  T1, T2          ; T1 = XOR result (bit0)

        andi T1, 0x01       ; keep only bit0 clean
        out PORTB, T1       ; output on PB0

        rjmp start
