#include <stdio.h>
#include <stdint.h> 
#include <stddef.h> 
// tinh check sum , cong tat ca cac byte 
uint8_t checksum8(const uint8_t *buf , size_t len){
    uint32_t sum = 0 ; 
    const uint8_t *p = buf ; 
    const uint8_t *end = buf +len ; 

    while( p < end){
        sum += *p ; 
        p++ ;
    }
    return (uint8_t)(sum % 256u); 
} 
// tim byte dau  tien co gia tri value 
const uint8_t *find_byte(const uint8_t *buf , 
                        size_t len , 
                        uint8_t value)
{
    const uint8_t *p = buf ; 
    const uint8_t *end = buf + len ;
    while (p < end){
        if(*p == value){
            return p ; 
        }
        p++ ; 

    } 
    return NULL ; 

}

// daon nguoc cac file trong buffer 

void reverse_byte(uint8_t *buf , size_t len){
    if(len < 2){
        return ; 
    }
    uint8_t *left = buf ; 
    uint8_t *right = buf + len -1 ; 
    while (left < right){
        uint8_t temp = *left ; 
        *left = *right ;
        *right = temp ; 
        left ++ ;
        right -- ; 
    }
}
int main(void){
    uint8_t buf[32]; 
    unsigned int n_input ; 
    unsigned int value_input ; 
    unsigned int byte_input ; 
    
    if(scanf("%u",&n_input) != 1 || n_input < 1 || n_input > 32){
        printf("LOI\n"); 
        return 1 ; 
    }

    size_t len = (size_t)n_input ; 
    uint8_t *p = buf ; 

    for(size_t i = 0 ; i < len ; i++){
        if(scanf("%x",&byte_input) != 1 || byte_input > 0xFFu){
            printf("LOI\n"); 
            return 1 ; 
        }
        *p = (uint8_t)byte_input ; 
        p++ ; 
    }
    if(scanf("%x",&value_input) != 1 || value_input > 0xFFu){
        printf("LOI\n");  
        return 1 ; 
    }
    uint8_t value = (uint8_t)value_input ; 

    uint8_t checksum = checksum8(buf,len); 
    printf("Checksum = 0x%02X\n",(unsigned int)checksum); 
    
    const uint8_t *found = find_byte(buf,len,value); 
    if(found != NULL){
        size_t index = (size_t)(found - buf); 
        printf("found 0x%02X at index %zu\n",
               (unsigned int)value, index);
    }
    else
    {
        printf("0x%02X not found\n",
               (unsigned int)value);
    }

    /* Goi ham dao nguoc */
    reverse_byte(buf, len);

    printf("reversed:");

    p = buf;

    while (p < buf + len)
    {
        printf(" %02X", (unsigned int)*p);
        p++;
    }

    printf("\n");

    return 0;
}
    
