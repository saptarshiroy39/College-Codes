library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity XOR_U_NOR is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : out  STD_LOGIC);
end XOR_U_NOR;

architecture Behavioral of XOR_U_NOR is

begin

C <= (((A NOR B) NOR A) NOR ((A NOR B) NOR B)) NOR (((A NOR B) NOR A) NOR ((A NOR B) NOR B));

end Behavioral;