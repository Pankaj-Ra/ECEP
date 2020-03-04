#!/bin/bash

NAMES=(
	   10005_ashwaqh_ahmed 
	   10004_soumya_u 
	   10004_nischith_manjunath 
	   10004_jeevan_anaparthy 
	   10004_a_chandra_sekhar 
	   10003_n_mithun 
	   10003_modi_dipan 
	   10003_jyothirmani  
	   10003_chaitanya_talluri 
	   10002_ryu_jin_yeol 
	   10002_lee_mingi 
	   10002_kim_eun_jou 
	   10002_kim_daeyoung  
	   10002_jo_hyejin 
	   10002_han_jeewook 
	   10002_ham_duk_goo 
	   10002_bae_yujin 
	   10001_sheshanandan_k_n 
	   10001_priyanka_roy 
	   10001_mohamed_yunus_s 
	   10001_d_d_venkatesh 
	   10001_abhishek_m 
	   09021_sri_harsha_s 
	   09020_sabah_parveen 
	   09019_u_sandeep
	  )

DECREMENT=9996

for (( i = 0 ; i < ${#NAMES[@]} ; i++ )) 
do 
	echo "${NAMES[$i]}:x:$DECREMENT:1000::/home/${NAMES[$i]}/bin/bash"
	DECREMENT=`expr $DECREMENT - 1`
	#chown -R ${NAMES[$i]}.trainings ${NAMES[$i]}
done

#In this example, the value ${#NAMES[@]} evaluates into the number of elements in the array (4 in this case). 
#The individual elements of the array are accessed, one at a time, using the index integer $i as ${NAMES[$i]}
