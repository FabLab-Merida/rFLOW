
# rFLOW - FabLab Mérida

Proyecto made in FabLab Mérida por el cual mediante el reciclaje de una antiga plancha de vapor y algunos componentes, se ha convertido en una estacion de soldadura BGA monocapa. Capaz de llegar hasta 250º, ideal para multiples tipos de pasta de estaño.

## Materiales 

1 * Relé de 5V que soporte como miínimo 250V y 13A. <br />
1 * Termistor (vease el .ino para mas información). <br />
1 * Resistencia de la plancha de vapor. <br />
1 * Baquelita monocapa virgen. <br />
1 * ATMEGA 328p. <br />
3 * Botones Push. <br />
3 * Resistencias de 1kO. <br />
1 * Resistencia de "sepadios" kO. <br />
1 * Condensador de "sepadios" uF. <br />
1 * Potenciometro 10kO. <br />
1 * LCD 16*4. <br />

## Observaciones

Se necesita que el Atmega use la frecuencia de relog interna de 8MHz, para ello se necesita grabar el bootloader por uno sin los parametros de Arduino, tanto en este repositorio como en la bibliografía encontrará información de como hacerlo.

## Bibliografía

LiquidCrystal.h          ==> https://www.arduino.cc/reference/en/libraries/liquidcrystal/ <br />
thermistor.h             ==> https://github.com/miguel5612/ThermistorLibrary <br />
Grabar bootloader        ==>  https://imasdcasero.wordpress.com/2016/06/06/arduino-con-oscilador-interno/ <br />
