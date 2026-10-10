#ifndef ADDR_BASE_H
#define ADDR_BASE_H

/* BCM2837 peripheral physical address base (Raspberry Pi 3 / 3B+). */
#define PERIPHERAL_BASE 0x3F000000UL
#define PHYSICAL_BASE   PERIPHERAL_BASE

#define GPIO_BASE (PERIPHERAL_BASE + 0x00200000UL)
#define AUX_BASE  (PERIPHERAL_BASE + 0x00215000UL)

#define MMIO_REG32(address) ((volatile unsigned int *)(address))

#endif /* ADDR_BASE_H */
