
#include <NewPing.h>
#define underPingpin 2
#define rightPingpin 12
#define frontPingpin 13
#define leftPingpin 3

NewPing UnderPing(underPingpin, underPingpin, 200);
NewPing RightPing(rightPingpin, rightPingpin, 200);
NewPing FrontPing(frontPingpin, frontPingpin, 200);
NewPing LeftPing(leftPingpin, leftPingpin, 200);

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
  //het declareren van alle motor pins:
  pinMode(LMpin1, OUTPUT);
  pinMode(LMpin2, OUTPUT);
  pinMode(LMpin3, OUTPUT);
  pinMode(LMpin4, OUTPUT);
  pinMode(RMpin1, OUTPUT);
  pinMode(RMpin2, OUTPUT);
  pinMode(RMpin3, OUTPUT);
  pinMode(RMpin4, OUTPUT);
  pinMode(1, OUTPUT);
  digitalWrite(1,LOW);
  Serial.begin(9600);
}

void loop() {

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



  if (warningFlagU)
  {
    while (true)
    {
      checkPingRight();
      checkDistRight();

      checkPingLeft();
      checkDistLeft();

      anticlockwise();

      if (warningFlagR)
      {
        break;
      }
      else if (warningFlagL)
      {
        for (int i = 0; i < 50; i ++)
        {
          anticlockwise();
        }
        for (int i = 0; i < 285; i ++)
        {
          clockwiseR();
        }
        while (true)
        {
          checkPingFront();
          checkDistFront();
          clockwise();
          if (warningFlagCloseF)
          {
            for (int i = 0; i < 275; i ++)
            {
              clockwiseR();

            }
            break;
          }
        }
      }

    }



  }



  if (warningFlagR)
  {
    /*
    //bijstuur algoritme om hem recht te zetten voor een bocht:
    bijsturen();


    //check of de robot dichtbij een muur staat voor hem:

    //ga naar voren totdat je 6 cm van de muur afbent
    for (int j = 0; j < 270; j ++)
    {
      clockwise();
      checkPingFront();
      checkDistFront();
      if (Distfront < 7)
      {
        break;
      }
    }
    //draai de bocht om naar rechts
    for (int i = 0; i < 280; i ++)
    {
      clockwiseL();

    }





    //check of er een gracht is onder je:
    checkPingUnder();
    checkDistUnder();
    if (Distunder > 20)
    {
      for (int i = 0; i < 280; i++)
      {
        anticlockwiseL(); 
      }
      for (int i = 0; i < 130; i ++)
      {
        clockwise();
      }
    }

  }
  */
bijsturen();
   


    for (int j = 0; j < 270; j ++)
    {
      clockwise();
      checkPingFront();
      checkDistFront();
      if (Distfront < 7)
      {
        break;
      }
    }
    for (int i = 0; i < 280; i ++)
    {
      clockwiseL();
    }

  

  }







  //als je op een kruispunt bent ga naar rechts:
  else if (warningFlagR && warningFlagL && warningFlagF)
  {

    for (int i = 0; i < 80; i ++)
    {
      clockwise();
    }
    for (int i = 0; i < 280; i ++)
    {
      clockwiseL();
    }
  }




  //als je naar links kan en ook rechtdoor blijf rechtdoor gaan:
  else if (warningFlagL && warningFlagF && !warningFlagR)
  {
    
    while (true)
    {
      
      checkPingFront();
      checkDistFront();
      checkPingRight();
      checkDistRight();

      clockwise();
      
     if(warningFlagCloseF)
      {
        break;
      }
      else if(warningFlagR)
      {
        break;
      }
    }  

  }



  //als je uiteindelijk naar links kan, bijsturen en naar links:
  else if (warningFlagL)
  {
   
    bijsturen();
   


    for (int j = 0; j < 270; j ++)
    {
      clockwise();
      checkPingFront();
      checkDistFront();
      if (Distfront < 7)
      {
        break;
      }
    }
    for (int i = 0; i < 280; i ++)
    {
      clockwiseR();
    }
   
  }

  else if(!warningFlagR && !warningFlagL && warningFlagCloseF)
  {
   while(true)
   {
   checkPingLeft();
   checkDistLeft();
   checkPingRight();
   checkDistRight();

   anticlockwise();
   if(warningFlagL)
   {
    for(int i =0; i < 80; i ++)
    {
      clockwise();
    }
    for(int i =0; i < 140; i ++)
    {
      anticlockwiseL();
      clockwiseR();
    }
   }
   else if(warningFlagR)
   {
    for(int i =0; i < 80; i ++)
    {
      clockwise();
    }
    for(int i =0; i < 140; i ++)
    {
      anticlockwiseR();
      clockwiseL();
    }
   }

    
   }



    
  }




  // als je uiteindelijk niks kan en rechtdoor moeet: blijf bijsturen en break als je naar links of rechts kan:
  else
  {
    while (!warningFlagR && !warningFlagL)
    {
      bijsturen();

      clockwise();
      checkPingLeft();
      checkDistLeft();
      checkPingRight();
      checkDistRight();
     

      if (warningFlagR || warningFlagL || warningFlagCloseF)
      {
        break;
      }
      

    }
  }
}


