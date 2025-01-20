#include <Adafruit_NeoPixel.h>

// API documentation for Adafruit_NeoPixel can be found here: 
// https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html

// Pin digital pin on the arduino that the LED string is connected to.
#define LED_PIN     6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  75

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50 // Set BRIGHTNESS to about 1/5 (max = 255)

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
}

void loop() {
  
  // Note: With strip.Color, you specify how much red, green and blue to use. The strip.Color method will
  // combine these colors together. The values for red, green and blue are in the range of (0-255). 
  // For example, to get a shade of purple, you can specify red and blue values (e.g. strip.Color(200,0,255)
 
 colorWipe(strip.Color(255,0,0), 50);
// showAllAtOnce(strip.Color(255,255,0));
// showAlternatingColorsAllAtOnce(strip.Color(0,255,0), strip.Color(0,0,255));
// showAlternatingColorsOneByOne(strip.Color(0,255,0), strip.Color(0,0,255));
// pulseHueOn(57085, 20);
}


// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
//
// TODO: Currently, this function only lights the first LED of the string. Modify it to 
// light all of the LEDs one after another as described above.
// Hint: Try a for loop. 
void colorWipe(uint32_t color, int wait) {
  strip.setPixelColor(0, color);
  delay(wait);
  strip.show();
}

// Fill strip with the specified color. All pixes in the strip will be lit at the same
// time.
//
// Hint: You do not need to use a for loop for this. 
// Check the documentation for the 
void showAllAtOnce(uint32_t color) {
  strip.setPixelColor(0, color);
  strip.show();
}

// Show a strip with alternating colors. After this function is called, the entire strip
// will display all at once with each even number pixel displaying color1 and each odd number pixel displaying color2.
// There are several ways to get the strip to show alternating colors. For example, there is the unimaganitive
// brute force method that I started below but was to lazy to finish where you explicitly set the color of 
// of each pixel. Do better. 
// Hints: 
// One method involes using a bool variable.
// Another method involves using the modulus operator.
//
// Both methods will require a for loop
void showAlternatingColorsAllAtOnce(uint32_t color1, uint32_t color2){
  strip.setPixelColor(0,color1);
  strip.setPixelColor(1,color2);
  strip.show();
}

// Show a strip with alternating colors one at a time. One this function is called, each pixel will display
// one at a time until the entire string is lit.
// Hint: You could implement this method with a for loop but ... Check out the adafruit documentation first:
// https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html
void showAlternatingColorsOneByOne(uint32_t color1, uint32_t color2){
  strip.setPixelColor(0,color1);
  strip.setPixelColor(1,color2);
  strip.show();
}

// Show a strip all one color and have it gradually brighten. This method uses strip.ColorHSV instead of 
// strip.Color in order to specify the color that each pixel will be set to. strip.ColorHSV takes as parameters, a hue, 
// staturation and brightness value. 
//
// The function will repeatidly get a color by calling strip.ColorHSV and set all of the pixes in the LED strip to that color.
// The first parameter in the call to strip.ColorHSV will be the hue value. The second parameter will be 255. The third parameter
// (the brightness) will start at 0 and increase by 1 for each successive call. 
// For the first parameter hue, use the 'hue' value that was passed into pulseHueOn, for
// 
void pulseHueOn(uint16_t hue, uint8_t wait) {
  delay(wait);
  strip.setPixelColor(0,strip.ColorHSV(hue, 255, 10));
  strip.show();
}
