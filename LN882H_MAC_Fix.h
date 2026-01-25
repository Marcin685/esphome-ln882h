#include "esphome.h"
#include "lwip/netif.h"

void force_mac_in_ram(uint8_t last_byte) {
    uint8_t fake_mac[] = {0xC0, 0x3E, 0xBA, 0x0E, 0x67, last_byte};
    struct netif *net_if = netif_list;
    while (net_if != NULL) {
        for (int i = 0; i < 6; i++) {
            net_if->hwaddr[i] = fake_mac[i];
        }
        net_if = net_if->next;
    }
}
