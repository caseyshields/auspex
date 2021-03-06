# auspex

Learning arduino by trying to build a compact rangefinger for Warhammer.

## Controller - Arduino Nano

Since current [servitor mind-locking](https://backyardbrains.com/experiments/roboRoachSurgery) technology is somewhat limited, I opted for a [Robotdyne clone](https://robotdyn.com/nano-v3-atmega-328-usb-ttl-ch340g-micro-usb-with-cable-soldered.html) of the [Arduino Nano](https://store.arduino.cc/usa/arduino-nano).

I'm using the [Arduino IDE](https://www.arduino.cc/en/Main/Software) to develop the program. Here are my Arduino IDE tool settings;
 - Tools->Board: Arduino Nano
 - Tools->Processor: ATmega328P (Old Bootloader)

Both of the devices have I2C interfaces for binaric canting, and are attached to the A4(SDA) and A5(SCL) pins. The components recieve the motive force via the Nano's 3.3v regulated power supply.

## Display - SSD1306

A monochrome 128 x 64 OLED display. I'm currently using [Adafruit's GFX and SSD1306 libraries](https://github.com/adafruit/Adafruit_SSD1306) for graphics.

## Sensor - VL53L0X

I was amazed this [sensor](https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html) exists. It has a SPAD reciever, VCSEL IR laser emitter, and some signal modulation and processing to figure out the phase shift of the reflected signal. All in a 2 x 4 mm surface mount chip for two bucks. Possibly xenos tech heresy.
    
I use [Polulu's VL53L0X library](https://github.com/pololu/vl53l0x-arduino) to command it, which was derived from the ST software I believe.

## TODO

 - Power
   - [ ] Determine battery
   - [ ] figure out convenient charging
 - Calibration
   - [x] Convert to Imperium units
   - [ ] characterize accuraccy up to 48" in tabletop conditions
   - [x] measure cone angle to see if this can even be used in a cluttered environment.
     - are optics an option if this needs to be corrected?
- Beam Forming
   - The light cone is actually 15 to 25 degrees wide. I should have read the sheet...
   - Are there cheap 940nm IR colaminating lenses?
   - Do I need to have separate ones for receiver and emitter?
   - [ ] ask optics suppliers- maybe something like [this](https://america.optosigma.com/aspheric-condenser-lenses.html)?
   - [ ] research [ST support](https://www.st.com/content/st_com/en/support/support-home.html), then ask if I can't figure it out.
 - Targeting laser
   - I need a cheap-o visible laser to point the sensor accurately
   - [X] Test if it degrades sensor accuracy?
     - Didn't noticably affect the range of samples(usu. 0.2-0.3") from 3 to 14". Though I wasn't too scientific about it.
     - If you shine the laser directly into the receiver you get more and more missed measurements, with more distant measurements being more susceptible.
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
   - Arduino [nano](https://store.arduino.cc/usa/arduino-nano) or the [Nano-every](https://store.arduino.cc/usa/nano-every)
   - polulu's [VL53L0X](https://www.pololu.com/product/2490) carrier
   - adafruit's [SDD1306](https://www.adafruit.com/product/326) carrier
 - I2C
   - [Wikipedia](https://en.wikipedia.org/wiki/I%C2%B2C)
   - [Nick Gammon post](https://gammon.com.au/i2c)
   - [Level Shifter](https://playground.arduino.cc/Main/I2CBi-directionalLevelShifter/)
 - Power
   - [Arduino playground articles](https://playground.arduino.cc/Main/IntWithHW-PwrSup/)