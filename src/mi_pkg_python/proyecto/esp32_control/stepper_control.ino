bool anyMotorMoving() {
  return (motor1.distanceToGo() != 0) ||
         (motor2.distanceToGo() != 0) ||
         (motor3.distanceToGo() != 0);
}
