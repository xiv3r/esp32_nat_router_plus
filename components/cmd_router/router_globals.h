/* Various global declarations for the esp32_nat_router

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#define PARAM_NAMESPACE "esp32_nat"
#include "lwip/ip4_addr.h"
#define PROTO_TCP 6
#define PROTO_UDP 17

   extern char *ssid;
   extern char *ent_username;
   extern char *ent_identity;
   extern char *passwd;
   extern char *static_ip;
   extern char *subnet_mask;
   extern char *gateway_addr;
   extern char *ap_ssid;
   extern char *ap_passwd;
   extern char *ap_ip;

   extern bool scanning_started;

   extern uint16_t connect_count;
   extern bool ap_connect;

   extern uint32_t my_ip;
   extern uint32_t my_ap_ip;

   void preprocess_string(char *str);
   int set_sta(int argc, char **argv);
   int set_sta_static(int argc, char **argv);
   int set_ap(int argc, char **argv);

   esp_err_t get_config_param_int(char *name, int *param);
   esp_err_t get_config_param_str(char *name, char **param);

   void print_portmap_tab();
   esp_err_t add_portmap(u8_t proto, u16_t mport, u32_t daddr, u16_t dport);
   esp_err_t del_portmap(u8_t proto, u16_t mport);

#ifdef __cplusplus
}
#endif
