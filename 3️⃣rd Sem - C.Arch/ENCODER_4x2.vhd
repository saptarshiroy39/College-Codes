library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ENCODER_4x2 is
    Port (
           Y3 : in  SID_LOGIC;
           Y2 : in  SID_LOGIC;
           Y1 : in  SID_LOGIC;
           Y0 : in  STD_LOGIC;
           B : in  STD_LOGIC;
           A : in  STD_LOGIC);
end ENCODER_4x2;

architecture Behavioral of ENCODER_4x2 is

begin

B <= Y3 OR Y2;
A <= Y3 OR Y1;

end Behavioral;

------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

ENTITY ENCODER_4x2_BS_vhd IS
END ENCODER_4x2_BS_vhd;

ARCHITECTURE behavior OF ENCODER_4x2_BS_vhd IS 

	-- Component Declaration for the Unit Under Test (UUT)
	COMPONENT ENCODER_4x2
	PORT(
		Y3 : IN std_logic;
		Y2 : IN std_logic;
		Y1 : IN std_logic;
		Y0 : IN std_logic;
		B : OUT std_logic;
		A : OUT std_logic
		);
	END COMPONENT;

	--Inputs
	SIGNAL Y3 :  std_logic := '0';
	SIGNAL Y2 :  std_logic := '0';
	SIGNAL Y1 :  std_logic := '0';
	SIGNAL Y0 :  std_logic := '0';

	--Outputs
	SIGNAL B :  std_logic;
	SIGNAL A :  std_logic;

BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: ENCODER_4x2 PORT MAP(
		Y3 => Y3,
		Y2 => Y2,
		Y1 => Y1,
		Y0 => Y0,
		B => B,
		A => A
	);

	tb : PROCESS
	BEGIN

		-- Wait 100 ns for global reset to finish
		wait for 100 ns;
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '1';
		
		wait for 100 ns;
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '1';
		Y0 <= '0';
		
		wait for 100 ns;
		Y3 <= '0';
		Y2 <= '1';
		Y1 <= '0';
		Y0 <= '0';
		
		wait for 100 ns;
		Y3 <= '1';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '0';

		-- Place stimulus here

		wait; -- will wait forever
	END PROCESS;

END;