/* ****************************************************
 * ****                                           *****
 * ****  ESTACIÓN DE SOLDADURA BGA Y REFLOW       *****
 * ****  VER: 0.9 RC1  by CyX - FabLab Mérida     *****
 * ****                                           *****
 * ****************************************************/
 

#include <LiquidCrystal.h> //https://www.arduino.cc/reference/en/libraries/liquidcrystal/
#include <thermistor.h> //https://github.com/miguel5612/ThermistorLibrary


// ##### Variables de configuración ####

//Configuración de hardware
int tipo_termistor = 1; //https://github.com/miguel5612/ThermistorLibrary#supported-thermistors
int tasa_temp = 10;  // Grados de "caché" para que el estaño se funda

//Configuración de los pines

int pin_boton_mas = 6;
int pin_boton_menos = 7;
int pin_boton_ok = 8;
int pin_plancha = 9;
int pin_termistor = A0;

const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  //Pines de la pantalla

// Estáticas
int temp_min = 150;
int temp_max = 210;
int temp_act = temp_min;

// ##### Variables del programa ####
bool inicializado = false;
int temp;
thermistor tempe(pin_termistor, tipo_termistor);
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// ##### Funciones del programa ####

bool inicializacion();
void calentar();
int tomar_temp(); // Candidata a irse

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 4);
  pinMode(pin_plancha, OUTPUT);
  pinMode(pin_termistor, INPUT);
  pinMode(pin_boton_ok,INPUT);
  pinMode(pin_boton_mas,INPUT);
  pinMode(pin_boton_menos,INPUT);
  
}

void loop() {
  lcd.setCursor(5, 0);
  lcd.print("Iniciando...");
  delay(500);
  inicializado = inicializacion();
  calentar();
  while (tomar_temp() + tasa_temp > temp_act) {
    lcd.clear();
    lcd.print("Temperatura: ");
    lcd.print(tomar_temp());
    delay(500);
  }
}

bool inicializacion() {

  while (inicializado != true) {
    lcd.clear();
    lcd.print("Temp. incial: ");
    lcd.print(temp_act);
    if (digitalRead(pin_boton_mas) == HIGH && temp_act >= temp_min && digitalRead(pin_boton_mas) == HIGH && temp_act < temp_max) {
      temp_act += 10;
    }
    if (digitalRead(pin_boton_menos) == HIGH && temp_act > temp_min && digitalRead(pin_boton_menos) == HIGH && temp_act <= temp_max) {
      temp_act -= 10;
    }
    if (digitalRead(pin_boton_ok) == HIGH) {
      return true;
    }
    delay(150);
  }
}


int tomar_temp() {                                            //Funcion optimizable (y eliminable), pero pereza
  temp = tempe.analog2temp();
  return temp;
}


void calentar() {
  if (tomar_temp() < temp_act) {
    while (tomar_temp() < temp_act) {
      digitalWrite(pin_plancha, 1);
      //Control de temperatura
      lcd.clear();
      lcd.print("Calentando,espere...");
      lcd.setCursor(0, 1);
      lcd.print("Temperatura: ");
      lcd.print(tomar_temp());
      lcd.print("/");
      lcd.print(temp_act);
      delay(300);
    }
  }

  if (tomar_temp() >= temp_act) {
    digitalWrite(pin_plancha, LOW);
  }
}
