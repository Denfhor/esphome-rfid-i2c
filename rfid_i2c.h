#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/log.h"
#include "Wire.h"

namespace esphome {
namespace rfid_i2c {

class RFID_I2C : public PollingComponent {
 public:
  sensor::Sensor *value_sensor = new sensor::Sensor();

  RFID_I2C() : PollingComponent(100) {}

  void setup() override;
  void update() override;
};

}  // namespace rfid_i2c
}  // namespace esphome
