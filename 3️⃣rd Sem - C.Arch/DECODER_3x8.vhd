library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity DECODER_3x8 is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           c : in  STD_LOGIC;
           D0 : out  SID_LOGIC;
           D1 : out  SID_LOGIC;
           D2 : out  SID_LOGIC;
           D3 : out  SID_LOGIC;
           D4 : out  SID_LOGIC;
           D5 : out  SID_LOGIC;
           D6 : out  SID_LOGIC;
           D7 : out  STD_LOGIC);
end DECODER_3x8;

architecture Behavioral of DECODER_3x8 is

begin

D0 <= (NOT A) AND (NOT B) AND (NOT C);
D1 <= (NOT A) AND (NOT B) AND C;
D2 <= (NOT A) AND B AND (NOT C);
D3 <= (NOT A) AND B AND C;
D4 <= A AND (NOT B) AND (NOT C);
D5 <= A AND (NOT B) AND C;
D6 <= A AND B AND (NOT C);
D7 <= A AND B AND C;

end Behavioral;

------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

ENTITY DECODER_3x8_BS_vhd IS
END DECODER_3x8_BS_vhd;

ARCHITECTURE behavior OF DECODER_3x8_BS_vhd IS 

	-- Component Declaration for the Unit Under Test (UUT)
	COMPONENT DECODER_3x8
	PORT(
		A : IN std_logic;
		B : IN std_logic;
    C : IN std_logic;
		D0 : OUT std_logic;
		D1 : OUT std_logic;
		D2 : OUT std_logic;
    D3 : OUT std_logic;
    D4 : OUT std_logic;
    D5 : OUT std_logic;
    D6 : OUT std_logic;
		D7 : OUT std_logic
		);
	END COMPONENT;

	--Inputs
	SIGNAL A :  std_logic := '0';
	SIGNAL B :  std_logic := '0';
  SIGNAL C :  std_logic := '0';

	--Outputs
	SIGNAL D0 :  std_logic;
	SIGNAL D1 :  std_logic;
	SIGNAL D2 :  std_logic;
	SIGNAL D3 :  std_logic;
  SIGNAL D4 :  std_logic;
	SIGNAL D5 :  std_logic;
	SIGNAL D6 :  std_logic;
	SIGNAL D7 :  std_logic;


BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: DECODER_3x8 PORT MAP(
		A => A,
		B => B,
    C => C,
		D0 => D0,
		D1 => D1,
		D2 => D2,
		D3 => D3,
    D4 => D4,
		D5 => D5,
		D6 => D6,
		D7 => D7
	);

	tb : PROCESS
	BEGIN

		-- Wait 100 ns for global reset to finish
		wait for 100 ns;
		A <= '0';
		B <= '0';
    C <= '0';
		
		wait for 100 ns;
		A <= '0';
		B <= '0';
    C <= '1';

		wait for 100 ns;
		A <= '0';
		B <= '1';
    C <= '0';

		wait for 100 ns;
		A <= '0';
		B <= '1';
    C <= '1';

    wait for 100 ns;
		A <= '1';
		B <= '0';
    C <= '0';

    wait for 100 ns;
		A <= '1';
		B <= '0';
    C <= '1';

    wait for 100 ns;
		A <= '1';
		B <= '1';
    C <= '0';

    wait for 100 ns;
		A <= '1';
		B <= '1';
    C <= '1';

		-- Place stimulus here

		wait; -- will wait forever
	END PROCESS;

END;