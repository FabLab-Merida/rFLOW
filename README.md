
# rFLOW - FabLab Mérida

Proyecto made in FabLab Mérida por el cual mediante el reciclaje de una antigua plancha de vapor y algunos componentes electronicos, se ha convertido en una estación de soldadura BGA monocapa. Capaz de llegar hasta 250º, ideal para multiples tipos de pasta de estaño.

## Motivación  

La principal motivación tras este proyecto es buscar una solución económica a la creacion de PCBs y reparación de estas promoviendo la economia circular y el reciclaje de componentes y piezas.

## Materiales 

1 * Relé de 5V que soporte como miínimo 250V y 13A. <br />
1 * Termistor (vease el .ino para mas información). <br />
1 * Resistencia de la plancha de vapor. <br />
1 * Baquelita monocapa virgen. <br />
1 * ATMEGA 328p. <br />
3 * Botones Push. <br />
3 * Resistencias de 1kO. <br />
1 * Resistencia de 4.7kO. <br />
1 * Condensador de 10uF. <br />
1 * Potenciometro 10kO. <br />
1 * LCD 16*4 segmentos. <br />

## Resultados

La posibilidad de usar un amplio rango de temperatura estable ha dado lugar a múltiples aplicaciones extra, desde el anteriormente mencionada creación de PCBs pasando por facilitar soldaduras por aire manteniendo la zona caliente o secado de filamento de impresora 3D.

## Observaciones

Se necesita que el Atmega use la frecuencia de relog interna de 8MHz, para ello se necesita grabar el bootloader por uno sin los parametros de Arduino, en la bibliografía encontrará información de como hacerlo.

## Bibliografía

LiquidCrystal.h          ==> https://www.arduino.cc/reference/en/libraries/liquidcrystal/ <br />
thermistor.h             ==> https://github.com/miguel5612/ThermistorLibrary <br />
Grabar bootloader        ==> https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoToBreadboard <br />
