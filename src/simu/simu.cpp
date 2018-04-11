/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "simu.h"

void simulate ( int nWin, int servTime ) { //°΄ΦΈΆ¨΄°ΏΪΚύ‘’·ώΞρΧάΚ±ΌδΔ£Δβ�ψΠΠ�΅Ξρ
   Queue<Customer>* windows = new Queue<Customer>[nWin]; //ΞͺΓΏ�»΄°ΏΪ΄΄½¨�»ΈφΆΣΑΠ
   for ( int now = 0; now < servTime; now++ ) { //ΤΪΟΒ°ΰΦ�Η°£¬ΓΏΈτ�»Έφ΅₯Ξ»Κ±Όδ
      if ( rand() % ( 1 + nWin ) ) { //ΠΒΉΛΏΝ�ΤnWin/(nWin + 1)΅ΔΈΕΒΚ΅½΄ο
         Customer c ; c.time = 1 + rand() % 98; //ΠΒΉΛΏΝ΅½΄ο£¬·ώΞρΚ±³€Λζ»ϊΘ·Ά¨
         c.window = bestWindow ( windows, nWin ); //Υ�³φΧξΌΡ£¨ΧξΆΜ£©΅Δ·ώΞρ΄°ΏΪ/*DSA*/ToDo: ΈόΎ«ΟΈ΅Δ²ίΒΤ
         windows[c.window].enqueue ( c ); //ΠΒΉΛΏΝΌΣΘλΆΤΣ¦΅ΔΆΣΑΠ
      }
      for ( int i = 0; i < nWin; i++ ) //·Φ±πΌμ²ι
         if ( !windows[i].empty() ) //Έχ·ΗΏΥΆΣΑΠ
            if ( -- windows[i].front().time <= 0 ) //ΆΣΚΧΉΛΏΝ΅Δ·ώΞρΚ±³€ΌυΙΩ�»Έφ΅₯Ξ»
               windows[i].dequeue(); //·ώΞρΝκ±Ο΅ΔΉΛΏΝ³φΑΠ£¬ΣΙΊσΌΜΉΛΏΝ½ΣΜζ
      /*DSA*/displayProgress ( windows, nWin, now ); //ΟΤΚΎ΅±Η°Έχ£¨΄°ΏΪ£©ΆΣΑΠΗιΏφ
      /*DSA*/delay > 0 ? //ΘτΓόΑξΠΠΦΈΆ¨΅ΔΚ±ΌδΌδΈτΞͺΥύΚύ
      /*DSA*/  _sleep ( delay ) : //ΤςΧφΟΰΣ¦΅ΔΡΣ³Ω
      /*DSA*/  getchar(); //·ρΤς£¬�ΤΚΦΆ―·½Κ½΅₯²½ΡέΚΎ
   } //for
   delete [] windows; //ΚΝ·ΕΛωΣΠΆΣΑΠ£¨΄ΛΗ°£¬~List()»αΧΤΆ―ΗεΏΥΆΣΑΠ£©
}