/*
Un pequeño script que cambia el color de leds como un semáforo.

También tiene conectado un led RGB que se pone morado cuando no hay
ningún led encendido.

El circuito tiene puenteado un buzzer que suena en verde para que sea 
apto para ciegos.

Cada 500ms lee si el botón está pulsado y con eso cambia el valor.
Esto también tiene como efecto que si dejamos el botón pulsado,
los colores cambian cada 500ms, siendo más divertido para el niño :)
*/

const int ledPin = LED_BUILTIN;  // the number of the LED pin

// inicio el currentPin a 1 para que no se ilumine ningún led
int currentPin = 1;

int ledState = LOW;  // ledState used to set the LED

// valores para el led RGB
int redPin = 8;
int greenPin = 9;
int bluePin = 10;

void logicaPrincipal(){

  leerBoton();

  apagarTodasLasLuces();

  cambiarDeColorElLedRGB();

  encenderElPinActivoDelSemaforo();

}

void iniciarSemaforo(){
  // harcodeados para enterarme de dónde estoy pinchando
  pinMode(6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void iniciarLedRGB(){
  // estos son para el led RGB que le gusta a mi hijo
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void leerBoton()
{
  byte buttonState = digitalRead(6);

  if (buttonState == LOW) {
    
    currentPin = currentPin + 1;
    
    if(currentPin == 5){ // si nos vamos al pin que no es, apagamos.
      currentPin = 1;
    }

    Serial.println("Botón pulsado:");
    Serial.println(currentPin);

  }
}

void apagarTodasLasLuces(){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    digitalWrite(currentPin, LOW);
}

void encenderElPinActivoDelSemaforo(){
  digitalWrite(currentPin, HIGH);
}

void cambiarDeColorElLedRGB(){
    if(currentPin == 2){
      digitalWrite(redPin, HIGH);
    } else if(currentPin == 3){
      digitalWrite(greenPin, HIGH);
    } else if(currentPin == 4){
      digitalWrite(bluePin, HIGH);
    } else {
        
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);

      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
    }
}

void setup() {  
  // Para enviar mensajes de log
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);

  iniciarSemaforo();

  iniciarLedRGB();
}

void loop() {
  delay(500);

  logicaPrincipal();
  
}
