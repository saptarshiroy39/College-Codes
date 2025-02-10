library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ENCODER_8x3 is
    Port (
           Y7 : in  SID_LOGIC;
           Y6 : in  SID_LOGIC;
           Y5 : in  SID_LOGIC;
           Y4 : in  STD_LOGIC;
           Y3 : in  SID_LOGIC;
           Y2 : in  SID_LOGIC;
           Y1 : in  SID_LOGIC;
           Y0 : in  STD_LOGIC;
           C : in  STD_LOGIC;
           B : in  STD_LOGIC;
           A : in  STD_LOGIC);
end ENCODER_8x3;

architecture Behavioral of ENCODER_8x3 is

begin

C <= Y7 OR Y6 OR Y5 OR Y4;
B <= Y7 OR Y6 OR Y3 OR Y2;
A <= Y7 OR Y5 OR Y3 OR Y1;

end Behavioral;

------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

ENTITY ENCODER_8x3_BS_vhd IS
END ENCODER_8x3_BS_vhd;

ARCHITECTURE behavior OF ENCODER_8x3_BS_vhd IS 

	-- Component Declaration for the Unit Under Test (UUT)
	COMPONENT ENCODER_8x3
	PORT(
		Y7 : IN std_logic;
		Y6 : IN std_logic;
		Y5 : IN std_logic;
		Y4 : IN std_logic;
		Y3 : IN std_logic;
		Y2 : IN std_logic;
		Y1 : IN std_logic;
		Y0 : IN std_logic;
    C : OUT std_logic;
		B : OUT std_logic;
		A : OUT std_logic
		);
	END COMPONENT;

	--Inputs
  SIGNAL Y7 :  std_logic := '0';
	SIGNAL Y6 :  std_logic := '0';
	SIGNAL Y5 :  std_logic := '0';
	SIGNAL Y4 :  std_logic := '0';
	SIGNAL Y3 :  std_logic := '0';
	SIGNAL Y2 :  std_logic := '0';
	SIGNAL Y1 :  std_logic := '0';
	SIGNAL Y0 :  std_logic := '0';

	--Outputs
  SIGNAL C :  std_logic;
	SIGNAL B :  std_logic;
	SIGNAL A :  std_logic;

BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: ENCODER_8x3 PORT MAP(
    Y7 => Y7,
		Y6 => Y6,
		Y5 => Y5,
		Y4 => Y4,
		Y3 => Y3,
		Y2 => Y2,
		Y1 => Y1,
		Y0 => Y0,
    C => C,
		B => B,
		A => A
	);

	tb : PROCESS
	BEGIN

		-- Wait 100 ns for global reset to finish
		wait for 100 ns;
    Y7 <= '0';
		Y6 <= '0';
		Y5 <= '0';
		Y4 <= '0';
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '1';
		
		wait for 100 ns;
    Y7 <= '0';
		Y6 <= '0';
		Y5 <= '0';
		Y4 <= '0';
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '1';
		Y0 <= '0';
		
		wait for 100 ns;
    Y7 <= '0';
		Y6 <= '0';
		Y5 <= '0';
		Y4 <= '0';
		Y3 <= '0';
		Y2 <= '1';
		Y1 <= '0';
		Y0 <= '0';
		
		wait for 100 ns;
    Y7 <= '0';
		Y6 <= '0';
		Y5 <= '0';
		Y4 <= '0';
		Y3 <= '1';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '0';

    wait for 100 ns;
    Y7 <= '0';
		Y6 <= '0';
		Y5 <= '0';
		Y4 <= '1';
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '0';

    wait for 100 ns;
    Y7 <= '0';
		Y6 <= '0';
		Y5 <= '1';
		Y4 <= '0';
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '0';

    wait for 100 ns;
    Y7 <= '0';
		Y6 <= '1';
		Y5 <= '0';
		Y4 <= '0';
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '0';

    wait for 100 ns;
    Y7 <= '1';
		Y6 <= '0';
		Y5 <= '0';
		Y4 <= '0';
		Y3 <= '0';
		Y2 <= '0';
		Y1 <= '0';
		Y0 <= '0';

		-- Place stimulus here

		wait; -- will wait forever
	END PROCESS;

END;