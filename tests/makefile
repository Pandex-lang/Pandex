CC = cc # gcc for me

ROOT_PATH = ..

TEST_OUTPUT = m

# main files
OBJECTS = scanner.o
OBJECTS += sym_tbl.o

# test files
OBJECTS += scanner_scan_kwd_fn_test.o
OBJECTS += scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test.o
OBJECTS += table.o

# main files
MAIN_TARGET_DEPS = scanner.o #
MAIN_TARGET_DEPS += sym_tbl.o

# test files
MAIN_TARGET_DEPS += scanner_scan_kwd_fn_test.o #
MAIN_TARGET_DEPS += scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test.o #
MAIN_TARGET_DEPS += table.o

#TEST_STATUS = scanner_scan_kwd_fn_test
#TEST_STATUS = scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test
TEST_STATUS = table

all: $(MAIN_TARGET_DEPS)
ifeq (${TEST_STATUS},scanner_scan_kwd_fn_test)
		$(CC) scanner.o ${TEST_STATUS}.o -o $(TEST_OUTPUT)
endif

ifeq (${TEST_STATUS},scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test)
	$(CC) scanner.o ${TEST_STATUS}.o -o $(TEST_OUTPUT)
endif

ifeq (${TEST_STATUS},table)
	$(CC) sym_tbl.o ${TEST_STATUS}.o -o $(TEST_OUTPUT)
endif


# main files
scanner.o:
	$(CC) -c $(ROOT_PATH)/analyzer/lexical/${@:.o=.c}

sym_tbl.o:
	$(CC) -c $(ROOT_PATH)/analyzer/lexical/${@:.o=.c}

# test files
scanner_scan_kwd_fn_test.o:
	$(CC) -c $(ROOT_PATH)/tests/${@:.o=.c}

scan__scan_getCharType_getCharNum_getCharTok_isAlpha_isNumeric_fn_s_test.o:
	$(CC) -c $(ROOT_PATH)/tests/${@:.o=.c}

table.o:
	$(CC) -c $(ROOT_PATH)/tests/${@:.o=.c}

clean:
	rm $(OBJECTS)
	rm $(TEST_OUTPUT)
