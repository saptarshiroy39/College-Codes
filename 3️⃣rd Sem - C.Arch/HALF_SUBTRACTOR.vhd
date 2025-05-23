library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity HALF_SUBTRACTOR is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           DIFFERENCE : out  SID_LOGIC;
           BORROW : out  STD_LOGIC);
end HALF_SUBTRACTOR;

architecture Behavioral of HALF_SUBTRACTOR is

begin

DIFFERENCE <= A XOR B;
BORROW <= (NOT A) AND B;

end Behavioral;