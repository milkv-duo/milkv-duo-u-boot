/*
 * Configuration for Versatile Express. Parts were derived from other ARM
 *   configurations.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CV180X_ASIC_H__
#define __CV180X_ASIC_H__

#include <asm/arch/cv180x_reg.h>

/* defined in cvipart.h */
#undef CONFIG_ENV_OFFSET
#undef CONFIG_ENV_OFFSET_REDUND
#undef CONFIG_ENV_SIZE
#undef CONFIG_ENV_IS_IN_SPI_FLASH
#undef CONFIG_ENV_IS_IN_MMC
#undef CONFIG_ENV_IS_IN_NAND
#undef CONFIG_ENV_SECT_SIZE

#undef CONFIG_SYS_MAXARGS
#undef CONFIG_SYS_PBSIZE
#undef CONFIG_SYS_CBSIZE
#undef CONFIG_SYS_MALLOC_LEN
#undef CONFIG_SYS_BOOTM_LEN
/* cvi_board_memmap.h is generated from build/boards/{CHIP_ARCH}/{BOARD}/memmap.py */
#include <asm/arch/cvi_board_memmap.h>
/* partition definitions header which is created by mkcvipart.py */
/* please do not modify header manually */
#include <asm/arch/cvipart.h>
#include <asm/arch/cvi_panel_diffs.h>

// defined in this .h
#undef CONFIG_BOOTCOMMAND

#define CONFIG_REMAKE_ELF

/* Physical Memory Map */
#define CONFIG_SYS_RESVIONSZ		CVIMMAP_ION_SIZE
#define CONFIG_SYS_BOOTMAPSZ		CVIMMAP_KERNEL_MEMORY_SIZE

#define PHYS_SDRAM_1			CVIMMAP_KERNEL_MEMORY_ADDR
#define PHYS_SDRAM_1_SIZE		CVIMMAP_KERNEL_MEMORY_SIZE
#define CFG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* Link Definitions */
#define CONFIG_SYS_INIT_SP_ADDR		CVIMMAP_CONFIG_SYS_INIT_SP_ADDR

/* default address for bootm command without arguments */
#define CONFIG_SYS_LOAD_ADDR		0x80300000
#define CONFIG_SYS_BOOTM_LEN		(64 << 20)

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (8 << 20))

#if defined(__aarch64__)
#define CONFIG_SYS_NONCACHED_MEMORY	BIT(20)	/* 1 MiB */
#endif

#if defined(__riscv)
#define CONFIG_SYS_CACHELINE_SIZE	64
#endif

// Frequency of ARM arch timer and RISC-V rdtime
#define SYS_COUNTER_FREQ_IN_SECOND 25000000

/* 16550 Serial Configuration */
#define CFG_SYS_NS16550_COM1		0x04140000
#define CFG_SYS_NS16550_SERIAL
#define CFG_SYS_NS16550_REG_SIZE	(-4)
#define CFG_SYS_NS16550_MEM32
#define CFG_SYS_NS16550_CLK		25000000

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		512	/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_SYS_MAXARGS		64	/* max command args */

#ifndef CONFIG_ENV_SECT_SIZE
#define CONFIG_ENV_SECT_SIZE		0x00040000
#endif

#define CONFIG_ENV_OVERWRITE

#define STDIN_CFG "serial"
#define STDOUT_CFG "serial"

#define CONFIG_IPADDR			192.168.8.13
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_GATEWAYIP		192.168.8.1
#define CONFIG_SERVERIP			192.168.8.60

#ifndef BOOT_TARGET_DEVICES
#define BOOT_TARGET_DEVICES(func)	\
	func(MMC, mmc, 0)		\
	func(PXE, pxe, na)		\
	func(DHCP, dhcp, na)

#endif

#define KERNEL_ADDR_R		__stringify(0x80200000)
#define KERNEL_COMP_ADDR_R	__stringify(0x80400000)
#define FDT_ADDR_R		__stringify(0x81980000)
#define SCRIPT_ADDR_R		__stringify(0x81982000)
#define PXEFILE_ADDR_R		__stringify(0x81983000)
#define FDTOVERLAY_ADDR_R	__stringify(0x81984000)
#define RAMDISK_ADDR_R		__stringify(0x81986000)

#include <config_distro_bootcmd.h>

#ifndef CFG_EXTRA_ENV_SETTINGS
#define CFG_EXTRA_ENV_SETTINGS \
	"stdin=" STDIN_CFG "\0" \
	"stdout=" STDOUT_CFG "\0" \
	"stderr=" STDOUT_CFG "\0" \
	"kernel_comp_addr_r=" KERNEL_COMP_ADDR_R "\0" \
	"kernel_comp_size=0x2000000\0" \
	"fdt_addr_r=" FDT_ADDR_R "\0" \
	"scriptaddr=" SCRIPT_ADDR_R "\0" \
	"kernel_addr_r=" KERNEL_ADDR_R "\0" \
	"pxefile_addr_r=" PXEFILE_ADDR_R "\0" \
	"fdtoverlay_addr_r=" FDTOVERLAY_ADDR_R "\0" \
	"ramdisk_addr_r=" RAMDISK_ADDR_R "\0" \
	BOOTENV
#endif


#endif /* __CV181X_ASIC_H__ */
