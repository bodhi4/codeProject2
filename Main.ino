
#include <NewPing.h>
#define underPingpin 2
#define rightPingpin 12
#define frontPingpin 13
#define leftPingpin 3
NewPing UnderPing(underPingpin,underPingpin,200);
NewPing RightPing(rightPingpin,rightPingpin,50);
NewPing FrontPing(frontPingpin, frontPingpin, 200);
NewPing LeftPing(leftPingpin, leftPingpin, 50);

int Distunder = 0;
int Distright = 0;
int Distfront = 0;
int DistLeft = 0;


bool warningFlagU;
bool warningFlagR;
bool warningFlagF;
bool warningFlagL;
bool warningFlagCloseF;


void setup() {
 //declare the motor pins as outputs
 pinMode(LMpin1, OUTPUT);
 pinMode(LMpin2, OUTPUT);
 pinMode(LMpin3, OUTPUT);
 pinMode(LMpin4, OUTPUT);
 pinMode(RMpin1, OUTPUT);
 pinMode(RMpin2, OUTPUT);
 pinMode(RMpin3, OUTPUT);
 pinMode(RMpin4, OUTPUT);

 Serial.begin(9600);
}

void loop(){



 warningFlagU = false;
 warningFlagR = false;
 warningFlagF = false;
 warningFlagL = false;
 warningFlagCloseF = false;
  checkPingRight();
  checkDistRight();
  
  checkPingUnder();
  checkDistUnder();

  checkPingFront();
  checkDistFront();

  checkPingLeft();
  checkDistLeft();
  


  
    if(warningFlagR)
     {
   
       if(warningFlagCloseF)
        {
           while(Distfront < 10)
            {
              {
                 clockwiseL();
                  anticlockwiseR();
              }
                checkPingFront();
                 checkDistFront();
               if(warningFlagF)
                {
                   break;
                }
            }
        }
        else if(warningFlagCloseF == false)
        {
          for(int j = 0; j < 126; j ++)
          {
            clockwise();
          }
          for(int i = 0; i < 256;i ++)
          {
            clockwiseL();
            anticlockwiseR();
          }
          checkPingFront();
          checkDistFront();
          if(Distfront > 10)
          {
            clockwise();
          }
        }
     }

      else if(warningFlagL)
      {
         for(int j = 0; j < 126; j ++)
          {
            clockwise();
          }
          for(int i = 0; i < 256;i ++)
          {
            clockwiseR();
            anticlockwiseL();
          }
          checkPingFront();
          checkDistFront();
          if(Distfront > 10)
          {
            clockwise();
          }
      }
       




    
   else if(warningFlagCloseF == true && warningFlagR == false)
   {
    while(warningFlagCloseF)
    {
     {
      clockwiseR();
      anticlockwiseL();
     }
      checkPingFront();
      checkDistFront();
      if(Distfront> 10)
      {
        clockwise();
      }
      
      
    }
    
   }
      
      
     
  
   
   
  
  else
  {
    
      clockwise();
    
  }
    

}

