#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "Wire.h"

namespace esphome {
namespace rfid_i2c {

class RFID_I2C : public PollingComponent {
 public:
  text_sensor::TextSensor *uid_sensor = new text_sensor::TextSensor();

  RFID_I2C() : PollingComponent(200) {}

  void setup() override;
  void update() override;
};

}  // namespace rfid_i2c
}  // namespace esphome

