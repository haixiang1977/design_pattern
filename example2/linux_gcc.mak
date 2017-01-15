SAMPLES_ROOT	= $(PWD)
TOOLKIT_ROOT = $(SAMPLES_ROOT)/toolkit
LIB_TARGET_PATH = $(TOOLKIT_ROOT)/lib
INCLUDE_TARGET_PATH = $(TOOLKIT_ROOT)/Core/include $(TOOLKIT_ROOT)/api/include

include $(SAMPLES_ROOT)/linux_gcc_rules.mak

CFLAGS = -Wall -pthread

EXE				= OpcClient
LIBS			= -L$(LIB_TARGET_PATH) -ltb5cpp -lxml2 -ltb5ot -ltb5util -ltb5stack -lstdc++ -lssl -lcrypto -lpthread -lrt -lm -ldl
INCLUDE_DIRS	= $(SAMPLES_ROOT) $(INCLUDE_TARGET_PATH)

SOURCES			= $(wildcard *.cpp)
HEADERS			= $(wildcard *.h $(patsubst %,%/*.h,$(INCLUDE_DIRS)))
OBJECTS			= $(SOURCES:%.cpp=%.o)

all: $(EXE)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXE)


$(EXE): $(OBJECTS)
	$(CC) $(EXTRA_CFLAGS) -o $@ $(OBJECTS) $(LIBS)

$(OBJECTS): $(HEADERS)
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(patsubst %,-I%,$(INCLUDE_DIRS)) $(EXTRA_CFLAGS) -o $@ $<
