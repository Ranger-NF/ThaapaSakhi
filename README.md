<img width="1280" alt="readme-banner" src="https://github.com/user-attachments/assets/35332e92-44cb-425b-9dff-27bcf1023c6c">

---

# 🎶 Thaapasakhi

## Basic Details

### Team Name: 🧠 MegaMinds

### Team Members
- Team Lead: **Mohammed Fahad** - Government Engineering College Palakkad
- Member 2: **N Fadeela** - Government Engineering College Palakkad
- Member 3: **Mohammed Muflih** - Government Engineering College Palakkad

### Project Description
A beautiful flawless project that plays melodies according to the subjected temperature 😉

### The Problem (that doesn't exist)
Nobody likes to sense the surrounding temperature by themselves, do they?
So, we made this complicated facade to help you with that 😌

### The Solution (that nobody asked for)
We collect data from a temperature sensor and play accurate melodies for you 🎶

## Technical Details
### Technologies/Components Used
For Software:
- Languages used: Javascript & CPP
- Framework ysed: Arduino & Node.JS
- Libraries used: Audic, ws, dht11,ESP8266WiFi.h,WiFiClient.h
- Tools used: Arduino IDE, Zed, Audacity

For Hardware:
- Components:
  - NodeMCU v1 (ESP8266)
  - DHT11 temperature sensor

### Implementation
1. Read data from DHT11 sensor
2. Send the data to [ntfy](https://ntfy.sh)
3. On the PC, establish a web socket to ntfy api.
4. Checking the temperatures, and playing specified audio files

# Installation

```
git clone https://github.com/Ranger-NF/Thaapasakhi/
cd Thaapasakhi
```

- Server:
```
cd src/server
npm install
```

- NodeMCU:
  - Open `src/mircrocontroller/main/main.ino` file in Arduino IDE
  - Connect NodeMCU board and upload the code


# Run
- Server:
  ```
  cd src/server
  node index.js
  ```

- NodeMCU: Just connect it to power

# Diagrams
![Workflow](docs/thaapasakhi-workflow.png)
*There are 3 parts: Microcontroller, Server(ntfy) and your PC(Node.js web server)*

# Schematic & Circuit
![Circuit](docs/thaapasakhi-circuit-diagram.png)
*GND(Ground) pin is connected to GND, VDD pin is connected to 3.3v and Signal pin is connected to D2 of NodeMCU*

![Schematic](docs/thaapasakhi-schematics.jpg)

# Build Photos
![Components](docs/thaapasakhi-components.png)

![Final](docs/thaapasakhi-final-build.jpg)
*GND(Ground) pin is connected to GND, VDD pin is connected to 3.3v and Signal pin is connected to D2 of NodeMCU*


### Project Demo
# Video
[Add your demo video link here]
*Explain what the video demonstrates*

## Team Contributions
- Mohammed Fahad: Server side logic, NodeMCU logic
- N Fadeela: Proposed the idea, collected the melodies and documented the project
- Mohammed Muflih: Assembled the circuit, edited audio files and NodeMCU logic

---
Made with ❤️ at TinkerHub Useless Projects

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProject--24-24?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)
