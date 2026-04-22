# ⚡ SAE E-BAJA 2023 – Start-Up Sequence Circuit

![Status](https://img.shields.io/badge/status-completed-success)
![Simulation](https://img.shields.io/badge/simulation-Proteus-blue)
![Platform](https://img.shields.io/badge/platform-Arduino_UNO-orange)
![Voltage](https://img.shields.io/badge/system-48V%20%7C%2012V%20%7C%205V-red)
![License](https://img.shields.io/badge/license-MIT-green)

---

## 📌 Overview
This repository presents the design and simulation of a **Low Voltage (LV) Start-Up Sequence Circuit** developed for the **SAE E-BAJA 2023** competition, following the 2022–2023 SAE rulebook.

The E-BAJA electrical system is divided into:
- 🔴 **High Voltage (HV) Circuit**
- 🔵 **Low Voltage (LV) Circuit**

The **HV system** (motor, controller, accumulator, etc.) is largely manufacturer-defined, limiting redesign flexibility.

The **LV system**, however, provides flexibility for implementing:
- Safety logic
- Start-up sequencing
- Driver interaction systems

👉 This project focuses entirely on the **LV circuit design, control logic, and simulation**.

<img width="1157" height="828" alt="image" src="https://github.com/user-attachments/assets/80b2e6b3-5415-4093-84ff-3ab77d6b67fe" />

---

## 🎯 Design Scope

The following SAE rulebook sections were implemented:

- ✅ Vehicle Controls  
- ✅ Tractive System Activation  
- ✅ Ready-to-Drive Mode  
- ✅ TSAL (Tractive System Active Light)  
- ✅ RTDS (Ready-To-Drive Sound)  

> ⚠️ HV-related systems like BMS and accumulator protection are excluded from this scope.

---

## 🚦 Key Functional Requirements

### 🔴 Brake Light
- Activates when brakes are pressed  
- Always functional (even during kill switch activation)  
- Powered independently for safety  

### 🔁 Reverse System
- Reverse light + audible alarm  
- Activated only in reverse gear  

### 🛑 Kill Switch
- Disconnects:
  - Tractive system
  - AIR (relay)
  - TSAL & RTDS  
- Does **NOT** disable brake light  

---

## 🚗 Ready-to-Drive Logic

Vehicle enters Ready-to-Drive Mode only when:

1. HV Cut-off switch is **ON**
2. Gear is in **Neutral**
3. Throttle is **Released**
4. Brake pedal is **Pressed**
5. Start button is **Pressed**

---

## 💡 TSAL (Tractive System Active Light)
- Flashing indicator when system is active  
- Frequency: **2–5 Hz**  
- Brightness: **>350 lumens**

---

## 🔊 RTDS (Ready-To-Drive Sound)
- Audible alert when vehicle becomes active  
- Duration: **1–3 seconds**  
- Minimum loudness: **70 dB**

---

## 🧰 Bill of Materials (Simulation)

| Component            | Description                    |
|---------------------|--------------------------------|
| Arduino UNO         | Control logic                  |
| Buck Converter      | 48V → 12V, 12V → 5V           |
| Relays              | Switching & control            |
| Toggle Switches     | Input simulation               |
| Buzzer              | RTDS                           |
| Lights              | TSAL & Brake Light             |

> 📝 Note: Fuses, switches, and motors are application-specific and excluded from core BOM.
<img width="469" height="320" alt="image" src="https://github.com/user-attachments/assets/da975697-aadd-42ce-8057-199274edf43e" />

---

## ⚙️ System Architecture

### 🔋 Power Flow
48V Battery
│
├── 150A Fuse
│
├── Ignition Relay (AIR)
│ │
│ ├── Motor Controller → Motor
│ └── DC-DC (48V → 12V)
│ ├── TSAL
│ ├── RTDS
│ └── Brake Light
│
└── DC-DC (12V → 5V)
└── Arduino UNO

## 🔁 Control Sequence

### ✅ Start-Up Process
1. Turn ON HV cut-off switch  
2. System checks:
   - Brake → Pressed  
   - Throttle → Released  
3. Press Start Button  
4. Arduino activates Ignition Relay  
5. System enters Ready-to-Drive Mode:
   - TSAL starts blinking  
   - RTDS buzzer activates  

---

## 🛑 Kill Switch Logic

- Two kill switches connected to relay coil  
- Pressing either:
  - Cuts off motor supply  
  - Disables TSAL & RTDS  
- **Brake light and controller remain powered**

---

## 🔌 Relay Configuration

| Relay Type | Function |
|-----------|--------|
| 12V Relay | Main ignition (AIR) |
| 5V Relays | TSAL, RTDS, Brake Light |
| Logic Relay | Arduino → 12V relay control |

---

## 🧪 Simulation Details

- Software: **Proteus Design Suite**
- Ideal voltage sources used:
  - 48V / 12V / 5V
- Separate grounds used for clarity
- Real system uses DC-DC converters

---

## 🖼️ Circuit Diagrams

### 🔧 Complete System
![System Diagram](https://github.com/user-attachments/assets/80b2e6b3-5415-4093-84ff-3ab77d6b67fe)

### ⚡ Power Section
![Power Flow](https://github.com/user-attachments/assets/74739d2b-34bd-44e2-8d39-8488b4ac406b)

### 🔁 Relay Logic
![Relay Design](https://github.com/user-attachments/assets/457dc9e2-8dca-44ae-8c08-7e79627eaf62)

### 🔌 Motor Simulation
![Motor Simulation](https://github.com/user-attachments/assets/30b446d4-53fd-4a79-ae9e-965b1f4245b1)

---

## ⚠️ Key Design Considerations

- ✔ Fail-safe operation under emergency conditions  
- ✔ Independent brake light supply  
- ✔ Rule-compliant activation logic  
- ✔ Modular and testable LV design  
- ✔ Real-world implementation feasibility  

---

## 📊 Conclusion

This project successfully demonstrates a **safe, rule-compliant LV start-up system** for an electric BAJA vehicle. The simulation validates:

- Controlled activation of tractive system  
- Proper kill switch behavior  
- Reliable TSAL and RTDS signaling  

---

## 🚀 Future Improvements

- Integration with real motor controller  
- CAN communication with BMS  
- Hardware PCB implementation  
- Fault diagnostics system  

---

## 👨‍💻 Author

**Arijeet Dutta**  
Electrical Engineering – SAE E-BAJA Project  
NIT Raipur
---

## 📄 License
MIT License

Copyright (c) 2026 Arijeet Dutta

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software...

This project is licensed under the **MIT License**.

