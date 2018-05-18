#include "Mape.h"

using namespace std;

Mape::mapInst Mape::mapIns = {
	{ "INT", "00000000" },
	{ "JMP", "00000010" },
	{ "CALL", "00000011" },
	{ "RET", "00000001" },
	{ "JZ", "00000100" },
	{ "JNZ", "00000101" },
	{ "JGZ", "00000110" },
	{ "JGEZ", "00000111" },
	{ "JLZ", "00001000" },
	{ "JLEZ", "00001001" },
	{ "LOAD", "00010000" },
	{ "STORE", "00010001" },
	{ "PUSH", "00100000" },
	{ "POP", "00100001" },
	{ "ADD", "00110000" },
	{ "SUB", "00110001" },
	{ "MUL", "00110010" },
	{ "DIV", "00110011" },
	{ "MOD", "00110100" },
	{ "AND", "00110101" },
	{ "OR", "00110110" },
	{ "XOR", "00110111" },
	{ "NOT", "00111000" },
	{ "ASL", "00111001" },
	{ "ASR", "00111010" }
};

Mape::mapAdres Mape::mapAdr = {
	{ "neposr", "100" },
	{ "regdir", "000" },
	{ "memdir", "110" },
	{ "regindir", "010" },
	{ "pomeraj", "111" }
};

Mape::mapTipovi Mape::mapTip = {
	{ "DD", "000" },
	{ "UW", "001" },
	{ "SW", "101" },
	{ "UB", "011" },
	{ "SB", "111" },
	{ "B", "011" },
	{ "W", "001" }
};

Mape::mapRegis Mape::mapReg = {
	{ "R0", "00000" },
	{ "R1", "00001" },
	{ "R2", "00010" },
	{ "R3", "00011" },
	{ "R4", "00100" },
	{ "R5", "00101" },
	{ "R6", "00110" },
	{ "R7", "00111" },
	{ "R8", "01000" },
	{ "R9", "01001" },
	{ "R10", "01010" },
	{ "R11", "01011" },
	{ "R12", "01100" },
	{ "R13", "01101" },
	{ "R14", "01110" },
	{ "R15", "01111" },
	{ "SP", "10000" },
	{ "PC", "10001" }
	
};