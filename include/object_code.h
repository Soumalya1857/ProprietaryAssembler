#ifndef OBJECT_CODE_H
#define OBJECT_CODE_H

#include <main.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <second_pass_parse.h>

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int double_word;

#define MAGIC 0xEFBEADDE
#define M 0xAAAA

// #ifndef SECOND_PASS_PARSE_H

// enum TOKEN_TYPES
// {
//     O,
//     R,
//     S,
//     L,
//     DB,
//     DW,
//     DD
// } TOKEN_TYPES;

// typedef struct token
// {
//     int type;
//     int value; // value in decimal
// } second_pass_token;

// typedef struct l
// {
//     int len;
//     second_pass_token *tokens;
// } line;

// line parse_intermediate_file(const char *filename);

// #endif

typedef struct modification_record
{
    word code;
    int offset;
    word value;
} modification_record;

/*
 * Writes the final object file
 * args: const char *object_file => output file name, line tokens_array => returned from parse_intermediate_file 
 * returns: 0 on SUCCESS
 * returns: -1 on ERROR
 */
int write_object_file(const char *object_file, line tokens_array);

/*
 * Object file generation: main
 * args: self_explainatory
 * returns: 0 on SUCCESS
 * returns: -1 on ERROR
 */
int generate_object_code(const char *intermeditate_file, const char *object_file);

#endif
