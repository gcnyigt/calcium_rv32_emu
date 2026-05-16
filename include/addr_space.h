#include "types.h"
#ifndef ADDR_SPACEH_H
#define ADDR_SPACEH_H
word read_word_from_address_space(word,rv32i*);
void write_word_to_address_space(word, word,rv32i*);
hword read_hword_from_address_space(word,rv32i*);
void write_hword_to_address_space(word,hword,rv32i*);
byte read_byte_from_address_space(word,rv32i*);
void write_byte_to_address_space(word,byte,rv32i*);
word fetch_instr(rv32i*);

#endif