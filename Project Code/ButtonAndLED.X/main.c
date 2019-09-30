#include "main.h"

void main()
{
    init_MAX7219();
    HC_05_Init();
    External_Interrupt_Init();
    TRISDbits.RD0 = 1;
    TRISDbits.RD1 = 1;
    do
    {
        
        for(int i=1; i<=8; i++) {
            MAX7219_1Unit(i,0);
        }
        if(right_flag){
            TurnRight();
            Close();
        }
        else if(left_flag){
            TurnLeft();
            Close();
        }
  
       receiveMsg();
    } while(1);
}