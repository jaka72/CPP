/*
	THE FUNCTION swap() IS ALREADY INCLUDED SOMEWHERE IN std::

	swap() seems to be in std::basic_ios


	OR IN iostream ????, IT WORKS WITH ALL DATA TYPES,
	BUT IF YOU OVERRIDE IT WITH A TEMPLATE swap()
	IT WILL NOT USE THE TEMPLATE, WHEN YOU GIVE IT STRINGS      INTS            STRINGS
	swap() works in 3 variants for ints:         swap()         mine              std
											   ::swap()         mine              mine
											std::swap()         std               std
	
															   INTS            STRINGS
												 min()         mine              mine
											   ::min()         mine              mine
											std::min()         std               std
	CHECK ON MAC !!!

	THIS CAN BE SOLVED WITH DOUBLE COLON PREPENDED TO THE FUNCTION NAME:   ::swap()
		operator:: 	Is called 'global scope resolution operator'
					It resolves to the top-level configuration (most outer class/namespace ???)

	I also added a class, to see if T can also be a class. But I guess it is not mandatory.
*/
