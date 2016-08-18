ifndef OC_DRIVER
OC_DRIVER=

vpath %.c $(DRIVERPATH)

HEADER += oc.h

ifeq ($(ARCHI),$(filter $(ARCHI),pic24ep dspic33ep dspic33ev))
 ARCHI_SRC += oc_pic24e_dspic33e.c
 HEADER += oc_pic24e_dspic33e.h
endif
ifeq ($(ARCHI),$(filter $(ARCHI),pic24f pic24fj pic24hj dspic30f dspic33fj))
 ARCHI_SRC += oc_pic24f_dspic33f_dspic30f.c
 HEADER += oc_pic24f_dspic33f_dspic30f.h
endif

endif
