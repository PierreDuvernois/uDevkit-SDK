/**
 * @file oc_pic24f_dspic33f_dspic30f.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright Robotips 2016
 *
 * @date August 18, 2016, 15:40 PM 
 * 
 * @brief Output Compare support driver for dsPIC30F, dsPIC33FJ, PIC24F, PIC24FJ, PIC24FV and PIC24HJ
 */

#ifndef OC_PIC24F_dsPIC33F_dsPIC30F_H
#define OC_PIC24F_dsPIC33F_dsPIC30F_H

#if defined(DEVICE_dsPIC30F1010) || defined(DEVICE_dsPIC33FJ06GS101) || defined(DEVICE_dsPIC33FJ06GS101A) \
 || defined(DEVICE_dsPIC33FJ06GS102) || defined(DEVICE_dsPIC33FJ06GS102A) || defined(DEVICE_dsPIC33FJ06GS202) \
 || defined(DEVICE_dsPIC33FJ06GS202A) || defined(DEVICE_dsPIC33FJ09GS302) || defined(DEVICE_PIC24F04KA200) \
 || defined(DEVICE_PIC24F04KA201) || defined(DEVICE_PIC24F08KA101) || defined(DEVICE_PIC24F08KA102) \
 || defined(DEVICE_PIC24F16KA101) || defined(DEVICE_PIC24F16KA102)
 #define OC_COUNT 1
#elif defined(DEVICE_dsPIC30F2010) || defined(DEVICE_dsPIC30F2010E) || defined(DEVICE_dsPIC30F2011) \
 || defined(DEVICE_dsPIC30F2011E) || defined(DEVICE_dsPIC30F2012) || defined(DEVICE_dsPIC30F2012E) \
 || defined(DEVICE_dsPIC30F2020) || defined(DEVICE_dsPIC30F2023) || defined(DEVICE_dsPIC30F3010) \
 || defined(DEVICE_dsPIC30F3010E) || defined(DEVICE_dsPIC30F3012) || defined(DEVICE_dsPIC30F3012E) \
 || defined(DEVICE_dsPIC30F3013) || defined(DEVICE_dsPIC30F3013E) || defined(DEVICE_dsPIC30F3014) \
 || defined(DEVICE_dsPIC30F3014E) || defined(DEVICE_dsPIC30F4012) || defined(DEVICE_dsPIC30F4012E) \
 || defined(DEVICE_dsPIC33FJ12GP201) || defined(DEVICE_dsPIC33FJ12GP202) || defined(DEVICE_dsPIC33FJ12MC201) \
 || defined(DEVICE_dsPIC33FJ12MC202) || defined(DEVICE_dsPIC33FJ16GP101) || defined(DEVICE_dsPIC33FJ16GP102) \
 || defined(DEVICE_dsPIC33FJ16GP304) || defined(DEVICE_dsPIC33FJ16GS402) || defined(DEVICE_dsPIC33FJ16GS404) \
 || defined(DEVICE_dsPIC33FJ16GS502) || defined(DEVICE_dsPIC33FJ16GS504) || defined(DEVICE_dsPIC33FJ16MC101) \
 || defined(DEVICE_dsPIC33FJ16MC102) || defined(DEVICE_dsPIC33FJ16MC304) || defined(DEVICE_dsPIC33FJ32GP101) \
 || defined(DEVICE_dsPIC33FJ32GP102) || defined(DEVICE_dsPIC33FJ32GP104) || defined(DEVICE_dsPIC33FJ32GP202) \
 || defined(DEVICE_dsPIC33FJ32GP204) || defined(DEVICE_dsPIC33FJ32MC101) || defined(DEVICE_dsPIC33FJ32MC102) \
 || defined(DEVICE_dsPIC33FJ32MC104) || defined(DEVICE_dsPIC33FJ32MC202) || defined(DEVICE_dsPIC33FJ32MC204) \
 || defined(DEVICE_PIC24FJ16MC101) || defined(DEVICE_PIC24FJ16MC102) || defined(DEVICE_PIC24FJ32MC101) \
 || defined(DEVICE_PIC24FJ32MC102) || defined(DEVICE_PIC24FJ32MC104) || defined(DEVICE_PIC24HJ12GP201) \
 || defined(DEVICE_PIC24HJ12GP202) || defined(DEVICE_PIC24HJ16GP304) || defined(DEVICE_PIC24HJ32GP202) \
 || defined(DEVICE_PIC24HJ32GP204)
 #define OC_COUNT 2
#elif defined(DEVICE_PIC24F16KA301) || defined(DEVICE_PIC24F16KA302) || defined(DEVICE_PIC24F16KA304) \
 || defined(DEVICE_PIC24F32KA301) || defined(DEVICE_PIC24F32KA302) || defined(DEVICE_PIC24F32KA304) \
 || defined(DEVICE_PIC24FJ128GA702) || defined(DEVICE_PIC24FJ128GA704) || defined(DEVICE_PIC24FJ128GA705) \
 || defined(DEVICE_PIC24FJ256GA702) || defined(DEVICE_PIC24FJ256GA704) || defined(DEVICE_PIC24FJ256GA705) \
 || defined(DEVICE_PIC24FJ64GA702) || defined(DEVICE_PIC24FJ64GA704) || defined(DEVICE_PIC24FJ64GA705) \
 || defined(DEVICE_PIC24FV16KA301) || defined(DEVICE_PIC24FV16KA302) || defined(DEVICE_PIC24FV16KA304) \
 || defined(DEVICE_PIC24FV32KA301) || defined(DEVICE_PIC24FV32KA302) || defined(DEVICE_PIC24FV32KA304)
 #define OC_COUNT 3
#elif defined(DEVICE_dsPIC30F3011) || defined(DEVICE_dsPIC30F3011E) || defined(DEVICE_dsPIC30F4011) \
 || defined(DEVICE_dsPIC30F4011E) || defined(DEVICE_dsPIC30F4013) || defined(DEVICE_dsPIC30F4013E) \
 || defined(DEVICE_dsPIC30F5015) || defined(DEVICE_dsPIC30F5015E) || defined(DEVICE_dsPIC30F5016) \
 || defined(DEVICE_dsPIC33FJ128GP202) || defined(DEVICE_dsPIC33FJ128GP204) || defined(DEVICE_dsPIC33FJ128GP802) \
 || defined(DEVICE_dsPIC33FJ128GP804) || defined(DEVICE_dsPIC33FJ128MC202) || defined(DEVICE_dsPIC33FJ128MC204) \
 || defined(DEVICE_dsPIC33FJ128MC802) || defined(DEVICE_dsPIC33FJ128MC804) || defined(DEVICE_dsPIC33FJ32GP302) \
 || defined(DEVICE_dsPIC33FJ32GP304) || defined(DEVICE_dsPIC33FJ32GS406) || defined(DEVICE_dsPIC33FJ32GS606) \
 || defined(DEVICE_dsPIC33FJ32GS608) || defined(DEVICE_dsPIC33FJ32GS610) || defined(DEVICE_dsPIC33FJ32MC302) \
 || defined(DEVICE_dsPIC33FJ32MC304) || defined(DEVICE_dsPIC33FJ64GP202) || defined(DEVICE_dsPIC33FJ64GP204) \
 || defined(DEVICE_dsPIC33FJ64GP802) || defined(DEVICE_dsPIC33FJ64GP804) || defined(DEVICE_dsPIC33FJ64GS406) \
 || defined(DEVICE_dsPIC33FJ64GS606) || defined(DEVICE_dsPIC33FJ64GS608) || defined(DEVICE_dsPIC33FJ64GS610) \
 || defined(DEVICE_dsPIC33FJ64MC202) || defined(DEVICE_dsPIC33FJ64MC204) || defined(DEVICE_dsPIC33FJ64MC802) \
 || defined(DEVICE_dsPIC33FJ64MC804) || defined(DEVICE_PIC24HJ128GP202) || defined(DEVICE_PIC24HJ128GP204) \
 || defined(DEVICE_PIC24HJ128GP502) || defined(DEVICE_PIC24HJ128GP504) || defined(DEVICE_PIC24HJ32GP302) \
 || defined(DEVICE_PIC24HJ32GP304) || defined(DEVICE_PIC24HJ64GP202) || defined(DEVICE_PIC24HJ64GP204) \
 || defined(DEVICE_PIC24HJ64GP502) || defined(DEVICE_PIC24HJ64GP504)
 #define OC_COUNT 4
#elif defined(DEVICE_PIC24FJ128GA006) || defined(DEVICE_PIC24FJ128GA008) || defined(DEVICE_PIC24FJ128GA010) \
 || defined(DEVICE_PIC24FJ16GA002) || defined(DEVICE_PIC24FJ16GA004) || defined(DEVICE_PIC24FJ32GA002) \
 || defined(DEVICE_PIC24FJ32GA004) || defined(DEVICE_PIC24FJ32GA102) || defined(DEVICE_PIC24FJ32GA104) \
 || defined(DEVICE_PIC24FJ32GB002) || defined(DEVICE_PIC24FJ32GB004) || defined(DEVICE_PIC24FJ48GA002) \
 || defined(DEVICE_PIC24FJ48GA004) || defined(DEVICE_PIC24FJ64GA002) || defined(DEVICE_PIC24FJ64GA004) \
 || defined(DEVICE_PIC24FJ64GA006) || defined(DEVICE_PIC24FJ64GA008) || defined(DEVICE_PIC24FJ64GA010) \
 || defined(DEVICE_PIC24FJ64GA102) || defined(DEVICE_PIC24FJ64GA104) || defined(DEVICE_PIC24FJ64GB002) \
 || defined(DEVICE_PIC24FJ64GB004) || defined(DEVICE_PIC24FJ96GA006) || defined(DEVICE_PIC24FJ96GA008) \
 || defined(DEVICE_PIC24FJ96GA010)
 #define OC_COUNT 5
#elif defined(DEVICE_PIC24FJ1024GA606) || defined(DEVICE_PIC24FJ1024GA610) || defined(DEVICE_PIC24FJ1024GB606) \
 || defined(DEVICE_PIC24FJ1024GB610) || defined(DEVICE_PIC24FJ128GA202) || defined(DEVICE_PIC24FJ128GA204) \
 || defined(DEVICE_PIC24FJ128GA406) || defined(DEVICE_PIC24FJ128GA410) || defined(DEVICE_PIC24FJ128GA412) \
 || defined(DEVICE_PIC24FJ128GA606) || defined(DEVICE_PIC24FJ128GA610) || defined(DEVICE_PIC24FJ128GB202) \
 || defined(DEVICE_PIC24FJ128GB204) || defined(DEVICE_PIC24FJ128GB406) || defined(DEVICE_PIC24FJ128GB410) \
 || defined(DEVICE_PIC24FJ128GB412) || defined(DEVICE_PIC24FJ128GB606) || defined(DEVICE_PIC24FJ128GB610) \
 || defined(DEVICE_PIC24FJ256GA406) || defined(DEVICE_PIC24FJ256GA410) || defined(DEVICE_PIC24FJ256GA412) \
 || defined(DEVICE_PIC24FJ256GA606) || defined(DEVICE_PIC24FJ256GA610) || defined(DEVICE_PIC24FJ256GB406) \
 || defined(DEVICE_PIC24FJ256GB410) || defined(DEVICE_PIC24FJ256GB412) || defined(DEVICE_PIC24FJ256GB606) \
 || defined(DEVICE_PIC24FJ256GB610) || defined(DEVICE_PIC24FJ512GA606) || defined(DEVICE_PIC24FJ512GA610) \
 || defined(DEVICE_PIC24FJ512GB606) || defined(DEVICE_PIC24FJ512GB610) || defined(DEVICE_PIC24FJ64GA202) \
 || defined(DEVICE_PIC24FJ64GA204) || defined(DEVICE_PIC24FJ64GA406) || defined(DEVICE_PIC24FJ64GA410) \
 || defined(DEVICE_PIC24FJ64GA412) || defined(DEVICE_PIC24FJ64GB202) || defined(DEVICE_PIC24FJ64GB204) \
 || defined(DEVICE_PIC24FJ64GB406) || defined(DEVICE_PIC24FJ64GB410) || defined(DEVICE_PIC24FJ64GB412)
 #define OC_COUNT 6
#elif defined(DEVICE_PIC24FJ128GA306) || defined(DEVICE_PIC24FJ128GA308) || defined(DEVICE_PIC24FJ128GA310) \
 || defined(DEVICE_PIC24FJ64GA306) || defined(DEVICE_PIC24FJ64GA308) || defined(DEVICE_PIC24FJ64GA310)
 #define OC_COUNT 7
#elif defined(DEVICE_dsPIC30F5011) || defined(DEVICE_dsPIC30F5011E) || defined(DEVICE_dsPIC30F5013) \
 || defined(DEVICE_dsPIC30F5013E) || defined(DEVICE_dsPIC30F6010) || defined(DEVICE_dsPIC30F6010A) \
 || defined(DEVICE_dsPIC30F6011) || defined(DEVICE_dsPIC30F6011A) || defined(DEVICE_dsPIC30F6012) \
 || defined(DEVICE_dsPIC30F6012A) || defined(DEVICE_dsPIC30F6013) || defined(DEVICE_dsPIC30F6013A) \
 || defined(DEVICE_dsPIC30F6014) || defined(DEVICE_dsPIC30F6014A) || defined(DEVICE_dsPIC30F6015) \
 || defined(DEVICE_dsPIC33FJ128GP206) || defined(DEVICE_dsPIC33FJ128GP206A) || defined(DEVICE_dsPIC33FJ128GP306) \
 || defined(DEVICE_dsPIC33FJ128GP306A) || defined(DEVICE_dsPIC33FJ128GP310) || defined(DEVICE_dsPIC33FJ128GP310A) \
 || defined(DEVICE_dsPIC33FJ128GP706) || defined(DEVICE_dsPIC33FJ128GP706A) || defined(DEVICE_dsPIC33FJ128GP708) \
 || defined(DEVICE_dsPIC33FJ128GP708A) || defined(DEVICE_dsPIC33FJ128GP710) || defined(DEVICE_dsPIC33FJ128GP710A) \
 || defined(DEVICE_dsPIC33FJ128MC506) || defined(DEVICE_dsPIC33FJ128MC506A) || defined(DEVICE_dsPIC33FJ128MC510) \
 || defined(DEVICE_dsPIC33FJ128MC510A) || defined(DEVICE_dsPIC33FJ128MC706) || defined(DEVICE_dsPIC33FJ128MC706A) \
 || defined(DEVICE_dsPIC33FJ128MC708) || defined(DEVICE_dsPIC33FJ128MC708A) || defined(DEVICE_dsPIC33FJ128MC710) \
 || defined(DEVICE_dsPIC33FJ128MC710A) || defined(DEVICE_dsPIC33FJ256GP506) || defined(DEVICE_dsPIC33FJ256GP506A) \
 || defined(DEVICE_dsPIC33FJ256GP510) || defined(DEVICE_dsPIC33FJ256GP510A) || defined(DEVICE_dsPIC33FJ256GP710) \
 || defined(DEVICE_dsPIC33FJ256GP710A) || defined(DEVICE_dsPIC33FJ256MC510) || defined(DEVICE_dsPIC33FJ256MC510A) \
 || defined(DEVICE_dsPIC33FJ256MC710) || defined(DEVICE_dsPIC33FJ256MC710A) || defined(DEVICE_dsPIC33FJ64GP206) \
 || defined(DEVICE_dsPIC33FJ64GP206A) || defined(DEVICE_dsPIC33FJ64GP306) || defined(DEVICE_dsPIC33FJ64GP306A) \
 || defined(DEVICE_dsPIC33FJ64GP310) || defined(DEVICE_dsPIC33FJ64GP310A) || defined(DEVICE_dsPIC33FJ64GP706) \
 || defined(DEVICE_dsPIC33FJ64GP706A) || defined(DEVICE_dsPIC33FJ64GP708) || defined(DEVICE_dsPIC33FJ64GP708A) \
 || defined(DEVICE_dsPIC33FJ64GP710) || defined(DEVICE_dsPIC33FJ64GP710A) || defined(DEVICE_dsPIC33FJ64MC506) \
 || defined(DEVICE_dsPIC33FJ64MC506A) || defined(DEVICE_dsPIC33FJ64MC508) || defined(DEVICE_dsPIC33FJ64MC508A) \
 || defined(DEVICE_dsPIC33FJ64MC510) || defined(DEVICE_dsPIC33FJ64MC510A) || defined(DEVICE_dsPIC33FJ64MC706) \
 || defined(DEVICE_dsPIC33FJ64MC706A) || defined(DEVICE_dsPIC33FJ64MC710) || defined(DEVICE_dsPIC33FJ64MC710A) \
 || defined(DEVICE_PIC24HJ128GP206) || defined(DEVICE_PIC24HJ128GP206A) || defined(DEVICE_PIC24HJ128GP210) \
 || defined(DEVICE_PIC24HJ128GP210A) || defined(DEVICE_PIC24HJ128GP306) || defined(DEVICE_PIC24HJ128GP306A) \
 || defined(DEVICE_PIC24HJ128GP310) || defined(DEVICE_PIC24HJ128GP310A) || defined(DEVICE_PIC24HJ128GP506) \
 || defined(DEVICE_PIC24HJ128GP506A) || defined(DEVICE_PIC24HJ128GP510) || defined(DEVICE_PIC24HJ128GP510A) \
 || defined(DEVICE_PIC24HJ256GP206) || defined(DEVICE_PIC24HJ256GP206A) || defined(DEVICE_PIC24HJ256GP210) \
 || defined(DEVICE_PIC24HJ256GP210A) || defined(DEVICE_PIC24HJ256GP610) || defined(DEVICE_PIC24HJ256GP610A) \
 || defined(DEVICE_PIC24HJ64GP206) || defined(DEVICE_PIC24HJ64GP206A) || defined(DEVICE_PIC24HJ64GP210) \
 || defined(DEVICE_PIC24HJ64GP210A) || defined(DEVICE_PIC24HJ64GP506) || defined(DEVICE_PIC24HJ64GP506A) \
 || defined(DEVICE_PIC24HJ64GP510) || defined(DEVICE_PIC24HJ64GP510A)
 #define OC_COUNT 8
#elif defined(DEVICE_PIC24FJ128DA106) || defined(DEVICE_PIC24FJ128DA110) || defined(DEVICE_PIC24FJ128DA206) \
 || defined(DEVICE_PIC24FJ128DA210) || defined(DEVICE_PIC24FJ128GA106) || defined(DEVICE_PIC24FJ128GA108) \
 || defined(DEVICE_PIC24FJ128GA110) || defined(DEVICE_PIC24FJ128GB106) || defined(DEVICE_PIC24FJ128GB108) \
 || defined(DEVICE_PIC24FJ128GB110) || defined(DEVICE_PIC24FJ128GB206) || defined(DEVICE_PIC24FJ128GB210) \
 || defined(DEVICE_PIC24FJ128GC006) || defined(DEVICE_PIC24FJ128GC010) || defined(DEVICE_PIC24FJ192GA106) \
 || defined(DEVICE_PIC24FJ192GA108) || defined(DEVICE_PIC24FJ192GA110) || defined(DEVICE_PIC24FJ192GB106) \
 || defined(DEVICE_PIC24FJ192GB108) || defined(DEVICE_PIC24FJ192GB110) || defined(DEVICE_PIC24FJ256DA106) \
 || defined(DEVICE_PIC24FJ256DA110) || defined(DEVICE_PIC24FJ256DA206) || defined(DEVICE_PIC24FJ256DA210) \
 || defined(DEVICE_PIC24FJ256GA106) || defined(DEVICE_PIC24FJ256GA108) || defined(DEVICE_PIC24FJ256GA110) \
 || defined(DEVICE_PIC24FJ256GB106) || defined(DEVICE_PIC24FJ256GB108) || defined(DEVICE_PIC24FJ256GB110) \
 || defined(DEVICE_PIC24FJ256GB206) || defined(DEVICE_PIC24FJ256GB210) || defined(DEVICE_PIC24FJ64GA106) \
 || defined(DEVICE_PIC24FJ64GA108) || defined(DEVICE_PIC24FJ64GA110) || defined(DEVICE_PIC24FJ64GB106) \
 || defined(DEVICE_PIC24FJ64GB108) || defined(DEVICE_PIC24FJ64GB110) || defined(DEVICE_PIC24FJ64GC006) \
 || defined(DEVICE_PIC24FJ64GC010)
 #define OC_COUNT 9
#else
 #define OC_COUNT 0
#endif

#endif // OC_PIC24F_dsPIC33F_dsPIC30F_H
