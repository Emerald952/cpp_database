SUBDIRS = cppdb cppdb-test cppdb-cli

all:
	$(MAKE) -C cppdb
	$(MAKE) -C cppdb-test
	$(MAKE) -C cppdb-cli

#runs make clean inside each folder
clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all clean cppdb cppdb-test cppdb-cli
