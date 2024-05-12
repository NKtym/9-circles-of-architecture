#pragma once
#include <fcntl.h>
#include <limits.h>
#include <myTerm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MEMORYSIZE 127
#define EMPTYMEMORY 0

#define REGISTER_FLAG 0x1
#define FLAG_SET(register_num) (flag | (1 << (register_num)))
#define FLAG_CLEAR(register_num) (flag & (~(1 << (register_num))))
#define FLAG_GET(register_num) ((flag >> (register_num - 1)) & REGISTER_FLAG)
#define REGISTER_MIN 0
#define REGISTER_MAX 5
#define ACCUM_MIN 0
#define ACCUM_MAX 0x7FFF
#define COMMAND_MIN 0
#define COMMAND_MAX 0x7F

#define SIGN_COMMAND 0
#define OPERATION_CODE_MIN 10
#define OPERATION_CODE_MAX 76
#define OPERAND_MIN 0
#define OPERAND_MAX 0x7F

#define CACHE_LINE 10
#define CACHE_LINES 5

struct caches
{
  int line[CACHE_LINE];
  int number;
  int priority;
};

extern int *ram;

extern int accum;

extern int cnt_command;

extern int flag;

extern struct caches cache[CACHE_LINES];

int sc_memoryInit (void);

int sc_memorySet (int address, int value);

int sc_memoryGet (int address, int *value);

int sc_memorySave (char *filename);

int sc_memoryLoad (char *filename);

int sc_regInit (void);

int sc_regSet (int reg, int value);

int sc_regGet (int reg, int *value);

int sc_accumulatorInit (void);

int sc_accumulatorSet (int value);

int sc_accumulatorGet (int *value);

int sc_icounterInit (void);

int sc_icounterSet (int value);

int sc_icounterGet (int *value);

int sc_commandEncode (int sign, int command, int operand, int *value);

int sc_commandDecode (int value, int *sign, int *command, int *operand);

int sc_commandValidate (int command);

void printCell (int address, enum colors fg, enum colors bg);

void printBigCell(int cnt);

void printFlags (void);

void printDecodedCommand (int value);

void printAccumulator (void);

void printCounters (void);

void printTerm (int address, int input);

void printCommand (void);

void IRC(int signum);

void usrsig_handler(int sig);

void CU();

int ALU(int command, int operand);

void printCache (void);

int check_cache(int operand);

void update_cache(int operand);