# RiPi_firmware-rebels
Artificially intelligent car made by interfacing sensors onto a raspberry pi. RiPi is designed to follow a black line and detect obstacles along its path. Upon detection of obstacle the bot with wait for 5 seconds for obstacle to clear, otherwise it will go around the obstacle and merge back onto black line.
### Hardware Specifications:
- DC Motors
    - Size(Approx): 7 x 2.2 x 1.9cm/2.76 x 0.87" x 0.75"   
    - Maximum torque: 800gf cm min (3V) ; No-load speed: 1:48 (3V time)
    - Operating voltage: 3V~12VDC (recommended operating voltage of about 6 to 8V)
    - With EMC, strong magnetic, it has an anti-interference ability.
- Ultrasonic Sensor
    - Power Supply :+5V DC
    - Quiescent Current : <2mA
    - Working Current: 15mA
    - Effectual Angle: <15°
    - Ranging Distance : 2cm – 400 cm/1″ – 13ft
    - Resolution : 0.3 cm
    - Measuring Angle: 30 degree
    - Trigger Input Pulse width: 10uS
    - Dimension: 45mm x 20mm x 15mm
- Line Sensor
    - Working voltage: DC 3.3V-5V
    - Working current: ≥ 20mA
    - Operating temperature: -10℃~+50℃
    - Detection distance: 2-40cm
    - IO Interface:3-wire interfaces
    - Output signal: TTL level (low level there is an obstacle, no obstacle high)
    - Adjustment: adjust multi-turn resistance
    - Effective angle: 35°   
- IR Sensor Module
    - 5VDC Operating voltage
    - I/O pins are 5V and 3.3V compliant
    - Range: Up to 20cm
    - Adjustable Sensing range
    - Built-in Ambient Light Sensor
    - 20mA supply current

### Schematic Diagram:
![schematic-diagram](https://github.com/ichaudry/RiPi_firmware-rebels/blob/master/schematic_diagram.png)
