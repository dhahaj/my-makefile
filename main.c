/**
* 
* 
*/

#define F_CPU 16000000
//#define DEVICE atmega328p
//#define __AVR_ATmega328P__

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/portpins.h>
#include <util/delay.h>

#define HIGH 1
#define LOW 0
#define get_pin(port, pin) (PORT ## port & _BV(pin)) >> pin
#define write_pin(port, pin, value) (value >=1 ? ( PORT ## port &= ~(_BV(pin) ) ) : ( PORT ## port |=   _BV(pin) )  )
#define set_low(port, pin) (PORT ## port &= ~(_BV(pin)))
#define set_high(port, pin) (PORT ## port |= (_BV(pin)))

typedef uint8_t byte;

byte mask = _BV(PB5) | _BV(PB4);

const char st[] PROGMEM = 	"test\r\n" \
"hdhdcjmdc";

void init(void)
{
	DDRB |= mask;
	DDRC = 0xFF;
	PORTC = 0xFF; 
	PORTB = mask; 
	_delay_ms(1000);
}	

int main(void)
{
	init();
	for(;;) {
		PORTC = PORTC ^ 0xFF;
		_delay_ms(50);
		byte v2 = get_pin(B, PB5);
		
		if(v2==HIGH)
			set_low(B, PB5);
		else
			set_high(B, PB5);
	}
	return 0;
}
