CC=clang++
DAYS=day1.cpp
DAYS_OBJ=$(subst .cpp,.o,$(DAYS))

all: days

days: $(DAYS_OBJ)
	$(foreach obj,$(DAYS_OBJ),$(CC) -O3 -o $(basename $(obj)) $(obj);)

%.o: %.cpp
	$(CC) -O3 -c $<

clean:
	rm -f *.o
	rm -f $(basename $(DAYS_OBJ))

