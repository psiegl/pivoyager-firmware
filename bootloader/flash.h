#ifndef _FLASH_H_
#define _FLASH_H_

#include <stdint.h>


#ifdef STM32F030
    // 1K page size
    #define FLASH_PAGE_SIZE ((uint32_t)0x00000400)

    // 8K
    #define FLASH_APP_START ((uint32_t)0x08002000)

    // Assuming 32K flash (0x8000)
    #define FLASH_APP_END ((uint32_t)(0x08008000-1))
#else
    #warning "Using generic STM32F0xx memroy configuration"
    // 1K page size
    #define FLASH_PAGE_SIZE ((uint32_t)0x00000400)

    // 4K
    #define FLASH_APP_START ((uint32_t)0x08001000)

    // Assuming 16K flash (0x4000)
    #define FLASH_APP_END ((uint32_t)(0x080084000-1))
#endif


void flash_open(void);

int flash_read_block(uint32_t flash_addr, uint16_t *data, uint16_t word_count);

int flash_write_block(uint32_t flash_addr, const uint16_t *data, uint16_t word_count);

int flash_erase_page(uint32_t page_addr);

int flash_start_main_application(void);

#endif
