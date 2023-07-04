/*
 BTHome protocol virtual sensors for ESPHome

 Author: Attila Farago
 */

#pragma once

#include "esphome/core/component.h"
#include "esphome/components/bthome_base/bthome_base_common.h"

namespace esphome
{
  namespace bthome_receiver_base
  {
    using namespace bthome_base;

    class BTHomeReceiverBaseBaseSensor : public Component
    {
    public:
      float get_setup_priority() const override { return setup_priority::DATA; }
      void dump_config() override;

      bthome_measurement_t get_measurement_type() { return this->measurement_type_; };
      void set_measurement_type(uint8_t measurement_type) { measurement_type_ = measurement_type; };

      bool match(const uint8_t measurement_type) { return this->measurement_type_ == measurement_type; }

      virtual void publish_data(float value) = 0;

    private:
      uint8_t measurement_type_{0};
    };
  }
}
