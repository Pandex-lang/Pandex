Pandex tests
=============

* in the `test` directory I push Pandex tests

but How their works ? How use them ?
-------------------------------------

so look at structure .

structure
~~~~~~~~~~
this directory hold some of files check the functions and etc

1) check the scanner ( starts by scan )
2) 


The makefile
-------------
I use makefile to run and check tests .

about makefile
~~~~~~~~~~~~~~~

1) variables
	- :code:`$(CC)` : :code:`$cc` hold the compiler ( e.g CC=gcc or CC=clang )
	- :code:`$(ROOT_PATH)` : it's hold relative root path so if you go there from here , you are in root
	- :code:`$(TEST_OUTPUT)` : name of executable file or :code:`$(CC) files.(o|c) -o $(TEST_OUTPUT)`
	- :code:`$(OBJECTS)` : :code:`.o` CC output names
	- :code:`$(MAIN_TARGET_DEPS)` : makefile main | default | all target needs targets executed before 
	- :code:`$(TEST_STATUS)` : type of test will execute
