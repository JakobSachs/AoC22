CC=clang++
DAYS=day1.cpp day2.cpp
DAYS_OBJ=$(subst .cpp,.o,$(DAYS))

all: days

days: $(DAYS_OBJ)
	$(foreach obj,$(DAYS_OBJ),$(CC) -Og -g -o $(basename $(obj)) $(obj);)

%.o: %.cpp
	$(CC) -Og -g -c $<

clean:
	rm -f *.o
	rm -f $(basename $(DAYS_OBJ))

