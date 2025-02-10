library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity FULL_SUBTRACTOR is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           DIFFERENCE : out  SID_LOGIC;
           BORROW : out  STD_LOGIC);
end FULL_SUBTRACTOR;

architecture Behavioral of FULL_SUBTRACTOR is

begin

DIFFERENCE <= A XOR B XOR C;
BORROW <= (NOT A AND B) OR (NOT A AND C) OR (B AND C);

end Behavioral;