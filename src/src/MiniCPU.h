/*
 * MiniCPU.h
 *
 *  Created on: Jun 24, 2017
 *      Author: benmorrisau
 */

#ifndef MINICPU_H_
#define MINICPU_H_

// Minip->cpp : Defines the entry point for the console application.

#define PML (64)    // Internal program memory length
#define DML (128)   // Internal data memory length

#define EXE (32)    // Execute Indirect Instructions

#define PFX (0)     // Prefix
#define NFX (1)     // Negative Prefix
#define INV (2)     // Invalid Instruction
#define LDK (3)     // Load Constant
#define LDL (4)     // Load Local
#define LDN (5)     // Load Non-Local
#define STL (6)     // Store Local
#define STN (7)     // Store Non-Local
#define LDY (8)     // Load Y (Non-Local Pointer)
#define STY (9)     // Store Y (Non-Local Pointer)
#define BNE (10)    // Branch If Not Equal   ~(Z == 1)
#define BPL (11)    // Branch If Plus        ~(N == 1)
#define BNC (12)    // Branch If Carry Clear ~(C == 1)
#define ADJ (13)    // Adjust X (Workspace Pointer)
#define RTS (14)    // Return From Subroutine
#define JSR (15)    // Jump To Subroutine
//#define POP (16)    // Pop A
#define SWP (16)    // Swap Y with Y shadow
#define XAB (17)    // Exchange A and B
#define XCH (18)    // Exchange X and {A,B}
#define LDA (19)    // Load A from KI
#define CLC (20)    // Clear Cy
#define SEC (21)    // Set Cy
#define ADC (22)    // Add: A = A +  B + Cy
#define SBC (23)    // Sub: A = A + ~B + Cy
#define ROL (24)    // Rotate A Left
#define ASL (25)    // Arithmetic Shift Left (shift 0 into lsb)
#define ROR (26)    // Rotate A Right
#define ASR (27)    // Arithmetic Shift Right (duplicate msb)
#define CPL (28)    // Complement: A = ~A
#define AND (29)    // AND: A = A & B
#define ORL (30)    // ORL: A = A | B
#define XOR (31)    // XOR: A = A ^ B

typedef struct {
        unsigned short  ma;     // Memory Address Register      (16 bits)
        unsigned char   io;     // Memory Data Register (I/O)   ( 8 bits)
        //
        //  CPU Registers
        //
        unsigned short  ip;     // Instruction Pointer          (16 bits)
        unsigned short  xp;     // Local Pointer                (16 bits)
        unsigned short  yp;     // Non-Local Pointer            (16 bits)
        unsigned short  ys;     // Non-Local Pointer Shadow     (16 bits)
        unsigned short  ki;     // Constant/Indirect Inst.      (16 bits)
        unsigned char   ir;     // Instruction Register         ( 4 bits)
        unsigned char   ra;     // ALU Register A               ( 8 bits)
        unsigned char   rb;     // ALU Register B               ( 8 bits)
        unsigned char   cy;     // ALU Carry Register           ( 1 bit )
        //
        //  Control Flags
        //
        unsigned char   clr_ki; // Clear ki flag                ( 1 bit )
        unsigned char   ld_kil; // Load ki(low) flag            ( 1 bit )
        unsigned char   ld_kih; // Load ki(high) flag           ( 1 bit )
        unsigned char   ld_vec; // Load Interrupt Vector flag   ( 1 bit )
    } CPU;


#endif /* MINICPU_H_ */
