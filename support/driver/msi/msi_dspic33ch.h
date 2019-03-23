/**
 * @file msi_dspic33ch.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright UniSwarm 2018
 *
 * @date March 2, 10:00 AM
 *
 * @brief Master Slave Interface driver for dsPIC33CH
 *
 * Implementation based on Microchip document DS70005278B :
 *  http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33-PIC24-FRM-Master-Slave-Interface-MSI-Module-70005278b.pdf
 */
 
#if defined(DEVICE_33CH128MP202) || defined(DEVICE_33CH128MP203) || defined(DEVICE_33CH128MP205) \
 || defined(DEVICE_33CH128MP206) || defined(DEVICE_33CH128MP208) || defined(DEVICE_33CH128MP502) \
 || defined(DEVICE_33CH128MP503) || defined(DEVICE_33CH128MP505) || defined(DEVICE_33CH128MP506) \
 || defined(DEVICE_33CH128MP508) || defined(DEVICE_33CH256MP205) || defined(DEVICE_33CH256MP206) \
 || defined(DEVICE_33CH256MP208) || defined(DEVICE_33CH256MP505) || defined(DEVICE_33CH256MP506) \
 || defined(DEVICE_33CH256MP508) || defined(DEVICE_33CH512MP205) || defined(DEVICE_33CH512MP206) \
 || defined(DEVICE_33CH512MP208) || defined(DEVICE_33CH512MP505) || defined(DEVICE_33CH512MP506) \
 || defined(DEVICE_33CH512MP508) || defined(DEVICE_33CH64MP202) || defined(DEVICE_33CH64MP203) \
 || defined(DEVICE_33CH64MP205) || defined(DEVICE_33CH64MP206) || defined(DEVICE_33CH64MP208) \
 || defined(DEVICE_33CH64MP502) || defined(DEVICE_33CH64MP503) || defined(DEVICE_33CH64MP505) \
 || defined(DEVICE_33CH64MP506) || defined(DEVICE_33CH64MP508)
 #define MSI_HAVE_MASTER_INTERFACE
#endif

#if defined(DEVICE_33CH128MP202S1) || defined(DEVICE_33CH128MP203S1) || defined(DEVICE_33CH128MP205S1) \
 || defined(DEVICE_33CH128MP206S1) || defined(DEVICE_33CH128MP208S1) || defined(DEVICE_33CH128MP502S1) \
 || defined(DEVICE_33CH128MP503S1) || defined(DEVICE_33CH128MP505S1) || defined(DEVICE_33CH128MP506S1) \
 || defined(DEVICE_33CH128MP508S1) || defined(DEVICE_33CH256MP205S1) || defined(DEVICE_33CH256MP206S1) \
 || defined(DEVICE_33CH256MP208S1) || defined(DEVICE_33CH256MP505S1) || defined(DEVICE_33CH256MP506S1) \
 || defined(DEVICE_33CH256MP508S1) || defined(DEVICE_33CH512MP205S1) || defined(DEVICE_33CH512MP206S1) \
 || defined(DEVICE_33CH512MP208S1) || defined(DEVICE_33CH512MP505S1) || defined(DEVICE_33CH512MP506S1) \
 || defined(DEVICE_33CH512MP508S1) || defined(DEVICE_33CH64MP202S1) || defined(DEVICE_33CH64MP203S1) \
 || defined(DEVICE_33CH64MP205S1) || defined(DEVICE_33CH64MP206S1) || defined(DEVICE_33CH64MP208S1) \
 || defined(DEVICE_33CH64MP502S1) || defined(DEVICE_33CH64MP503S1) || defined(DEVICE_33CH64MP505S1) \
 || defined(DEVICE_33CH64MP506S1) || defined(DEVICE_33CH64MP508S1)
 #define MSI_HAVE_SLAVE_INTERFACE
#endif

#if defined(DEVICE_33CH128MP202) || defined(DEVICE_33CH128MP202S1) || defined(DEVICE_33CH128MP203) \
 || defined(DEVICE_33CH128MP203S1) || defined(DEVICE_33CH128MP205) || defined(DEVICE_33CH128MP205S1) \
 || defined(DEVICE_33CH128MP206) || defined(DEVICE_33CH128MP206S1) || defined(DEVICE_33CH128MP208) \
 || defined(DEVICE_33CH128MP208S1) || defined(DEVICE_33CH128MP502) || defined(DEVICE_33CH128MP502S1) \
 || defined(DEVICE_33CH128MP503) || defined(DEVICE_33CH128MP503S1) || defined(DEVICE_33CH128MP505) \
 || defined(DEVICE_33CH128MP505S1) || defined(DEVICE_33CH128MP506) || defined(DEVICE_33CH128MP506S1) \
 || defined(DEVICE_33CH128MP508) || defined(DEVICE_33CH128MP508S1) || defined(DEVICE_33CH256MP205) \
 || defined(DEVICE_33CH256MP205S1) || defined(DEVICE_33CH256MP206) || defined(DEVICE_33CH256MP206S1) \
 || defined(DEVICE_33CH256MP208) || defined(DEVICE_33CH256MP208S1) || defined(DEVICE_33CH256MP505) \
 || defined(DEVICE_33CH256MP505S1) || defined(DEVICE_33CH256MP506) || defined(DEVICE_33CH256MP506S1) \
 || defined(DEVICE_33CH256MP508) || defined(DEVICE_33CH256MP508S1) || defined(DEVICE_33CH512MP205) \
 || defined(DEVICE_33CH512MP205S1) || defined(DEVICE_33CH512MP206) || defined(DEVICE_33CH512MP206S1) \
 || defined(DEVICE_33CH512MP208) || defined(DEVICE_33CH512MP208S1) || defined(DEVICE_33CH512MP505) \
 || defined(DEVICE_33CH512MP505S1) || defined(DEVICE_33CH512MP506) || defined(DEVICE_33CH512MP506S1) \
 || defined(DEVICE_33CH512MP508) || defined(DEVICE_33CH512MP508S1) || defined(DEVICE_33CH64MP202) \
 || defined(DEVICE_33CH64MP202S1) || defined(DEVICE_33CH64MP203) || defined(DEVICE_33CH64MP203S1) \
 || defined(DEVICE_33CH64MP205) || defined(DEVICE_33CH64MP205S1) || defined(DEVICE_33CH64MP206) \
 || defined(DEVICE_33CH64MP206S1) || defined(DEVICE_33CH64MP208) || defined(DEVICE_33CH64MP208S1) \
 || defined(DEVICE_33CH64MP502) || defined(DEVICE_33CH64MP502S1) || defined(DEVICE_33CH64MP503) \
 || defined(DEVICE_33CH64MP503S1) || defined(DEVICE_33CH64MP505) || defined(DEVICE_33CH64MP505S1) \
 || defined(DEVICE_33CH64MP506) || defined(DEVICE_33CH64MP506S1) || defined(DEVICE_33CH64MP508) \
 || defined(DEVICE_33CH64MP508S1)
 #define MSI_MAILBOX_COUNT 16
 #define MSI_PROTOCOL_COUNT 8
#endif
