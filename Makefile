objs = menu.o Backstage.o Interface.o 
  
vms: $(objs)
	cc $(objs) -o vms

.PHONY: clean

clean:
	rm -f $(objs) vms