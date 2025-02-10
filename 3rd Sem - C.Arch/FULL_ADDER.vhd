library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity FULL_ADDER is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           SUM : out  SID_LOGIC;
           CARRY : out  STD_LOGIC);
end FULL_ADDER;

architecture Behavioral of FULL_ADDER is

begin

SUM <= A XOR B XOR C;
CARRY <= (A AND B) OR (B AND C) OR (C AND A);

end Behavioral;