library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity NOT is
    Port ( A : in  STD_LOGIC;
           C : out  STD_LOGIC);
end NOT;

architecture Behavioral of NOT is

begin

C <= NOT A;

end Behavioral;