/*
 *  fizzbuzz.c
 *
 *  A collection of solutions to the so-called "fizz buzz" test, as proposed by I. Ghory
 * 
 *  from the very reasonable to the very insane, implemented in plain C89.
 *
 *  V1-V7, OBF1 by Thomas Gruetzmacher (tomaes@32x.de)
 *  
 *  OBF2 by Rrrola
 *
 *  Licence: This source code is in the public domain.
 *
 */


#include <stdio.h>
#include <stdlib.h>


#define OBF2



int main(int argc, char ** argv)
{

 int i, range = 100;



/* a no-nonsense, to-the-letter, standard solution, most programmers would think of first. */
#ifdef V1
 for( i = 0; i <= range; i++ )
 {      
       if (i%5 == 0 && i%3 == 0) 
          printf("fizzbuzz\n"); 
       else
       if (i%3 == 0) 
          printf("fizz\n"); 
       else
       if (i%5 == 0) printf("buzz\n"); 
       else
           printf("%d\n",i);
 }
#endif


  
/* somewhat different and slightly optimized version. still a very reasonable and readable version */
#ifdef V2

 char n[4] = {0};
 
 for( i = 0; i++ < range; )
 {      
       if (i%15 == 0) 
          puts("fizzbuzz"); 
       else
       if (i%3 == 0) 
          puts("fizz"); 
       else
       if (i%5 == 0) puts("buzz"); 
       else
           puts( itoa(i,n,10) );
 }
#endif


  
/* some further tweaking. not as obvious as before, but still reasonable */  
#ifdef V3
 for( i = 0; i++ < range; )
 {      
       if (!(i%15)) 
          puts("fizzbuzz"); 
       else
       if (!(i%3)) 
          puts("fizz"); 
       else
       if (!(i%5)) puts("buzz"); 
       else
           printf("%d\n", i);
 }  
#endif



/* here's a first solution that is a little more obscure and not very readable any more */ 
#ifdef V4 
 char *fb[] = { "fizz", "buzz", "fizzbuzz" };  

 for( i = 0; i++ < range; )
     !(i%15) ? puts(fb[2]) : !(i%5) ? puts(fb[1]) : !(i%3) ? puts(fb[0]) : printf("%d\n",i); 
#endif



/* let's put everything in one printf(), quite raunchy version. */
#ifdef V5
 char n[4] = {0};
 
 for(i = 0; i++ < range;)
   printf( "\n%s%s%s%s", 
         ( (i%3)&&(i%5)&&(i%15)    )       ? itoa(i,n,10) : "",  
         ( (!(i%3))&&(i%5)&&(i%15) )       ? "fizz"       : "", 
         ( (!(i%5))&&(i%3)&&(i%15) )       ? "buzz"       : "", 
         ( (!(i%15))&&(!(i%5))&&(!(i%3)) ) ? "fizzbuzz"   : "" );
#endif
 
 
 
/* a fairly liberal interpretation of the test (omitting a tiny part) that is not using modulo any more. */ 
#ifdef V6
 for( i = 0; i++ < range; )
 {
    printf("\ni:%d, fizz?: %s",     i, ( (i/3.  - (float)(i/3))  ) ? ":(" :":)");
    printf("\ni:%d, buzz?: %s",     i, ( (i/5.  - (float)(i/5))  ) ? ":(" :":)");
    printf("\ni:%d, fizzbuzz?: %s", i, ( (i/15. - (float)(i/15)) ) ? ":(" :":)");   
 }
#endif



/* same, same, but different; combination of V4 and V6, with some minor obfuscation.  */
#ifdef V7    
#define F float
 char *fb[] = { "fizz", "buzz", "fizzbuzz", "!", "~" };   

 for( i = 0; i++ < range; ) 
 {
    printf( "i:%3.d %s-> %s\t",   i, fb[~-3], fb[  (i/15. - (F)(i/15)) ? 0x7&4 : -1&3 ] );
    printf( "i:%3.d %s-> %s\t\t", i, fb[ !0], fb[  (i/5.  - (F)(i/05)) ? 0x7&4 : -1&3 ] );
    printf( "i:%3.d %s-> %s\t\n", i, fb[ !1], fb[  (i/3.  - (F)(i/03)) ? 0x7&4 : -1&3 ] );
 }
#endif

  
  
/* Now let's up the ante a bit and show a glimpse of what's possible, but certainly
   not desirable. :) You could still figure it out, but you'd need some time, I guess.
   all the terrible things happen in the array init part, the main loop is still 
   unobfuscated yet. */  
#ifdef OBF1
 int k = 0142; 
 i = (~~!'\0'<<0xA)-(!'\0'<<5)+(!'\0'<<3);
        
 char s[] = {k, k+4, k+7, k+19, k+24, !!(k-~~k)}, f[*s-0x5d], b[(!i|!i-~!-03)*5]; 
    
 f[!s] = s[!!k]; f[1?1&!!i+!i:!i] = s[1<<1]; f[(!!k^!k)<<!!k] = *(s+(0x400>>010)); 
 f[3] = s[(-1^!-1)&(!!~1<<2)]; f[1^!-1+01^~-1+1<<2-!'?'] = *(s+!!~0+2*2);
    
 b[!s] = s[!f]; b[0?0:!!'Z'] = s[-1&0x3]; b[~0*-1<<1] = *(f+!0*2); 
 b[3] = f[1^!-1+2]; b[~!+04?04:04] = s[~0&0x10-~~0xb];
   
 while(i--) (!(i%15))?printf("%s%s\n",f,b):(!(i%5))?puts(b):(!(i%3))?puts(f):printf("%d\n",i);
#endif  
    
    
    
/* Yep, this is actually a 74 byte assembly program in a char array dumped as a .com file, then executed.
   Obviously, this only works on suitable operating systems (up to XP on Windows, otherwise you'd need DOSBox).
   All credit for the contents of c[] belongs to Rrrola. */
#ifdef OBF2  
 char c[] = 
 { 
   0x40, 0x43, 0xD1, 0xCB, 0x72, 0xFC, 0x60, 0x93, 0xBA, 0x36, 0x01, 0xA9, 0x48, 0x12, 0x75, 0x1B,
   0xB2, 0x40, 0xA9, 0x20, 0x04, 0x75, 0x14, 0xB2, 0x3C, 0x48, 0x74, 0x0F, 0x93, 0xF6, 0x74, 0x48,
   0x05, 0x30, 0x30, 0x89, 0x44, 0x46, 0x3C, 0x31, 0x80, 0xD2, 0x0A, 0xB4, 0x09, 0xCD, 0x21, 0x61,
   0x40, 0x3C, 0x64, 0x76, 0xCD, 0xC3, 0x46, 0x69, 0x7A, 0x7A, 0x0A, 0x24, 0x46, 0x69, 0x7A, 0x7A,
   0x42, 0x75, 0x7A, 0x7A, 0x0A, 0x24, 0x00, 0x00, 0x0A, 0x24 
 };

  FILE * file = fopen ("fizzbuzz.com","wb");  
  if (file != NULL) { fwrite (c, 1, sizeof(c), file ); fclose (file); }  
  system("fizzbuzz.com");  
#endif
   
  
  system("PAUSE");	
  return 0;
}
