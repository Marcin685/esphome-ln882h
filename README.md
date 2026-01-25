## Duplicate MAC Address Fix (LN882H)

If your bulbs share the same MAC address (`00:50:C2:5E:10:88`), use the provided `LN882H_MAC_Fix.h` to spoof a unique one.

### Implementation:
1. Place `LN882H_MAC_Fix.h` in your ESPHome config folder.
2. Add this to your YAML:

```yaml
substitutions:
  my_suffix: "0x31" # Unique hex for each bulb

esphome:
  includes:
    - LN882H_MAC_Fix.h

on_boot:
  priority: 900
  then:
    - lambda: |-
        force_mac_in_ram(${my_suffix});

interval:
  - interval: 10s
    then:
      - lambda: |-
          force_mac_in_ram(${my_suffix});
