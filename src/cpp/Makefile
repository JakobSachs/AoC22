CC=clang++
DAYS=day1.cpp day2.cpp day3.cpp day4.cpp day5.cpp
DAYS_OBJ=$(subst .cpp,.o,$(DAYS))

all: days

days: $(DAYS_OBJ)
	$(foreach obj,$(DAYS_OBJ),$(CC) -std=c++20 -Og -g -o $(basename $(obj)) $(obj);)

%.o: %.cpp
	$(CC) -Og -g -c -std=c++20 $<

clean:
	rm -f *.o
	rm -f $(basename $(DAYS_OBJ))

