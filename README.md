# ESPHome LN882H Duplicate MAC Fix

This repository provides a reliable solution for smart bulbs based on the **LN882H** chipset that suffer from a common manufacturing defect: **identical factory MAC addresses** (`00:50:C2:5E:10:88`).

### The Problem
When multiple bulbs with the same MAC address are powered on, they cause IP conflicts, DHCP failures, and overall network instability. 

### The Solution
Instead of risky hardware flashing, this project uses **Software MAC Spoofing**. By injecting a unique MAC address into the LwIP network stack in RAM during boot, your router sees each bulb as a unique device and assigns individual IP addresses.


## Duplicate MAC Address Fix (LN882H)

If your bulbs share the same MAC address (`00:50:C2:5E:10:88`)

### Implementation:
1. Add this to your YAML:

```yaml

#NEW CODE - INSERT ONLY THIS TO ESPHOME

  on_boot:
    priority: 900
    then:
      - lambda: |-
          const uint8_t mac[] = {0xC0, 0x3E, 0xBA, 0x0E, 0x67, 0x11}; // address you want
          WiFi.setMacAddress(mac);
