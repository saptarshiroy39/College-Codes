library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity DECODER_2x4 is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           D0 : out  SID_LOGIC;
           D1 : out  SID_LOGIC;
           D2 : out  SID_LOGIC;
           D3 : out  STD_LOGIC);
end DECODER_2x4;

architecture Behavioral of DECODER_2x4 is

begin

D0 <= (NOT A) AND (NOT B);
D1 <= (NOT A) AND B;
D2 <= A AND (NOT B);
D3 <= A AND B;

end Behavioral;

------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

ENTITY DECODER_2x4_BS_vhd IS
END DECODER_2x4_BS_vhd;

ARCHITECTURE behavior OF DECODER_2x4_BS_vhd IS 

	-- Component Declaration for the Unit Under Test (UUT)
	COMPONENT DECODER_2x4
	PORT(
		A : IN std_logic;
		B : IN std_logic;
		D0 : OUT std_logic;
		D1 : OUT std_logic;
		D2 : OUT std_logic;
		D3 : OUT std_logic
		);
	END COMPONENT;

	--Inputs
	SIGNAL A :  std_logic := '0';
	SIGNAL B :  std_logic := '0';

	--Outputs
	SIGNAL D0 :  std_logic;
	SIGNAL D1 :  std_logic;
	SIGNAL D2 :  std_logic;
	SIGNAL D3 :  std_logic;

BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: DECODER_2x4 PORT MAP(
		A => A,
		B => B,
		D0 => D0,
		D1 => D1,
		D2 => D2,
		D3 => D3
	);

	tb : PROCESS
	BEGIN

		-- Wait 100 ns for global reset to finish
		wait for 100 ns;
		A <= '0';
		B <= '0';
		
		wait for 100 ns;
		A <= '0';
		B <= '1';

		wait for 100 ns;
		A <= '1';
		B <= '0';

		wait for 100 ns;
		A <= '1';
		B <= '1';
		
		-- Place stimulus here

		wait; -- will wait forever
	END PROCESS;

END;