#include <Stepper.h>
#include <Servo.h>

// Cleaned from the Arduino gantry-control logic preserved in the
// original GSET project notes. Hardware pin assignments and the
// communication interface should be verified against the physical build.

constexpr int STEPS_PER_REVOLUTION = 200;
constexpr float MM_PER_REVOLUTION = 411.203f;
constexpr int SERVO_PIN = 6;
constexpr int DISPENSE_OPEN_ANGLE = 180;
constexpr int DISPENSE_CLOSED_ANGLE = 0;

Stepper gantryStepper(STEPS_PER_REVOLUTION, 8, 9, 10, 11);
Servo dispenserServo;

void setup() {
  Serial.begin(9600);
  gantryStepper.setSpeed(60);

  dispenserServo.attach(SERVO_PIN);
  dispenserServo.write(DISPENSE_CLOSED_ANGLE);

  Serial.println("Gantry controller ready");
}

void loop() {
  // Expected serial input: horizontal displacement in millimeters.
  // In the original system this value was supplied by the Raspberry Pi
  // after the pothole-detection subsystem determined the target position.
  if (Serial.available() > 0) {
    const float displacementMm = Serial.parseFloat();

    if (displacementMm > 0.0f) {
      moveToTarget(displacementMm);
      dispenseMaterial();
      returnHome(displacementMm);
    }
  }
}

long millimetersToSteps(float displacementMm) {
  const float revolutions = displacementMm / MM_PER_REVOLUTION;
  return static_cast<long>(revolutions * STEPS_PER_REVOLUTION);
}

void moveToTarget(float displacementMm) {
  const long targetSteps = millimetersToSteps(displacementMm);
  Serial.print("Moving to target: ");
  Serial.print(displacementMm);
  Serial.println(" mm");
  gantryStepper.step(targetSteps);
}

void dispenseMaterial() {
  Serial.println("Dispensing material");
  dispenserServo.write(DISPENSE_OPEN_ANGLE);
  delay(500);
  dispenserServo.write(DISPENSE_CLOSED_ANGLE);
  delay(250);
}

void returnHome(float displacementMm) {
  const long targetSteps = millimetersToSteps(displacementMm);
  Serial.println("Returning home");
  gantryStepper.step(-targetSteps);
}
