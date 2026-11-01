# Technical Project Summary

## Objective

Develop a smart-city prototype capable of detecting potholes, estimating their volume, and positioning an automated repair dispenser over the detected road defect.

## System Architecture

The project was divided into two major subsystems:

1. **Detection and analysis** — a 2D LiDAR connected to a Raspberry Pi generated and processed point-cloud data to detect potholes and estimate their position and volume.
2. **Repair actuation** — an Arduino controlled a horizontal gantry and servo-based dispenser. The Arduino received target information from the detection subsystem, moved the dispenser to the target location, dispensed repair material, and returned the gantry toward its home position.

## Detection Approach

The team used geometric processing techniques described in the final research report, including Adaptive Breakpoint Detection and Douglas-Peucker simplification. Repeated 2D scans were used to approximate a third spatial dimension for volume analysis.

## My Primary Responsibilities

- Embedded communication between the detection and dispenser subsystems
- Arduino-based motor-control logic
- Power integration
- Stepper-driven gantry positioning
- Servo-based dispensing control
- System-level integration and testing

## Reported Performance

- Pothole-present detection rate: 100%
- False-positive rate when no pothole was present: 20%
- Volume-estimation error: 20.2%

## Attribution

This was a multi-person GSET research project. The repository documents the complete system for context while explicitly distinguishing my primary contributions from work completed collaboratively by the team.
