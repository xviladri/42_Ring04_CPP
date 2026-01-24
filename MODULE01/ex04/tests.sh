#!/bin/bash

# Colores para la salida
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

PROGRAM="./sed_is_for_losers"
TEST_FILE="test_input.txt"

# Compilar
echo -e "${GREEN}Compiling...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Función de ayuda para ejecutar tests
run_test() {
    local test_name="$1"
    local s1="$2"
    local s2="$3"
    local expected_content="$4"

    echo -e "\n--- Test: $test_name ---"
    echo "Pattern: '$s1' -> Replacement: '$s2'"
    
    $PROGRAM "$TEST_FILE" "$s1" "$s2"
    
    if [ ! -f "$TEST_FILE.replace" ]; then
        echo -e "${RED}FAIL: Output file not created.${NC}"
        return
    fi

    local actual_content=$(cat "$TEST_FILE.replace")
    
    if [ "$actual_content" == "$expected_content" ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FAIL${NC}"
        echo "Expected: '$expected_content'"
        echo "Got:      '$actual_content'"
    fi
}

# Crear archivo de prueba base
setup_file() {
    echo "Hello World" > $TEST_FILE
    echo "This is a test file." >> $TEST_FILE
    echo "World needs C++." >> $TEST_FILE
}

# --- Ejecución de Tests ---

# 1. Reemplazo básico
setup_file
EXPECTED=$'Hello 42\nThis is a test file.\n42 needs C++.\n'
run_test "Basic Replacement" "World" "42" "$EXPECTED"

# 2. Reemplazo múltiple en misma línea
echo "a a a" > $TEST_FILE
EXPECTED="b b b"
run_test "Multiple occurrences line" "a" "b" "$EXPECTED"

# 3. Borrado (s2 vacío)
setup_file
EXPECTED=$'Hello \nThis is a test file.\n needs C++.\n'
run_test "Delete word (empty replacement)" "World" "" "$EXPECTED"

# 4. No encontrado
setup_file
EXPECTED=$(cat $TEST_FILE)
run_test "String not found" "Python" "C++" "$EXPECTED"

# 5. Evitar recursión infinita (a -> aa)
echo "a" > $TEST_FILE
EXPECTED="aa"
run_test "Infinite loop check (a -> aa)" "a" "aa" "$EXPECTED"

# 6. Caracteres especiales
echo "Hello\nWorld" > $TEST_FILE # Note: echo behavior with \n varies, using simple setup
echo -e "Hello\nWorld" > $TEST_FILE
EXPECTED=$'Hello\nEarth'
run_test "Newline preservation" "World" "Earth" "$EXPECTED"

# Limpieza
echo -e "\n${GREEN}Cleaning up...${NC}"
rm -f $TEST_FILE $TEST_FILE.replace
make fclean
