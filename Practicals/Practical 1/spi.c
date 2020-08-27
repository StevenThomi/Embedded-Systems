/*
 *****************************************************************************************
 * Practical 1
 * WRITTEN BY: STEVEN THOMI
 * DATE CREATED: 26TH AUGUST 2020
 * LICENSE: MIT LICENSE
 *****************************************************************************************
 * You are on a team responsible for developing a super simple SPI interface for working
 * with a low baud-rate multiplexer.
 * To save costs, use the GPIO pins of a cheap microcontroller instead of having to buy a
 * microcontroller with dedicated SPI pins.
 
 * The code below implements the ability to shift out data over SPI using GPIO pins - to
 * save costs.
 * Using gdb, determine the failure points of the program. Consolidate these items into a
 * single PDF and submit it on Vula.
 
 * You can make the following assumptions:
 * The hardware is all connected and configured correctly
 * Setting the variables dataPin and clockPin writes those vales to the given pins
 * The clock pin normally sits sits low (CPOL = 0)
 * The expected value should be written out on the rising edge of clockPin (CPHA = 1)
 * The value intended to be shifted out is 0b11010101
 *****************************************************************************************
*/

//===========================================================
// SHIFT OUT ARGUMENT ON RISING EDGE OF CLOCK - shiftOut(int)
//===========================================================
// DESCRIPTION: This function uses pinState to shift out the
// formal parameters as bits on the rising edge of the system
// clock.
// - pinState : shifted out value
// - clockPin : regulates a clock cycle
// - dataPin  : physical microcontroller pin, on/off cycle
//===========================================================

void shiftOut(int myDataOut)
{
    // pinState set in loop
    int pinState;

    // clock initially set to low:
    // approaching rising edge
    int dataPin = 0;
    int clockPin = 0;
    
    // output 8 data bits
    // most significant bit (MSB) set to 0
    int i;
    for (i = 1; i <= 8; i++)
    {
        // clock set to low:
        // approaching rising edge
        // begin reading, active dataPin
        clockPin = 0;
        
        //---------------------------------------
        // LOGIC: If least significant bit (LSB)
        // is 0 then even, else odd
        // This is, of course, limiting myDataOut
        // to non-fractional binary
        //---------------------------------------
        // using example given in main(void),
        // all iterations illustrated for case:
        // myDataOut = 10110101
        //
        // 8 - i = 7 ; 00000001; output = 1
        // 8 - i = 6 ; 00000010; output = 0
        // 8 - i = 5 ; 00000101; output = 1
        // 8 - i = 4 ; 00001011; output = 1
        // 8 - i = 3 ; 00010110; output = 0
        // 8 - i = 2 ; 00101101; output = 1
        // 8 - i = 1 ; 01011010; output = 0
        // 8 - i = 0 ; 10110101; output = 1
        //---------------------------------------
        if ((myDataOut >>(8-i ))%2)!= 0 ) {
            pinState= 1;
        }
        else
        {
            pinState= 0;
        }
    
        // clock set to high:
        // terminate reading, deactive dataPin
        dataPin = 1;
        // gdb break //
        clockPin = 1;
        dataPin = 0;
        // gdb break //
    }
    
    clockPin = 0;
}

int main(){
    shiftOut(0b10110101);
    return 1;
}
