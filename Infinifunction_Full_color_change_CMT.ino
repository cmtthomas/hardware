// RGBW (Red Green Blue White Neo-Pixel starter function 
// CW Coleman 181214 a
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 32
#define BRIGHTNESS(BRIGHTNESS);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);
// *******************************************************
void setup() {
  Serial.begin(115200);
  strip.setBrightness(50);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
// *******************************************************
// Initialize some variables for the void loop()
// global vaiables
int red = 0,  green = 255, blue = 255, white = 10, led;

int wait = 100;
int count = 0;
// *******************************************************

void loop() {
  
  if (count = 0) neo_black(0,0,0,0,0,16);
  //delay(1000);
  snake_function(16, 20, red, green, blue, white); 
  delay(50);
  neg_snake_function(12, -1, red, green, blue, white);
  delay(50);
  neg_snake_function(15,12, red, green, blue, white); 
  delay(50);
  snake_function(20, 32, red, green, blue, white); 
  delay(wait);
  //red = red +15, green = green-10, blue = blue -30; //1st attempt, larger specturm of color but slow to start
  red = red +50, green = green-70, blue = blue -60;  //2nd attempt, narrower spectrum but more differentiable colors
  //Serial.print(red,green,blue);
  if (red >= 255) red = 19;
  if (green <=0) green = 225;
  if (blue <= 0) blue = 128;
  Serial.print("R:");
  Serial.print(red); 
  Serial.print(" ");
  Serial.print("G:");
  Serial.print(green);
  Serial.print(" ");
  Serial.print("B:");
  Serial.print(blue);  
  Serial.print("    |    ");
  
  neo_black(0,0,0,0,16,20);
  back_to_neo_black(0,0,0,0,12,-1); 
  back_to_neo_black(0,0,0,0,15,12);
  neo_black(0,0,0,0,20,32);
  //delay(wait);
  
  
  
  
}
// *******************************************************
// globals l (LEDS)  done (stop variable)
int l = 0 ; int done;

void snake_function (int sled, int eled, int r, int g, int b, int w){

    for (int i = sled; i < eled; i++){
      white = w;
      red = r;
      green = g;
      blue = b;
      led = i; 
      strip.setPixelColor(led, red, green , blue, white);
      delay(wait);
      strip.show();
  }
}

void alt_neg_snake_function (int sled, int eled, int r, int g, int b, int w){

    for (int i = sled; i < eled; i--){
      white = w;
      red = r;
      green = g;
      blue = b;
      led = i; 
      strip.setPixelColor(led, red, green , blue, white);
      delay(wait);
      strip.show();
  }
}

void neg_snake_function (int nsled, int neled, int r, int g, int b, int w){

    for (int i = nsled; i > neled; i--){
      white = w;
      red = r;
      green = g;
      blue = b;
      led = i; 
      strip.setPixelColor(led, red, green , blue, white);
      delay(wait);
      strip.show();
  }
}


// Blanking Functions***************************************
void neo_black (int r, int g, int b, int w, int led, int fled ){
    //n is the led
    for (int n = led; n < fled;n++){
      strip.setPixelColor(n, r, g , b, w);
      strip.show();
      delay(wait);
    }
}
void back_to_neo_black (int r, int g, int b, int w, int led, int fled ){
    //n is the led
    for (int n = led; n > fled;n--){
      strip.setPixelColor(n, r, g , b, w);
      strip.show();
      delay(wait);
    }
}
void alt_back_to_neo_black (int r, int g, int b, int w, int led, int fled ){
    //n is the led
    for (int n = led; n < fled;n--){
      strip.setPixelColor(n, r, g , b, w);
      strip.show();
      delay(wait);
    }

Serial.print(" * * BLACK * *");

}
