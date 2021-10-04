#include <iostream>
#include "heltec.h"
using namespace std;

class Display {
  protected:
  int x;
  int y;

  public:
    Display(){
      x=0;
      y=0;
      }
    Display &operator() (int nx, int ny) {
            x = nx;
            y = ny;
            return *this;
    }
    void inicio() {
       Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);
    }
    void imprimir(int x,int y,String txt){
        Heltec.display -> clear();
        Heltec.display -> drawString(x, y, txt);
        Heltec.display -> display();
    }
    friend Display& operator << (Display &d, const String &txt) {
        Heltec.display -> clear();
        Heltec.display -> drawString(d.x, d.y, txt);
        Heltec.display -> display();
        return d;
    }
    
};

Display screen; // def-ctor
String mensaje;
int con=0;
void setup() {
  // put your setup code here, to run once:
  screen.inicio();

}

void loop() {
  // put your main code here, to run repeatedly:
 // mensaje = "Funciona";
  //screen.imprimir(0,15,mensaje);
  con++;
  if(1==con){
  screen(0,15)<<"Ahora funciona";    
  }
  delay(1000);     
}
