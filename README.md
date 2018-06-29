# ArduinoPWMController
For Lite-ON VSA Team

User envirement:
arduino-1.0.1 IDE
Arduino Uno

To User:

  This's Code for PWM signal output, and I diliver in three mode. 
  All of program can be rewrited to fit different situations , just change the parameters at the top of program

Mode I  :

    Program name    : Triple_signal 
    Signal freqence : 60  Hz (default) 
    Output Voltage  : 4.7 V
    depiction       : In this mode, I set three different and synchronous pulse width.
    
    Output Pin :

      Pin-4 :  duty cycle => 0.6%  pulse width => 100 microsecend
      Pin-7 :  duty cycle => 2.0%  pulse width => 333 microsecend
      Pin-8 :  duty cycle => 3.0%  pulse width => 500 microsecend
    

Mode II :

    Program name    : PWM_asynchronous
    Signal freqence : 60  Hz (default)
    Output Voltage  : 4.7 V
    depiction       : In this mode, User set duty_cycle for signal_1 at first,and signal_1 will be a stantard. Second, User set Timing  andduty_cycle.(Ex: Timing=200 >>> signal_2 leading signal_1 200 microsecend|||Timing=-300 >>> signal_2 laging signal_1  300 microsecend) 
  
    Output Pin :
      Pin-7 :  duty cycle => 0.6%  pulse width => 100 microsecend
      Pin-8 :  duty cycle => 3.0%  pulse width => 500 microsecend

Mode III :

    Program name    : PWM_switch
    Signal freqence : 60  Hz (default)
    Output Voltage  : 4.7 V
    depiction       : In this mode, User can change the duty cycle by touching 5V_Pin with Pin_2. 
   
    Input  Pin :
      Pin-2 :  mode swicth
    Output Pin :
      Pin-4 :  (case1) duty cycle => 3.0%  pulse width => 500 microsecend
               (case2) duty cycle => 2.0%  pulse width => 333 microsecend
               (case3) duty cycle => 0.6%  pulse width => 100 microsecend
