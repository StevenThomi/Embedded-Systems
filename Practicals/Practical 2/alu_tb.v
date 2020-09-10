/*
 *****************************************************************************************
 * FILE: Practical 2
 * FILE NAME: alu_tb.v
 * WRITTEN BY: STEVEN THOMI
 * DATE CREATED: 26TH AUGUST 2020
 * LICENSE: MIT LICENSE
 *****************************************************************************************
 * You will need to implement a Verilog module to create an 8-bit ALU with the following
 * shown in table I below. The design must also include an internal “accumulator” register,
 * and have a clocked input. No flags are necessary for this implementation.

 * You can assume A and B are unsigned
 *****************************************************************************************
*/

//==========================================
// ALU TEST BENCH - ALU_tb();
//==========================================
// DESCRIPTION:
// ------------
//              __________________
//              |                |
//        A_____|                |
//        B_____|   8-BIT ALU    |____ Acc
//   ALU_Sel____|                |
//       clk____|                |
//              |________________|
//===========================================

module ALU_tb();

  // inputs
  reg clk;
  reg[7:0] A;
  reg[7:0] B;
  reg[3:0] ALU_Sel;

  // output
  wire [7:0] Acc;

  // instantiate the module
  ALU a1(
  .clk(clk),
  .A(A),
  .B(B),
  .ALU_Sel(ALU_Sel),
  .Acc(Acc)
  );

  initial
  begin

    $display("\t\tTime \tA \t\tB \t\tALU_Sel \tAcc");
    $monitor("%d \t%b \t%b \t%b \t\t%b",$time,A,B,ALU_Sel,Acc);

    $dumpfile("alu.vcd");
    $dumpvars;
    clk = 1'b1;                         //set clock to 1
    //-----inputs-----
    A = 8'b00000001;                    // A = 1
    B = 8'b00000001;                    // B = 1

    ALU_Sel = 4'b0000;                  //select = 0000

    repeat(15)
      begin
        #5
        clk = !clk;                     //set clock to 0
        #5

        clk = !clk;                     //set clock to 1 //__________

        ALU_Sel = ALU_Sel + 4'b0001;    //select = 0000 //___________
      end

  end
endmodule
