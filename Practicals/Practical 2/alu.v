/*
 *****************************************************************************************
 * FILE: Practical 2
 * FILE NAME: alu.v
 * WRITTEN BY: STEVEN THOMI
 * DATE CREATED: 26TH AUGUST 2020
 * LICENSE: MIT LICENSE
 *****************************************************************************************
 * You will need to implement a Verilog module to create an 8-bit ALU with the following
 * shown in table I below. The design must also include an internal “accumulator” register,
 * and have a clocked input. No flags are necessary for this implementation.

 * You can assume A and B are unsigned

 * ROL and ROR commands implement left and right shifts respectively, but the bit that is
 * shifted out is moved back to the new bit.
 * Consider 1011001 as an example. with the ROL command, the result is 0110011. With ROR we
 * get 1101100.
 *****************************************************************************************
*/

//=========================================================================
// 8-BIT ALU - ALU(input clk, A, B, ALU_Sel, output Acc);
//=========================================================================
// DESCRIPTION:
// ------------
// | Operation           | Opcode            | ALU Operation               |
// | :------------------:| :---------------: | :-------------------------- |
// |  ADD                | 0000              | Acc = A + B                 |
// |  SUB                | 0001              | Acc = A - B                 |
// |  MUL                | 0010              | Acc = A * B                 |
// |  DIV                | 0011              | Acc = A / B                 |
// |  ADDA               | 0100              | Acc = Acc + A               |
// |  MULA               | 0101              | Acc = Acc * A               |
// |  MAC                | 0110              | Acc = Acc + (A * B)         |
// |  ROL                | 0111              | Acc = A rotated left by 1   |
// |  ROR                | 1000              | Acc = A rotated right by 1  |
// |  AND                | 1001              | Acc = A and B               |
// |  OR                 | 1010              | Acc = A or B                |
// |  XOR                | 1011              | Acc = A xor B               |
// |  NAND               | 1100              | Acc = A nand B              |
// |  ETH                | 1101              | Acc = 0xFF if A = B else 0  |
// |  GTH                | 1110              | Acc = 0xFF if A > B else 0  |
// |  LTH                | 1111              | Acc = 0xFF if A < B else 0  |
//==========================================================================

module ALU( input clk,                // input clock
            input [7:0] A,            // 8-bit unsigned ALU input 1
            input [7:0] B,            // 8-bit unsigned ALU input 2
            input [3:0] ALU_Sel,      // select line
            output reg [7:0] Acc      // 8-bit unsigned ALU output
          );

  reg [7:0] accumulator;              // 8-bit ALU output register

  always@(posedge clk)
  begin

  case(ALU_Sel)

    4'b0000: // Acc = A + B
      accumulator = A + B ;

    4'b0001: // Acc = A - B
      accumulator = A - B;

    4'b0010: // Acc = A * B
      accumulator = A * B;

    4'b0011: // Acc = A / B
      accumulator = A / B;

    4'b0100: // Acc = Acc + A
      accumulator = accumulator + A;

    4'b0101: // Acc = Acc * A
      accumulator = accumulator * A;

    4'b0110: // Acc = Acc + (A * B)
      accumulator = accumulator + (A * B);

    4'b0111: // Acc = A rotated left by 1
      begin
        accumulator = {{A[6:0]},{A[7]}};
      end

    4'b1000: // Acc = A rotated right by 1
      begin
        accumulator = {{A[0]},{A[7:1]}};
      end

    4'b1001: // Acc = A and B
      accumulator = A & B;

    4'b1010: // Acc = A or B
      accumulator = A | B;

    4'b1011: // Acc = A xor B
      accumulator = A ^ B;

    4'b1100: // Acc = A nand B
      accumulator = ~(A & B);

    4'b1101: // Acc = 0xFF if A = B else 0
      accumulator = (A == B)? 8'hFF : 0;

    4'b1110: // Acc = 0xFF if A > B else 0
      accumulator = (A > B)? 8'hFF : 0;

    4'b1111: // Acc = 0xFF if A < B else 0
      accumulator = (A < B)? 8'hFF : 0;

    default: // Addition
      accumulator = A + B ;

  endcase

  Acc <= accumulator;

  end
endmodule
