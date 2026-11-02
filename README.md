# 2D LiDAR Pothole Detection & Autonomous Repair

A team engineering project developed through the Governor's School of New Jersey Program in Engineering & Technology (GSET) to detect potholes with 2D LiDAR, estimate pothole volume, and command a motorized dispenser to move to the detected location and deliver repair material.

## Project Overview

The system combined a Raspberry Pi-based sensing and processing subsystem with an Arduino-controlled repair mechanism. A 2D LiDAR sensor generated point-cloud data used for pothole detection and volume estimation, while a horizontal gantry and servo-based dispenser provided the physical repair mechanism.

The project investigated a complete smart-city workflow:

**LiDAR sensing → point-cloud processing → pothole detection → volume/displacement calculation → embedded communication → motor positioning → material dispensing**

## My Contribution

This was a team project. My primary work focused on the embedded integration between the detection and repair subsystems, including:

- Arduino communication with the detection system
- Passing pothole displacement and volume information to the dispenser subsystem
- Power integration between project components
- Stepper-motor control for horizontal gantry positioning
- Servo control for the dispensing mechanism
- Integrating the Raspberry Pi / Arduino portions into a working prototype

The detection and volume-analysis algorithms were developed collaboratively by the team; this repository does not claim that every algorithmic component was solely my work.

## Hardware & Technologies

- 2D LiDAR sensor
- Raspberry Pi
- Arduino
- Stepper motor and horizontal gantry
- Servo-controlled dispenser
- C++ / Arduino firmware
- Python-based LiDAR processing
- NumPy / SciPy / Matplotlib
- Point-cloud geometry

## Algorithms Used by the Team

The sensing subsystem used techniques including:

- 2D polar point-cloud generation
- Multiple LiDAR scans to approximate a third spatial dimension
- Adaptive Breakpoint Detection for geometry segmentation
- Douglas-Peucker curve simplification
- Pothole detection and volume estimation
- Convex-hull geometry for volume analysis

## Results

The final project report documented:

- **100% detection rate** in trials where a pothole was present
- **20% false-positive rate** when a pothole was absent
- **20.2% error** in volume estimation
- A working combined detection-and-dispensing prototype

The project was later accepted into the **MIT Undergraduate Research Technology Conference (MIT URTC)**.

## Repository Structure

```text
lidar-pothole-repair/
├── README.md
├── gantry/
│   └── gantry_controller.ino
├── lidar-processing/
│   ├── README.md
│   ├── LICENSE
│   ├── abd.py
│   ├── convert_to_3d_cloud.py
│   ├── convex_hull.py
│   ├── douglas_peucker.py
│   ├── lidar_data.py
│   ├── lidar_init.py
│   └── test_angle.py
├── docs/
│   └── project-summary.md
└── .gitignore
```

## LiDAR Source-Code Provenance

The original LiDAR-processing source has been recovered from the team's public repository and preserved in `lidar-processing/` substantially as originally published.

Original team repository: https://github.com/rahulc07/gset-lidar

Related publication: https://ieeexplore.ieee.org/document/10937641

The recovered source includes the RPLidar acquisition pipeline, Adaptive Breakpoint Detection, Douglas-Peucker simplification, 2D-to-3D point conversion, and convex-hull volume analysis. Because this was collaborative team work, the inclusion of these files here does not imply sole authorship. The original copyright and license notice is preserved in `lidar-processing/LICENSE`.

## Future Improvements

- Add system wiring and block diagrams
- Add photographs and video of the prototype
- Improve calibration of volume estimation
- Reduce false-positive detections
- Add closed-loop position feedback to the dispenser system
- Refactor the recovered research code into a reproducible, documented Python environment
