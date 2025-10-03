# The LightCar Race

Are you up for a challenge? Build the best-performing autonomous car that can follow a lead car through a course as quickly and accurately as possible. Prove that your design and code are the best!

GitHub repository with all resources:  
https://github.com/Microttus/LightCare

---

## Competition Overview

The LightCar Race is a competition centered on designing both hardware and software for a vehicle that follows a **LeadCar**. The LeadCar drives a preset path with varying speeds and turns. Your goal:

- Follow the LeadCar, using light sensors.
- Complete as many loops as possible.
- After the first loop, stop precisely ~10 cm behind the LeadCar.
- Be judged on multiple criteria (see below).

You use **two photoresistors** to track the LeadCar, which emits light from its rear. By combining data from both sensors, your vehicle should maintain close and accurate following.  
The drive logic is implemented on an **Arduino Uno** (in C) or optionally via MATLAB/Simulink.

---

## Judging Criteria

Vehicles are evaluated across **4 categories**, each graded from 1 to 10:

1. **Best Looking Code**
    - Clean, neat formatting
    - Use of functions
    - Good, descriptive variable names
    - Consistency and readability
    - Adjustable, maintainable code
    - Simple solutions to complex problems

2. **Best Following Performance**
    - Ability to follow for a long continuous loop
    - Ability to complete multiple loops
    - Smooth driving behavior

3. **Closest Stopping**
    - Complete at least one loop
    - Stop as near as possible to 10 cm behind the LeadCar
    - Maintain stability while the LeadCar is stationary

4. **Most Creative Design**
    - Original & creative form
    - Must contain all required components
    - Must be drivable

---

## LeadCar Details

- The LeadCar’s design and code are available in the GitHub repo.
- It uses a **Blocklight** 9 V light source at the rear to provide a tracking signal.
- The light module is commercially available (e.g. Biltema, Amazon).

---

## Design & Build Rules

- You **must design your own frame**. Possible fabrication methods:
    - 3D printing (PLA)
    - Laser cutting acrylic
    - CNC machining
- Wheels may be custom-made or off-the-shelf.
- Assembly methods such as soldering, screws, or glue are allowed.
- Some components are **mandatory**, others optional (see below).

### Required Components

- Arduino Uno ×1
- Motor controller (L298) ×1
- 9 V battery ×1
- Power wiring to L298 ×1
- Two TT motors ×2
- Two photoresistors ×2
- Two resistors ×2
- Wiring, connectors, etc.
- Wheels
- (Optional extras below)

### Optional Components

- Additional sensors (e.g. proximity)
- 9 g servo (for steering)
- Extra weight (ballast)
- Any other enhancements you deem beneficial

### Circuit Diagram

The necessary components must be wired appropriately (sensors → Arduino → motor driver → motors).  
Refer to the GitHub repo for a full circuit schematic.

---

## Academic & Technical Notes

- While a basic implementation is achievable with empirical tuning, more advanced control theory (PID, state estimation, sensor fusion) may yield superior performance.
- Mechanical considerations (weight distribution, friction, chassis rigidity) influence performance significantly.
- The GitHub repo includes:

    - An introduction to Arduino IDE for beginners
    - A slide deck with mechanical and mathematical insights
    - Example code
    - Hardware diagrams

---

## Getting Started

1. Clone the GitHub repository: `git clone https://github.com/Microttus/LightCare`
2. Review hardware designs, example code, and diagrams
3. Design and fabricate your chassis and mount points
4. Wire up sensors, motors, power, and controller
5. Develop and tune your control algorithm
6. Test loops and stopping behavior
7. Iterate — performance is judged not just on function, but on style, smoothness, and creativity

---

## License & Participation

Check the GitHub repository for licensing details, contribution guidelines, and more.  
We encourage creativity, experimentation, and sharing of improvements.

---

## Acknowledgments & Credits

This project is part of Signature Makerspace’s demo projects.

---

*This README is based on content from the project page at Signature Makerspace.*  
