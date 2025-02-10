library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MUX_4x1 is
    Port ( S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           I0 : in  STD_LOGIC;
           I1 : in  STD_LOGIC;
           I2 : in  STD_LOGIC;
           I3 : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end MUX_4x1;

architecture Behavioral of MUX_4x1 is

begin

Y <= ((NOT S0) AND (NOT S1) AND I0) OR ((NOT S0) AND S1 AND I1) OR (S0 AND (NOT S1) AND I2) OR (S0 AND S1 AND I3);

end Behavioral;

------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

ENTITY MUX_4x1_TB_vhd IS
END MUX_4x1_TB_vhd;

ARCHITECTURE behavior OF MUX_4x1_TB_vhd IS 

	-- Component Declaration for the Unit Under Test (UUT)
	COMPONENT MUX_4x1
	PORT(
		S0 : IN std_logic;
		S1 : IN std_logic;
		I0 : IN std_logic;
		I1 : IN std_logic;
		I2 : IN std_logic;
		I3 : IN std_logic;          
		Y : OUT std_logic
		);
	END COMPONENT;

	--Inputs
	SIGNAL S0 :  std_logic := '0';
	SIGNAL S1 :  std_logic := '0';
	SIGNAL I0 :  std_logic := '0';
	SIGNAL I1 :  std_logic := '0';
	SIGNAL I2 :  std_logic := '0';
	SIGNAL I3 :  std_logic := '0';

	--Outputs
	SIGNAL Y :  std_logic;

BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: MUX_4x1 PORT MAP(
		S0 => S0,
		S1 => S1,
		I0 => I0,
		I1 => I1,
		I2 => I2,
		I3 => I3,
		Y => Y
	);

	tb : PROCESS
	BEGIN

		-- Wait 100 ns for global reset to finish
		wait for 100 ns;
		I0 <= '0';
		I1 <= '1';
		I2 <= '1';
		I3 <= '0';
		S0 <= '0';
		S1 <= '0';
		
		wait for 100 ns;
		S0 <= '0';
		S1 <= '1';
		
		wait for 100 ns;
		S0 <= '1';
		S1 <= '0';
		
		wait for 100 ns;
		S0 <= '1';
		S1 <= '1';
		
		-- Place stimulus here

		wait; -- will wait forever
	END PROCESS;

END;