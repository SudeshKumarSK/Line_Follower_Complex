int rm1 = 10;
int rm2 = 11;
int lm1 = 6;
int lm2 = 9;
int l, c1, c2, c3, r,e; //naming the sensors
int i;

int tdelay = 160;  //320

void Stop()                          //stop
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}

void forward()
{
  analogWrite(lm1,200);
  analogWrite(lm2,0);
  analogWrite(rm1,200);
  analogWrite(rm2,0);
  
}
void forward1()                        //forward_less_speed
{
  analogWrite(lm1,128);
  analogWrite(lm2,0);
  analogWrite(rm1,128);
  analogWrite(rm2,0);
} 
void smallright()                  //small right
{
  analogWrite(lm1,200);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
void smallleft()                    //small left
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,200);
  analogWrite(rm2,0);
}

void right()                        //right
{
  analogWrite(lm1,200);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,200);
  
}
void left()                          //left
{
  analogWrite(lm1,0);
  analogWrite(lm2,200);
  analogWrite(rm1,200);
  analogWrite(rm2,0);
  
}


int eosens()
{
  readsens();
  if (((c1 + c2 + c3) == 1) || ((c1 + c2 + c3) == 2))
    return 1;
  else
    return 0;
}


void readsens()                      //reading sensors
{
  l = digitalRead(A0);
  c1 = digitalRead(A1);
  c2 = digitalRead(A2);
  c3 = digitalRead(A3);
  r = digitalRead(A4);
} 


void inch()
{
  Stop();
  delay(150);
  forward();
  delay(70);
  Stop();
  delay(150);
  readsens();
}

void setup()
{
 //Declare input pins

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  //pinMode(en1, OUTPUT);
  //pinMode(en2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  //Serial.begin(115170);
}


void loop()
{

 
  readsens();

 if((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1))
  {
    forward();
  }

  else if(((l==1)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1))||((l==1)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1))||((l==0)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1)))
  {
    smallleft();
   
  }

   else if(((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==1))||((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==1))||((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==0))||((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==0)))
  {
    smallright();
  }

  else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
  {
    inch();
    //readsens();
    e=eosens();
    if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))
    {
    right();
    }
    
    else if(e==1)
    {
      forward();
    }
    
  }


  else if((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==0)||(l==1)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
  {
    inch();
    if(eosens())
    {
    forward();
    delay(tdelay);
    }
    else
    {
      right();
      delay(tdelay);
    }
    
    
    
  }
  
  else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)))
  {
    inch();
   if(eosens())
    {
    forward();
    delay(100);
    }
    else
    {
      left();
      delay(tdelay);
    }
  }
else if (((l=0)&&(c1=1)&&(c2=0)&&(c3=1)&&(r=1))||((l=1)&&(c1=0)&&(c2=1)&&(c3=0)&&(r=1)))
{
  left();
}
 else if ((l=1)&&(c1=1)&&(c2=0)&&(c3=1)&&(r=0))
  {
    right();
  }
 
  }
/*
  //########################################################
  else if((l==1)&&(c1==0)&&(c2==1)&&(c3==0)&&(r==1)||(l==1)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)||(l==0)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1)||(l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==0))
  {
    right();
    delay(75);
  }

*/
