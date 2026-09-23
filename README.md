# Cable-Driven Prosthetic Finger Joint & Testing Rig

> **A motorized, cable-actuated prosthetic finger prototype featuring tactile force feedback, rapid 3D prototyping, and Arduino control.**

This project is an experimental prototype of an articulated prosthetic finger that curls and extends using motorized pull strings (cables). Built as a low-cost mechatronics prototype, the setup combines mechanical 3D-printed parts, a motor drive system, and sensors to detect touch and adjust grip.

---

## 1. How the System Works

```text
               [ Arduino Controller (C++) ]
                            │
        ┌───────────────────┴───────────────────┐
        ▼                                       ▼
 [ Motor & Cable Rig ]                   [ Sensor Feedback ]
 • Servo / Stepper Motor                 • Pressure sensor (force-sensitive)
 • Motor Pulley                          • Ultrasonic distance sensor
 • Nylon tendon cable (pulls finger)     • Visual LED indicator
        │                                       │
        └───────────────────┬───────────────────┘
                            ▼
                [ 3D-Printed Finger ]
                • 3-joint trapezoidal segments
                • Paracord spine (keeps it aligned)
                • Bends from flat (0°) to full grip (90°)

```

## 2. Challenges & Iterations

* **Actuation & Torque:** The initial stepper motor repeatedly stalled under tendon load due to low torque and battery voltage drop. Upgraded to a dedicated servo motor and stabilized the power rail, eliminating stalls and achieving a smooth 0° to 90° flexion grasp in under 1 second.
* **Tactile Sensing Circuit:** The default 470Ω pull-down resistor left the force-sensitive sensor insensitive to touch. Bench-tested resistors up to 1.5MΩ to retune the voltage divider, drastically lowering the activation threshold so gentle contact triggers immediate LED feedback.
* **Firmware Timing:** The microcontroller missed real-time touch events because synchronous serial writes and motor sweeps blocked the main loop. Restructured the C++ execution logic to poll sensor pins continuously, cutting contact detection latency to immediate responsiveness.
* **Joint Kinematics:** The original single-piece 3D-printed flexure hinge bound up and risked fatigue snapping along layer lines. Redesigned the finger into segmented trapezoidal digits linked with a flexible paracord spine, delivering natural anatomical bending without pinching or lateral wobble.

---

## 3. Core Skills 

* **Embedded Microcontrollers:** Arduino programming (C++), motor control, reading analog sensor inputs
* **Electronics & Breadboarding:** Sensors, soldering
* **Mechanical CAD (SolidWorks):** Modeling parametric parts and testbed, 3D printing (FDM) in PLA & TPU.

---

## 4. Repository Structure

```
├── cad/
│   ├── assemblies/          # SolidWorks assembly files 
│   ├── parts/               # SolidWorks part files 
│   └── stl/                 # 3D print files 
├── firmware/
│   └── prosthetic_finger/   # Arduino sketches (.ino)
├── electronics/
│   └── schematics/          # Breadboard wiring and resistor layout diagrams
└── docs/
    └── logs/                # Weekly testing logs and prototype sketches
    └── documentation/       # Documentation of final product
