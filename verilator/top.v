module top(
  input clk,
  input rst,
  input a,
  input b,
  output f
);
  assign f = a ^ b;
endmodule

