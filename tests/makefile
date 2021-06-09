CC = gcc # or clang for me

ROOT_PATH = ..

TEST_OUTPUT = m

OBJECTS = scanner.o
OBJECTS += scanner_scan_kwd_fn_test.o
OBJECTS += scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test.o
OBJECTS += $(TEST_OUTPUT)

MAIN_TARGET_DEPS = scanner.o 
MAIN_TARGET_DEPS += scanner_scan_kwd_fn_test.o #
MAIN_TARGET_DEPS += scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test.o

#TEST_STATUS = scanner_scan_kwd_fn_test
TEST_STATUS = scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test

all: $(MAIN_TARGET_DEPS)
ifeq ($(TEST_STATUS),scanner_scan_kwd_fn_test)
		$(CC) scanner.o scanner_scan_kwd_fn_test.o -o $(TEST_OUTPUT)
endif
ifeq ($(TEST_STATUS),scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test)
	$(CC) scanner.o \
	scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test.c \
	-o $(TEST_OUTPUT)
endif

	
# main files
scanner.o:
	$(CC) -c $(ROOT_PATH)/analyzer/lexical/scanner.c
	
	
# test files
scanner_scan_kwd_fn_test.o:
	$(CC) -c $(ROOT_PATH)/tests/scanner_scan_kwd_fn_test.c
	
scan__scan_getCharType_getCharNum_getCharTok_isAlpha_isNumeric_fn_s_test.o:
	$(CC) -c $(ROOT_PATH)/tests/scan__scan_get_CharType_CharNum_CharTok_is_Alpha_Numeric_fn_s_test.c

clean:
	rm $(OBJECTS)
	rm $(TEST_OUTPUT)
