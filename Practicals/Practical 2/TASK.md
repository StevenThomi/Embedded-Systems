## Scenario
Implement a Verilog module to create an 8-bit ALU with the following shown in the table below. 

The design must also include an internal “accumulator” register, and have a clocked input. 

No flags are necessary for this implementation.


| Operation           | Opcode            | ALU Operation                  |
| :------------------:| :---------------: | :----------------------------- |
|  ADD                | 0000              | Acc = A + B                    |
|  SUB                | 0001              | Acc = A - B                 \| |
|  MUL                | 0010              | Acc = A * B                    |
|  DIV                | 0011              | Acc = A / B                 \| |
|  ADDA               | 0100              | Acc = Acc + A                  |
|  MULA               | 0101              | Acc = Acc * A               \| |
|  MAC                | 0110              | Acc = Acc + (A * B)            |
|  ROL                | 0111              | Acc = A rotated left by 1   \| |
|  ROR                | 1000              | Acc = A rotated right by 1     |
|  AND                | 1001              | Acc = A and B               \| |
|  OR                 | 1010              | Acc = A or B                   |
|  XOR                | 1011              | Acc = A xor B               \| |
|  NAND               | 1100              | Acc = A nand B                 |
|  ETH                | 1101              | Acc = 0xFF if A = B else 0  \| |
|  GTH                | 1110              | Acc = 0xFF if A > B else 0     |
|  LTH                | 1111              | Acc = 0xFF if A < B else 0  \| |
