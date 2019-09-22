# auspex

Learning arduino by building a compact rangefinger for warhammer. Praise the motive force.

## Controller - Arduino Nano

I'm using [Arduino IDE](https://www.arduino.cc/en/Main/Software) to develop the program.
I think I have an older version of A [Robotdyne](https://robotdyn.com/nano-v3-atmega-328-usb-ttl-ch340g-micro-usb-with-cable-soldered.html) clone with a built in USB programmer;
 - Tools->Board: Arduino Nano
 - Tools->Processor: ATmega328P (Old Bootloader)

## Display - SSD1306

A monochrome 128 x 64 OLED display which is controlled with I2C.

I'm currently using [Adafruit's GFX and SSD1306 libraries](https://github.com/adafruit/Adafruit_SSD1306) for graphics.

## Sensor - VL53L0X

I was amazed this [sensor](https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html) exists.
    
I use [Polulu's VL53L0X library](https://github.com/pololu/vl53l0x-arduino) to command it.

## TODO

 - Power
   - [ ] Determine battery
   - [ ] figure out convenient charging
 - Calibration
   - [ ] Convert to imperial units
   - [ ] characterized accuraccy up to 48"
   - [ ] measure cone angle to see if this can even be used in a cluttered environment.
     - are optics an option if this needs to be corrected?
 - Targeting laser
   - I need a visible laser to point the sensor accurately
   - [ ] Test if it degrades sensor accuracy?
 - Cabinet
   - [ ] investigate 'Tiny Duino' for better form factor
   - [ ] Cut portal and mount screen
   - [ ] Cut portal and mount sensor
   - [ ] Cut portal and mount laser
   - [ ] Mount controller
   - [ ] Mount battery
   - [ ] Etch ruler for shorter distance

## Notes

 - [Arduino Language Reference](https://www.arduino.cc/reference/en/)
 - To install the needed libraries go to Tools->Manage Libraries and search for the above projects
 - I cobbled the hardware together from cheap clones bundled from kits and some amazon searches; Going forward I'll buy some from people making the convenient software and kits. Here are some links;
   - Arduino [nano](https://store.arduino.cc/usa/arduino-nano)
   - polulu's [VL53L0X](https://www.pololu.com/product/2490) carrier
   - adafruit's [SDD1306](https://www.adafruit.com/product/326) carrier
 - I2C
   - [Wikipedia](https://en.wikipedia.org/wiki/I%C2%B2C)
   - [Nick Gammon post](https://gammon.com.au/i2c)
   - [Level Shifter](https://playground.arduino.cc/Main/I2CBi-directionalLevelShifter/)
 - Power
   - [Arduino playground articles](https://playground.arduino.cc/Main/IntWithHW-PwrSup/)