unsigned long LastMicros;

void setup( void ) {
  Serial.begin( 2000000 );
  LastMicros = micros();
}

void loop( void ) {
 unsigned long ThisMicros;
 unsigned long Delta;
 
 ThisMicros = micros();
 Delta = ThisMicros - LastMicros;
 LastMicros = ThisMicros;
 Serial.println( Delta );
 
 //delay( 1001 );
}
