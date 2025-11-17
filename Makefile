TARGET = jogo

#compilador
CXX = g++


#Flags de Compilacao
RAYLIB = raylib
THIRD_PARTY = third-party
CFLAGS = -g -Wall -std=c++11 -I$(THIRD_PARTY) -I$(RAYLIB)
LDFLAGS = 
LIBS = -lraylib -lm -lpthread -ldl -lX11


#Faz a troca de variaveis caso o OS seja o Lixows
ifeq ($(OS), Windows_NT)
	LDFLAGS = -L/msys64//mingw64/lib -mwindows
	LIBS = -lraylib -lmingw32 -lopengl32 -lgdi32 -lwinmm
endif


#Diretorios
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
BIN_DIR = bin
OBJ_DIR = build

ifeq ($(COVERAGE),1)
	CFLAGS += -fprofile-arcs -ftest-coverage
	OBJ_DIR = build_coverage
	TARGET = programa_coverage
	LDFLAGS += -lgcov
endif

#Arquivos padrao
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

MAIN_OBJ = $(OBJ_DIR)/jogo.o 
DEPENDENCIAS_O = $(filter-out $(MAIN_OBJ), $(OBJ))


#Arquivos de teste
TESTS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.test.o, $(TESTS))
TEST_BIN = $(BIN_DIR)/tests


all: $(BIN_DIR)/$(TARGET)

#Compilacao do Jogo
$(BIN_DIR)/$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(LIBS) $(LDFLAGS)
	@echo "-------- Jogo compilado com sucesso --------"
	
#Compilacao dos .cpp -> .o 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "-------- Compilado: $< --------"

#Compilacao de testes
$(TEST_BIN): $(DEPENDENCIAS_O) $(TEST_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS)
	@echo "-------- Testes compilados com sucesso --------"


$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "-------- Compilado teste: $< --------"


clean:
	rm -rf build build_coverage $(BIN_DIR)
	@echo "-------- Arquivos deletados --------"

#Rodar o jogo
run: all
	@./$(BIN_DIR)/$(TARGET)

#Rodar testes
test:
	$(MAKE) COVERAGE=1 $(TEST_BIN)
	@echo "-------- Testes doctest $(TEST_BIN) --------"
	@./$(TEST_BIN)
