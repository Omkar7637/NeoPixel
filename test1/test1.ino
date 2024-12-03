#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h> 


#define PIN 12

int delayValue=500;
int i,j,k,m,n,x; 
//the Wemos WS2812B RGB shield has 1 LED connected to pin 2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(300, PIN, NEO_GRB + NEO_KHZ800);

const unsigned int bitmap24[]={
 
0xD1A4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00,    // 0x0010 1 -(00-14) pixels
0x00, 0x00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7F007F, 0x0000,    // 0x0020 2 -(15-29) pixels

0x0000, 0x0000, 0x7F007F, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x0030 3 -(30-44) pixels
0x0000, 0x00, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x000, 0x0000, 0x7F007F, 0x00, 0x0000, 0x00, 0x0000,    // 0x0040 4 -(45-59) pixels

0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x0050 5 -(60-74) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x00, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x0060 6 -(75-89) pixels

0x0000, 0x0000, 0x0000, 0x7F007F, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x0070 7 -(90-104) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x0000, 0x0000, 0x0000, 0xD1A4, 0x00, 0x0000,    // 0x0080 8 -(105-119) pixels

0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00, 0x001f1f, 0x001f1f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x0090 9 -(120-134) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f1f, 0x001f1f, 0x00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x00A0 10(135-159) pixels

0x0000, 0x0000, 0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000, 0x0000, 0x0000,    // 0x 00B0 11-(150-164) pixels
0x0000, 0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000, 0x0000,    // 0x00C0 12-(165-179) pixels

0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0x00007f, 0x00, 0x00007f, 0x00007f, 0x00007f, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000,    // 0x00D0 13-(180-194) pixels
0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0x00007f, 0x7F007F, 0x00007f, 0x7F007F, 0x00, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000,    // 0x00E0 14-(195-209) pixels

0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0x00007f, 0x00007f, 0x00007f, 0x00007f, 0x00007f, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000,    // 0x00F0 15-(210-224) pixels
0x0000, 0x0000, 0xA902, 0xA902, 0xA902, 0x00, 0x7F007F, 0x00007f, 0x7F007f, 0x00007f, 0xA902, 0xA902, 0xA902, 0x0000, 0x0000,    // 0x0100 16-(225-239) pixels

0x0000, 0x0000, 0xA902, 0xA902, 0xA902, 0x00007f, 0x00007f, 0x00007f, 0x00, 0x00007f, 0xA902, 0xA902, 0xA902, 0x0000, 0x0000,    // 0x0110 17-(240-254) pixels
0x0000, 0x0000, 0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000, 0x0000, 0x0000,    // 0x0120 18-(255-269) pixels

0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0xA902, 0x0000, 0x0000, 0x0000, 0x0000,    // 0x0130 19-(270-284) pixels
0xD1A4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00    // 0x0140 20-(285-300) pixels

};


  
void setup() 
{
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
 
}


void loop() 
{

/*
   for(m=0; m<300; m++)  { pixels.setPixelColor(m,0x0); }
   pixels.show();

//-----------------------------------------------------------------------------------------------------
// Image rolling from Top to the Center of the Matrix   
    
//*********************************                          
      
      for(m=0; m<15; m++){ Serial.print(m);  Serial.print("  ");  }
      Serial.println("\n"); 
      delay(500);
   
//********************************* 
      
      for(m=0; m<15; m++){ Serial.print(m);  Serial.print("  ");  }
     
      
      for(m=0; m<15; m++){ Serial.print(29-m);  Serial.print("  "); }
      Serial.println("\n"); 
      delay(500);
//********************************* 
      
      for(m=0; m<15; m++){ Serial.print(m);  Serial.print("  ");  }
      
      for(m=0; m<15; m++){ Serial.print(29-m);  Serial.print("  "); }
      
      for(m=0; m<15; m++){ Serial.print(30+m);  Serial.print("  "); }
      Serial.println("\n"); 
      delay(500);
//********************************* 
    
      for(m=0; m<15; m++){ Serial.print(m);  Serial.print("  ");  }
     
      for(m=0; m<15; m++){ Serial.print(29-m);  Serial.print("  "); }
 
      for(m=0; m<15; m++){ Serial.print(30+m);  Serial.print("  "); }

      for(m=0; m<15; m++){ Serial.print(59-m);  Serial.print("  "); }
      Serial.println("\n"); 
      delay(500);



    delay(3000);

}
*/
//********* THE PROGRAM END HERE **************
/* 
//simple function which takes values for the red, green and blue led and also
//a delay
void setColor(int led, int redValue, int greenValue, int blueValue, int delayValue)
{
  pixels.setPixelColor(led, pixels.Color(redValue, greenValue, blueValue)); 
  pixels.show();
  delay(delayValue);
}

*/



//--------------------------------------------------------------------------------
//Panti rolling from Right to Left code

  for(i=0; i<15; i++)
   {    
    for(j=0; j<10; j++)
     {
       n= ((14-i)+(j*30)); 
       x=j*30;
       for(m=0; m<i+1; m++){pixels.setPixelColor(n++,bitmap24[x++]);}

       x=15+(j*30);   
       n=((15+i)+(j*30));
       for(m=0; m<i+1; m++){pixels.setPixelColor(n--,bitmap24[x++] ); }
     }
      pixels.show();
      delay(70);
    }
  
 
 //***********************   

  for(i=14; i>0; i--)
   {    
        
    for(j=0; j<10; j++)
     {
       n=j*30;                            
       x=((15-i)+(j*30));
       for(m=i; m>0; m--){pixels.setPixelColor(n++,bitmap24[x++]); }
     
       x=((30-i)+(j*30));                                       
       n=29+(j*30);                            
       for(m=i; m>0; m--){pixels.setPixelColor(n--,bitmap24[x++]);  }     
     } 
      pixels.show();
      delay(70);       
    }  

}
/*
//-----------------------------------------------------------------------------------------------------
// Image rolling from Left to the Center of the Matrix   

   for(i=0; i<14; i++)
   {          
    for(j=0; j<10; j++)
     {
       n= j*30;                       
       x=(14-i)+(j*30);    
       for(m=0; m<i+1; m++){pixels.setPixelColor(n++,bitmap24[x++]);}

       x=(29-i)+(j*30);   
       n=29 +(j*30);                           
       for(m=0; m<i+1; m++){pixels.setPixelColor(n--,bitmap24[x++]);}
     }
     pixels.show();
     delay(30);        
   }  

//--------------------------------------------------------------------------------------------------------
// Image rolling from Center to the Right of the Matrix   

   for(i=14; i>=0; i--)
   {          
    for(j=0; j<10; j++)
     {
       n= (14-i)+(j*30);                       
       x=j*30;
       for(m=0; m<i+1; m++){pixels.setPixelColor(n++,bitmap24[x++]);}
     }
       
       n=(15+i) +(j*30); 
       x=15+(j*30);                          
       for(m=0; m<i+1; m++){pixels.setPixelColor(n--,bitmap24[x++]);}
    }
     pixels.show();
     delay(30);   
     
     for(m=0; m<300; m++)  { pixels.setPixelColor(m,0x0); }
     pixels.show();
     
    }  

    delay(3000);
*/
