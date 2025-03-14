library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity HALF_ADDER is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           SUM : out  SID_LOGIC;
           CARRY : out  STD_LOGIC);
end HALF_ADDER;

architecture Behavioral of HALF_ADDER is

begin

SUM <= A XOR B;
CARRY <= A AND B;

end Behavioral;