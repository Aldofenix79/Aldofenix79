// ESP32 hypo version 1

// estructuras datos: vector, array, tuple, pair 
// pair<T1,T2> = template class

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <tuple>
#include <utility> // pair
//#include <math.h> // sqrt
#include <cmath> // hypot

#define INLINE inline __attribute__((always_inline))

using namespace std;

int ledPin = 2;

INLINE float square(float num) { return num * num; }

INLINE float hipo(float n1, float n2) { return sqrt(square(n1) + square(n2)); }

double suma;

int veces;

int ledState = LOW;

using Catetos = pair<float,float>; // sinonimo-tipo array<float,2>; tuple<float, float>; 
//using Catetos = tuple<float,float>; // sinonimo-tipo array<float,2>; tuple<float, float>; 
//using Catetos = array<float,2>; // sinonimo-tipo array<float,2>; tuple<float, float>; 
using  Triang = vector<Catetos>;

Triang cat = { {2.0F, 2.5F}, {5.0F, 5.5F}, {5.0F, 6.0F} }; // vector<pair<float, float>>



void setup() {
    
    Serial.begin(9600);
    delay(3000);
    //for (auto [c1, c2] : cat) { // type inferencing + structured binding + for-collection
    for (auto par : cat) // structured binding
    {                               
        auto c1 = get<0>(par); //par.first;
        auto c2 = get<1>(par); //par.second;
        cout
            << fixed << setw(5) << setprecision(2)
            << "cateto#1: "   << c1 
            << ", cateto#2: " << c2 << ", hipotenusa: "
            //<< hipo(c1, c2) << endl;
            //<< hypot(c1, c2) << endl;
            << hypot(c1, c2)
            <<"\n El total de la suma es: "<< (suma = suma + static_cast<double>(hypot(c1, c2))) //sumatoria y casteo
            <<"\n Las veces que parpadearea el led son: "<< (veces = static_cast<int>(suma)) << endl;

            
    }
    pinMode(ledPin, OUTPUT);
    /*
    for (int i=0;i<=veces*2;i++)
    {
    if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
    else 
      {
      ledState = LOW;
      }
    cout<<"Parpadeo # "<<(i/2)<<endl;
    digitalWrite(ledPin, ledState);
    delay(500);
    digitalWrite(ledPin, ledState);
    }   
    digitalWrite(ledPin, LOW); 
    */    
}

void loop()
{
  for (int i=0;i<=veces*2;i++)
    {
    if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
    else 
      {
      ledState = LOW;
      }
    cout<<"Parpadeo # "<<(i/2)<<endl;
    digitalWrite(ledPin, ledState);
    delay(500);
    digitalWrite(ledPin, ledState);
    }   
    digitalWrite(ledPin, LOW);
    delay(5000);
}
