CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g -Iincludes
CC = g++

SRC_DIR = src
INCLUDE_DIR = includes

OBJECTS = main.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o userType.o

banking-app: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: $(SRC_DIR)/main.cpp bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o userType.o
	$(CC) $(CFLAGS) -c $<

highInterestSavingsType.o: $(SRC_DIR)/highInterestSavingsType.cpp $(INCLUDE_DIR)/highInterestSavingsType.h bankAccountType.o  savingsAccountType.o
	$(CC) $(CFLAGS) -c $<

savingsAccountType.o: $(SRC_DIR)/savingsAccountType.cpp $(INCLUDE_DIR)/savingsAccountType.h bankAccountType.o
	$(CC) $(CFLAGS) -c $<

certificateOfDepositType.o: $(SRC_DIR)/certificateOfDepositType.cpp $(INCLUDE_DIR)/certificateOfDepositType.h bankAccountType.o
	$(CC) $(CFLAGS) -c $<

bankAccountType.o: $(SRC_DIR)/bankAccountType.cpp $(INCLUDE_DIR)/bankAccountType.h
	$(CC) $(CFLAGS) -c $<

serviceChargeCheckingType.o: $(SRC_DIR)/serviceChargeCheckingType.cpp $(INCLUDE_DIR)/serviceChargeCheckingType.h checkingAccountType.o
	$(CC) $(CFLAGS) -c $<

highInterestCheckingType.o: $(SRC_DIR)/highInterestCheckingType.cpp $(INCLUDE_DIR)/highInterestCheckingType.h noServiceChargeCheckingType.o
	$(CC) $(CFLAGS) -c $<

noServiceChargeCheckingType.o: $(SRC_DIR)/noServiceChargeCheckingType.cpp $(INCLUDE_DIR)/noServiceChargeCheckingType.h checkingAccountType.o
	$(CC) $(CFLAGS) -c $<

checkingAccountType.o: $(SRC_DIR)/checkingAccountType.cpp $(INCLUDE_DIR)/checkingAccountType.h bankAccountType.o
	$(CC) $(CFLAGS) -c $<

userType.o: $(SRC_DIR)/userType.cpp $(INCLUDE_DIR)/userType.h
	$(CC) $(CFLAGS) -c $<

transfersAndWire.o: $(SRC_DIR)/transfersAndWire.cpp $(INCLUDE_DIR)/transfersAndWire.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f banking-app *.o *~
