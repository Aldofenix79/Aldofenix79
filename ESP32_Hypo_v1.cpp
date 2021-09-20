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
